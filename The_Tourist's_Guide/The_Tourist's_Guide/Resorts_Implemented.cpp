#include "Resorts.h"

Resort::Resort()
{
	resort_name = "";
	resort_ranking = 0.0;
	for (int i = 0; i < 4; i++)
	{
		seasons[i] =  "";
	}
	next_resort = NULL;
	prev_resort = NULL;
	menuptr = NULL;
}
Resort::~Resort()
{}

