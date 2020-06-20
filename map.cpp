/******************************************************************
** Program Name:	map.cpp
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		Implementation of Map class
******************************************************************/

#include "map.hpp"

/*****************************************************************
** Description: Default constructor
*****************************************************************/
Map::Map(){
	//Default the grid to point to all nullptr
	for(int row = 0; row < 17; row++){
		for(int col = 0; col < 12; col++){
			dungeon[row][col] = nullptr;
		}
	}

	//Assign pointers to spaces
	//Columns first
	for(int row = 1; row < 16; row++){
		dungeon[row][2] = new Empty;
	}

	for(int row = 9; row < 14; row++){
		dungeon[row][9] = new Empty;
	}

	for(int row = 4; row < 8; row++){
		dungeon[row][5] = new Empty;
	}

	for(int row = 4; row < 7; row++){
		dungeon[row][9] = new Empty;
	}

	//Rows Next
	for(int col = 3; col < 6; col++){
		dungeon[1][col] = new Empty;
	}

	for(int col = 3; col < 9; col++){
		dungeon[9][col] = new Empty;
	}

	for(int col = 5; col < 10; col++){
		dungeon[3][col] = new Empty;
	}
	
	for(int col = 6; col < 10; col++){
		dungeon[7][col] = new Empty;
	}

	dungeon[8][7] = new Empty;

	//Special spaces
	dungeon[5][1] = new Item;
	dungeon[12][3] = new Item;
	dungeon[1][6] = new Door;
	dungeon[1][7] = new Goal;
	dungeon[4][7] = new Key;
	dungeon[14][9] = new Sphinx;
	dungeon[14][8] = new Weapon;

	//Connect spaces
	for(int row = 0; row < 17; row++){
		for(int col = 0; col < 12; col++){
			connectSpace(row, col);
		}
	}
}

/*****************************************************************
** Description: Function connects spaces on the map
*****************************************************************/
void Map::connectSpace(int row, int col){
	if(dungeon[row][col] != nullptr){
		if(dungeon[row - 1][col] != nullptr){
			dungeon[row][col]->setUp(dungeon[row - 1][col]);
		}

		if(dungeon[row + 1][col] != nullptr){
			dungeon[row][col]->setDown(dungeon[row + 1][col]);
		}
	
		if(dungeon[row][col - 1] != nullptr){
			dungeon[row][col]->setLeft(dungeon[row][col - 1]);
		}

		if(dungeon[row][col + 1] != nullptr){
			dungeon[row][col]->setRight(dungeon[row][col + 1]);
		}
	}
}

/*****************************************************************
** Description: Destructor
*****************************************************************/
Map::~Map(){
	//Columns first
	for(int row = 1; row < 16; row++){
		delete dungeon[row][2];
	}

	for(int row = 9; row < 14; row++){
		delete dungeon[row][9];
	}

	for(int row = 4; row < 8; row++){
		delete dungeon[row][5];
	}

	for(int row = 4; row < 7; row++){
		delete dungeon[row][9];
	}

	//Rows Next
	for(int col = 3; col < 6; col++){
		delete dungeon[1][col];
	}

	for(int col = 3; col < 9; col++){
		delete dungeon[9][col];
	}

	for(int col = 5; col < 10; col++){
		delete dungeon[3][col];
	}
	
	for(int col = 6; col < 10; col++){
		delete dungeon[7][col];
	}

	delete dungeon[8][7];

	//Special spaces
	delete dungeon[5][1];
	delete dungeon[12][3];
	delete dungeon[1][6];
	delete dungeon[1][7];
	delete dungeon[4][7];
	delete dungeon[14][9];
	delete dungeon[14][8];

	//Set 2d array to nullptr
	for(int row = 0; row < 17; row++){
		for(int col = 0; col < 12; col++){
			dungeon[row][col] = nullptr;
		}
	}
}

/*****************************************************************
** Description: Function prints map to screen
*****************************************************************/
void Map::print(){
	cout 	<< "-----Map Key------\n"
		<< "Player : O\n"
		<< "Monster : @\n"
		<< "Healing Item : +\n"
		<< "Goal : $\n"
		<< "Door : ]\n"
		<< "Key: : %\n"
		<< "Weapon : W\n"
		<< "Sphinx : &\n";

	for(int row = 0; row < 17; row++){
		for(int col = 0; col < 12; col++){
			if(dungeon[row][col] == nullptr)
				cout << '#';

			else if(dungeon[row][col]->getBeing() != nullptr){
				if((dungeon[row][col]->getBeing())->isPlayer())
					cout << "O";

				if((dungeon[row][col]->getBeing())->isMonster())
					cout << "@";
			}
				
			else
				cout << dungeon[row][col]->display();
		}
		cout << endl;
	}
}

/*****************************************************************
** Description: Function returns pointer to space
*****************************************************************/
Space * Map::getSpace(int row, int col){
	return dungeon[row][col];
}
