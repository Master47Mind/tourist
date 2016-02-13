#include "Cuisines.h"

Cuisine::Cuisine()
{
	category_name = "";
	next_cuisine = NULL;
	prev_cuisine = NULL;
	foodptr = NULL;
}
Cuisine::~Cuisine()
{}
