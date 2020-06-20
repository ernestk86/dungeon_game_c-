/******************************************************************
** Program Name:	programStart.cpp
** Author:		Ernest Kim
** Date:		4/17/2019
** Description:		Source code for the programStart function.
******************************************************************/

#include "programStart.hpp"

bool programStart(string progName){
	int choice = 0;	

	cout 	<< "Welcome to " << progName << "!\n";
	cout 	<< "Please enter a choice:\n"
		<< "1. Begin\n"
		<< "2. Quit\n";

	while((choice !=1) && (choice !=2)){
		cin >> choice;

		//Check for failed extraction
		if((cin.fail()) || (choice < 1) || (choice > 2)){
			cin.clear(); //Put program back to 'normal' operation mode
			cin.ignore(); //Remove bad input
			cout 	<< "That does not work. Please enter a choice: \n"
				<< "1. Begin\n"
				<< "2. Quit" << endl;
		}
	}
	
	if(choice == 2){
		cout << "Now exiting " << progName << endl;
		return false;
	}
	return true;
}
