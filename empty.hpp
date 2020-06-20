/******************************************************************
** Program Name:	empty.hpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Empty inherited class from Space
******************************************************************/

#include "space.hpp"

#ifndef EMPTY_HPP
#define EMPTY_HPP

class Empty : public Space{
	private:

	public:
		Empty() : Space(){

		}

		char display();
		bool isEmpty();
		void change();
};

#endif
