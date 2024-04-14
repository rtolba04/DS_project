#pragma once
#include "LinkedQueue.h"
#include "randGen.h"
#include "earthArmy.h"
#include "Alienarmy.h"
class Game
{private:
	randGen randgen_obj;
	earthArmy EA_obj;
	Alienarmy AA_obj;

	
	
public:
	randGen* getrand();
	earthArmy* getEA();
	Alienarmy* getAA();
};

