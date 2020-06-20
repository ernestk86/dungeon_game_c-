/******************************************************************
** Program Name:	weapon.cpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Implementation of Weapon class
******************************************************************/

#include "weapon.hpp"

/*****************************************************************
** Description: Function returns character to display on map
*****************************************************************/
char Weapon::display(){
	if(hasWeapon)
		return 'W';
	else
		return ' ';
}

/*****************************************************************
** Description: Function returns true
*****************************************************************/
bool Weapon::isWeapon(){
	return true;
}

/*****************************************************************
** Description: Function returns true
*****************************************************************/
void Weapon::change(){
	hasWeapon = false;
}
