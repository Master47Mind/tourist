#include "Resorts.h"

# ifndef ZONES_H_
# define ZONES_H_
struct Zone
{
	string zone_name;
	Zone *prev_zone;
	Zone *next_zone;
	Resort *resortptr;

	Zone();
	~Zone();
};
#endif