# include "Zones_List.h"
# include "Zones.h"
# include "Resorts_List.h"
# include "Comestibles_List.h"

Zone_List::Zone_List()
{
	zone_headptr = NULL;
}
void Zone_List::addZone_nodes(string n, Zone** a_headptr) //always add at head to reduce complexity of insertion due to traversal
{
	zone_headptr = *a_headptr;

	if (zone_headptr == NULL)
	{
		Zone *node = new Zone();
		setZone_name(n, node);
		zone_headptr = node;
	}
	else
	{
		Zone *node = new Zone();
		setZone_name(n, node);
		node->next_zone = zone_headptr;
		zone_headptr->prev_zone = node;
		zone_headptr = node;
	}
	*a_headptr = zone_headptr;
}
void Zone_List::look_upZone_nodes(string n, Zone* a_headptr)
{
	zone_headptr = a_headptr;
	Zone *temp;
	bool check = false;
	temp = zone_headptr;

	while (temp!=NULL)
	{
		if (n == temp->zone_name)
		{
			cout << "Requested Zone detected!" << endl;
			cout << "Name: " << getZone_name(temp)<< endl;
			check = true;
			break;
		}
		temp = temp->next_zone;
	}

	if (check == false && temp == NULL)
		cout << "Could not find this Zone!" << endl;
}
void Zone_List::deleteZone_nodes(string n, Zone** a_headptr, Resort_List& list, Cuisine_List& cu_list, Comestibles_List& com_list)
{
	Zone *temp;
	zone_headptr = *a_headptr; // work in terms of class members
	temp = zone_headptr;
	bool check = false;

	while (temp!=NULL)
	{
		if (n == temp->zone_name)
		{
			if (temp == zone_headptr)
			{
				check = true;
				cout << "Deleting requested Zone! "<< endl;
				zone_headptr = temp->next_zone;
				temp->next_zone = NULL;
				list.Whole_List_Wiper(&temp->resortptr,cu_list, com_list);
				delete temp;
				break;
			}
			else if (temp->next_zone == NULL)
			{
				check = true;
				cout << "Deleting requested Zone!" << endl;
				temp->prev_zone->next_zone = NULL;
				temp->prev_zone = NULL;
				list.Whole_List_Wiper(&temp->resortptr, cu_list, com_list);
				delete temp;
				break;
			}
			else
			{
				check = true;
				cout << "Deleting requested Zone!" << endl;
				temp->prev_zone->next_zone = temp->next_zone;
				temp->next_zone->prev_zone = temp->prev_zone;
				list.Whole_List_Wiper(&temp->resortptr, cu_list, com_list);
				delete temp;
				break;
			}
		}
		temp = temp->next_zone;
	}

	if ( temp == NULL && check == false)
	cout << "Could not find this Zone!" << endl;
	
	*a_headptr = zone_headptr; // reflect changes
}
void Zone_List::setZone_name(string n, Zone* ptr)
{
	ptr->zone_name = n;
}
string Zone_List::getZone_name(Zone* ptr)
{
	return ptr->zone_name;
}
Zone_List::~Zone_List()
{}
void Zone_List::DataStructure_Devastator(Zone** a_headptr, Resort_List& list, Cuisine_List& cu_list, Comestibles_List& com_list) //free all memory occupied
{
	Zone *del_temp;
	cout << "Wiping all Zones!" << endl;
	zone_headptr = *a_headptr;
	del_temp = zone_headptr;

	while (zone_headptr)
	{
		del_temp = zone_headptr;
		zone_headptr = del_temp->next_zone;
		del_temp->next_zone = NULL;
		if (zone_headptr != NULL)
			zone_headptr->prev_zone = NULL;
		list.Whole_List_Wiper(&del_temp->resortptr, cu_list, com_list);
		delete del_temp;
	}

	*a_headptr = zone_headptr;
}
void Zone_List::Print_All_Zones(Zone* a_headptr)
{
	zone_headptr = a_headptr;
	Zone *temp;
	temp = zone_headptr;

	if (temp != NULL)
		cout << "Requested Zones are: " << endl;
	else
		cout << "No Zones established for tourism yet!" << endl;

	while (temp != NULL)
	{
		cout << "Name: " << getZone_name(temp) << endl;
		cout << endl;
		temp = temp->next_zone;
	}
}
Zone* Zone_List::Location_Seeker(string n, Zone* a_headptr) //finds target node
{
	zone_headptr = a_headptr;
	Zone *temp;
	temp = zone_headptr;

	while (temp!=NULL)
	{
		if (n == temp->zone_name)
		{
			return temp;
		}
		temp = temp->next_zone;
	}

	if (temp == NULL)
	cout << "No such Zone!" << endl;
	
	return NULL;
}
void Zone_List::editZone_node_fields(Zone* ptr)
{
	int choice;
	string str;
	cout << "1)Edit Name, 0)Exit ? " << endl;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter new name: " << endl;
			fflush(stdin);
			getline(cin, str);
			setZone_name(str, ptr);
			break;
		case 0:
			break;
		default:
			cout << "Invalid directive! " << endl;
		}

		cout << "Anything else to edit or edit again: 1)Name, 0)Exit ? " << endl;
		cin >> choice;
	} while (choice != 0);
}