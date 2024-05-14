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
		while (!ptr->checkUMLsold()) //while uml soldiers msh fadya
		{
			Earthsoldiers* es;
			int pri;
			//Earthsoldiers* es = ptr->UMLsoldHead();
		    ptr->removeUMLsold(es,pri);
			

			if (ptr->getTime() - es->get_tj_uml() > 10) //edit to time join UML
			{
				ptr->kill(es);
			}
			else {
				int oldhealth = es->GetHealth();
				int healthimp = (GetPower() * GetHealth() / 100) / sqrt(oldhealth);
				es->SetHealth(healthimp + oldhealth);
				//Setattackcapacity(Attackcapacity - 1);
				Attackcapacity--;
				if (es->GetHealth() > (oldhealth) * 20 / 100)
				{
					
					ptr->getEA()->addUnit(es);
				}
				else {
					
					temp->enqueue(es);
				}
				if (Attackcapacity == 0) break;
			}
		}
		 if (!ptr->checkUMLtank()) {
			 Earthtanks* et;
			ptr->removeUMLtank(et);
			if (ptr->getTime() - et->get_tj_uml() > 10) // edit so it is time joined UML
			{
				ptr->kill(et);
			}
			else {
				int oldhealth = et->GetHealth();
				int healthimp = (GetPower() * GetHealth() / 100) / sqrt(oldhealth);
				et->SetHealth(healthimp + oldhealth);
				Attackcapacity--;
				if (et->GetHealth() > (oldhealth) * 20 / 100)
				{
					
					ptr->getEA()->addUnit(et);
				}
				else {
					
					temp->enqueue(et);
				}
			}
			
		}
		if(ptr->checkUMLsold()&& ptr->checkUMLtank()) break;
	}
	while (temp->getfrontPtr())
	{
		Unitclass* u;
		temp->dequeue(u);
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
	ptr->getEA()->getHLstack().pop(h);
	//kill hu?
	
}

