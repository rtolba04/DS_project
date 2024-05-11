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

	while (ac!=0)
	{
		//attacking es
		Earthsoldiers* es;
		ptr->getEA()->getESqueue().dequeue(es);
		int Health_og_es = es->GetHealth();
		int Damage = ((GetPower()) * (GetHealth()) / 100) / sqrt(es->GetHealth());
		if (Damage >= es->GetHealth())   //if damage already greater than initial health, kill 3alatool
			ptr->kill(es);
		es->SetHealth(Health_og_es - Damage); //set new health (after damage)
		if (es->GetHealth() <= 0.2 * Health_og_es && es->GetHealth() > 0)
		{
			int pri = -(es->GetHealth());
			ptr->UMLsoldiers.enqueue(es, pri);    
			es->set_tj_uml(ptr->getTime());
		}
		else if (es->GetHealth() > 0.2 * Health_og_es && es->GetHealth() < Health_og_es)
		{
			temp_es->enqueue(es);
		}
		ac--;
		
		if (ac == 0) break;
		//attacking et
		Earthtanks* et;
		ptr->getEA()->getETstack().pop(et);
		int Health_og_et= et->GetHealth();
		int Damage = ((GetPower()) * (GetHealth()) / 100) / sqrt(et->GetHealth());
		if (Damage >= et->GetHealth())   //if damage already greater than initial health, kill 3alatool
			ptr->kill(et);
		et->SetHealth(Health_og_et - Damage); //set new health (after damage)
		if (et->GetHealth() <= 0.2 * Health_og_es && es->GetHealth() > 0)
		{
			ptr->UMLtanks.enqueue(et);    
			et->set_tj_uml(ptr->getTime());
		}
		else if (es->GetHealth() > 0.2 * Health_og_es && es->GetHealth() < Health_og_es)
		{
			temp_et->enqueue(et);
		}

		ac--;
	}
	Earthsoldiers* es;
	Earthtanks* et;

	while (temp_es->dequeue(es))
		ptr->getEA()->getESqueue().enqueue(es);
	while (temp_et->dequeue(et))
		ptr->getEA()->getETstack().push(et);
	
}
	

