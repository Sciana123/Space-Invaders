#pragma once
#include "Game_Actor.h"
class Monsters:public Game_Actor
{
public:
	Monsters();
	void move();

private:
	bool direction; // true= move toward the right, false = move toward the left
};

