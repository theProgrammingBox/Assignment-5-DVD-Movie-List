#include "StackList.h"

/**********************************************************
* StackList
* --------------------------------------------------------
* This function sets the head pointer to NULL and the
* stackCount to 0.
*
* returns nothing
**********************************************************/

StackList::StackList()
{
	head = NULL;
	stackCount = 0;
}

/**********************************************************
* ~StackList
* --------------------------------------------------------
* This function will delete all the nodes in the stack.
* It will also set the head pointer to NULL if the stack
* is empty.
*
* returns nothing
**********************************************************/

StackList::~StackList()
{
	while (!IsEmpty())
	{
		Pop();
	}
}

/**********************************************************
* Push
* --------------------------------------------------------
* This function will add a new node to the top of the
* stack.
*
* returns nothing
**********************************************************/

void StackList::Push(DVDNode newDVD)	// IN - the new node to be added
{
	DVDNode* temp = new DVDNode;
	temp->title = newDVD.title;
	temp->leadingActor = newDVD.leadingActor;
	temp->supportingActor = newDVD.supportingActor;
	temp->genre = newDVD.genre;
	temp->alternateGenre = newDVD.alternateGenre;
	temp->year = newDVD.year;
	temp->rating = newDVD.rating;
	temp->synopsis = newDVD.synopsis;
	temp->next = head;
	head = temp;
	stackCount++;
}

/**********************************************************
* Pop
* --------------------------------------------------------
* This function will remove the top node from the stack
* and return it.
*
* returns DVDNode
**********************************************************/

DVDNode StackList::Pop()
{
	DVDNode temp = *head;
	DVDNode* temp2 = head;
	head = head->next;
	stackCount--;
	delete temp2;
	return temp;
}

/**********************************************************
* IsEmpty
* --------------------------------------------------------
* This function will return true if the stack is empty.
*
* returns bool
**********************************************************/

bool StackList::IsEmpty() const
{
	return head == NULL;
}

/**********************************************************
* Peek
* --------------------------------------------------------
* This function will return the top node of the stack.
*
* returns DVDNode
**********************************************************/

DVDNode StackList::Peek() const
{
	return *head;
}

/**********************************************************
* Size
* --------------------------------------------------------
* This function will return the size of the stack.
*
* returns int
**********************************************************/

int StackList::Size() const
{
	return stackCount;
}