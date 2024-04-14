#include "Game.h"
#include "Aliensoldiers.h"
#include "Alienmonsters.h"
#include "LinkedQueue.h"
#include "ArrBag.h"
#include "Derivedqueue.h"
#include "ArrayStack.h"
#include "Aliendrones.h"
#include "alienArmy.h"
#include "priQueue.h"

int main()
{
	alienArmy a1;
	Aliensoldiers* as1 = new Aliensoldiers(5, 2, 3, 4, 5);
	Aliensoldiers* as2 = new Aliensoldiers(1, 4, 6, 1, 6);
	Alienmonsters* am1 = new Alienmonsters(3, 2, 3, 4, 5);
	Alienmonsters* am2 = new Alienmonsters(4, 2, 3, 4, 5);
	Aliendrones* ad1 = new Aliendrones(5, 2, 3, 4, 5);
	Aliendrones* ad2 = new Aliendrones(6, 2, 7, 2, 5);
	Aliensoldiers* as3 = new Aliensoldiers(1, 4, 6, 1, 6);
	Aliensoldiers* as4 = new Aliensoldiers(1, 4, 6, 1, 6);
	Aliensoldiers* as5 = new Aliensoldiers(1, 4, 6, 1, 6);
	a1.addUnit(as1);
	a1.addUnit(as2);
	a1.addUnit(as3);
	a1.addUnit(as4);
	a1.addUnit(as3);
	a1.addUnit(am1);
	a1.addUnit(am2);
	a1.addUnit(ad1);
	a1.addUnit(ad2);
	a1.print();

}