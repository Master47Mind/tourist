# include "Cuisines_List.h"
# include "Comestibles_List.h"

Cuisine_List::Cuisine_List()
{
	cuisine_headptr = NULL;
}
void Cuisine_List::editCuisine_node_fields(Cuisine* temp)
{
	int choice;
	string str;
	cout << "What do you want to edit: 1)Category Name, 0)Exit ? " << endl;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter new name: " << endl;
			fflush(stdin);
			getline(cin, str);
			setCuisine_name(str, temp);
			break;
		case 0:
			break;
		default:
			cout << "Invalid directive! " << endl;
		}

		cout << "Anything else to edit or edit again: 1)Category Name, 0)Exit ? " << endl;
		cin >> choice;
	} while (choice != 0);
}
void Cuisine_List::addCuisine_to_all_resorts(string n, Zone** a_zheadptr)
{
	Zone* ztemp = new Zone();
	ztemp = *a_zheadptr;
	Resort* rtemp = new Resort();

	if (ztemp == NULL)
	cout << "Cannot add to non-existent Zones list!" << endl;

	while (ztemp != NULL)
	{
		rtemp = ztemp->resortptr;

		while (rtemp != NULL)
		{
			addCuisine_nodes(n, &rtemp->menuptr);
			rtemp = rtemp->next_resort;
		}
		
		ztemp = ztemp->next_zone;
	}
}
void Cuisine_List::setCuisine_name(string n, Cuisine *ptr)
{
	ptr->category_name = n;
}
string Cuisine_List::getCuisine_name(Cuisine *ptr)
{
	return ptr->category_name;
}
void Cuisine_List::addCuisine_nodes(string n, Cuisine** a_headptr)
{
	cuisine_headptr = *a_headptr;

	if (cuisine_headptr == NULL)
	{
		Cuisine *node = new Cuisine();
		setCuisine_name(n, node);
		cuisine_headptr = node;
	}
	else
	{
		Cuisine *node = new Cuisine();
		setCuisine_name(n, node);
		node->next_cuisine = cuisine_headptr;
		cuisine_headptr->prev_cuisine = node;
		cuisine_headptr = node;
	}
	*a_headptr = cuisine_headptr ;
}
void Cuisine_List::deleteCuisine_nodes(string n, Cuisine** a_headptr, Comestibles_List& list)
{
	Cuisine *temp;
	cuisine_headptr = *a_headptr; //work in terms of this structure memmbers
	temp = cuisine_headptr;
	bool check = false;

	while (temp!=NULL)
	{
		if (n == temp->category_name)
		{
			if (temp == cuisine_headptr)
			{
				cout << "Deleting requested food category!" << endl;
				cuisine_headptr = temp->next_cuisine;
				temp->next_cuisine = NULL;
				if (temp->foodptr!=NULL)
				list.Whole_List_Wiper(&temp->foodptr);
				delete temp;
				check = true;
				break;
			}
			else if (temp->next_cuisine == NULL)
			{
				cout << "Deleting requested food category!" << endl;
				temp->prev_cuisine->next_cuisine = NULL;
				temp->prev_cuisine = NULL;
				list.Whole_List_Wiper(&temp->foodptr);
				delete temp;
				check = true;
				break;
			}
			else
			{
				cout << "Deleting requested food category!" << endl;
				temp->prev_cuisine->next_cuisine = temp->next_cuisine;
				temp->next_cuisine->prev_cuisine = temp->prev_cuisine;
				list.Whole_List_Wiper(&temp->foodptr);
				delete temp;
				check = true;
				break;
			}
		}

		temp = temp->next_cuisine;
	}

	if (check == false && temp == NULL)
	cout << "Could not find this food category!" << endl;

	*a_headptr = cuisine_headptr; //reflect changes in data structure
}
void Cuisine_List::look_upCuisine_nodes(string n, Cuisine* a_headptr)
{
	cuisine_headptr = a_headptr;
	Cuisine *temp;
	temp = cuisine_headptr;
	bool check = false;

	while (temp!=NULL)
	{
		if (n == temp->category_name)
		{
			cout << "Requested food category found!" << endl;
			cout << "Category Type: " << getCuisine_name(temp) << endl;
			check = true;
			break;
		}

		temp = temp->next_cuisine;	
	}

	if (check == false && temp == NULL)
	cout << "Could not find this food category!" << endl;
}
void Cuisine_List::Whole_List_Wiper(Cuisine** a_headptr, Comestibles_List& list) //destroys all nodes in list
{
	cuisine_headptr = *a_headptr;
	Cuisine *del_temp = NULL;
	cout << "Wiping whole food category list of this Resort!" << endl;

	while (cuisine_headptr)
	{
		del_temp = cuisine_headptr;
		cuisine_headptr = del_temp->next_cuisine;
		del_temp->next_cuisine = NULL;
		if (cuisine_headptr != NULL)
		    cuisine_headptr->prev_cuisine = NULL;
		list.Whole_List_Wiper(&del_temp->foodptr);
		delete del_temp;
	}

	*a_headptr = cuisine_headptr;
}
void Cuisine_List::Print_Whole_Menu_Offered(Cuisine* a_headptr, Comestibles_List& list)
{
	cuisine_headptr = a_headptr;
	Cuisine *temp;
	temp = cuisine_headptr;

	if (temp != NULL)
		cout << "Requested food categories offered and items contained are: " << endl;
	else
		cout << "No food categories established yet!" << endl;

	while (temp != NULL)
	{
		cout << "Name: " <<getCuisine_name(temp)<<endl;
		list.Print_Whole_List(temp->foodptr);
		cout << endl;
		temp = temp->next_cuisine;
	}
}
Cuisine* Cuisine_List::Location_Seeker(string n, Cuisine* a_headptr) //finds target node
{
	cuisine_headptr = a_headptr;
	Cuisine *temp;
	temp = cuisine_headptr;

	while (temp!=NULL)
	{
		if (n == temp->category_name)
		{
			return temp;
		}

		temp = temp->next_cuisine;
	}

	if (temp == NULL)
	cout << "No such Cuisine Category!" << endl;
	
	return NULL;
}