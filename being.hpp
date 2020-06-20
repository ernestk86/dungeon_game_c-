/******************************************************************
** Program Name:	being.hpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Being parent class for units in game
******************************************************************/
#include <iostream>

using std::cout;
using std::endl;

#ifndef BEING_HPP
#define BEING_HPP

class Being{
	protected:
		int health;
		int items;
		bool key;
		bool weapon;
		bool beatSphinx;
		int xCoor;
		int yCoor;
		int direct;

	public:
		Being(){
			health = 30;
			items = 4;
			key = false;
			weapon = false;
			beatSphinx = false;
		}

		virtual ~Being(){

		}

		virtual bool isPlayer() = 0;
		virtual bool isMonster() = 0;
		virtual void obtainKey();
		virtual bool getKey();
		virtual void obtainWeapon();
		virtual bool getWeapon();
		virtual void changeSphinx();
		virtual bool getBeatSphinx();
		virtual int getItems();
		virtual void addItem();
		virtual void useItem();
		virtual void subHealth();
		virtual void zeroHealth();
		virtual int getHealth();
		virtual int getXCoor();
		virtual int getYCoor();
		virtual void addXCoor();
		virtual void subXCoor();
		virtual void addYCoor();
		virtual void subYCoor();
		virtual void changeDirect(int);
		virtual int getDirect();
};

#endif
