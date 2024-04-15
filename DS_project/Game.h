#pragma once
#include "LinkedQueue.h"
#include"Unitclass.h"
#include "randGen.h"
#include "earthArmy.h"
#include "alienArmy.h"
class Game
{private:
	int time;
	randGen randomgen; //randgen obj
	earthArmy Earth;//Earth obj
	alienArmy Alien;//alien obj

	
	
public:
	Game();
	randGen* getrand();
	earthArmy* getEA();
	alienArmy* getAA();
	bool loadfromfile();
	void kill(Unitclass* unit);
	void printKill();
	void test();
	~Game();
};

