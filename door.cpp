/******************************************************************
** Program Name:	door.cpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Implementation of Door class
******************************************************************/

#include "door.hpp"

/*****************************************************************
** Description: Function returns character to display on map
*****************************************************************/
char Door::display(){
	return ']';
}

/*****************************************************************
** Description: Function returns true
*****************************************************************/
bool Door::isDoor(){
	return true;
}

void Door::change(){}
