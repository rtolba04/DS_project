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
	LinkedQueue<Earthsoldiers*>* temp = nullptr;
	while (ac != 0)
	{
		Earthsoldiers* es;
		int Health_og = es->GetHealth(); //original health
		ptr->getEA()->getESqueue().dequeue(es); //dequeue first ES
		int Damage = ((GetPower()) * (GetHealth()) / 100) / sqrt(es->GetHealth()); //calculate damage 
		if (Damage >= es->GetHealth())   //if damage already greater than initial health, kill 3alatool
			ptr->kill(es);
		es->SetHealth(es->GetHealth() - Damage); //set new health (after damage)
		if (es->GetHealth() <= 0.2 * Health_og && es->GetHealth() > 0)
		{
			int pri = -(es->GetHealth());
			ptr->UMLsoldiers.enqueue(es, pri);    //need to get time joined UML!!!!!!!!!!
		}
		else if (es->GetHealth() > 0.2 * Health_og && es->GetHealth() < Health_og)
		{
			temp->enqueue(es);
		}//

	}
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
