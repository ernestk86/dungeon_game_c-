/******************************************************************
** Program Name:	goal.hpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Goal inherited class from Space
******************************************************************/
#include "space.hpp"

#ifndef GOAL_HPP
#define GOAL_HPP

class Goal : public Space{
	private:

	protected:

	public:
		Goal() : Space(){

		}

		char display();
		bool isGoal();
		void change();
};

#endif
