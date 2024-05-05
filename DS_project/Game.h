#pragma once
#include "LinkedQueue.h"
#include"Unitclass.h"
#include "randGen.h"
#include "earthArmy.h"
#include "alienArmy.h"
class Game
{
private:
	int time;
	randGen randomgen; //randgen obj
	earthArmy Earth;//Earth obj
	alienArmy Alien;//alien obj
	LinkedQueue<Unitclass*>* killed;
	ArrayStack<Health*>HLstack;
	


public:
	Game();
	LinkedQueue<Earthtanks*>UMLtanks; 
	priQueue<Earthsoldiers*>UMLsoldiers;
	randGen* getrand();
	earthArmy* getEA();
	alienArmy* getAA();
	int getTime();
	bool loadfromfile();
	void PrintKilledList();

	void kill(Unitclass* unit);

	void test();
	//void testnew();
	~Game();
};

