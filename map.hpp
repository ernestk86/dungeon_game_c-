/******************************************************************
** Program Name:	map.hpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Map class
******************************************************************/

#include "empty.hpp"
#include "item.hpp"
#include "key.hpp"
#include "door.hpp"
#include "weapon.hpp"
#include "sphinx.hpp"
#include "goal.hpp"

#include <iostream>

using std::cout;
using std::endl;

#ifndef MAP_HPP
#define MAP_HPP

class Map{
	private:
		Space * dungeon[17][12] = {};
	protected:

	public:
		Map();
		~Map();
		void connectSpace(int, int);
		void print();
		Space * getSpace(int, int);
};

#endif
