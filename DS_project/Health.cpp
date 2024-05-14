#include "Health.h"
#include "earthArmy.h"
#include "Unitclass.h"
#include"Game.h"
using namespace std;
Health::Health(int id, int jt, int h, int p, int ac) :Unitclass(id, jt, h, p, ac, "HU") {}

void Health::attack()
{
	LinkedQueue<Unitclass*>* temp = new LinkedQueue<Unitclass*>();
	while (Getattackcapacity() != 0) {
		while (!ptr->checkUMLsold())
		{
			int pri = -GetHealth();
			Earthsoldiers* es = ptr->UMLsoldHead();
			if (ptr->getTime() - es->get_tj_uml() > 10) //edit to time join UML
			{
				ptr->kill(es);
			}
			else {
				int oldhealth = es->GetHealth();
				int healthimp = (GetPower() * GetHealth() / 100) / sqrt(oldhealth);
				es->SetHealth(healthimp + oldhealth);
				Setattackcapacity(Attackcapacity - 1);
				if (es->GetHealth() > (oldhealth) * 20 / 100)
				{
					ptr->removeUMLsold(es, -es->GetHealth());
					ptr->getEA()->addUnit(es);
				}
				else {
					ptr->removeUMLsold(es, -es->GetHealth());
					temp->enqueue(es);
				}
			}
		}
		 if (!ptr->checkUMLtank()) {
			Earthtanks* et = ptr->UMLtankHead();
			if (ptr->getTime() - et->get_tj_uml() > 10) // edit so it is time joined UML
			{
				ptr->kill(et);
			}
			else {
				int oldhealth = et->GetHealth();
				int healthimp = (GetPower() * GetHealth() / 100) / sqrt(oldhealth);
				et->SetHealth(healthimp + oldhealth);
				Setattackcapacity(Attackcapacity - 1);
				if (et->GetHealth() > (oldhealth) * 20 / 100)
				{
					ptr->removeUMLtank(et);
					ptr->getEA()->addUnit(et);
				}
				else {
					ptr->removeUMLtank(et);
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
			ptr->addUMLsold(es, pri);
		}
		if (u->Gettype() == "ET") {
			Earthtanks* et = dynamic_cast<Earthtanks*>(u);
			ptr->addUMLtank(et);
		}
	}
	Health* h;
	ptr->removeHeal(* &h);
	//kill hu?
	
}

