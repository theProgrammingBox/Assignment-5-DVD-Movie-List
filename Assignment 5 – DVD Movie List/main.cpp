#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct DVDNode
{
	string title;
	string leadingActor;
	string supportingActor;
	string genre;
	string alternateGenre;
	int year;
	int rating;
	string synopsis;
	DVDNode* next;
};

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

StackList::StackList()
{
	head = NULL;
	stackCount = 0;
}

/**********************************************************
* StackList
* --------------------------------------------------------
* This function sets the head pointer to NULL and the
* stackCount to 0.
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
* ~StackList
* --------------------------------------------------------
* This function will delete all the nodes in the stack.
* It will also set the head pointer to NULL if the stack
* is empty.
*
* returns nothing
**********************************************************/

void StackList::Push(DVDNode newDVD)
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
* Push
* --------------------------------------------------------
* This function will add a new node to the top of the
* stack.
*
* returns nothing
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
* Pop
* --------------------------------------------------------
* This function will remove the top node from the stack
* and return it.
*
* returns DVDNode
**********************************************************/

bool StackList::IsEmpty() const
{
	return head == NULL;
}

/**********************************************************
* IsEmpty
* --------------------------------------------------------
* This function will return true if the stack is empty.
*
* returns bool
**********************************************************/

DVDNode StackList::Peek() const
{
	return *head;
}

/**********************************************************
* Peek
* --------------------------------------------------------
* This function will return the top node of the stack.
*
* returns DVDNode
**********************************************************/

int StackList::Size() const
{
	return stackCount;
}

/**********************************************************
* Size
* --------------------------------------------------------
* This function will return the size of the stack.
*
* returns int
**********************************************************/

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
	string WorpWarp(string plot) const;
	string AdjustTitle(string title) const;
	void PrintHeader(
		ofstream& outputFilestring, // IN - output file
		string  name,  				// IN - Lab or Assignment name
		char    type,  				// IN - Determines if Lab or Assignment
		string  number) const;  	// IN - Lab or Assignment number
};

MovieList::MovieList()
{
}

/**********************************************************
* MovieList
* --------------------------------------------------------
* This function is the constructor for the MovieList class.
*
* returns nothing
**********************************************************/

MovieList::~MovieList()
{
}

/**********************************************************
* ~MovieList
* --------------------------------------------------------
* This function is the destructor for the MovieList class.
*
* returns nothing
**********************************************************/

void MovieList::CreateList(string inputFileName)
{
	ifstream inputFile;
	inputFile.open(inputFileName);
	string title;
	string leadingActor;
	string supportingActor;
	string genre;
	string alternateGenre;
	int year;
	int rating;
	string synopsis;
	while (inputFile)
	{
		getline(inputFile, title);
		getline(inputFile, leadingActor);
		getline(inputFile, supportingActor);
		getline(inputFile, genre);
		getline(inputFile, alternateGenre);
		inputFile >> year;
		inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
		inputFile >> rating;
		inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(inputFile, synopsis);
		inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
		DVDNode newDVD;
		newDVD.title = title;
		newDVD.leadingActor = leadingActor;
		newDVD.supportingActor = supportingActor;
		newDVD.genre = genre;
		newDVD.alternateGenre = alternateGenre;
		newDVD.year = year;
		newDVD.rating = rating;
		newDVD.synopsis = synopsis;
		Push(newDVD);
	}
	inputFile.close();
}

/**********************************************************
* CreateList
* --------------------------------------------------------
* This function will read in the file and create a new
* node for each line.
*
* returns nothing
**********************************************************/

void MovieList::OutputList(string outputFileName)
{
	ofstream outputFile;
	DVDNode* temp;
	int index;
	outputFile.open(outputFileName);
	PrintHeader(outputFile, "DVD Movie List", 'a', "5");
	temp = head;
	index = 1;
	while (temp != NULL)
	{
		outputFile << "***************************************************************************\n";
		outputFile << "MOVIE #: " << left << setw(9) << index << "Title: " << AdjustTitle(temp->title) << "\n";
		outputFile << "---------------------------------------------------------------------------\n";
		outputFile << "Year: " << left << setw(12) << temp->year << "Rating: " << temp->rating << "\n";
		outputFile << "---------------------------------------------------------------------------\n";
		outputFile << "Leading Actor:    " << left << setw(24) << temp->leadingActor << "Genre 1: " << temp->genre << "\n";
		outputFile << "Supporting Actor: " << left << setw(24) << temp->supportingActor << "Genre 2: " << temp->alternateGenre << "\n";
		outputFile << "---------------------------------------------------------------------------\n";
		outputFile << "PLOT: \n" << WorpWarp(temp->synopsis) << "\n";
		outputFile << "***************************************************************************\n\n\n";
		temp = temp->next;
		index++;
	}
	outputFile.close();
}

/**********************************************************
* OutputList
* --------------------------------------------------------
* This function will output the list to the file.
*
* returns nothing
**********************************************************/

string MovieList::WorpWarp(string plot) const
{
	const int SIZE = 75;
	int index = SIZE;

	while (index < plot.size())
	{
		while (!isspace(plot[index]) && index >= 0)
		{
			index--;
		}

		plot[index] = '\n';
		index += SIZE;
	}

	return plot;
}

/**********************************************************
* WorpWarp
* --------------------------------------------------------
* This function will warp the plot to the correct size.
*
* returns string
**********************************************************/

string MovieList::AdjustTitle(string title) const
{
	if (title.size() > 47)
	{
		title = title.substr(0, 47) + "...";
		return title;
	}
	else
	{
		return title;
	}
}

/**********************************************************
* AdjustTitle
* --------------------------------------------------------
* This function will adjust the title to the correct size.
*
* returns string
**********************************************************/

void MovieList::PrintHeader(
	ofstream& outputFilestring, // IN - output file
	string  name,  				// IN - Lab or Assignment name
	char    type,  				// IN - Determines if Lab or Assignment
	string  number) const  		// IN - Lab or Assignment number
{
	outputFilestring << left;
	outputFilestring << "**************************************************\n";
	outputFilestring << "* PROGRAMMED BY : Justin Gea\n";
	outputFilestring << "* ";
	if (type == 'a')
	{
		outputFilestring << "ASSIGNMENT #" << setw(2);
	}
	else
	{
		outputFilestring << "LAB #" << setw(9);
	}
	outputFilestring << number << ": " << name << endl;
	outputFilestring << "**************************************************\n\n\n";
	outputFilestring << right;
}

/**********************************************************
* PrintHeader
* --------------------------------------------------------
* This function will output the header to the file.
*
* returns nothing
**********************************************************/

int main()
{
	string inputFileName;
	string outputFileName;
	MovieList movieList;

	cout << "Enter the name of the input file (input.txt for default): ";
	getline(cin, inputFileName);
	movieList.CreateList("input.txt");
	cout << "Enter the name of the output file (output.txt for default): ";
	getline(cin, outputFileName);
	movieList.OutputList("output.txt");
	return 0;
}