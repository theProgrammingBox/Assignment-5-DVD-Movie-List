#pragma once
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