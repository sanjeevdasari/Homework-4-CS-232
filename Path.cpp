/* Path.cpp implements a class for storing PATH information.
 *
 * Written by: Charles Kornoelje (cek26)
 * CS 232 - HW 4 |  Calvin University
 * March 9, 2020
 */

#include "Path.h"
#include <iostream>
#include <string.h>
#include <dirent.h> // opendir()
#include <sys/types.h>
using namespace std;

// TODO: need to deallocate arrays???? del array?

Path::Path()
{
    getPathDirs();
    // find("ls");
    // find("flutter");
    // find("asdf");
    // getDirectory(1);
    // getDirectory(10);
}

/*
 * return the index of the directory containing program, or -1 if 
 *  program is in no directory.
 * Referenced: https://stackoverflow.com/questions/3554120/open-directory-using-c
 */
int Path::find(const string &program) const
{
    const char *cur_dir;
    DIR *pDir;
    struct dirent *pDirent;
    for (unsigned i = 0; i < dirs.size(); i++)
    {
        cur_dir = dirs[i].c_str();
        // printf("Looking at %d %s\n", i, cur_dir);
        pDir = opendir(cur_dir);
        if (pDir != NULL)
        {
            if (read(pDir, pDirent, program))
            {
                return i;
            }
        }
        else
        {
            // printf("Cannot open directory '%s'\n", cur_dir);
        }
    }
    return -1;
}

int Path::read(DIR *pDir, struct dirent *pDirent, const string &prog) const
{

    // printf(cur_dir);
    // while ((pDirent = readdir(pDir)) != NULL) {
    //     printf("[%s]\n", pDirent->d_name);
    // }

    while ((pDirent = readdir(pDir)) != NULL)
    {
        if (pDirent->d_name == prog)
        {
            closedir(pDir);
            return true;
        }
    }

    closedir(pDir);
    return false;
}
/* return the name of the directory whose index is i.
 *
 * 
 */
string Path::getDirectory(int i) const
{
    // TODO: error handling?
    return dirs[i];
}

// Referenced: https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/
void Path::getPathDirs()
{
    char *path = getenv("PATH");
    if (path != NULL)
    {
        char *token = strtok(path, ":");
        while (token != NULL)
        {
            dirs.push_back(token);
            token = strtok(NULL, ":");
        }
    }

    // for (unsigned i = 0; i < dirs.size(); i++)
    //     cout << dirs[i] << endl;
}
