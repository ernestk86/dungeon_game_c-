/******************************************************************
** Program Name:	sphinx.hpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Sphinx inherited class from Space
******************************************************************/
#include "space.hpp"

#ifndef SPHINX_HPP
#define SPHINX_HPP

class Sphinx : public Space{
	private:

	protected:

	public:
		Sphinx() : Space(){

		}

		char display();
		bool isSphinx();
		void change();
};

#endif
