/******************************************************************
** Program Name:	space.cpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Implementation of Space class
******************************************************************/

#include "space.hpp"

/*****************************************************************
** Description: Function returns pointer to space above
*****************************************************************/
Space * Space::getUp(){
	return up;
}

/*****************************************************************
** Description: Function sets pointer to space above
*****************************************************************/
void Space::setUp(Space * up){
	this->up = up;
}

/*****************************************************************
** Description: Function returns pointer to space below
*****************************************************************/
Space * Space::getDown(){
	return down;
}

/*****************************************************************
** Description: Function sets pointer to space below
*****************************************************************/
void Space::setDown(Space * down){
	this->down = down;
}

/*****************************************************************
** Description: Function returns pointer to space to left
*****************************************************************/
Space * Space::getLeft(){
	return left;
}

/*****************************************************************
** Description: Function sets pointer to space to left
*****************************************************************/
void Space::setLeft(Space * left){
	this->left = left;
}

/*****************************************************************
** Description: Function returns pointer to space to right
*****************************************************************/
Space * Space::getRight(){
	return right;
}

/*****************************************************************
** Description: Function sets pointer to space to right
*****************************************************************/
void Space::setRight(Space * right){
	this->right = right;
}

/*****************************************************************
** Description: Function returns pointer to being
*****************************************************************/
Being * Space::getBeing(){
	return being;
}

/*****************************************************************
** Description: Function sets pointer to being
*****************************************************************/
void Space::setBeing(Being * value){
	being = value;
}

/*****************************************************************
** Description: Function returns false
*****************************************************************/
bool Space::isEmpty(){
	return false;
}

/*****************************************************************
** Description: Function returns false
*****************************************************************/
bool Space::isItem(){
	return false;
}

/*****************************************************************
** Description: Function returns false
*****************************************************************/
bool Space::isDoor(){
	return false;
}

/*****************************************************************
** Description: Function returns false
*****************************************************************/
bool Space::isGoal(){
	return false;
}

/*****************************************************************
** Description: Function returns false
*****************************************************************/
bool Space::isKey(){
	return false;
}

/*****************************************************************
** Description: Function returns false
*****************************************************************/
bool Space::isSphinx(){
	return false;
}

/*****************************************************************
** Description: Function returns false
*****************************************************************/
bool Space::isWeapon(){
	return false;
}

/*****************************************************************
** Description: Function moves being
*****************************************************************/
void Space::move(int direct){
	if((direct == 1) && (getUp() != nullptr)){
		(this->being)->subXCoor();
		getUp()->setBeing(this->being);
		setBeing(nullptr);
	}

	if((direct == 2) && (getDown() != nullptr)){
		(this->being)->addXCoor();
		getDown()->setBeing(this->being);
		setBeing(nullptr);
	}

	if((direct == 3) && (getLeft() != nullptr)){
		(this->being)->subYCoor();
		getLeft()->setBeing(this->being);
		setBeing(nullptr);
	}

	if((direct == 4) && (getRight() != nullptr)){
		(this->being)->addYCoor();
		getRight()->setBeing(this->being);
		setBeing(nullptr);
	}
}

/*****************************************************************
** Description: Function returns true
*****************************************************************/
bool Space::getHasItem(){
	return true;
}

/*****************************************************************
** Description: Function moves monster
*****************************************************************/
void Space::moveMonster(){
	if(((this->being)->getDirect() == 1) && (getUp() != nullptr))
		move(1);

	else if(((this->being)->getDirect() == 2) && (getDown() != nullptr))
		move(2);

	else if(((this->being)->getDirect() == 3) && (getLeft() != nullptr))
		move(3);

	else if(((this->being)->getDirect() == 4) && (getRight() != nullptr))
		move(4);

	else if((getDown() != nullptr) && (getLeft() != nullptr)){
		(this->being)->changeDirect(3);
		move(3);
	}

	else if((getDown() != nullptr) && (getRight() != nullptr)){
		(this->being)->changeDirect(2);
		move(2);
	}

	else if((getUp() != nullptr) && (getRight() != nullptr)){
		(this->being)->changeDirect(4);
		move(4);
	}

	else if((getUp() != nullptr) && (getLeft() != nullptr)){
		(this->being)->changeDirect(1);
		move(1);
	}
}
