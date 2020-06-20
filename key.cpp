/******************************************************************
** Program Name:	key.cpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Implementation of Key class
******************************************************************/

#include "key.hpp"

/*****************************************************************
** Description: Function returns character to display on map
*****************************************************************/
char Key::display(){
	if(hasKey)
		return '%';
	else
		return ' ';
}

/*****************************************************************
** Description: Function returns true
*****************************************************************/
bool Key::isKey(){
	return true;
}

/*****************************************************************
** Description: Function changes space to no longer have key
*****************************************************************/
void Key::change(){
	hasKey = false;
}
