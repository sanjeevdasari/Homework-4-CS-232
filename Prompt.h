/* Prompt.h declares a class representing the command-line prompt.
 *
 * Written by: Charles Kornoelje (cek26)
 * Partner: Sanjeev Dasari (sd47)
 * CS 232 - HW 4 |  Calvin University
 * March 10, 2020
 */

#include<string>
using namespace std;

class Prompt
{
    public:
        Prompt();
        ~Prompt();
        string get() const;
    private:
        static char *current_path;
};