/******************************************************************
** Program Name:	item.hpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Item inherited class from Space
******************************************************************/
#include "space.hpp"

#ifndef ITEM_HPP
#define ITEM_HPP

class Item : public Space{
	private:
		bool hasItem;
	protected:

	public:
		Item() : Space(){
			hasItem = true;
		}

		char display();
		bool isItem();
		void change();
		bool getHasItem();
};

#endif
