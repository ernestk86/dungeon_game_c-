/******************************************************************
** Program Name:	sMenu.cpp
** Author:		Ernest Kim
** Date:		6/6/2019
** Description:		Source code for implementation of questions
**			for menu.
******************************************************************/

#include "sMenu.hpp"

/*****************************************************************
** Description:	Function presents a menu for the user
*****************************************************************/
int sMenu(){
	int choice = 0;

	cout 	<< "So:" << endl
		<< "1. String cheese and potatos?" << endl
		<< "2. Polymorphism" << endl
		<< "3. Rick and Morty" << endl
		<< "4. CS162" << endl
		<< "5. Pencil Vester" << endl;

	while((choice < 1) || (choice > 5)){
		cin >> choice;

		if((cin.fail()) || (choice < 1) || (choice > 5)){
			cin.clear();
			cin.ignore();
			cout << "That doesn't work. Please choose an integer from 1-5:" << endl;
		}
	}

	return choice;
}
