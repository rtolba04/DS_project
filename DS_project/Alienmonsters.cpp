#include "Alienmonsters.h"
#include "Game.h"
#include <iostream>
using namespace std;

Alienmonsters::Alienmonsters(int id, int jt, int h, int p, int ac) :Unitclass(id, jt, h, p, ac, "AM")
{

}
void Alienmonsters::attack()
{
	int ac = Getattackcapacity();
	
	LinkedQueue<Earthsoldiers*>* temp_es = nullptr;
	LinkedQueue<Earthtanks*>* temp_et = nullptr;

	while (ac >=2)
	{
		Earthsoldiers* es;
		Earthtanks* et;
		ptr->getEA()->getESqueue().dequeue(es);
		ptr->getEA()->getETstack().pop(et);



	}

	
}
	

