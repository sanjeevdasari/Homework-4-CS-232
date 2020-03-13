/*
 * CommandLine.cpp is a class to read a command line and construct a vector from the arguments
 *
 *  Created on: Mar 11, 2020
 *      Author: Sanjeev Dasari (sd47)
 *		Partner: charles
 * CS 232 - Homework - 4
 */

#include "CommandLine.h"

using namespace std;


CommandLine::CommandLine() 
                            // it is the default constructor
{
	argc = 0;
}

/*
 * CommandLine() explicit constructor
 * Parameter: istream& in
 *		Used to read in the commands from the user
 * Set the noAmpersand bool variable to false if there is an ampersand in the command-line
 */

// --------------------------------------------------------
CommandLine::CommandLine(istream& in) 

{
	argc = 0;

	noAmpersand_var = true;

	string argString;
	getline(in, argString);
	istringstream argStream (argString);

	string word;
	while (argStream >> word) 
{
		if (strcmp(word.c_str(), "&") == 0) 
                {
			noAmpersand_var = false;
		} else 

                {
			myArgv.push_back(word);
			argc++;
		}
}

	argv = new char*[myArgv.size()];

	for (size_t i = 0; i < myArgv.size(); i++) 
        {
		argv[i] = new char[myArgv[i].size() + 1];
		strcpy(argv[i], myArgv[i].c_str());
	}
}

//------------------------------------------------------------

char* CommandLine::getCommand() const

{
	return argv[0];
}                        // returns a pointer to the command portion of the command-line (i.e., argv[0]).

//------------------------------------------------------------

int CommandLine::getArgCount() const

{
	return argc;    // // return the number of command-line arguments on the command-line (i.e., argc).
}

//------------------------------------------------------------

char** CommandLine::getArgVector() const  // incrementing the char** array pointer

{
	return argv;
}                         // returns a pointer to a char* array, each entry of which points to one 'word' of the command-line (i.e., argv).            

// -----------------------------------------------------------

char* CommandLine::getArgVector(int i) const

{
	return argv[i];              // return a pointer to the ith (zero-relative) command-line 'word' (i.e., argv[i]).
}                                    // returns the argument from the vector at the given index

//------------------------------------------------------------

bool CommandLine::noAmpersand() const

{                                  // returns true if and only if no ampersand was given on the command-line
	return noAmpersand_var;
}                                 //  returns false if and only if ampersand was given in the command-line

//------------------------------------------------------------

CommandLine::~CommandLine() 
{                                 // destructor for the CommandLine class
	for (size_t i = 0; i < myArgv.size(); i++) 
        {
		delete[] argv[i];
	}                       // reclaims memory from each element in argv as well as argv itself

	delete[] argv;

}