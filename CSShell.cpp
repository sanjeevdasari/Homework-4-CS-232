/* CSShell.cpp implements a shell class that simulates a shell program
 *
 * Written by: Sanjeev Dasari (sd47) and Charles Kornoelje (cek26)
 * CS 232 - HW 4 | Calvin University
 * March 9, 2020
 */

#include "CSShell.h"
#include <iostream>
#include <unistd.h>   // chdir()
#include <sys/wait.h> // waitpid()
using namespace std;

/* run() runs the shell, continually prompting for input
 *   and executes commands.
 * Will continue until 'exit' received.
 */
void CSShell::run()
{
  while (true)
  {
    // Shell I/O
    Prompt prompt;
    cout << prompt.get() << "/CSShell/$ " << flush;
    CommandLine cl(cin);
    char *command = cl.getCommand();
    int argc = cl.getArgCount();

    handleCommand(command, prompt, cl);
  }
}

/* handleCommand(const char *command, Prompt &prompt, CommandLine &cl) 
 *   will execute the command from the user via prompt. 
 * params: char* command, ref to prompt, ref to cl.
 * post-condition: command executed.
 */
void CSShell::handleCommand(const char *command, Prompt &prompt, CommandLine &cl)
{
  if (string(command) == "cd")
  {
    if (chdir(cl.getArgVector(1)) == -1)
    {
      cout << "Cannot change to directory: " << cl.getArgVector(1) << endl;
    }
  }
  else if (string(command) == "pwd")
  {
    cout << prompt.get() << endl;
  }
  else if (string(command) == "exit")
  {
    cout << "Exiting..." << endl;
    exit(0);
  }
  else
  {
    runSysProg(command, prompt, cl);
  }
}

/* runSysProg(const char *command, Prompt &prompt, CommandLine &cl) 
 *   will execute a system program of name, command.
 * params: char* command, ref to prompt, ref to cl.
 * post-condition: system prog executed.
 */
void CSShell::runSysProg(const char *command, Prompt &prompt, CommandLine &cl)
{
  if (path.find(command) == -1)
    {
      cout << "Cannot locate command: " << command << endl;
    }
    else
    {
      // Create for to execute sys prog.
      pid_t child = fork();
      if (child == -1)
      {
        cout << "Fork failed." << endl;
      }
      else if (child == 0)
      {
        // Execution of sys program.
        string prog_path = path.getDirectory(path.find(command)) + "/" + command;
       int error = execve(prog_path.c_str(), cl.getArgVector(), NULL);
       if (error == -1)
       {
         cout << "Cannot execute command: " << command << endl;
       }
      }

      int status;
      if (cl.noAmpersand())
      {
        waitpid(child, &status, 0);
      }
    }
}