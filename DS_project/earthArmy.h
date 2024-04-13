#pragma once
#include"Earthgunnery.h"
#include"Earthsoldiers.h"
#include"Earthtanks.h"
#include"LinkedQueue.h"
#include"ArrayStack.h"
#include"priQueue.h"
#include"Unitclass.h"



class earthArmy
{private:
	LinkedQueue<Earthsoldiers*>ESqueue;
	ArrayStack<Earthtanks*>ETstack;
	priQueue<Earthgunnery*>EGpriqueue;
public:
	void attack();
	void addUnit(Unitclass* unit);
	void removeUnit(Unitclass* unit);
	void print();
};

