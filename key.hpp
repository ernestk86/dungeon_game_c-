/******************************************************************
** Program Name:	key.hpp
** Author:		Ernest Kim
** Date:		6/4/2019	
** Description:		Key inherited class from Space
******************************************************************/
#include "space.hpp"

#ifndef KEY_HPP
#define KEY_HPP

class Key : public Space{
	private:
		bool hasKey;
	protected:

	public:
		Key() : Space(){
			hasKey = true;
		}

		char display();
		bool isKey();
		void change();
};

#endif
