# Homework-4-CS-232

A Command Shell
Overview
A shell is a program that repeatedly:
reads a user command from the keyboard; and
performs that command on behalf of the user.
Your task in this 2-person group assignment is to write your own xyshell program, where x and y are the first initials of the people in your group.
Details
This project is to write an object-oriented C++ shell program. Each non-trivial object in the project should be written as a class. Your driver program for the project should be no more complicated than this:
#include "XYShell.h"

int main()
{
   XYShell myShell;
   myShell.run();
}

One possible breakdown of the functionality is as follows:
XYShell - your shell class, with two public methods:
XYShell() - initialize your shell; and
void run() - execute your shell.
In addition to executing system programs (e.g., ls, ps, cat), your shell must also 	handle cd, pwd, and exit as built-in commands (you may find the chdir() and getcwd() system calls to be useful for this).
CommandLine - a class to read a command-line, with these public methods: 	
CommandLine(istream& in) - construct a CommandLine by reading a command-line from in, parsing it, and building instance variables for argc and argv (you may find the calloc() and free() system calls to be of use here).
char* getCommand() const - return a pointer to the command portion of the command-line (i.e., argv[0]).
int getArgCount() const - return the number of command-line arguments on the command-line (i.e., argc).
char** getArgVector() const - return a pointer to a char* array, each entry of which points to one 'word' of the command-line (i.e., argv).	
char* getArgVector(int i) const - return a pointer to the ith (zero-relative) command-line 'word' (i.e., argv[i]).
bool noAmpersand() const - returns true if and only if no ampersand was given on the command-line
Path - a class to represent the directories in which your shell searches for executable programs, with these public methods:
Path() - construct a Path from the PATH environment variable, by storing each directory in PATH in a vector<string> (you may find the getenv() system call to be of use).
int find(const string& program) const - return the index of the directory containing program, or -1 if program is in no directory (you may find the opendir(), readdir(), and closedir() system calls to be of use here). 
string getDirectory(int i) const - return the name of the directory whose index is i.
Prompt - a class to represent the command-line prompt, containing these public methods:
Prompt() - a constructor that builds a Prompt as the full path to the working directory (you may find the getcwd() system call to be of use).
string get() const - an accessor that returns the current value of the Prompt.
You should feel free to create other classes as you need them. You may also define additional methods in each of these classes. Methods that define messages to be sent to class objects should be implemented as public methods; methods used to define class utilities or break a big method into more manageable pieces should be defined as private methods. Stylistically, no method should be more than a half-page in length (10 lines in length would be even better). Remember: Any class that allocates memory dynamically should provide a destructor to reclaim that memory, to avoid leaking memory.
To execute system programs, your shell should use the fork(), waitpid(), and execve() system calls: The fork() call clones the current process to create a child process that is a complete copy of its parent. The child process should then use execve() to execute the user's command.
If no ampersand has been given on the command-line, the parent should use waitpid() to wait until the child terminates; otherwise (an ampersand was given, indicating the command was to be run in the background), it should return to the top of its loop, prompt the user, and await their next command. You may also find the sched_yield() system call to be useful in synchronizing the parent and child processes.
You should read the UNIX manual pages (section 2) for the details of the various system calls listed above, especially what header files must be #include-d to use them. There are also may be WWW tutorials/examples available that you may find useful.
To illustrate:
$ ./xyshell

should run your shell, which then displays its prompt (as below) and awaits a user command:

/home/vtn2/proj/shell/$ 

When the user types a command, the program should perform that command and then prompt for the next one:
  
/home/vtn2/proj/shell$ ps
     PID TTY          TIME CMD
     2208 pts/2    00:00:00 bash
     2428 pts/2    00:00:00 xyshell
     2485 pts/2    00:00:00 ps
/home/vtn2/proj/shell/$

If the user types a command with an ampersand, the program should not wait before prompting for the next command:

/home/vtn2/proj/shell$ ps &
/home/vtn2/proj/shell$
     PID TTY          TIME CMD
     2208 pts/2    00:00:00 bash
     2428 pts/2    00:00:00 xyshell
     2485 pts/2    00:00:00 ps
