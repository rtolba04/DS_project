#include "earthArmy.h"
#include "Unitclass.h"
#include "Earthtanks.h"
using namespace std;







void earthArmy::attack()
{}

void earthArmy::addUnit(Unitclass* unit)
{
	if (unit->Gettype() == "ET")
	{
		Earthtanks* typePtr= dynamic_cast<Earthtanks*>(unit);
		ETstack.push(typePtr);
	}
	if (unit->Gettype() == "ES")
	{
		Earthsoldiers* typePtr = dynamic_cast<Earthsoldiers*>(unit);
		ESqueue.enqueue(typePtr);
	}
	if (unit->Gettype() == "EG")
	{
		Earthgunnery* typePtr = dynamic_cast<Earthgunnery*>(unit);

		int pri;
		pri = ((typePtr->GetHealth() + typePtr->GetPower()) / 2);
		EGpriqueue.enqueue(typePtr,pri);
	}
}

void earthArmy::removeUnit(Unitclass* unit)
{
	if (unit->Gettype() == "ET")
	{
		Earthtanks* et;
		ETstack.pop(et);
	}
	if (unit->Gettype() == "ES")
	{
		Earthsoldiers* es;
		ESqueue.dequeue(es);
	}
	if (unit->Gettype() == "EG")
	{
		Earthgunnery* eg;
		int pri;
		pri = ((unit->GetHealth() + unit->GetPower()) / 2);
		EGpriqueue.enqueue(eg, pri);
	}
	//check if we need to add the killed to a list
}

void print() {



}
