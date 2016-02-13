# include "Cuisines.h"
# include "Comestibles_List.h"

#ifndef CUISINE_LIST_H_
#define CUISINE_LIST_H_
struct Cuisine_List
{
	Cuisine *cuisine_headptr;

	Cuisine_List();
	void addCuisine_to_all_resorts(string, Zone**);
	void editCuisine_node_fields(Cuisine*);
	void setCuisine_name(string,Cuisine*);
	string getCuisine_name(Cuisine*);
	void addCuisine_nodes(string, Cuisine**);
	void deleteCuisine_nodes(string, Cuisine**, Comestibles_List&);
	void look_upCuisine_nodes(string, Cuisine*);
	void Whole_List_Wiper(Cuisine**, Comestibles_List&);
	void Print_Whole_Menu_Offered(Cuisine*, Comestibles_List&);
	Cuisine* Location_Seeker(string, Cuisine*);
};
# endif