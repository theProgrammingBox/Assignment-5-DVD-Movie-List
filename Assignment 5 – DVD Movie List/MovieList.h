#pragma once
#include "StackList.h"

class MovieList : public StackList
{
public:

	/*** CONSTRUCTOR & DESTRUCTOR ***/

	MovieList();	// constructor
	~MovieList();	// destructor

	/***  MUTATORS ***/

	void CreateList(string inputFileName);

	/***  ACCESSORS ***/

	void OutputList(string outputFileName);

private:
	string WorpWrap(string plot) const;
	string AdjustTitle(string title) const;
	void PrintHeader(
		ofstream& outputFilestring, // IN - output file
		string  name,  				// IN - Lab or Assignment name
		char    type,  				// IN - Determines if Lab or Assignment
		string  number) const;  	// IN - Lab or Assignment number
};