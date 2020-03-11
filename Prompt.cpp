/* Prompt.h implements a class representing the command-line prompt.
 *
 * Written by: Charles Kornoelje (cek26)
 * CS 232 - HW 4 |  Calvin University
 * March 10, 2020
 */

#include "Prompt.h"
#include <iostream>
#include <unistd.h> // getcwd()
using namespace std;

// TODO: do I need to deallocate arrays?

// Don't want to assume C++11
char *Prompt::current_path = new char[512];

// Default constructor
Prompt::Prompt()
{
    getcwd(current_path, 512);
    // printf("%s\n", current_path);
    get();
}

/* an accessor that returns the current value of the Prompt
 * 
 */
string Prompt::get() const
{
    cout << string(current_path) << endl;
    return string(current_path);
}

Prompt::~Prompt()
{
    delete[] current_path;
}
