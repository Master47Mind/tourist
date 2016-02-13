# include "Resorts_List.h"
# include "Cuisines_List.h"

int Resort_List::getNode_Count(Resort* a_headptr)
{
	Resort* temp;
	temp = a_headptr;
	int count = 0;

	while (temp != NULL)
	{
		count++;
		temp = temp->next_resort;
	}
	return count;
}
void Resort_List::sortbyRank(Resort* a_headptr)
{
	//Linked List variant of Shell Sort
	int i, flag = 1, listLength = getNode_Count(a_headptr), d = listLength;
	while (flag || (d >= 1))
	{
		flag = 0;
		if (d == 1) 
			d = 0;
		d = (d + 1) / 2;
		for (i = 0; i < (listLength - d); i++)
		{
			int temp = 0;
			Resort *temp2 = resort_headptr, *temp1;
		
				while (temp < i)
				{
					temp2 = temp2->next_resort;
					temp++;
				}
				temp1 = temp2;
				temp = 0;

				while (temp < d)
				{
					temp1 = temp1->next_resort;
					temp++;
				}
			
			if (temp1 != NULL && temp2 != NULL)
			{
				if (temp1->resort_ranking > temp2->resort_ranking)
				{
					Resort swappertemp, *next, *prev;
					swappertemp = *temp1;           //copies next and prev too
					next = temp1->next_resort;
					prev = temp1->prev_resort;
					*temp1 = *temp2;
					temp1->next_resort = next;
					temp1->prev_resort = prev;
					next = temp2->next_resort;
					prev = temp2->prev_resort;
					*temp2 = swappertemp;
					temp2->prev_resort = prev;
					temp2->next_resort = next;
					flag = 1;
				}
			}
		}
	}
	return;
}
void Resort_List::setResort_name(string name, Resort *ptr)
{
	ptr->resort_name = name;
}
void Resort_List::setResort_ranking(double rank,Resort *ptr)
{
	ptr->resort_ranking = rank;
}
void Resort_List::addResort_nodes(Resort** a_headptr, string name_of_resort,string *season_ptr, double ranking)
{
	resort_headptr = *a_headptr;

	if (resort_headptr == NULL)
	{
		Resort *node = new Resort();
		setResort_name(name_of_resort, node);
		setResort_seasons(season_ptr, node);
		setResort_ranking(ranking, node);
		resort_headptr = node;
	}
	else
	{
		Resort *node = new Resort();
		setResort_name(name_of_resort, node);
		setResort_seasons(season_ptr, node);
		setResort_ranking(ranking, node);
		node->next_resort = resort_headptr;
		resort_headptr->prev_resort = node;
		resort_headptr = node;
	}
	*a_headptr = resort_headptr;
}
Resort_List::Resort_List()
{
	resort_headptr = NULL;
}
void Resort_List::deleteResort_nodes(string n,Resort** a_headptr, Cuisine_List& cu_list, Comestibles_List& com_list)
{
	Resort *temp;
	bool check = false;
	resort_headptr = *a_headptr; //work in terms of functionality structure members
	temp = resort_headptr;

	while (temp!=NULL)
	{
		if (n == temp->resort_name)
		{
			if (temp == resort_headptr)
			{
				cout << "Deleting requested Resort!" << endl;
				resort_headptr = temp->next_resort;
				temp->next_resort = NULL;
				cu_list.Whole_List_Wiper(&temp->menuptr, com_list);
				delete temp;
				check = true;
				break;
			}
			else if (temp->next_resort == NULL)
			{
				cout << "Deleting requested Resort!" << endl;
				temp->prev_resort->next_resort = NULL;
				temp->prev_resort = NULL;
				cu_list.Whole_List_Wiper(&temp->menuptr, com_list);
				delete temp;
				check = true;
				break;
			}
			else
			{
				cout << "Deleting requested Resort!" << endl;
				temp->prev_resort->next_resort = temp->next_resort;
				temp->next_resort->prev_resort = temp->prev_resort;
				cu_list.Whole_List_Wiper(&temp->menuptr, com_list);
				delete temp;
				check = true;
				break;
			}
		}
		temp = temp->next_resort;
	}

	if (check == false && temp == NULL)
	cout << "Could not find this Resort!" << endl;
	
	*a_headptr = resort_headptr; //reflect changes in original with help of double pointer received from main()
}
void Resort_List::look_upResort_nodes_by_name(string n,Resort* a_headptr)
{
	resort_headptr = a_headptr;
	Resort *temp;
	bool check = false;
	string *str_ptr;
	temp = resort_headptr;
	while (temp!=NULL)
	{
		if (n == temp->resort_name)
		{
			check = true;
			cout << "Requested Resort in this vicinity detected!" << endl;
			cout << "Name: " << getResort_name(temp) << "\nTourism stature out of 10: " << getResort_ranking(temp) << endl;
			cout << "Holiday terrific seasons: ";
			str_ptr = getResort_seasons(temp);
			for (int i = 0; i < 4; i++)
				cout << str_ptr[i] << " ";

			cout << endl;
			break;
		}
		
		temp = temp->next_resort;
	}

	if (temp == NULL && check == false)
	cout << "Could not find this Resort!" << endl;
	
}
void Resort_List::look_upResort_nodes_by_season(string s, Resort* a_headptr)
{
	resort_headptr = a_headptr;
	Resort *temp;
	string *str_ptr;
	bool check = false;
	temp = resort_headptr;

	while (temp!=NULL)
	{
		str_ptr = getResort_seasons(temp);
		for (int i = 0; i < 4; i++)
		{
			if (s == str_ptr[i])
			{
				cout << "Requested Resorts in this vicinity detected!" << endl;
				cout << "Name: " << getResort_name(temp) << "\nTourism stature out of 10: " << getResort_ranking(temp) << endl;
				cout << endl;
				check = true;
				break;
			}
		}
		
		temp = temp->next_resort;
	}

	if (temp == NULL && check == false)
	cout << "Could not find such Resort!" << endl;
}
void Resort_List::setResort_seasons(string* sptr, Resort* ptr)
{
	for (int i = 0; i < 4; i++)
	ptr->seasons[i] = sptr[i];
}
string* Resort_List::getResort_seasons(Resort* ptr)
{
	return ptr->seasons;
}
string Resort_List::getResort_name(Resort* ptr)
{
	return ptr->resort_name;
}
double Resort_List::getResort_ranking(Resort* ptr)
{
	return ptr->resort_ranking;
}
void Resort_List::Print_All_Resorts_in_Vicinity(Resort* a_headptr)
{
	resort_headptr = a_headptr;
	Resort *temp;
	string *str_ptr;
	temp = resort_headptr;

	if (temp != NULL)
		cout << "Requested Resorts in this vicinity are: " << endl;
	else
		cout << "No Resorts established here yet!" << endl;

	while (temp != NULL)
	{
		cout << "Name: " << getResort_name(temp) << endl;
		cout << "Holiday terrific seasons: ";
		str_ptr = getResort_seasons(temp);
		for (int i = 0; i < 4; i++)
			cout << str_ptr[i] << " ";

		cout << endl;
		cout << "Tourism stature out of 10: " << getResort_ranking(temp) << endl;
		cout << endl;
		temp = temp->next_resort;
	}
}
void Resort_List::Whole_List_Wiper(Resort** a_headptr, Cuisine_List& list, Comestibles_List& com_list) //free all nodes' memory occupied
{
	resort_headptr = *a_headptr;
	Resort *del_temp = NULL;
	cout << "Wiping all Resorts of this Zone!" << endl;

	while (resort_headptr)
	{
		del_temp = resort_headptr;
		resort_headptr = del_temp->next_resort;
		del_temp->next_resort = NULL;
		if (resort_headptr != NULL)
			resort_headptr->prev_resort = NULL;
		list.Whole_List_Wiper(&del_temp->menuptr, com_list);
		delete del_temp;
	}

	*a_headptr = resort_headptr;
}
Resort_List::~Resort_List()
{}
Resort* Resort_List::Location_Seeker(string n, Resort* a_headptr)
{
	resort_headptr = a_headptr;
	Resort *temp;
	temp = resort_headptr;

	while (temp!=NULL)
	{
		if (n == temp->resort_name)
		{
			return temp;
		}
		temp = temp->next_resort;
	}

	if (temp == NULL)
	cout << "No such Resort!" << endl;

	return NULL;
}
void Resort_List::editResort_node_fields(Resort* temp)
{
	int choice;
	string str;
	string arr[4];
	double rating;

	cout << "What do you want to edit: 1)Name, 2)Season, 3)Ranking, 0)Exit ? " << endl;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter new name of Resort: " << endl;
			fflush(stdin);
			getline(cin, str);
			setResort_name(str, temp);
			break;
		case 2:
			cout << "Enter new seasons; press just enter in place of a season which is unfavorable: " << endl;
			for (int i = 0; i < 4; i++)
			{
				getline(cin, arr[i]);
			}
			setResort_seasons(arr, temp);
			break;
		case 3:
			cout << "Enter new tourism ranking out of 10: " << endl;
			cin >> rating;
			setResort_ranking(rating, temp);
			break;
		case 0:
			break;
		default:
			cout << "Invalid directive! " << endl;
		}

		cout << "Anything else to edit or edit again: 1)Name, 2)Seasons, 3)Rating, 0)Exit ? " << endl;
		cin >> choice;
	} while (choice != 0);
}