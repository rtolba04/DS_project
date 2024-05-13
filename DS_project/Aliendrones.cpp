#include "Aliendrones.h"
#include "Game.h"
#include <iostream>
using namespace std;

Aliendrones::Aliendrones(int id, int jt, int h, int p, int ac) :Unitclass(id, jt, h, p, ac, "AD")
{
}
void Aliendrones :: attack() {
	int ac = Getattackcapacity();
	LinkedQueue<Earthgunnery*>* temp_eg = new LinkedQueue<Earthgunnery*>();
	LinkedQueue<Earthtanks*>* temp_et = new LinkedQueue<Earthtanks*>();
	int id1;
	int id2;
	//pee
	ptr->getAA()->setADshooting1(ID);
	ptr->getAA()->setADshooting2(ID);

	while (ac != 0)
	{
		//attacking et
		Earthtanks* et;

		if (ptr->getEA()->getETstack().pop(et)) {

			et->set_ta(ptr->getTime());
			et->set_df();
			int Health_og_et = et->GetHealth();
			int Damage1 = ((GetPower()) * (GetHealth()) / 100) / sqrt(et->GetHealth());
			if (Damage1 >= Health_og_et)   //if damage already greater than initial health, kill 3alatool
			{
				ptr->kill(et);
				et->set_td(ptr->getTime());
				et->set_dd();
				et->set_db();
			}
				
			et->SetHealth(Health_og_et - Damage1); //set new health (after damage)
			if (et->GetHealth() <= 0.2 * Health_og_et && et->GetHealth() > 0)
			{
				ptr->addUMLtank(et);
			//	ptr->UMLtanks.enqueue(et);
				et->set_tj_uml(ptr->getTime());
			}
			else if (et->GetHealth() > 0.2 * Health_og_et && et->GetHealth() < Health_og_et)
			{
				temp_et->enqueue(et);
			}
			ac--;
		}
		

		if (ac == 0) break;
		//attacking eg
		Earthgunnery* eg;
		int pri;
		if (ptr->getEA()->getEGpriqueue().dequeue(eg, pri))
		{
			eg->set_ta(ptr->getTime());
			eg->set_df();

			int Health_og_eg = eg->GetHealth();
			int Damage2 = ((GetPower()) * (GetHealth()) / 100) / sqrt(eg->GetHealth());
			if (Damage2 >= Health_og_eg)   //if damage already greater than initial health, kill 3alatool
			{
				ptr->kill(eg);
				eg->set_td(ptr->getTime());
				eg->set_dd();
				eg->set_db();

			}
				
			eg->SetHealth(Health_og_eg - Damage2); //set new health (after damage)
			temp_eg->enqueue(eg);
			ac--;
		}
		if (ptr->getEA()->getEGpriqueue().isEmpty() && ptr->getEA()->getETstack().isEmpty())
			break;
	}

	Earthgunnery* eg;
	int pri;

	Earthtanks* et;

	while (temp_et->dequeue(et))
		ptr->getEA()->getETstack().push(et);
	while (temp_eg->dequeue(eg))
	{    
		pri = eg->getpri();
		ptr->getEA()->getEGpriqueue().enqueue(eg,pri);  
	}
		

}