/******************************************************************
** Program Name:	item.cpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Implementation of Item class
******************************************************************/

#include "item.hpp"

/*****************************************************************
** Description: Function returns character to display on map
*****************************************************************/
char Item::display(){
	if(hasItem)
		return '+';
	else
		return ' ';
}

/*****************************************************************
** Description: Function returns true
*****************************************************************/
bool Item::isItem(){
	return true;
}

/*****************************************************************
** Description: Function changes hasItem to false
*****************************************************************/
void Item::change(){
	hasItem = false;
}

/*****************************************************************
** Description: Function returns value of hasItem
*****************************************************************/
bool Item::getHasItem(){
	return hasItem;
}

