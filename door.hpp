/******************************************************************
** Program Name:	door.hpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Door inherited class from Space
******************************************************************/
#include "space.hpp"

#ifndef DOOR_HPP
#define DOOR_HPP

class Door : public Space{
	private:

	protected:

	public:
		Door() : Space(){

		}

		char display();
		bool isDoor();
		void change();
};

#endif
