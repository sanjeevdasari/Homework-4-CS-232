/* Prompt.h implements a class representing the command-line prompt.
 *
 * Written by: Charles Kornoelje (cek26)
 * Partner: Sanjeev Dasari (sd47)
 * CS 232 - HW 4 |  Calvin University
 * March 10, 2020
 */

#include "Prompt.h"
#include <iostream>
#include <unistd.h> // getcwd()
using namespace std;

// Don't want to assume C++11. Old versions don't support initalizing static vars
//   in the .h files.
char *Prompt::current_path = new char[512];

/* Prompt() is a default Prompt constructor
 * Sets the current_path to the cwd.
 */
Prompt::Prompt()
{
    getcwd(current_path, 512);
}

/* get() const an accessor that returns the current value of the Prompt
 * return: string of current path.
 */
string Prompt::get() const
{
    return string(current_path);
}

// Destructor
Prompt::~Prompt()
{
    delete[] current_path;
}
