/* Path.h declares a class for storing PATH information.
 *
 * Written by: Charles Kornoelje (cek26)
 * CS 232 - HW 4 |  Calvin University
 * March 9, 2020
 */

#include <string>
#include <vector>
#include <dirent.h> // DIR
using namespace std;

class Path
{
    public:
        Path();
        int find(const string& program) const; // A read-only function
    private:
        void getPathDirs();
        int read(DIR *pDir, struct dirent *pDirent, const string &prog) const;
        vector<string> dirs;
};
