#include "alienArmy.h"
#include "Unitclass.h"
#include "Alienmonsters.h"
#include "ArrBag.h"
#include "Aliensoldiers.h"
#include "Aliendrones.h"
#include <iostream>
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
	if (unit->Gettype() == "AD")
	{
		Aliendrones* typePtr = dynamic_cast<Aliendrones*>(unit);
		ADqueue.enqueue(typePtr);
	}
}

void alienArmy::removeUnit(Unitclass* unit1, Unitclass* unit2) {
	if (unit1->Gettype() == "AD" && unit2->Gettype() == "AD") {
		// Check if the ADqueue has at least two elements
		if (ADqueue.getcount() >= 2) {
			// Dequeue the first Aliendrones object
			Aliendrones* as1;
			ADqueue.dequeue(as1);
			// Dequeue the second Aliendrones object
			Aliendrones* as2;
			ADqueue.Dequeueback(as2);
		}
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
		Aliendrones* as;
		ADqueue.dequeue(as);

	}//////
	if (unit->Gettype() == "AM")
	{
		Alienmonsters* am = dynamic_cast<Alienmonsters*>(unit);
		AMarray.remove(am);
	}
	//check if we need to add the killed to a list
}

void alienArmy::print()
{

	cout << ASqueue.getcount() << " " << "AS" << " ";
	ASqueue.printqueue();
	cout << endl;

	cout << ADqueue.getcount() << " AD ";
	ADqueue.printqueue();
	cout << endl;

	cout << AMarray.getCount() << " AM ";
	AMarray.printarr();
	cout << endl;

}

