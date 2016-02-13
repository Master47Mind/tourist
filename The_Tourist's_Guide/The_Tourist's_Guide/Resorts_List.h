# include "Resorts.h"
# include "Comestibles_List.h"
# include "Cuisines_List.h"

#ifndef RESORT_LIST_H_
#define RESORT_LIST_H_
struct Resort_List
{
	Resort *resort_headptr;

	Resort_List();
	int getNode_Count(Resort*);
	void sortbyRank(Resort*);
	void addResort_nodes(Resort**, string, string*, double);
	void editResort_node_fields(Resort*);
	void deleteResort_nodes(string,Resort**, Cuisine_List&, Comestibles_List&);
	void look_upResort_nodes_by_name(string,Resort*);
	void look_upResort_nodes_by_season(string, Resort*);
	void setResort_name(string, Resort*);
	void setResort_ranking(double, Resort*);
	void setResort_seasons(string*,Resort*);
	string getResort_name(Resort*);
	double getResort_ranking(Resort*);
	string* getResort_seasons(Resort*);
	void Print_All_Resorts_in_Vicinity(Resort*);
	void Whole_List_Wiper(Resort**,Cuisine_List&, Comestibles_List&);
	Resort* Location_Seeker(string, Resort*);
	~Resort_List();
};
#endif