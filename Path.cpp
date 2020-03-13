/* Path.cpp implements a class for storing PATH information.
 *
 * Written by: Charles Kornoelje (cek26)
 * Partner: Sanjeev Dasari (sd47)
 * CS 232 - HW 4 | Calvin University
 * March 9, 2020
 */

#include "Path.h"
#include <iostream>
#include <string.h>
#include <dirent.h> // opendir()
#include <sys/types.h>
using namespace std;

/* Path() is a default Path constructor
 * It will initalize a list of PATH directories
 *   from the environment variables storing the
 *   values in private instance var, vector<string> dirs.
 */ 
Path::Path()
{
    getPathDirs();
}

/* find(const string &program) const is a read-only function that finds
 *   a program by traversion PATH directories.
 * params: string reg of prog name.
 * return: the index of the directory containing program, or -1 if 
 *  program is in no directory.
 * Referenced: https://stackoverflow.com/questions/3554120/open-directory-using-c
 */
int Path::find(const string &program) const
{
    const char *cur_dir;
    DIR *p_dir;
    struct dirent *p_dirent;

    // Traverse directories
    for (unsigned i = 0; i < dirs.size(); i++)
    {
        cur_dir = dirs[i].c_str();

        // Try to open directory
        p_dir = opendir(cur_dir);
        if (p_dir != NULL)
        {
            if (read(p_dir, p_dirent, program))
            {
                return i;
            }
        }
    }
    return -1;
}

/* read(DIR *p_dir, struct dirent *p_dirent, const string &prog) const 
 *   is a read-only function that finds a program checking if 
 *   prog is located in dir.
 * params: pointer to directory, pointer to directory entity, string reg of prog name.
 * return: boolean, true if prog is in directory, false otherwise
 */
int Path::read(DIR *p_dir, struct dirent *p_dirent, const string &prog) const
{
    while ((p_dirent = readdir(p_dir)) != NULL)
    {
        if (p_dirent->d_name == prog)
        {
            closedir(p_dir);
            return true;
        }
    }
    closedir(p_dir);
    return false;
}

/* getDirectory(int i) const is a RO function that returns
 *  the string name of the directory of a index in the PATH
 *  dirs vector.
 * return: string, name of the directory whose index is i.
 */
string Path::getDirectory(int i) const
{
    return dirs[i];
}

/* getPathDirs() is a private function to set the instance
 *   dirs vector. 
 */
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
}
