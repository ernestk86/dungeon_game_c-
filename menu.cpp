/******************************************************************
** Program Name:	menu.cpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Source code for implementation of questions
**			for menu.
******************************************************************/

#include "menu.hpp"

/*****************************************************************
** Description:	Function presents a menu for the user
*****************************************************************/
int menu(){
	int choice = 0;

	cout 	<< "What would you like to do?" << endl
		<< "1. Move up" << endl
		<< "2. Move down" << endl
		<< "3. Move left" << endl
		<< "4. Move right" << endl
		<< "5. Use healing item" << endl;

	while((choice < 1) || (choice > 5)){
		cin >> choice;

		if((cin.fail()) || (choice < 1) || (choice > 5)){
			cin.clear();
			cin.ignore();
			cout 	<< "That doesn't work. Please choose an integer from 1-5:" << endl
				<< "1. Move up" << endl
				<< "2. Move down" << endl
				<< "3. Move left" << endl
				<< "4. Move right" << endl
				<< "5. Use healing item" << endl;
		}
	}

	return choice;
}
