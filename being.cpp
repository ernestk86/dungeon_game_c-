/******************************************************************
** Program Name:	being.cpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Implementation of Being class
******************************************************************/

#include "being.hpp"

/*****************************************************************
** Description: Function gives being the key to the door
*****************************************************************/
void Being::obtainKey(){
	key = true;
}

/*****************************************************************
** Description: Function returns value of key
*****************************************************************/
bool Being::getKey(){
	return key;
}

/*****************************************************************
** Description: Function gives being the weapon to kill monster
*****************************************************************/
void Being::obtainWeapon(){
	weapon = true;
}

/*****************************************************************
** Description: Function returns value of weapon
*****************************************************************/
bool Being::getWeapon(){
	return weapon;
}

/*****************************************************************
** Description: Function changes value of beatSphinx
*****************************************************************/
void Being::changeSphinx(){
	beatSphinx = true;
}

/*****************************************************************
** Description: Function returns value of beatSphinx
*****************************************************************/
bool Being::getBeatSphinx(){
	return beatSphinx;
}

/*****************************************************************
** Description: Function returns how many healing items player has
*****************************************************************/
int Being::getItems(){
	return items;
}

/*****************************************************************
** Description: Function adds a healing item to player's inventory
*****************************************************************/
void Being::addItem(){
	items++;
}

/*****************************************************************
** Description: Function uses healing item
*****************************************************************/
void Being::useItem(){
	if(items > 0){
		items--;
		health += 10;
	}

	else{
		cout << "You don't have any healing items!\n";
	}
}

/*****************************************************************
** Description: Function subtracts health from player
*****************************************************************/
void Being::subHealth(){
	health--;
}	

/*****************************************************************
** Description: Function sets player's health to zero
*****************************************************************/
void Being::zeroHealth(){
	health = 0;;
}
	
/*****************************************************************
** Description: Function returns health
*****************************************************************/
int Being::getHealth(){
	return health;
}

/*****************************************************************
** Description: Getters for the x/y coordinates
*****************************************************************/
int Being::getXCoor(){
	return xCoor;
}

int Being::getYCoor(){
	return yCoor;
}

/*****************************************************************
** Description: Functions increment/decrement the x/y coordinates
*****************************************************************/
void Being::addXCoor(){
	xCoor++;
}

void Being::subXCoor(){
	xCoor--;
}

void Being::addYCoor(){
	yCoor++;
}

void Being::subYCoor(){
	yCoor--;
}

/*****************************************************************
** Description: Getter/setter for being's direction
*****************************************************************/
void Being::changeDirect(int d){
	direct = d;
}

int Being::getDirect(){
	return direct;
}
