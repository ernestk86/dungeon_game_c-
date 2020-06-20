/******************************************************************
** Program Name:	weapon.hpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Weapon inherited class from Space
******************************************************************/
#include "space.hpp"

#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon : public Space{
	private:
		bool hasWeapon;
	protected:

	public:
		Weapon() : Space(){
			hasWeapon = true;
		}

		char display();
		bool isWeapon();
		void change();
};

#endif
