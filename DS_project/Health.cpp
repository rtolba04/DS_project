#include "Health.h"
#include "earthArmy.h"
#include "Unitclass.h"
#include"Game.h"
using namespace std;
Health::Health(int id, int jt, int h , int p, int ac) :Unitclass(id, jt, h, p, ac, "HU")
{
}
void Health::attack()
{
	Health* HU;
	LinkedQueue<Unitclass*>* temp = nullptr;
	while (HU->Getattackcapacity() != 0) {
		if (ptr->UMLsoldiers.getHead())
		{
			int pri = -GetHealth();
			Earthsoldiers* es = ptr->UMLsoldiers.getHead()->getItem(pri);
			if (ptr->getTime() - es->Getjointime() > 10) //edit to time join UML
			{
				ptr->kill(es);
			}
			else {
				int oldhealth = es->GetHealth();
				int healthimp = (HU->GetPower() * HU->GetHealth() / 100) / sqrt(oldhealth);
				es->SetHealth(healthimp + oldhealth);
				HU->Setattackcapacity(Attackcapacity - 1);
				if (es->GetHealth() > (oldhealth)*20/100) {
					ptr->getEA()->addUnit(es);
				}
				else {
					temp->enqueue(es);
				}
			}

		}
		else if(ptr->UMLtanks.getfrontPtr()) {
			Earthtanks* et = ptr->UMLtanks.getfrontPtr()->getItem();
			if (ptr->getTime() - et->Getjointime() > 10) // edit so it is time joined UML
			{
				ptr->kill(et);
			}
			else {
				int oldhealth = et->GetHealth();
				int healthimp = (HU->GetPower() * HU->GetHealth() / 100) / sqrt(oldhealth);
				et->SetHealth(healthimp + oldhealth);
				HU->Setattackcapacity(Attackcapacity - 1);
				if (et->GetHealth() > (oldhealth) * 20 / 100) {
					ptr->getEA()->addUnit(et);
				}
				else {
					temp->enqueue(et);
				}
			}

		}

	}
	while (temp->getfrontPtr())
	{
		Unitclass* u = temp->getfrontPtr()->getItem();
		if (u->Gettype() == "ES") {
			int pri = -(u->GetHealth());
			Earthsoldiers* es = dynamic_cast<Earthsoldiers*>(u);
			ptr->UMLsoldiers.enqueue(es, pri);
		}
		if (u->Gettype() == "ET") {
			Earthtanks* et = dynamic_cast<Earthtanks*>(u);
			ptr->UMLtanks.enqueue(et);
		}
	}

	delete HU;
	//3ayzin n delete HU HOW???
}