#pragma once
#include "LinkedQueue.h"
#include"Unitclass.h"
#include "randGen.h"
#include "earthArmy.h"
#include "alienArmy.h"
class Game
{
protected:
	int time; 
	string status;
	randGen randomgen; //randgen obj
	earthArmy Earth;//Earth obj
	alienArmy Alien;//alien obj
	LinkedQueue<Unitclass*>* killed;
	ArrayStack<Health*>HLstack;
	priQueue<Earthsoldiers*>UMLsoldiers;
	LinkedQueue<Earthtanks*>UMLtanks;


public:
	Game();
	randGen* getrand();
	earthArmy* getEA();
	alienArmy* getAA();
	int getTime();
	bool loadfromfile();
	void savetofile(const string& filename);
	void addHeal(Health* h);
	void removeHeal(Health* &hu);
	void addUMLtank(Earthtanks* et);
	void addUMLsold(Earthsoldiers* es, int pri);
	void removeUMLsold(Earthsoldiers* &es, int& pri);
	void removeUMLtank(Earthtanks*& et);
	void printUMLtank();
	bool checkUMLsold();
	bool checkUMLtank();
	Earthsoldiers* UMLsoldHead();
	Earthtanks* UMLtankHead();
	void PrintKilledList();
	void kill(Unitclass* unit);
	void printscreen();
	ArrayStack<Health*>& getHLstack();
	
	void simulate();
	//void testnew();
	~Game();
};

