#include <iostream>
#include <string>
# include "Comestibles.h"
using namespace std;

Comestibles::Comestibles()
{
	 name = "";
	 ingredients = "";
	 taste = "";
	 next_comestible = NULL;
	 prev_comestible = NULL;
}
Comestibles::~Comestibles()
{}

