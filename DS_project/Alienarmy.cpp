#include "alienArmy.h"
#include "Unitclass.h"
#include "Alienmonsters.h"
#include "Aliensoldiers.h"
#include "Aliendrones.h"
#include <iostream>
using namespace std;


void alienArmy::attack()
{ 
	Aliensoldiers* as; //make one soldier attack (FIFO)
	ASqueue.peek(as);
	as->attack();
	                 //make one randomly picked monster attack
	int AM_ind; // randomly generated index from AM array
	int AM_size = AMarray.getCount();
	AM_ind = rand() % AM_size;
	AMarray.getelement(AM_ind)->attack();

	if (ADqueue.getcount() >= 2) // if more than 2 drones exist, attack
	{
		Aliendrones* AD1; //make 2 drones attack
		Aliendrones* AD2;
		ADqueue.peek(AD1);
		ADqueue.peekback(AD2);
		AD1->attack();
		AD2->attack();
	}
	
}
/*void Earthsoldiers :: attack() {
	LinkedQueue<Aliensoldiers*>* temp = nullptr;  // since earth soldiers only attack soldiers alien thentemp list doesnt  have to e unit class
	Earthsoldiers* Esoldierpicked;
	int ac1 = Esoldierpicked->Getattackcapacity();
	while(ac1!=0){
		Aliensoldiers* Asoldierpicked;
		int oldsoldierhealth = Asoldierpicked->GetHealth();
		int Damage = ((Esoldierpicked->GetPower()) * (Esoldierpicked->GetHealth()) / 100) / sqrt(oldsoldierhealth);
		if (Damage < oldsoldierhealth) {
			Asoldierpicked->SetHealth(oldsoldierhealth - Damage);
			temp->enqueue(Asoldierpicked);
		}
		else{
			ptr->kill(Asoldierpicked);
		}
		ac1--;
	}

}*/
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

