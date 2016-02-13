# include "Comestibles.h"

#ifndef CUISINE_H_
#define CUISINE_H_
struct Cuisine
{
	string category_name;
	Cuisine *next_cuisine;
	Cuisine *prev_cuisine;
	Comestibles *foodptr;

	Cuisine();
	~Cuisine();
};
# endif