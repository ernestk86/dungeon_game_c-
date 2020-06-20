/******************************************************************
** Program Name:	player.hpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Player inherited class from Being
******************************************************************/
#include "being.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player : public Being{
	private:

	protected:

	public:
		Player(int x, int y) : Being(){
			xCoor = x;
			yCoor = y;
		}

		bool isPlayer();
		bool isMonster();
};

#endif
