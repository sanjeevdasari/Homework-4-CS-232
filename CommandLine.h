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
	CommandLine(istream& in);
	char* getCommand() const;
	int getArgCount() const;
	char** getArgVector() const;
	char* getArgVector(int i) const;
	bool noAmpersand() const;
	virtual ~CommandLine();

                                     // Private variables
private:
	int argc;
	char** argv;
	vector<string> myArgv;
	bool noAmpersand_var;
};


