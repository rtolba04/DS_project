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
	int ASshooting;
	int AMshooting;
	int ADshooting1;
	int ADshooting2;

public:
	void setASshooting(int ASID);
	int getASshooting();
	void setAMshooting(int AMID);
	int getAMshooting();
	void setADshooting1(int ADID);
	int getADshooting1();
	void setADshooting2(int ADID);
	int getADshooting2();
	void attack();
	void addUnit(Unitclass* unit);
	//void removeUnit(Unitclass*& unit1, Unitclass*& unit2);
//void removeUnit(Unitclass*& unit, string type);
	bool AS_remove(Aliensoldiers*& as);
	bool AM_remove(Alienmonsters*& am);
	bool AD_remove(Aliendrones*& ad1, Aliendrones*& ad2);
	void print();
    LinkedQueue<Aliensoldiers*>& getASqueue();
	ArrBag<Alienmonsters*>& getAMarray();
	Derivedqueue<Aliendrones*>& getADqueue();

};

