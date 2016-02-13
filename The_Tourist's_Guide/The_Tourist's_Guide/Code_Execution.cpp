# include <iostream>
# include <string>
# include <sapi.h>
# include <exception> 
# include<stdlib.h> 
# include <Windows.h>
# include "Comestibles.h"
# include "Comestibles_List.h"
# include "Cuisines.h"
# include "Cuisines_List.h"
# include "Resorts.h"
# include "Resorts_List.h"
# include "Zones.h"
# include "Zones_List.h"
# include <MMSystem.h>
# pragma comment(lib, "winmm.lib")

using namespace std;

bool Credentials_Analyzer(string);
bool InputPassword();
int AdminChoices();
int TouristChoices();
int Text_to_Speech(int);

void main()
{
	Text_to_Speech(1);
	PlaySound(TEXT("Mystical forest_chant.wav"), NULL, SND_FILENAME | SND_ASYNC);
	
	Comestibles_List com_list;
	Cuisine_List cu_list;
	Resort_List res_list;
	Zone_List z_list;
	string str,taste,style,ingre;
	bool x;
	string arr[4];
	double rating;
	Zone* zone_traveller = new Zone();
	Resort* resort_traveller = new Resort();
	Cuisine* cuisine_traveller = new Cuisine();
	Comestibles* comestibles_traveller = new Comestibles();
	char choice ;
	int menuchoice;

	try
	{
		do
		{
		start:
			cout << "If you are an admin, press 'a'; if you are a tourist, press 't'; press 'e' to exit program" << endl;
			fflush(stdin);
			cin >> choice;

			if (choice == 'a')
			{
				if (InputPassword())
				{
					do
					{
							menuchoice = AdminChoices();
							system("CLS");

							switch (menuchoice)
							{
							case 1:
								cout << "Enter name of the Zone: " << endl;
								fflush(stdin);
								getline(cin, str);
								z_list.addZone_nodes(str, &z_list.zone_headptr);

								cout << "Set its Resorts now: 1)Yes! 0)No! ?" << endl;
								cin >> x;
								if (x)
								{
									zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
									cout << endl;
									do
									{
										cout << "Enter name of Resort: " << endl;
										fflush(stdin);
										getline(cin, str);
										cout << "Enter seasons; press just enter in place of a season which is not favorable: " << endl;
										for (int i = 0; i < 4; i++)
										{
											getline(cin, arr[i]);
										}
										cout << "Enter its tourism ranking out of 10: " << endl;
										cin >> rating;
										res_list.addResort_nodes(&zone_traveller->resortptr, str, arr, rating);
										resort_traveller = res_list.Location_Seeker(str, zone_traveller->resortptr);
										cout << endl;
										cout << "Add Cuisine Categories now: 1)Yes! 0)No! ?" << endl;
										cin >> x;
										if (x)
										{
											do
											{
												cout << "Enter name of Category: " << endl;
												fflush(stdin);
												getline(cin, str);
												cu_list.addCuisine_nodes(str, &resort_traveller->menuptr);
												cuisine_traveller = cu_list.Location_Seeker(str, resort_traveller->menuptr);
												cout << endl;
												cout << "Set Cateogory's Eatables now: 1)Yes! 0)No! ?" << endl;
												cin >> x;
												if (x)
												{
													do
													{
														cout << "Enter name of Food Item: " << endl;
														fflush(stdin);
														getline(cin, str);
														cout << "Enter taste of Food Item: " << endl;
														fflush(stdin);
														getline(cin, taste);
														cout << "Enter ingredients of Food Item: " << endl;
														fflush(stdin);
														getline(cin, ingre);
														cout << "Enter style of Food Item: " << endl;
														fflush(stdin);
														getline(cin, style);
														com_list.addComestibles_nodes(str, ingre, taste, style, &cuisine_traveller->foodptr);
														cout << "Add another Comestible in this Category now: 1)Yes! 0)No! ?" << endl;
														cin >> x;
													} while (x);
												}
												cout << "Add another Cuisine category now: 1)Yes! 0)No! ?" << endl;
												cin >> x;
											} while (x);
										}
										cout << "Set more Resorts now: 1)Yes! 0)No! ?" << endl;
										cin >> x;
									} while (x);
								}
								break;
							case 2:
								if (z_list.zone_headptr != NULL)
								{
									cout << "Enter name of Zone to which you want to add a Resort: " << endl;
									fflush(stdin);
									getline(cin, str);
									zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
									cout << endl;

									if (zone_traveller != NULL)
									{
										cout << "Enter name of Resort: " << endl;
										fflush(stdin);
										getline(cin, str);
										cout << "Enter seasons; press just enter in place of a season which is unfavorable: " << endl;
										for (int i = 0; i < 4; i++)
										{
											getline(cin, arr[i]);
										}
										cout << "Enter its tourism ranking out of 10: " << endl;
										cin >> rating;

										res_list.addResort_nodes(&zone_traveller->resortptr, str, arr, rating);
										resort_traveller = res_list.Location_Seeker(str, zone_traveller->resortptr);
										cout << endl;
										cout << "Add Cuisine Categories now: 1)Yes! 0)No! ?" << endl;
										cin >> x;
										if (x)
										{
											do
											{
												cout << "Enter name of Category: " << endl;
												fflush(stdin);
												getline(cin, str);
												cu_list.addCuisine_nodes(str, &resort_traveller->menuptr);
												cout << "Add another Cuisine category now: 1)Yes! 0)No! ?" << endl;
												cin >> x;
											} while (x);
										}
									}
									else
										cout << "Cannot add to a non-existent zone!" << endl;
								}
								else
									cout << "Add the Zones first!" << endl;
								break;
							case 3:
								cout << "Enter name of Zone in which this Resort exists: " << endl;
								fflush(stdin);
								getline(cin, str);
								zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
								cout << endl;

								if (zone_traveller != NULL)
								{
									cout << "Enter name of Resort: " << endl;
									fflush(stdin);
									getline(cin, str);

									if (zone_traveller->resortptr != NULL)
									{
										resort_traveller = res_list.Location_Seeker(str, zone_traveller->resortptr);
										cout << endl;
										if (resort_traveller != NULL)
										{
											do
											{
												cout << "Enter name of Category: " << endl;
												fflush(stdin);
												getline(cin, str);
												cu_list.addCuisine_nodes(str, &resort_traveller->menuptr);
												cout << "Add another Cuisine category now: 1)Yes! 0)No! ?" << endl;
												cin >> x;
											} while (x);
										}
									}
									else
										cout << "No Resorts for this Zone!" << endl;
								}
								break;
							case 4:
								cout << "Enter name of Zone in which Resort exists: " << endl;
								fflush(stdin);
								getline(cin, str);
								zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
								cout << endl;

								if (zone_traveller != NULL)
								{
									cout << "Enter name of Resort: " << endl;
									fflush(stdin);
									getline(cin, str);

									if (zone_traveller->resortptr != NULL)
									{
										resort_traveller = res_list.Location_Seeker(str, zone_traveller->resortptr);
										cout << endl;
										if (resort_traveller != NULL)
										{
											cout << "Enter name of Category to which add Eatables: " << endl;
											fflush(stdin);
											getline(cin, str);

											if (resort_traveller->menuptr != NULL)
											{
												cuisine_traveller = cu_list.Location_Seeker(str, resort_traveller->menuptr);
												cout << endl;
												if (cuisine_traveller != NULL)
												{
													do
													{
														cout << "Enter name of Food Item: " << endl;
														fflush(stdin);
														getline(cin, str);
														cout << "Enter taste of Food Item: " << endl;
														fflush(stdin);
														getline(cin, taste);
														cout << "Enter ingredients of Food Item: " << endl;
														fflush(stdin);
														getline(cin, ingre);
														cout << "Enter style of Food Item: " << endl;
														fflush(stdin);
														getline(cin, style);
														com_list.addComestibles_nodes(str, ingre, taste, style, &cuisine_traveller->foodptr);
														cout << "Add another Comestible in this Category now: 1)Yes! 0)No! ?" << endl;
														cin >> x;
													} while (x);
												}
											}
											else
												cout << "No Food Categories in this Resort yet!" << endl;
										}
									}
									else
										cout << "No Resorts exist for the Zone!" << endl;
								}
								break;
							case 5:
								cout << "Enter name of Category you want to add to all Resorts: " << endl;
								fflush(stdin);
								getline(cin, str);
								zone_traveller = z_list.zone_headptr;
								cu_list.addCuisine_to_all_resorts(str, &zone_traveller);
								break;
							case 6:
								z_list.Print_All_Zones(z_list.zone_headptr);
								break;
							case 7:
								cout << "Enter name of Zone whose Resorts you want to see: " << endl;
								fflush(stdin);
								getline(cin, str);
								zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
								cout << endl;

								if (zone_traveller != NULL)
								{
									if (zone_traveller->resortptr != NULL)
										res_list.Print_All_Resorts_in_Vicinity(zone_traveller->resortptr);
									else
										cout << "No Resorts for this Zone yet!" << endl;
								}
								break;
							case 8:
								cout << "Enter name of Zone in which Resort exists: " << endl;
								fflush(stdin);
								getline(cin, str);
								zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
								cout << endl;
								if (zone_traveller != NULL)
								{
									cout << "Enter name of Resort: " << endl;
									fflush(stdin);
									getline(cin, str);

									if (zone_traveller->resortptr != NULL)
									{
										resort_traveller = res_list.Location_Seeker(str, zone_traveller->resortptr);
										cout << endl;
										if (resort_traveller != NULL)
											cu_list.Print_Whole_Menu_Offered(resort_traveller->menuptr, com_list);
									}
									else
										cout << "No Resorts in this Zone yet!" << endl;
								}
								break;
							case 9:
								cout << "Enter name of Zone you want to edit: " << endl;
								fflush(stdin);
								getline(cin, str);
								zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
								cout << endl;

								if (zone_traveller != NULL)
								{
									z_list.editZone_node_fields(zone_traveller);
								}
								break;
							case 10:
								if (z_list.zone_headptr != NULL)
								{
									cout << "Enter name of Zone in which Resort exists: " << endl;
									fflush(stdin);
									getline(cin, str);
									zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
									cout << endl;

									if (zone_traveller != NULL)
									{
										cout << "Enter name of Resort: " << endl;
										fflush(stdin);
										getline(cin, str);
										resort_traveller = res_list.Location_Seeker(str, zone_traveller->resortptr);
										cout << endl;
										if (resort_traveller != NULL)
											res_list.editResort_node_fields(resort_traveller);
									}
									else
										cout << "Cannot add to a non-existent zone!" << endl;
								}
								else
									cout << "Add the Zones first!" << endl;
								break;
							case 11:
								cout << "Enter name of Zone in which this Resort exists: " << endl;
								fflush(stdin);
								getline(cin, str);
								zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
								cout << endl;
								if (zone_traveller != NULL)
								{
									cout << "Enter name of Resort: " << endl;
									fflush(stdin);
									getline(cin, str);

									if (zone_traveller->resortptr != NULL)
									{
										resort_traveller = res_list.Location_Seeker(str, zone_traveller->resortptr);
										cout << endl;
										if (resort_traveller != NULL)
										{
											if (resort_traveller->menuptr != NULL)
											{
												cout << "Enter name of Cuisine Category you want to edit: " << endl;
												fflush(stdin);
												getline(cin, str);
												cuisine_traveller = cu_list.Location_Seeker(str, resort_traveller->menuptr);
												cout << endl;
												if (cuisine_traveller != NULL)
													cu_list.editCuisine_node_fields(cuisine_traveller);
											}
											else
												cout << "No Food Categories for this Resort yet!" << endl;
										}
									}
									else
										cout << "No Resorts for this Zone!" << endl;
								}
								break;
							case 12:
								cout << "Enter name of Zone in which this Resort exists: " << endl;
								fflush(stdin);
								getline(cin, str);
								zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
								cout << endl;
								if (zone_traveller != NULL)
								{
									cout << "Enter name of Resort: " << endl;
									fflush(stdin);
									getline(cin, str);

									if (zone_traveller->resortptr != NULL)
									{
										resort_traveller = res_list.Location_Seeker(str, zone_traveller->resortptr);
										cout << endl;
										if (resort_traveller != NULL)
										{
											if (resort_traveller->menuptr != NULL)
											{
												cout << "Enter name of Cuisine Category where Eatable is found: " << endl;
												fflush(stdin);
												getline(cin, str);
												cuisine_traveller = cu_list.Location_Seeker(str, resort_traveller->menuptr);
												cout << endl;
												if (cuisine_traveller != NULL)
												{
													if (cuisine_traveller->foodptr != NULL)
													{
														cout << "Enter name of Eatable you want to edit: " << endl;
														fflush(stdin);
														getline(cin, str);
														comestibles_traveller = com_list.Location_Seeker(str, cuisine_traveller->foodptr);
														cout << endl;
														if (comestibles_traveller != NULL)
															com_list.editComestible_node_fields(comestibles_traveller);
													}
													else
														cout << "No Eatables in this Category!" << endl;
												}
											}
											else
												cout << "No Food Categories for this Resort yet!" << endl;
										}
									}
									else
										cout << "No Resorts for this Zone!" << endl;
								}
								break;
							case 13:
								cout << "Enter name of Zone you want to delete: " << endl;
								fflush(stdin);
								getline(cin, str);
								z_list.deleteZone_nodes(str, &z_list.zone_headptr, res_list, cu_list, com_list);
								break;
							case 14:
								cout << "Enter name of Zone in which Resort exists: " << endl;
								fflush(stdin);
								getline(cin, str);
								zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
								cout << endl;
								if (zone_traveller != NULL)
								{
									cout << "Enter name of Resort you want to delete: " << endl;
									fflush(stdin);
									getline(cin, str);
									res_list.deleteResort_nodes(str,&zone_traveller->resortptr,cu_list,com_list);
								}
								break;
							case 15:
								cout << "Enter name of Zone in which Resort exists: " << endl;
								fflush(stdin);
								getline(cin, str);
								zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
								cout << endl;
								if (zone_traveller != NULL)
								{
									cout << "Enter name of Resort whose Food Category is to be deleted: " << endl;
									fflush(stdin);
									getline(cin, str);
									resort_traveller = res_list.Location_Seeker(str, zone_traveller->resortptr);
									cout << endl;
									if (resort_traveller != NULL)
									{
										cout << "Enter name of Food Category to be deleted: " << endl;
										fflush(stdin);
										getline(cin, str);
										cu_list.deleteCuisine_nodes(str, &resort_traveller->menuptr,com_list);
									}
								}
								break;
							case 16:
								cout << "Enter name of Zone in which Resort exists: " << endl;
								fflush(stdin);
								getline(cin, str);
								zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
								cout << endl;
								if (zone_traveller != NULL)
								{
									cout << "Enter name of Resort whose Eatables to be deleted: " << endl;
									fflush(stdin);
									getline(cin, str);
									resort_traveller = res_list.Location_Seeker(str, zone_traveller->resortptr);
									cout << endl;
									if (resort_traveller != NULL)
									{
										cout << "Enter name of Food Category in which Eatable exists: " << endl;
										fflush(stdin);
										getline(cin, str);
										cuisine_traveller = cu_list.Location_Seeker(str, resort_traveller->menuptr);
										cout << endl;
										if (cuisine_traveller != NULL)
										{
											cout << "Enter name of Eatable to delete: " << endl;
											fflush(stdin);
											getline(cin, str);
											com_list.deleteComestible_nodes(str, &cuisine_traveller->foodptr);
										}
									}
								}
								break;
							case 17:
								cout << "Enter name of Zone: " << endl;
								fflush(stdin);
								getline(cin, str);
								z_list.look_upZone_nodes(str, z_list.zone_headptr);
								break;
							case 18:
								cout << "Enter name of Zone in which Resort may exist: " << endl;
								fflush(stdin);
								getline(cin, str);
								zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
								cout << endl;
								if (zone_traveller != NULL)
								{
									cout << "Enter name of Resort to search: " << endl;
									fflush(stdin);
									getline(cin, str);
									res_list.look_upResort_nodes_by_name(str, zone_traveller->resortptr);
								}
								break;
							case 19:
								Text_to_Speech(5);
								cout << "Are you sure you want to wipe server drives? y/n" << endl;
								fflush(stdin);
								cin >> choice;
								if (z_list.zone_headptr != NULL)
								{
									if (choice == 'y')
									{
										Text_to_Speech(3);
										cout << "Server wipes in " << endl;
										for (int sec = 5; sec >= 0; sec--)
										{
											Sleep(1000);
											Beep(900, 500);
											cout << sec << " seconds" << endl;
										}
											Sleep(1000);
									}
                                   z_list.DataStructure_Devastator(&z_list.zone_headptr, res_list, cu_list, com_list);
								   Beep(1200, 1000);
								}
								else
									cout << "Data structure does not exist!" << endl;
								break;
							case 0:
								Text_to_Speech(7);
								break;
							default:
								cout << "Invalid directive!" << endl;
							}			
					} while (menuchoice != 0);
				}
			}

			else if (choice == 't')
			{
				Text_to_Speech(4);
				do
				{
						menuchoice = TouristChoices();
						system("CLS");

						switch (menuchoice)
						{
						case 1:
							cout << "Enter name of Zone: " << endl;
							fflush(stdin);
							getline(cin, str);
							z_list.look_upZone_nodes(str, z_list.zone_headptr);
							zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
							cout << endl;
							if (zone_traveller != NULL)
							{
								cout << "Want to see its Resorts also: 1)Yes! 0)No! ?" << endl;
								cin >> x;
								if (x)
									res_list.Print_All_Resorts_in_Vicinity(zone_traveller->resortptr);
							}
							break;
						case 2:
							z_list.Print_All_Zones(z_list.zone_headptr);
							break;
						case 3:
							cout << "Enter name of Zone in which Resort may exist: " << endl;
							fflush(stdin);
							getline(cin, str);
							zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
							cout << endl;
							if (zone_traveller != NULL)
							{
								cout << "Enter name of Resort to search: " << endl;
								fflush(stdin);
								getline(cin, str);
								res_list.look_upResort_nodes_by_name(str, zone_traveller->resortptr);
								resort_traveller = res_list.Location_Seeker(str, zone_traveller->resortptr);
								cout << endl;
								if (resort_traveller != NULL)
								{
									cout << "Want to see its menu also: 1)Yes! 0)No! ?" << endl;
									cin >> x;
									if (x)
									   cu_list.Print_Whole_Menu_Offered(resort_traveller->menuptr, com_list);	
								}
							}
							break;
						case 4:
							cout << "Enter name of Zone you want to travel to: " << endl;
							fflush(stdin);
							getline(cin, str);
							zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
							cout << endl;
							if (zone_traveller != NULL)
							{
								cout << "Enter season of your holidays: " << endl;
								fflush(stdin);
								getline(cin, str);
								res_list.look_upResort_nodes_by_season(str, zone_traveller->resortptr);
								do
								{
									cout << "Want to see some menus also: 1)Yes! 0)No! ?" << endl;
									cin >> x;
									if (x)
									{
										cout << "Enter name of Resort you want to choose: " << endl;
										fflush(stdin);
										getline(cin, str);
										resort_traveller = res_list.Location_Seeker(str, zone_traveller->resortptr);
										cout << endl;
										if (resort_traveller != NULL)
											cu_list.Print_Whole_Menu_Offered(resort_traveller->menuptr, com_list);
									}
								} while (x);
							}
							break;
						case 5:
							cout << "Enter name of Zone you want to travel to: " << endl;
							fflush(stdin);
							getline(cin, str);
							zone_traveller = z_list.Location_Seeker(str, z_list.zone_headptr);
							cout << endl;
							if (zone_traveller != NULL)
							{
								res_list.sortbyRank(zone_traveller->resortptr);
								res_list.Print_All_Resorts_in_Vicinity(zone_traveller->resortptr);
							}
							break;
						case 0:
							Text_to_Speech(7);
							break;
						default:
							cout << "Invalid directive!" << endl;
						}

				} while (menuchoice != 0);
			}

			else if (choice == 'e')
			{
				Text_to_Speech(6);
				break;
			}

			else
			{
				cout << "Invalid choice!" << endl;
				goto start;
			}

		} while (choice != 'e');
	}
	catch (exception e)
	{
		e.what();
	}
	return;
}

int TouristChoices()
{
	cout << "\nEnter your choice: " << endl
		<< "1- Look up a Zone in database by name" << endl
		<< "2- See all existing Zones in database " << endl
		<< "3- Look up a Resort in database by name " << endl
		<< "4- See recommendations by season of your holidays " << endl
		<< "5- See recommendations of Resorts in descending order of their ratings" << endl
		<< "0- Sign out\n???_";

	int menuChoice;
	cin >> menuChoice; // input menu selection
	return menuChoice;
}
int AdminChoices()
{
	cout << "\nEnter your choice: " << endl
		<< "1- Add a Zone in database " << endl
		<< "2- Add a Resort in a Zone " << endl
		<< "3- Add a Cuisne category in a Resort" << endl
		<< "4- Add a Food Item in a Cuisine Category of any Resort" << endl
		<< "5- Add a Cuisine category to all Resorts" << endl
		<< "6- See all existing Zones in database " << endl
		<< "7- See all existing Resorts in a Zone " << endl
		<< "8- See whole menu offered in a Resort " << endl
		<< "9- Update a Zone in database " << endl
		<< "10- Update a Resort of any Zone " << endl
		<< "11- Update a Cuisine Category offered by a Resort " << endl
		<< "12- Update a Food Item in any Cuisine Category of a Resort " << endl
		<< "13- Delete a Zone in database " << endl
		<< "14- Delete a Resort of any Zone " << endl
		<< "15- Delete a Cuisine Category of any Resort " << endl
		<< "16- Delete a Food Item within Cuisine Category of a Resort " << endl
		<< "17- Look up a Zone in database by name " << endl
		<< "18- Look up a Resort in database by name " << endl
		<< "19- Wipe site server " << endl
		<< "0- Sign out\n???_";

	int menuChoice;
	cin >> menuChoice; // input menu selection 
	return menuChoice;
}
int Text_to_Speech(int what)
{
	ISpVoice * pVoice = NULL;

	if (FAILED(::CoInitialize(NULL)))
		return FALSE;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
	if (SUCCEEDED(hr))
	{
		if (what == 1)
		{
			hr = pVoice->Speak(L"Welcome to the Tourist Guide!", SPF_IS_XML, NULL);
		}
		else if (what == 0)
		{
			hr = pVoice->Speak(L"Access <pitch middle = '-120'/> denied!", SPF_IS_XML, NULL);
		}
		else if (what == 2)
		{
			hr = pVoice->Speak(L"Access granted Wecome Admin!", SPF_IS_XML, NULL);
		}
		else if (what == 3)
		{
			hr = pVoice->Speak(L"<pitch middle = '-200'/> Data destruction <pitch middle = '-100'/> protocol has been initiated!", SPF_IS_XML, NULL);
		}
		else if (what == 4)
		{
			hr = pVoice->Speak(L"Welcome <pitch middle = '-10'/> Tourist!", SPF_IS_XML, NULL);
		}
		else if (what == 5)
		{
			hr = pVoice->Speak(L"<pitch middle = '-100'/>Is this your <pitch middle = '-150'/> final wish Admin!", SPF_IS_XML, NULL);
		}
		else if (what == 6)
		{
			hr = pVoice->Speak(L"Good <pitch middle = '-50'/> Bye!", SPF_IS_XML, NULL);
		}
		else if (what == 7)
		{
			hr = pVoice->Speak(L"<pitch middle = '-100'/>Current User Session <pitch middle = '-150'/> Closure!", SPF_IS_XML, NULL);
		}
		pVoice->Release();
		pVoice = NULL;
	}
	::CoUninitialize();
	return TRUE;
}
bool Credentials_Analyzer(string admin_pass)
{
	bool x = false;
	if (admin_pass == "MasterMind")
	{
		Text_to_Speech(2);
		cout << "Access granted, Welcome Admin!" << endl;
		x = true;
	}

	else 
	{ 
		Text_to_Speech(0);
		cout << "Access denied! You are not recognized as Admin!" << endl; 
	}

	return x;
}
bool InputPassword()
{
	string str = "";
	cout << "\nEnter your password: " << endl;
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));//Hide what is entered
	fflush(stdin);
	getline(cin, str);
	SetConsoleMode(hStdin, mode);//Echo now what is entered 
	 return Credentials_Analyzer(str);
}