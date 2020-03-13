/* CSShell.h declares a shell class that simulates a shell program
 *
 * Written by: Sanjeev Dasari (sd47) andCharles Kornoelje (cek26)
 * CS 232 - HW 4 | Calvin University
 * March 9, 2020
 */

#ifndef CSSHELL_H // include guard
#define CSSHELL_H

#include "Path.h"
#include "Prompt.h"
#include "CommandLine.h"

class CSShell {
    public:
        CSShell() { };
        void run();
    private:
        Path path;
        void handleCommand(const char *command, Prompt &prompt, CommandLine &cl);
        void runSysProg(const char *command, Prompt &prompt, CommandLine &cl);
};

#endif /* CSSHELL_H */