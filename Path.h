/* Path.h declares a class for storing PATH information.
 *
 * Written by: Charles Kornoelje (cek26)
 * CS 232 - HW 4 |  Calvin University
 * March 9, 2020
 */

#include <string>
#include <vector>
using namespace std;

class Path
{
    public:
        Path();
    private:
        void getPathDirs();
        vector<string> dirs;
};
