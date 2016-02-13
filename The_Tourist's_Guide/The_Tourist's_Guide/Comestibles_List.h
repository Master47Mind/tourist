# include "Comestibles.h"
# include "Zones.h"

#ifndef COMESTIBLES_LIST_H_
#define COMESTIBLES_LIST_H_
struct Comestibles_List
{
	Comestibles *comestibles_headptr;

	Comestibles_List();
	void setComestible_name(string, Comestibles*);
	void setComestible_taste(string, Comestibles*);
	void setComestible_ingredients(string, Comestibles*);
	void setComestible_style(string, Comestibles*);
	void addComestibles_nodes(string, string, string, string, Comestibles**);
	void editComestible_node_fields(Comestibles*);
	void deleteComestible_nodes(string, Comestibles**);
	void Whole_List_Wiper(Comestibles**);
	void Print_Whole_List(Comestibles*);
	void look_upComestible_nodes(string, Comestibles*);
	string getComestible_name(Comestibles*);
	string getComestible_ingredients(Comestibles*);
	string getComestible_taste(Comestibles*);
	string getComestible_style(Comestibles*);
	Comestibles* Location_Seeker(string, Comestibles*);
	~Comestibles_List();
};

#endif