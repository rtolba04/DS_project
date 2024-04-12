#include "earthArmy.h"

void earthArmy::addUnit(Unitclass* unit)
{
	if (unit->Gettype() == "ET")
	{
		ETstack.push(unit);
	}
	if (unit->Gettype() == "ES")
	{
		ESqueue.enqueue(unit);
	}
	if (unit->Gettype() == "EG")
	{
		EGpriqueue.enqueue(unit);
	}
}
