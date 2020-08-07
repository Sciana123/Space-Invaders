#pragma once
#include "Game_Actor.h"

/**
* Lasers coming down from ennemies
* child of Game_Actor class
*/
class Monster_Lasers :public Game_Actor {
public:
	Monster_Lasers(int x, int y); // constructor
	void restart(int x, int y);  // revive a laser
	void move();
};