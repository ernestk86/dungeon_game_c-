/******************************************************************
** Program Name:	space.hpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Space abtract class
******************************************************************/
#include "being.hpp"

#ifndef SPACE_HPP
#define SPACE_HPP

class Space{
	protected:
		Space * up;
		Space * down;
		Space * left;
		Space * right;
		Being * being;

	public:
		Space(){
			up = nullptr;
			down = nullptr;
			left = nullptr;
			right = nullptr;
			being = nullptr;
		}

		virtual ~Space(){};

		Space * getUp();
		void setUp(Space *);
		Space * getDown();
		void setDown(Space *);
		Space * getLeft();
		void setLeft(Space *);
		Space * getRight();
		void setRight(Space *);
		Being * getBeing();
		void setBeing(Being *);

		virtual char display() = 0;
		virtual bool isEmpty();
		virtual bool isItem();
		virtual bool isDoor();
		virtual bool isGoal();
		virtual bool isKey();
		virtual bool isSphinx();
		virtual bool isWeapon();
		virtual void move(int);
		virtual void change() = 0;
		virtual bool getHasItem();
		virtual void moveMonster();
};

#endif
