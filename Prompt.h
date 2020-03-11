/* Prompt.h declares a class representing the command-line prompt.
 *
 * Written by: Charles Kornoelje (cek26)
 * CS 232 - HW 4 |  Calvin University
 * March 10, 2020
 */



class Prompt
{
    public:
        Prompt();
        ~Prompt();
        
    private:
        static char *current_path;
};