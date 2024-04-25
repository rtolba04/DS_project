#pragma once

#include"Aliensoldiers.h"
#include"Aliendrones.h"
#include"Alienmonsters.h"
#include"LinkedQueue.h"
#include"ArrayStack.h"
#include"priQueue.h"
#include"Unitclass.h"
#include "ArrBag.h"
#include "Derivedqueue.h"
class alienArmy
{
private:
	LinkedQueue<Aliensoldiers*>ASqueue;
	ArrBag<Alienmonsters*>AMarray;
	Derivedqueue<Aliendrones*> ADqueue;
public:
	void attack();
	void addUnit(Unitclass* unit);
	//void removeUnit(Unitclass*& unit1, Unitclass*& unit2);
//void removeUnit(Unitclass*& unit, string type);
	bool AS_remove(Aliensoldiers*& as);
	bool AM_remove(Alienmonsters*& am);
	bool AD_remove(Aliendrones*& ad1, Aliendrones*& ad2);
	void print();
};

