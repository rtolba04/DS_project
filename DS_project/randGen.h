#pragma once
#include "Game.h"
#include "Unitclass.h"
class randGen
{
private:
	int pwr;
	int health;
	int attackcap;
	Game* game_ptr;

public:
	void setpwr(int p);
	void sethealth(int h);
	void setattack(int ac);
	Unitclass* createunit();

};

