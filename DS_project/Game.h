#pragma once
#include "LinkedQueue.h"
#include "randGen.h"
#include "earthArmy.h"
#include "alienArmy.h"
class Game
{private:
	randGen random; //randgen obj
	earthArmy Earth;//Earth obj
	alienArmy Alien;//alien obj

	//
public:
	randGen* getrand();
	earthArmy* getEA();
	alienArmy* getAA();
	bool loadfromfile();

};

.6++