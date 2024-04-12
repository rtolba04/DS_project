#include "earthArmy.h"

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
		EGpriqueue.enqueue(unit);
	}
}
