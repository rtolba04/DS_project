#pragma once
#include"Earthgunnery.h"
#include"Earthsoldiers.h"
#include"Earthtanks.h"
#include"LinkedQueue.h"
#include"ArrayStack.h"
#include"priQueue.h"
#include"Unitclass.h"
#include"Health.h"



class earthArmy
{private:
	LinkedQueue<Earthsoldiers*>ESqueue;
	ArrayStack<Earthtanks*>ETstack;
	priQueue<Earthgunnery*>EGpriqueue;
public:
	
	void attack();
	void addUnit(Unitclass* unit);
	//void removeUnit(Unitclass*& unit,string type);
	bool ET_remove(Earthtanks*& et);
	bool ES_remove(Earthsoldiers*& es);
	bool EG_remove(Earthgunnery *& eg,int& pri);
	void print();
};

