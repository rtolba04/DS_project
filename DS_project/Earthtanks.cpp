#include "Earthtanks.h"
#include "Game.h"
#include "ArrBag.h"
#include <iostream>
using namespace std;

Earthtanks::Earthtanks(int id, int jt, int h, int p, int ac) :Unitclass(id, jt, h, p, ac, "ET")
{

}
void Earthtanks::attack()
{
	LinkedQueue<Unitclass*>* temp = new LinkedQueue<Unitclass*>();
	int ac2 = Getattackcapacity();
	int EScount = ptr->getEA()->getESqueue().getcount();
	int AScount = ptr->getAA()->getASqueue().getcount();
	int Damage;
	ptr->getEA()->setETshooting(ID);

	if (EScount < (0.3 * AScount)) { //keeps attacking soldiers till 80 percent then attacks  monsters
		while (ac2 != 0 && EScount < (0.8 * AScount)) {
			Alienmonsters* AM;
			Aliensoldiers* AS;
			// randomly generated index from AM array
			int AM_size = ptr->getAA()->getAMarray().getCount();


			if (AM_size != 0) {
				
				int AM_ind = rand() % AM_size;
				AM = ptr->getAA()->getAMarray().getelement(AM_ind);
				ptr->getAA()->getAMarray().remove(AM);
				AM->set_ta(ptr->getTime());
				AM->set_df();
				//dequeue RANDOM AM ??????????????
				int AMHealth_og = AM->GetHealth();
				Damage = ((GetPower()) * (GetHealth()) / 100) / sqrt(AMHealth_og);
				if (Damage >= AMHealth_og) {
					ptr->kill(AM);
					AM->set_td(ptr->getTime());
					AM->set_dd();
					AM->set_db();

				}
				else if (Damage < AMHealth_og) {
					AM->SetHealth(AMHealth_og - Damage);
					temp->enqueue(AM);
				}
				ac2--;
			}
			if (ac2 == 0) { return; }
			if (!ptr->getAA()->getASqueue().isEmpty()) {
				
				ptr->getAA()->getASqueue().dequeue(AS); //dequeue first AS
				AS->set_ta(ptr->getTime());
				AS->set_df();
				int ASHealth_og = AS->GetHealth();
				Damage = ((GetPower()) * (GetHealth()) / 100) / sqrt(ASHealth_og);
				if (Damage >= ASHealth_og) {
					ptr->kill(AS);
					AS->set_td(ptr->getTime());
					AS->set_dd();
					AS->set_db();

				}
				else if (Damage < ASHealth_og) {
					AS->SetHealth(ASHealth_og - Damage);
					temp->enqueue(AS);
				}
				ac2--;
			}
			EScount = ptr->getEA()->getESqueue().getcount();
			AScount = ptr->getAA()->getASqueue().getcount();
		}
	}

	EScount = ptr->getEA()->getESqueue().getcount();
	AScount = ptr->getAA()->getASqueue().getcount();

	if (EScount >= 0.3 * AScount) {  // attack monsters if ES> 0.3AS
		while (ac2 != 0) {
			Alienmonsters* AM;
			int AM_size = ptr->getAA()->getAMarray().getCount();
			if (AM_size != 0) {
				int AM_ind = rand() % AM_size;
				AM = ptr->getAA()->getAMarray().getelement(AM_ind);
				ptr->getAA()->getAMarray().remove(AM);
				int Health_og = AM->GetHealth();
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
			else if (AM_size == 0) break;
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
			temp->dequeue(u);
		}
	}
}

void Earthtanks::set_tj_uml(int tjuml)
{
	tj_uml = tjuml;
}

int Earthtanks::get_tj_uml()
{
	return tj_uml;
}