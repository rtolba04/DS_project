#include "Earthgunnery.h"
#include <iostream>
#include "LinkedQueue.h"
#include "alienArmy.h"
#include "Game.h"
using namespace std;

Earthgunnery::Earthgunnery(int id, int jt, int h, int p, int ac) :Unitclass(id, jt, h, p, ac, "EG")
{
}
void Earthgunnery::attack()
{
	LinkedQueue<Unitclass*>* temp = new LinkedQueue<Unitclass*>();
	int ac2 = Getattackcapacity();
	int AMcount = ptr->getAA()->getAMarray().getCount();
	int ADcount = ptr->getAA()->getADqueue().getcount();
	int Damage;
	int Damage1;
	int Damage2;
	ptr->getEA()->setEGshooting(ID);

	{//keeps attacking soldiers till 80 percent then attacks  monsters
		while (ac2 != 0) {
			Alienmonsters* AM;
			Aliendrones* AD1;
			Aliendrones* AD2;
			if (ac2 != 0) {// randomly generated index from AM array
				int AM_size = ptr->getAA()->getAMarray().getCount();
				if (AM_size != 0) {
					
				int AM_ind = rand() % AM_size;
					AM = ptr->getAA()->getAMarray().getelement(AM_ind);
					ptr->getAA()->getAMarray().remove(AM);
					AM->set_ta(ptr->getTime());
					AM->set_df();
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
				}
				ac2--;
			
			}
			if (ac2 == 0) { break; }
			if (ac2 != 0 && ac2!=1) {
				if (ptr->getAA()->getADqueue().getcount() >= 2) {
					ptr->getAA()->getADqueue().dequeue(AD1);
					ptr->getAA()->getADqueue().Dequeueback(AD2);
					int AD1Health_og = AD1->GetHealth();
					int AD2Health_og = AD2->GetHealth();
					Damage1 = ((GetPower()) * (GetHealth()) / 100) / sqrt(AD1Health_og);
					Damage2 = ((GetPower()) * (GetHealth()) / 100) / sqrt(AD2Health_og);
					if (Damage1 >= AD1Health_og) {
						ptr->kill(AD1);

					}
					else if (Damage1< AD1Health_og) {
						AD1->SetHealth(AD1Health_og - Damage1);
						temp->enqueue(AD1);
					}
					ac2--;
					if (Damage2 >= AD2Health_og) {
						ptr->kill(AD2);

					}
					else if (Damage2 < AD2Health_og) {
						AD2->SetHealth(AD2Health_og - Damage2);
						temp->enqueue(AD2);
					}
				}
				ac2--;
			}
			else if (ptr->getAA()->getADqueue().getcount() == 1) {
				ptr->getAA()->getADqueue().dequeue(AD1);
				int AD1Health_og = AD1->GetHealth();

				Damage1 = ((GetPower()) * (GetHealth()) / 100) / sqrt(AD1Health_og);
				if (Damage1 >= AD1Health_og) {
					ptr->kill(AD1);

				}
				else if (Damage1 < AD1Health_og) {
					AD1->SetHealth(AD1Health_og - Damage1);
					temp->enqueue(AD1);
				}
				ac2--;
			}
		
		}
		int flag = 0;
		while (temp->getfrontPtr())
		{
			Unitclass* u = temp->getfrontPtr()->getItem();
			if (u->Gettype() == "AM") {
				Alienmonsters* AM = dynamic_cast<Alienmonsters*>(u);
				ptr->getAA()->addUnit(AM);
			}
			if (u->Gettype() == "AD") {
				Aliendrones* AD = dynamic_cast<Aliendrones*>(u);

				if (flag == 0) {
					ptr->getAA()->getADqueue().Enqueuefront(AD);
					flag = 1;
				}
				else if (flag == 1) {

					ptr->getAA()->getADqueue().enqueue(AD);
					flag = 0;
				}
			}
			temp->dequeue(u);
		}
	}
}

int Earthgunnery::getpri()
{	int pri = (GetHealth() + GetPower());
	return pri;
}
