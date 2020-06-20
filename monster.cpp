/******************************************************************
** Program Name:	monster.cpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Implementation of Monster class
******************************************************************/

#include "monster.hpp"

/*****************************************************************
** Description: Function returns false
*****************************************************************/
bool Monster::isPlayer(){
	return false;
}

/*****************************************************************
** Description: Function returns true
*****************************************************************/
bool Monster::isMonster(){
	return true;
}
