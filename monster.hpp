/******************************************************************
** Program Name:	monster.hpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Monster inherited class from Being
******************************************************************/
#include "being.hpp"

#ifndef MONSTER_HPP
#define MONSTER_HPP

class Monster : public Being{
	private:

	protected:

	public:
		Monster(int x, int y) : Being(){
			xCoor = x;
			yCoor = y;
			direct = 4;
		}

		bool isPlayer();
		bool isMonster();
};

#endif
