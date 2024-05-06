#include "Earthtanks.h"
#include "Game.h"
#include <iostream>
using namespace std;

Earthtanks::Earthtanks(int id, int jt, int h, int p, int ac) :Unitclass(id, jt, h, p, ac, "ET")
{

}
void Earthtanks::attack()
{
	LinkedQueue<Unitclass*>* temp = nullptr; 
	int ac2 = Getattackcapacity();
	int EScount = ptr->getEA()->getESqueue().getcount();
	int AScount = ptr->getAA()->getASqueue().getcount(); 
	if (EScount < (0.3 * AScount) ) { //keeps attacking soldiers till 80 percent then attacks  monsters
		while (ac2 != 0 && EScount < (0.8 * AScount)) {
			Alienmonsters* AM;
			Aliensoldiers* AS;
			int AMHealth_og = AM->GetHealth();
			ptr->getAA()->getAMarray().remove(AM);//dequeue RANDOM AM ??????????????
			int Damage = ((GetPower()) * (GetHealth()) / 100) / sqrt(AMHealth_og);
			if (Damage >= AMHealth_og) {
				ptr->kill(AM);

			}
			else if (Damage < AMHealth_og) {
				AM->SetHealth(AMHealth_og - Damage);
				temp->enqueue(AM);
			}
			ac2--;
			if (ac2 != 0) { return; }
			int ASHealth_og = AS->GetHealth();
			ptr->getAA()->getASqueue().dequeue(AS); //dequeue first AS
			int Damage = ((GetPower()) * (GetHealth()) / 100) / sqrt(ASHealth_og);
			if (Damage >= ASHealth_og) {
				ptr->kill(AS);

			}
			else if (Damage < ASHealth_og) {
				AS->SetHealth(ASHealth_og - Damage);
				temp->enqueue(AS);
			}
			ac2--;
			EScount = ptr->getEA()->getESqueue().getcount();
			AScount = ptr->getAA()->getASqueue().getcount();
		}	
	}
	EScount = ptr->getEA()->getESqueue().getcount();
	AScount = ptr->getAA()->getASqueue().getcount();
	if (EScount >= 0.3 * AScount) {  // attack monsters if ES> 0.3AS
		while (ac2 != 0) {
			Alienmonsters* AM;
			int Health_og = AM->GetHealth();
			ptr->getAA()->getAMarray().remove(AM);//dequeue first AM
			int Damage = ((GetPower()) * (GetHealth()) / 100) / sqrt(Health_og);
			if (Damage >= Health_og) {
				ptr->kill(AM);

			}
			else if (Damage < Health_og) {
				AM->SetHealth(Health_og - Damage);
				temp->enqueue(AM);
			}
			ac2--;
		}
	}
	while (temp->getfrontPtr())
	{
		Unitclass* u = temp->getfrontPtr()->getItem();
		if (u->Gettype() == "AM") {
			Alienmonsters* AM = dynamic_cast<Alienmonsters*>(u);
			ptr->getAA()->addUnit(AM);
		}
		if (u->Gettype() == "AS") {
			Aliensoldiers* AS = dynamic_cast<Aliensoldiers*>(u);
			ptr->getAA()->addUnit(AS);
		}
	}
}


