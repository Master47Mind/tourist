# include "Zones.h"
# include "Resorts_List.h"

# ifndef ZONES_LIST_H_
# define ZONES_LIST_H_
struct Zone_List
{
	Zone *zone_headptr;

	Zone_List();
	void editZone_node_fields(Zone*);
	void addZone_nodes(string,Zone**);
	void look_upZone_nodes(string, Zone*);
	Zone* Location_Seeker(string, Zone*);
	void deleteZone_nodes(string, Zone**, Resort_List&, Cuisine_List&, Comestibles_List&);
	void setZone_name(string, Zone*);
	string getZone_name(Zone*);
	void Print_All_Zones(Zone*);
	void DataStructure_Devastator(Zone**,Resort_List&, Cuisine_List&, Comestibles_List&);
	~Zone_List();
};
#endif