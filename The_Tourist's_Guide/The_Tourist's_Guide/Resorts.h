#include <iostream>
#include <string>
# include "Cuisines.h"
using namespace std;

#ifndef RESORT_H_
#define RESORT_H_
struct Resort
{
	string resort_name;
	string seasons[4];
	double resort_ranking;
	Resort *next_resort;
	Resort *prev_resort;
	Cuisine *menuptr;

public:
	Resort();
	~Resort();
};
#endif