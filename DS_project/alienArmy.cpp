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

bool alienArmy::AS_remove(Aliensoldiers*& as)
{
	return ASqueue.dequeue(as);
}
bool alienArmy::AM_remove(Alienmonsters*& am)
{
	return AMarray.remove(am);
}
bool alienArmy::AD_remove(Aliendrones*& ad1, Aliendrones*& ad2)
{
	
	if (ADqueue.getcount() < 2)
	{
		return false;
	}
	return ADqueue.dequeue(ad1) && ADqueue.Dequeueback(ad2);

}

//void alienArmy::removeUnit(Unitclass*& unit1, Unitclass* &unit2) {
//	 
//		// Check if the ADqueue has at least two elements
//	if (ADqueue.getcount() >= 2) {
//		// Dequeue the first Aliendrones object
//		Aliendrones* ad1;
//		ADqueue.dequeue(ad1);
//		// Dequeue the second Aliendrones object
//		Aliendrones* ad2;
//		ADqueue.Dequeueback(ad2);
//
//		unit1 = ad1;
//		unit2 = ad2;
//	}
//}
//
//void alienArmy::removeUnit(Unitclass*& unit,string type)
//{
//	if (type == "AS")
//	{
//		Aliensoldiers* as;
//		ASqueue.dequeue(as);
//		unit = as;
//	}
//	if (type == "AD")
//	{
//		Aliendrones* ad;
//		ADqueue.dequeue(ad);
//		unit = ad;
//	}//////
//	if (type == "AM")
//	{
//		Alienmonsters* am = dynamic_cast<Alienmonsters*>(unit);
//		AMarray.remove(am);
//		unit = am;
//	}
//	//check if we need to add the killed to a list
//}

void alienArmy::print()
{
	
	cout << "=========== Alien Army Alive Units ===========" << endl;

	cout << ASqueue.getcount()<<" " << "AS" << " ";
	ASqueue.printqueue();
	cout << endl;

	cout << ADqueue.getcount() << " AD ";
	ADqueue.printqueue();
	cout << endl;

    cout << AMarray.getCount() << " AM ";
	AMarray.printarr();
	cout << endl;
	
}

