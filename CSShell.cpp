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
using namespace std;

CSShell::CSShell()
{
  // CommandLine cl(cin);
}

void CSShell::run()
{
  Path path;
  Prompt prompt;

  string cur_path = prompt.get();

  while (true)
  {
    CommandLine cl(cin);
    char *command = cl.getCommand();
    int argc = cl.getArgCount();

    if (string(command) == "cd")
    {
      // Handle cd

      // Modify path 
      cout << "cd worked" << endl;
    }
    else if (string(command) == "pwd")
    {
      // will this change?
      cout << cur_path << ": " << endl;
      // cout << path << ": " << flush;
    }
    else if (string(command) == "exit")
    {
      // quit program
      exit(0);
    }
    else
    {

    }
  }
}