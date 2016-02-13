#include "Zones.h"

Zone::Zone()
{
	zone_name = "";
	next_zone = NULL;
	prev_zone = NULL;
	resortptr = NULL;
}
Zone::~Zone()
{}
