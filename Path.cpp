/* Path.cpp implements a class for storing PATH information.
 *
 * Written by: Charles Kornoelje (cek26)
 * CS 232 - HW 4 |  Calvin University
 * March 9, 2020
 */

#include "Path.h"
#include <iostream>
#include <string.h>
using namespace std;

Path::Path()
{
    getPathDirs();
    
}

// Referenced: https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/
void Path::getPathDirs()
{
    
    char *path = getenv("PATH");
    if (path != NULL) {
        char* token = strtok(path, ":");
        while (token != NULL)
        {
            dirs.push_back(token);
            token = strtok(NULL, ":");
        }
    }

    for (int i = dirs.size() - 1; i >= 0; i--) 
        cout << dirs[i] << endl;
}


