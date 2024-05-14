#pragma once
#include"Earthgunnery.h"
#include"Earthsoldiers.h"
#include"Earthtanks.h"
#include "ArrBag.h"
#include"LinkedQueue.h"
#include"ArrayStack.h"
#include"priQueue.h"
#include"Unitclass.h"
#include"Health.h"
#include "Derivedqueue.h"
#include "Game.h"





class earthArmy
{private:
	LinkedQueue<Earthsoldiers*>ESqueue;
	ArrayStack<Earthtanks*>ETstack;
	priQueue<Earthgunnery*>EGpriqueue;
	int ESshooting;
	int ETshooting;
	int EGshooting;
	Game* gptr;

public:
	void setESshooting(int ESID);
	int getESshooting();
	void setETshooting(int ETID);
	int getETshooting();
	void setEGshooting(int EGID);
	int getEGshooting();
	void attack();
	void addUnit(Unitclass* unit);
	//void removeUnit(Unitclass*& unit,string type);
	bool ET_remove(Earthtanks*& et);
	bool ES_remove(Earthsoldiers*& es);
	bool EG_remove(Earthgunnery *& eg,int& pri);
	void print();
	LinkedQueue<Earthsoldiers*>& getESqueue();

	ArrayStack<Earthtanks*>& getETstack();

	priQueue<Earthgunnery*>& getEGpriqueue();
	
};

