#include <iostream>
#include <string>
# include "Comestibles_List.h"

using namespace std;

Comestibles_List::Comestibles_List()
{
	comestibles_headptr = NULL;
}
void Comestibles_List::setComestible_name(string n, Comestibles *ptr)
{
	ptr->name = n;
}
void Comestibles_List::setComestible_taste(string t, Comestibles *ptr)
{
	ptr->taste = t;
}
void Comestibles_List::setComestible_ingredients(string i, Comestibles *ptr)
{
	ptr->ingredients = i;
}
void Comestibles_List::setComestible_style(string s, Comestibles *ptr)
{
	ptr->style = s;
}
void Comestibles_List::addComestibles_nodes(string n, string i, string t, string s, Comestibles** a_headptr) //always adds at head to reduce complexity for insertion due to traversals
{
	comestibles_headptr = *a_headptr;
	if (comestibles_headptr == NULL)
	{
		Comestibles *node = new Comestibles();
		setComestible_name(n, node);
		setComestible_ingredients(i, node);
		setComestible_style(s, node);
		setComestible_taste(t, node);
		comestibles_headptr = node;
	}
	else
	{
		Comestibles *node = new Comestibles();
		setComestible_name(n, node);
		setComestible_ingredients(i, node);
		setComestible_style(s, node);
		setComestible_taste(t, node);
		node->next_comestible = comestibles_headptr;
		comestibles_headptr->prev_comestible = node;
		comestibles_headptr = node;
	}
	*a_headptr = comestibles_headptr;
}
void Comestibles_List::editComestible_node_fields(Comestibles* temp)
{
	int choice;
	string str;
	cout << "What do you want to edit: 1)Name, 2)Ingredients, 3)Style, 4)Taste, 0)Exit ? " << endl;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1: 
			cout << "Enter new name: " << endl;
			fflush(stdin);
			getline(cin, str);
			setComestible_name(str, temp);
			break;
		case 2:
			cout << "Enter new ingredients: " << endl;
			fflush(stdin);
			getline(cin, str);
			setComestible_ingredients(str, temp);
			break;
		case 3:
			cout << "Enter new style: " << endl;
			fflush(stdin);
			getline(cin, str);
			setComestible_style(str,temp);
			break;
		case 4:
			cout << "Enter new taste: " << endl;
			fflush(stdin);
			getline(cin, str);
			setComestible_taste(str, temp);
			break;
		case 0:
			break;
		default: 
			cout << "Invalid directive! " << endl;
		}

		cout << "Anything else to edit or edit again: 1)Name, 2)Ingredients, 3)Style, 4)Taste, 0)Exit ? " << endl;
		cin >> choice;
	} while (choice != 0);
}
string Comestibles_List::getComestible_name(Comestibles *ptr)
{
	return ptr->name;
}
string Comestibles_List::getComestible_taste(Comestibles *ptr)
{
	return ptr->taste;
}
string Comestibles_List::getComestible_ingredients(Comestibles *ptr)
{
	return ptr->ingredients;
}
string Comestibles_List::getComestible_style(Comestibles *ptr)
{
	return ptr->style;
}
void Comestibles_List::deleteComestible_nodes(string n, Comestibles** a_headptr)
{
	comestibles_headptr = *a_headptr; //work in terms of this structore's members
	Comestibles *temp;
	temp = comestibles_headptr;
	bool check = false;

	while (temp!=NULL)
	{
		if (n == temp->name)
		{
			if (temp == comestibles_headptr)
			{
				cout << "Deleting requested food item!" << endl;
				comestibles_headptr = temp->next_comestible;
				temp->next_comestible = NULL;
				delete temp;
				check = true;
				break;
			}
			else if (temp ->next_comestible == NULL)
			{
				cout << "Deleting requested food item!" << endl;
				temp->prev_comestible->next_comestible = NULL;
				temp->prev_comestible = NULL;
				delete temp;
				check = true;
				break;
			}
			else
			{
				cout << "Deleting requested food item!" << endl;
				temp->prev_comestible->next_comestible = temp->next_comestible;
				temp->next_comestible->prev_comestible = temp->prev_comestible;
				delete temp;
				check = true;
				break;
			}
		}
	
		temp = temp->next_comestible;
	}

	if (check == false && temp == NULL)
	{
		cout << "Could not find this food item!" << endl;
	}

	*a_headptr = comestibles_headptr; //reflect changes in data structure made in main()
}
void Comestibles_List::look_upComestible_nodes(string n, Comestibles* a_headptr)
{
	comestibles_headptr = a_headptr;
	Comestibles *temp;
	temp = comestibles_headptr;
	bool check = false;

	while (temp!=NULL)
	{
		if (n == temp->name)
		{
			cout << "Requested Food Item found!" << endl;
			cout << "Name: " << getComestible_name(temp) << "\nTaste: " << temp->taste << "\nIngredients: " << getComestible_ingredients(temp) << "\nStyle: " << getComestible_style(temp) << endl;
			check = true;
			break;
		}
		
		temp = temp->next_comestible;	
	}

	if (temp == NULL)
	cout << "Could not find this food item!" << endl;
}
void Comestibles_List::Whole_List_Wiper(Comestibles** a_headptr) //destroys whole list
{
	comestibles_headptr = *a_headptr;
	Comestibles *del_temp;
	cout << "Wiping whole food items' list in this category!" << endl;

	while (comestibles_headptr)
	{
		del_temp = comestibles_headptr;
		comestibles_headptr = del_temp->next_comestible;
		if (comestibles_headptr!=NULL)
		   comestibles_headptr->prev_comestible = NULL;
		del_temp->next_comestible = NULL;
		delete del_temp;
	}

	*a_headptr = comestibles_headptr;
}
void Comestibles_List::Print_Whole_List(Comestibles* a_headptr)
{
	comestibles_headptr = a_headptr;
	Comestibles *temp;
	temp = comestibles_headptr;

	if (temp!=NULL)
	cout << "Requested food items in this category are: " << endl;
	else 
		cout << "No food items in this category yet!" << endl;

	while (temp!=NULL)
	{
		cout << "Name: " << getComestible_name(temp) << "\nTaste: " << temp->taste << "\nIngredients: " << getComestible_ingredients(temp) << "\nStyle: " << getComestible_style(temp) << endl;
		cout << endl;
		temp = temp->next_comestible;
	}
}
Comestibles_List::~Comestibles_List()
{}
Comestibles* Comestibles_List::Location_Seeker(string n, Comestibles* a_headptr) // finds target node
{
	comestibles_headptr = a_headptr;
	Comestibles* temp;
	temp = comestibles_headptr;
	bool check = false;

	while (temp!=NULL)
	{
		if (n == temp->name)
		{
			return temp;
		}
		
		temp = temp->next_comestible;
	}

	if (temp == NULL)
	cout << "No such Eatable!" << endl;

	return NULL;
}