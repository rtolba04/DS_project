#include "earthArmy.h"
#include "Unitclass.h"
#include "Earthtanks.h"
#include "Health.h"
#include "Game.h"

using namespace std;

void earthArmy::setESshooting(int ESID)
{
	ESshooting = ESID;
}

int earthArmy::getESshooting()
{
	return ESshooting;
}

void earthArmy::setETshooting(int ETID)
{
	ETshooting = ETID;
}

int earthArmy::getETshooting()
{
	return ETshooting;
}

void earthArmy::setEGshooting(int EGID)
{
	EGshooting = EGID;
}

int earthArmy::getEGshooting()
{
	return EGshooting;
}


void earthArmy::attack()
{
	Earthsoldiers* Esoldierpicked;
	if (ESqueue.peek(Esoldierpicked))
Esoldierpicked->attack();

	Earthtanks* tankpicked;
	if (ETstack.peek(tankpicked))
	tankpicked->attack();
	Earthgunnery* gunnerypicked;
	int pri;
	if(EGpriqueue.peek(gunnerypicked,pri))
	gunnerypicked->attack();

	Health* healpicked;
	if (HLstack.pop(healpicked))
	{
	
		healpicked->attack();

	}
		

}

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
		EGpriqueue.enqueue(typePtr,typePtr->getpri());
	}
	if (unit->Gettype() == "HU") {
		Health* typePtr = dynamic_cast<Health*>(unit);
		HLstack.push(typePtr);
	}
	
}

LinkedQueue<Earthsoldiers*>& earthArmy::getESqueue()
{
	return ESqueue;
}

bool earthArmy::ET_remove(Earthtanks*& et)
{
	return ETstack.pop(et);
}

bool earthArmy::ES_remove(Earthsoldiers*& es)
{
	return ESqueue.dequeue(es);
}

bool earthArmy::EG_remove(Earthgunnery*& eg,int & pri)
{
	return EGpriqueue.dequeue(eg,pri);
}

ArrayStack<Earthtanks*>& earthArmy::getETstack()
{
	return ETstack;
}
priQueue<Earthgunnery*>& earthArmy::getEGpriqueue()
{
	return EGpriqueue;
}



//void earthArmy::removeUnit(Unitclass*& unit, string type)
//{
//	if (type == "ET")
//	{
//		Earthtanks* et;
//		ETstack.pop(et);
//		// et = dynamic_cast<Earthtanks*>(unit);
//		unit = et;
//	
//	}
//	if (type == "ES")
//	{
//		Earthsoldiers* es;
//		ESqueue.dequeue(es);
//		
//		unit = es;
//	}
//	if (type == "EG")
//	{
//		Earthgunnery* eg;
//		int pri;
//		EGpriqueue.dequeue(eg, pri);
//		unit =eg;
//	}
//	//check if we need to add the killed to a list
//}

void earthArmy::print()
{
	cout << "=========== Earth Army Alive Units ===========" << endl;
	
	
	cout << ESqueue.getcount() << " ES ";
	ESqueue.printqueue();
	cout << endl;

	cout << ETstack.getcount() << " ET ";
	ETstack.printstack();
	cout << endl;

	cout << EGpriqueue.getcount() << " EG ";
	EGpriqueue.printpri();
	cout << endl;
}

void earthArmy::addHeal(Health* h)
{
	HLstack.push(h);
}

void earthArmy::removeHeal(Health*& hu)
{
	HLstack.pop(hu);
}

ArrayStack<Health*>& earthArmy::getHLstack()
{
	return HLstack;
}


