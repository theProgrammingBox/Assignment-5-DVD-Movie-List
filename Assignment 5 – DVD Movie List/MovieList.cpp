#include "MovieList.h"

/**********************************************************
* MovieList
* --------------------------------------------------------
* This function is the constructor for the MovieList class.
*
* returns nothing
**********************************************************/

MovieList::MovieList()
{
}

/**********************************************************
* ~MovieList
* --------------------------------------------------------
* This function is the destructor for the MovieList class.
*
* returns nothing
**********************************************************/

MovieList::~MovieList()
{
}

/**********************************************************
* CreateList
* --------------------------------------------------------
* This function will read in the file and create a new
* node for each line.
*
* returns nothing
**********************************************************/

void MovieList::CreateList(string inputFileName)	// IN - The name of the file to read
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
* OutputList
* --------------------------------------------------------
* This function will output the list to the file.
*
* returns nothing
**********************************************************/

void MovieList::OutputList(string outputFileName)	// IN - The name of the file to write
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
		outputFile << "PLOT: \n" << WorpWrap(temp->synopsis) << "\n";
		outputFile << "***************************************************************************\n\n\n";
		temp = temp->next;
		index++;
	}
	outputFile.close();
}

/**********************************************************
* WorpWarp
* --------------------------------------------------------
* This function will warp the plot to the correct size.
*
* returns string
**********************************************************/

string MovieList::WorpWrap(string plot) const	// IN - The plot getting wrapped
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
* AdjustTitle
* --------------------------------------------------------
* This function will adjust the title to the correct size.
*
* returns string
**********************************************************/

string MovieList::AdjustTitle(string title) const	// IN - The title getting adjusted
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
* PrintHeader
* --------------------------------------------------------
* This function will output the header to the file.
*
* returns nothing
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