#include <iostream>
#include <string>

using namespace std;

#ifndef COMESTIBLES_H_
#define COMESTIBLES_H_
struct Comestibles
{
	string name;
	string ingredients;
	string taste;
	string style;
	Comestibles *next_comestible;
	Comestibles *prev_comestible;

	Comestibles();
	~Comestibles();
};
# endif