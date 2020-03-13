/*
 * CSShell.h is a shell class that simulates a shell program
 *
 * Written by: Sanjeev AND Charles (cek26)
 * CS 232 - HW 4
 * March 9, 2020
 */

#include "CSShell.h"
#include "Path.h"
#include "Prompt.h"
#include <iostream>
#include <unistd.h>   // chdir()
#include <sys/wait.h> // waitpid()
using namespace std;

CSShell::CSShell()
{
}

void CSShell::run()
{
  Path path;

  while (true)
  {
    Prompt prompt;
    CommandLine cl(cin);
    char *command = cl.getCommand();
    int argc = cl.getArgCount();

    if (string(command) == "cd")
    {
      // Handle incorrect commands!!!!!
      chdir(cl.getArgVector(1));
    }
    else if (string(command) == "pwd")
    {
      cout << prompt.get() << ": " << endl;
    }
    else if (string(command) == "exit")
    {
      exit(0);
    }
    else
    {
      pid_t child = fork();
      if (child == 0)
      {
        char *env_args[] = {(char *)0}; // TODO check this.
        string prog_path = path.getDirectory(path.find(command)) + "/" + command;
        cout << execve(prog_path.c_str(), cl.getArgVector(), env_args) << flush;
      }
      int status;
      if (cl.noAmpersand())
      {
        waitpid(child, &status, 0);
      }

      // BUG: forks don't close themselves.
    }
  }
}