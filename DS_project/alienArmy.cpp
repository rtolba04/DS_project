#include "alienArmy.h"
#include "Unitclass.h"
#include "Alienmonsters.h"
#include "Aliensoldiers.h"
#include "Aliendrones.h"
using namespace std;







void alienArmy::attack()
{}

void alienArmy::addUnit(Unitclass* unit)
{
	if (unit->Gettype() == "AM")
	{
		Alienmonsters* typePtr = dynamic_cast<Alienmonsters*>(unit);
		AMarray.add(typePtr);
	}
	if (unit->Gettype() == "AS")
	{
		Aliensoldiers* typePtr = dynamic_cast<Aliensoldiers*>(unit);
		ASqueue.enqueue(typePtr);
	}
	if (unit->Gettype() == "ED")
	{
		Aliendrones* typePtr = dynamic_cast<Aliendrones*>(unit);
		ADqueue.enqueue(typePtr);
	}
}

void alienArmy::removeUnit(Unitclass* unit)
{
	if (unit->Gettype() == "AS")
	{
		Aliensoldiers* as;
		ASqueue.dequeue(as);
	}
	if (unit->Gettype() == "AD")
	{
		Aliendrones* as1;
		Aliendrones* as2;
		ADqueue.dequeue(as1);
		ADqueue.Dequeueback(as2);
	}//////
	if (unit->Gettype() == "AM")
	{
		Alienmonsters* am;
		
		AMarray.remove(am);
	}
	//check if we need to add the killed to a list
}

void print() {



}
