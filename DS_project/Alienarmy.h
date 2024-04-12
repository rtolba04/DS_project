#pragma once

#include"Aliensoldiers.h"
#include"Aliendrones.h"
#include"Alienmonsters.h"
#include"LinkedQueue.h"
#include"ArrayStack.h"
#include"priQueue.h"
#include"Unitclass.h"
#include "arr"
class alienArmy
{
private:
	LinkedQueue<Aliensoldiers*>ASqueue;
	<Alienmonsters*>AMarray;
	<Aliendrones*>; ADqueue;
public:
	void attack();
	void addUnit(Unitclass* unit);
	void removeUnit(Unitclass* unit);
	void print();
};

