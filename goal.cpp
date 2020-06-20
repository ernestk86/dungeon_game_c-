/******************************************************************
** Program Name:	goal.cpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Implementation of Goal class
******************************************************************/

#include "goal.hpp"

/*****************************************************************
** Description: Function returns character to display on map
*****************************************************************/
char Goal::display(){
	return '$';
}

/*****************************************************************
** Description: Function returns true
*****************************************************************/
bool Goal::isGoal(){
	return true;
}

void Goal::change(){}
