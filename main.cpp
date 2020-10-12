/******************************************************************
** Program Name:	Dungeon
** Author:		Ernest Kim
** Date:		6/4/2019
** Description:		A dungeon crawling game
******************************************************************/
#include "programStart.hpp"
#include "menu.hpp"
#include "sMenu.hpp"
#include "sResponse.hpp"
#include "map.hpp"
#include "player.hpp"
#include "monster.hpp"
#include "prompt.hpp"

#include <cmath>
using std::abs;

enum prompt{
	INTRO = 1,
	NOHEALTH,
	MONSTER,
	KEY,
	SPHINXINTRO,
	SPHINXCHOICE,
	WEAPON,
	DOOR,
	GOAL
};

int main(){
	//Gameloop variable
	bool keepPlaying = true;

	//Randomize seed for die
	unsigned seed;
	seed = time(0);
	srand(seed);

	//Prompt player to begin game
	if(programStart("Dungeon") == false)
		return 0;

	//Create dungeon and initialize everything
	Map dungeon;
	Being * user = new Player(15,2);
	Being * beast = new Monster(7,7);
	dungeon.getSpace(15,2)->setBeing(user);
	dungeon.getSpace(7,7)->setBeing(beast);

	//Introduction and rules
	printPrompt(INTRO);

/**************************************************************************************************************
**************************************************************************************************************/
	//Start game
	while(keepPlaying){
		//Print map
		dungeon.print();

		//Print player stats
		cout	<< "You're health: "
			<< user->getHealth()
			<< endl
			<< "Number of healing items you have: "
			<< user->getItems()
			<< endl;

		//User action options
		switch(menu()){
			//Move up
			case 1:
				//Check if player can occupy space
				if(dungeon.getSpace(user->getXCoor(),user->getYCoor())->getUp() != nullptr){
					//Move player up
					dungeon.getSpace(user->getXCoor(), user->getYCoor())->move(1);
					//Subtract health
					user->subHealth();
					//Move monster in dungeon
					if(beast != nullptr)
						dungeon.getSpace(beast->getXCoor(), beast->getYCoor())->moveMonster();
				}
				//Player can't move there
				else
					cout << "You can't move there, a wall is in the way.\n";
			break;

			//Move down
			case 2:
				//Check if player can occupy space
				if(dungeon.getSpace(user->getXCoor(),user->getYCoor())->getDown() != nullptr){
					//Move player down
					dungeon.getSpace(user->getXCoor(), user->getYCoor())->move(2);
					//Subtract health
					user->subHealth();
					//Move monster in dungeon
					if(beast != nullptr)
						dungeon.getSpace(beast->getXCoor(), beast->getYCoor())->moveMonster();
				}
				//Player can't move there
				else
					cout << "You can't move there, a wall is in the way.\n";
			break;

			//Move left
			case 3:
				//Check if player can occupy space
				if(dungeon.getSpace(user->getXCoor(),user->getYCoor())->getLeft() != nullptr){
					//Move player left
					dungeon.getSpace(user->getXCoor(), user->getYCoor())->move(3);
					//Subtract health
					user->subHealth();
					//Move monster in dungeon
					if(beast != nullptr)
						dungeon.getSpace(beast->getXCoor(), beast->getYCoor())->moveMonster();
				}
				//Player can't move there
				else
					cout << "You can't move there, a wall is in the way.\n";
			break;

			//Move right
			case 4:
				//Check if player can occupy space
				if(dungeon.getSpace(user->getXCoor(),user->getYCoor())->getRight() != nullptr){
					//Move player right
					dungeon.getSpace(user->getXCoor(), user->getYCoor())->move(4);
					//Subtract health
					user->subHealth();
					//Move monster in dungeon
					if(beast != nullptr)
						dungeon.getSpace(beast->getXCoor(), beast->getYCoor())->moveMonster();
				}
				//Player can't move there
				else
					cout << "You can't move there, a wall is in the way.\n";
			break;

			//Use healing item
			case 5:
				//Check if user has healing item
				if(user->getItems() > 0){
					//Use item
					user->useItem();
					cout << "Your health has been restored.\n";
				}
				//Player doesn't have healing item
				else
					cout << "You don't have any healing items.\n";
			break;
		}

/**************************************************************************************************************
**************************************************************************************************************/

		//Player runs out of health and dies
		if(user->getHealth() < 1){
			//Explanation
			printPrompt(NOHEALTH);
			//Turn off game
			keepPlaying = false;
		}

		//Player reaches item
		if((keepPlaying == true) && (dungeon.getSpace(user->getXCoor(), user->getYCoor())->isItem())){
			//Check if space has item
			if(dungeon.getSpace(user->getXCoor(), user->getYCoor())->getHasItem()){
				//Congratulate, add item, and change space to an empty space
				cout	<< "You've obtained a healing item!\n";
				user->addItem();
				dungeon.getSpace(user->getXCoor(), user->getYCoor())->change();
			}

			else
				cout	<< "There are no more items in this space.\n";
		}

		//Player and monster meet up
		if((keepPlaying == true) && (beast != nullptr) &&(abs(user->getXCoor() - beast->getXCoor()) < 2) && (abs(user->getYCoor() - beast->getYCoor()) < 2)){
			//If player has sword
			if(user->getWeapon()){
				//Print map
				dungeon.print();
				//Indicate to player that monster is slain and empty space monster was in
				cout 	<< "You have slayed the beast with your newly acquired legendary weapon!\n";
				dungeon.getSpace(beast->getXCoor(), beast->getYCoor())->setBeing(nullptr);
				//Delete monster
				delete beast;
				beast = nullptr;				
			}

			//If player doesn't have sword
			else{
				//Print map
				dungeon.print();
				//Indicate that player is dead
				printPrompt(MONSTER);
				keepPlaying = false;
			}
		}

		//Player reaches key
		if((keepPlaying == true) && (dungeon.getSpace(user->getXCoor(), user->getYCoor())->isKey())){
			//Player already has key
			if(user->getKey())
				cout 	<< "You already have the key.\n";

			//Player doesn't have key
			else{
				//Indicate player has picked up key, give key to player, change key space to empty space
				printPrompt(KEY);
				user->obtainKey();
				dungeon.getSpace(user->getXCoor(), user->getYCoor())->change();
			}				
		}

		//Player runs into Sphinx
		if((keepPlaying == true) && (user->getBeatSphinx() == false) && (dungeon.getSpace(user->getXCoor(), user->getYCoor())->isSphinx())){
			printPrompt(SPHINXINTRO);

			//Player enters Sphinx quiz loop
			bool sPlaying = true;

			//Sphinx quiz
			while(sPlaying){
				printPrompt(SPHINXCHOICE);
				switch(sMenu()){
					case 1:
						sResponse();
					break;

					case 2:
						sResponse();
					break;

					case 3:
						sResponse();
					break;

					//Correct response
					case 4:
						cout << "Well then, I guess you can proceed now.\n";
						sPlaying = false;
						user->changeSphinx();
					break;

					case 5:
						sResponse();
					break;
				}
			}
		}

		//Player reaches weapon
		if((keepPlaying == true) && (dungeon.getSpace(user->getXCoor(), user->getYCoor())->isWeapon())){
			//Player already has weapon
			if(user->getWeapon())
				cout	<< "You already have the legendary weapon of lore.\n";
	
			//Player obtains weapon
			else{
				printPrompt(WEAPON);
				user->obtainWeapon();
				dungeon.getSpace(user->getXCoor(), user->getYCoor())->change();
			}
		}

		//Player reaches door
		if((keepPlaying == true) && (dungeon.getSpace(user->getXCoor(), user->getYCoor())->isDoor())){
			//Player has key to unlock door
			if(user->getKey()){
				printPrompt(DOOR);
			}

			//Player doesn't have the key
			else{
				cout	<< "You don't have the key to get through this door.\n";
				//Move player back a space away from door
				dungeon.getSpace(user->getXCoor(), user->getYCoor())->move(3);
			}
		}

		//Player reaches goal
		if((keepPlaying == true) && (dungeon.getSpace(user->getXCoor(), user->getYCoor())->isGoal())){
			//Congratulate player and end game
			printPrompt(GOAL);
			keepPlaying = false;
		}
	}
/***************************************************************************************************************
***************************************************************************************************************/


	cout << "Thank you for playing dungeon! Hope you had fun!\n";

	//Free up memory
	delete user;
	user = nullptr;
	if(beast != nullptr)
		delete beast;
	beast = nullptr;

	return 0;
}
