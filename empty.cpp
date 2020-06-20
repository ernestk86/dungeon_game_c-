/******************************************************************
** Program Name:	empty.cpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Implementation of empty class
******************************************************************/

#include "empty.hpp"

/*****************************************************************
** Description: Function returns character to display on map
*****************************************************************/
char Empty::display(){
	return ' ';
}

/*****************************************************************
** Description: Function returns true
*****************************************************************/
bool Empty::isEmpty(){
	return true;
}

void Empty::change(){}
