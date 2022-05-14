#pragma once
#include "Header.h"

class StackList
{
public:

	/*** CONSTRUCTOR & DESTRUCTOR ***/

	StackList();	// constructor
	~StackList();	// destructor

	/***  MUTATORS ***/

	void Push(DVDNode newDVD);
	DVDNode Pop();

	/***  ACCESSORS ***/

	bool IsEmpty() const;
	DVDNode Peek() const;
	int Size() const;

protected:
	DVDNode* head;		// IN & OUT - name of the animal
	int stackCount;		// IN & OUT - age of the animal
};