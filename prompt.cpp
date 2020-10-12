/******************************************************************
** Program Name:	prompt.cpp
** Author:		    Ernest Kim
** Date:		    10/12/2020
******************************************************************/

#include "prompt.hpp"

/*****************************************************************
** Description: Function returns character to display on map
*****************************************************************/
void printPrompt(int prompt){
    switch (prompt) {
        case 1:
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
        break;

        case 2:
        cout	<< "Oh no the deadly atmosphere in the dungeon got to you!\n"
			<< "You have died in the dungeon.\n";
        break;

        case 3:
        cout	<< "You have been attacked by the beast. Where is your weapon?!\n"
			<< "You have died, you are now dead.\n";
        break;

        case 4:
        cout	<< "You have obtained the key!\n"
			<< "Now you can unlock the door and get out of here!\n";
        break;

        case 5:
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
        break;

        case 6:
        cout	<< "Come next year I will be on my way to graduating from this program to\n"
			<< "Seize the moment that I get hired by a decent tech company with these qualities\n"
			<< "1. The company must have a healthy work culture...\n"
			<< "6. The company have co-workers that I like and would want to hang out with\n"
			<< "2. I will get started on opening my own Indie Game Developement Studio\n";
        break;

        case 7:
        cout	<< "You have obtained the legendary weapon of lore!\n"
			<< "Now you can slay the monster guarding the key!\n";
        break;

        case 8:
        cout 	<< "You insert the key... and click! The door's now\n"
			<< "unlocked! Let's get out of this dungeon!\n";
        break;

        case 9:
        cout 	<< "Congratulations! You've survived and made it out of the dungeon!\n"
			<< "You are winner!\n";
        break;
    }
}