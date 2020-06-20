/******************************************************************
** Program Name:	sResponse.cpp
** Author:		Ernest Kim
** Date:		6/6/2019
** Description:		Implementation of sResponse function
******************************************************************/

#include "sResponse.hpp"

void sResponse(){
	switch((rand() % 5) +1){
		case 1:
			cout << "Psh! Do you even read?! No. Try again.\n";
		break;

		case 2:
			cout << "You should just give up. Nope. Try again.\n";
		break;

		case 3:
			cout << "Again!\n";
		break;

		case 4:
			cout << "Are you trying? Reread the script. Again.\n";
		break;

		case 5:
			cout << "Wrong. Try again.\n";
		break;
	}
}
