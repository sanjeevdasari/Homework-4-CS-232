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
#include "CommandLine.h"
#include <iostream>
using namespace std;

CSShell::CSShell()
{

}

void CSShell::run()
{
  Path path;
  Prompt prompt;
  CommandLine cl;

  while (true)
  {
    char *command = cl.getCommand();
    int argc = cl.getArgCount();

    string path = prompt.get();

    if (command == "cd")
    {
      // Handle cd

      // Modify path 
    }
    else if (command = "pwd")
    {
      // will this change?
      cout << path << ": " << flush;
    }
    else if (command = "exit")
    {
      // quit program
      exit(0);
    }
    else
    {
      
    }
    


  }
}