/*Created on: Mar 11, 2020
 *Author: Sanjeev Dasari (sd47), Partner: Charles
 *CS 232 - Homework 4
 */
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sstream>     // inputing and outputting stream (class)

using namespace std;


class CommandLine 

{              // declaring command class

                                     // Public methods and variables
public:
	CommandLine(istream& in); //  Used to read in the commands from the user
	char* getCommand() const;
	int getArgCount() const;  // number of command-line arguments on the command-line
	char** getArgVector() const;  // pointer to a char* array
	char* getArgVector(int i) const; // pointer to the ith (zero-relative) command-line 'word'
	bool noAmpersand() const; // true or false if ampersand was given in the command-line
	virtual ~CommandLine();    // destructor for the CommandLine class

                                     // Private variables
private:
	int argc;
	char** argv;
	vector<string> myArgv;
	bool noAmpersand_var;
};


