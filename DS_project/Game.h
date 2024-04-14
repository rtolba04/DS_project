#pragma once
#include "LinkedQueue.h"
#include "randGen.h"
#include "earthArmy.h"
#include "alienArmy.h"
class Game
{private:
	int time;
	randGen random; //randgen obj
	earthArmy Earth;//Earth obj
	alienArmy Alien;//alien obj
	LinkedQueue<Unitclass*>*killed;

	
public:
	Game();
	randGen* getrand();
	earthArmy* getEA();
	alienArmy* getAA();
	bool loadfromfile();
	void kill(Unitclass*);
	void printKill();
};
