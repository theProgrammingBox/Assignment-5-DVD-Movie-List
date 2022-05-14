/**********************************************************
 * AUTHOR :			Justin Gea
 * Assignment #5 : 	DVD Movie List
 **********************************************************/

#include "MovieList.h"

 /**********************************************************
 * DVD Movie List
 * _________________________________________________________
 * This program will read in a file of movies and output
 * the movies in a list.
 * _________________________________________________________
 * INPUT:
 * 		inputFileName: The name of the input file.
 * 		outputFileName: The name of the output file.
 *
 * OUTPUT:
 * 		The movies in a list.
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