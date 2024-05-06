#include "Earthsoldiers.h"
#include "Aliensoldiers.h"
#include "Game.h"
#include <iostream>
#include "alienArmy.h"
#include  "earthArmy.h"
using namespace std;

Earthsoldiers::Earthsoldiers(int id, int jt, int h, int p, int ac) :Unitclass(id, jt, h, p, ac,"ES")
{

}
/*int ac = Getattackcapacity();
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
*/
void Earthsoldiers :: attack() {
	LinkedQueue<Aliensoldiers*>* temp = nullptr;  // since earth soldiers only attack soldiers alien thentemp list doesnt  have to e unit class
	
	int ac1 = Getattackcapacity();
	while(ac1!=0){
		Aliensoldiers* AS;
		int Health_og = AS->GetHealth();
		ptr->getAA()->getASqueue().dequeue(AS); //dequeue first AS
		int Damage = ((GetPower()) * (GetHealth()) / 100) / sqrt(Health_og);
		if (Damage >= Health_og) {
			ptr->kill(AS);
			
		}
		else if( Damage< Health_og){
			AS->SetHealth(Health_og - Damage);
			temp->enqueue(AS);
		}
		ac1--;
	}


}