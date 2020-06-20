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

#include <cmath>
using std::abs;

int main(){
	bool keepPlaying = true;
	unsigned seed;
	seed = time(0);
	srand(seed);

	if(programStart("Dungeon") == false)
		return 0;

	//Create dungeon and initialize everything
	Map dungeon;
	Being * user = new Player(15,2);
	Being * beast = new Monster(7,7);
	dungeon.getSpace(15,2)->setBeing(user);
	dungeon.getSpace(7,7)->setBeing(beast);

	//Explain rules
	cout	<< "Welcome to the Dungeon! You've been placed here as a test to see if you really are\n"
		<< "the true hero this land has been waiting for! The first thing you notice is that the\n"
		<< "atmosphere is heavy here. Very heavy. So heavy in fact that it's a detriment to your\n"
		<< "health. So for every STEP you take you will LOSE ONE HEALTH. But fear not! There are\n"
		<< "HEALING ITEMS scattered throughout this dungeon that will restore 10 of your health!\n"
		<< "HEALING ITEMS look like a + on the map. They're all over this place. Also you have some.\n"
		<< "The goal here is to reach the GOAL and get out of this dungeon! The GOAL is marked\n"
		<< "on the map with $. So you want to make your way over to $. But what's that? there's\n"
		<< "a ] in front of it? Yeah that's a DOOR and it's locked. You'll need the KEY to unlock\n"
		<< "it. The KEY is %. But wait there's a @ patrolling that hallway. Yeah you better steer\n"
		<< "clear of @. That's the MONSTER that guards the key. If you run into him it's game over\n"
		<< "unless... you have the LEGENDARY WEAPON. The LEGENDARY WEAPON W is being guarded by the\n"
		<< "beautiful SPHINX &. Careful though, the SPHINX isn't just there for show, she's guarding\n"
		<< "the LEGENDARY WEAPON. You'll have to meet her and brave the challenge that she presents.\n"
		<< "Well good luck! Your people await you, if you are the true hero.\n"
		<< endl;

/**************************************************************************************************************
**************************************************************************************************************/
	//Start game
	while(keepPlaying){
		dungeon.print();
		cout	<< "You're health: "
			<< user->getHealth()
			<< endl
			<< "Number of healing items you have: "
			<< user->getItems()
			<< endl;

		//User action options
		switch(menu()){
			case 1:
				if(dungeon.getSpace(user->getXCoor(),user->getYCoor())->getUp() != nullptr){
					dungeon.getSpace(user->getXCoor(), user->getYCoor())->move(1);
					user->subHealth();
					if(beast != nullptr)
						dungeon.getSpace(beast->getXCoor(), beast->getYCoor())->moveMonster();
				}

				else
					cout << "You can't move there, a wall is in the way.\n";
			break;

			case 2:
				if(dungeon.getSpace(user->getXCoor(),user->getYCoor())->getDown() != nullptr){
					dungeon.getSpace(user->getXCoor(), user->getYCoor())->move(2);
					user->subHealth();
					if(beast != nullptr)
						dungeon.getSpace(beast->getXCoor(), beast->getYCoor())->moveMonster();
				}

				else
					cout << "You can't move there, a wall is in the way.\n";
			break;

			case 3:
				if(dungeon.getSpace(user->getXCoor(),user->getYCoor())->getLeft() != nullptr){
					dungeon.getSpace(user->getXCoor(), user->getYCoor())->move(3);
					user->subHealth();
					if(beast != nullptr)
						dungeon.getSpace(beast->getXCoor(), beast->getYCoor())->moveMonster();
				}

				else
					cout << "You can't move there, a wall is in the way.\n";
			break;

			case 4:
				if(dungeon.getSpace(user->getXCoor(),user->getYCoor())->getRight() != nullptr){
					dungeon.getSpace(user->getXCoor(), user->getYCoor())->move(4);
					user->subHealth();
					if(beast != nullptr)
						dungeon.getSpace(beast->getXCoor(), beast->getYCoor())->moveMonster();
				}

				else
					cout << "You can't move there, a wall is in the way.\n";
			break;

			case 5:
				if(user->getItems() > 0){
					user->useItem();
					cout << "Your health has been restored.\n";
				}

				else
					cout << "You don't have any healing items.\n";
			break;
		}

/**************************************************************************************************************
**************************************************************************************************************/

		//Player runs out of health
		if(user->getHealth() < 1){
			cout	<< "Oh no the deadly atmosphere in the dungeon got to you!\n"
				<< "You have died in the dungeon.\n";
			keepPlaying = false;
		}

		//Player reaches item
		if((keepPlaying == true) && (dungeon.getSpace(user->getXCoor(), user->getYCoor())->isItem())){
			if(dungeon.getSpace(user->getXCoor(), user->getYCoor())->getHasItem()){
				cout	<< "You've obtained a healing item!\n";
				user->addItem();
				dungeon.getSpace(user->getXCoor(), user->getYCoor())->change();
			}

			else
				cout	<< "There are no more items in this space.\n";
		}

		//Player and monster meet up
		if((keepPlaying == true) && (beast != nullptr) &&(abs(user->getXCoor() - beast->getXCoor()) < 2) && (abs(user->getYCoor() - beast->getYCoor()) < 2)){
			if(user->getWeapon()){
				dungeon.print();
				cout 	<< "You have slayed the beast with your newly acquired legendary weapon!\n";
				dungeon.getSpace(beast->getXCoor(), beast->getYCoor())->setBeing(nullptr);
				delete beast;
				beast = nullptr;				
			}

			else{
				dungeon.print();
				cout	<< "You have been attacked by the beast. Where is your weapon?!\n"
					<< "You have died, you are now dead.\n";
				keepPlaying = false;
			}
		}

		//Player reaches key
		if((keepPlaying == true) && (dungeon.getSpace(user->getXCoor(), user->getYCoor())->isKey())){
			if(user->getKey())
				cout 	<< "You already have the key.\n";

			else{
				cout	<< "You have obtained the key!\n"
					<< "Now you can unlock the door and get out of here!\n";
				user->obtainKey();
				dungeon.getSpace(user->getXCoor(), user->getYCoor())->change();
			}				
		}

		//Player runs into Sphinx
		if((keepPlaying == true) && (user->getBeatSphinx() == false) && (dungeon.getSpace(user->getXCoor(), user->getYCoor())->isSphinx())){
			cout	<< "You look to see that there is a Sphinx guarding the legendary\n"
				<< "weapon needed to slay the monster of the dungeon. 'Yes it is just\n"
				<< "as you think, I am a Sphinx' As fearsome as they can be, this Sphinx\n"
				<< "possesses a rare beauty that radiates from her body. 'Now I know why\n"
				<< "you are here. You need to escape this dungeon to prove to the people\n"
				<< "that you are their long awaited savior. And to do that you need this key\n"
				<< "that I happen to be guarding. Well as a Sphinx, like the rest of my kind\n"
				<< "I have a riddle for you. If you can answer it correctly then I will let\n"
				<< "you through to the key. However answer it wrong, and you'll see a nasty\n"
				<< "side to me that you'll wish you hadn't.\n\n";

		bool sPlaying = true;

			while(sPlaying){
				cout	<< "Come next year I will be on my way to graduating from this program to\n"
					<< "Seize the moment that I get hired by a decent tech company with these qualities\n"
					<< "1. The company must have a healthy work culture...\n"
					<< "6. The company have co-workers that I like and would want to hang out with\n"
					<< "2. I will get started on opening my own Indie Game Developement Studio\n";
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
			if(user->getWeapon())
				cout	<< "You already have the legendary weapon of lore.\n";
	
			else{
				cout	<< "You have obtained the legendary weapon of lore!\n"
					<< "Now you can slay the monster guarding the key!\n";
				user->obtainWeapon();
				dungeon.getSpace(user->getXCoor(), user->getYCoor())->change();
			}
		}

		//Player reaches door
		if((keepPlaying == true) && (dungeon.getSpace(user->getXCoor(), user->getYCoor())->isDoor())){
			if(user->getKey()){
				cout 	<< "You insert the key... and click! The door's now\n"
					<< "unlocked! Let's get out of this dungeon!\n";
			}

			else{
				cout	<< "You don't have the key to get through this door.\n";
				dungeon.getSpace(user->getXCoor(), user->getYCoor())->move(3);
			}
		}

		//Player reaches goal
		if((keepPlaying == true) && (dungeon.getSpace(user->getXCoor(), user->getYCoor())->isGoal())){
			cout 	<< "Congratulations! You've survived and made it out of the dungeon!\n"
				<< "You are winner!\n";
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
