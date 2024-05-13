#include "Aliensoldiers.h"
#include "LinkedQueue.h"
#include "Game.h"
#include <iostream>
using namespace std;

Aliensoldiers::Aliensoldiers(int id, int jt, int h, int p, int ac) :Unitclass(id, jt, h, p, ac, "AS")
{

}
void Aliensoldiers::attack()
{
	int ac = Getattackcapacity();
	LinkedQueue<Earthsoldiers*>* temp = new LinkedQueue<Earthsoldiers*>();
	ptr->getAA()->setASshooting(ID);

	while (ac != 0)
	{
		Earthsoldiers* es;
		if (!ptr->getEA()->getESqueue().isEmpty()) { // if queue not empty 
			
			ptr->getEA()->getESqueue().dequeue(es); //dequeue first ES
			es->set_ta(ptr->getTime());
			es->set_df();
			int Health_og = es->GetHealth(); //original health
			int Damage = ((GetPower()) * (GetHealth()) / 100) / sqrt(es->GetHealth()); //calculate damage 
			if (Damage >= es->GetHealth())   //if damage already greater than initial health, kill 3alatool
			{
				ptr->kill(es);
				es->set_td(ptr->getTime());
				es->set_dd();
				es->set_db();
			}
				
			es->SetHealth(Health_og - Damage); //set new health (after damage)
			if (es->GetHealth() <= 0.2 * Health_og && es->GetHealth() > 0)
			{
				int pri = -(es->GetHealth());
				ptr->addUMLsold(es, pri);
				es->set_tj_uml(ptr->getTime()); //getting tj uml
			}
			else if (es->GetHealth() > 0.2 * Health_og && es->GetHealth() < Health_og)
			{
				temp->enqueue(es);
			}
			ac--;
		}
		 else if(ptr->getEA()->getESqueue().isEmpty())
			break;
		}
	Earthsoldiers* es;
	while (temp->dequeue(es))
		ptr->getEA()->getESqueue().enqueue(es);
	
}
/*//int damage= (unit1power*unit1health/100)/rootunithealth2
	LinkedQueue<Aliensoldiers*>* temp = nullptr;  // since earth soldiers only attack soldiers alien thentemp list doesnt  have to e unit class
	int ac1 = Getattackcapacity();
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
