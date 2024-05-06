#include<iostream>
using namespace std;
#include"Game.h"
int main()
{
	Game G;
	G.getrand()->setGame(&G);
	//G.test();


Earthsoldiers* E1 = new Earthsoldiers(49, 2, 3, 500, 4);
Aliensoldiers* a1 = new Aliensoldiers(145, 1, 60, 500, 4);
Aliensoldiers* a2 = new Aliensoldiers(456, 3, 4, 1, 1);
Aliensoldiers* a3 = new Aliensoldiers(89, 4, 3, 1, 1);
Aliensoldiers* a4 = new Aliensoldiers(407, 4, 4, 1, 1);
Aliensoldiers* a5 = new Aliensoldiers(404, 4, 5, 1, 1);
Aliensoldiers* a6 = new Aliensoldiers(4, 4, 2, 1, 1);

G.getEA()->addUnit(E1);
G.getAA()->addUnit(a1);
G.getAA()->addUnit(a2);
G.getAA()->addUnit(a3);
G.getAA()->addUnit(a4);
G.getAA()->addUnit(a5);
G.getAA()->addUnit(a6);
E1->setgame(&G);
E1->attack();
G.test();
//.getEA()->print();
//G.getAA()->print();
//A1->setgame(&G);
//A1->attack();
//G.printGame();
//system("pause");*/
	/*Game g2;
	Unitclass* unit=nullptr;
	Earthtanks* et = new Earthtanks(7,8,8,8,8);
	g2.getEA()->addUnit(et);
	g2.getEA()->removeUnit(unit, "ET");

	cout << unit;
	cout << "wwwwwwwwwwwwwwwwwwwwwwwwwwwww";*/
	//for (int time=1; time <= 50; time++)
	//{
	//	cout << "Current Timestep " << time << endl;
	//	g1.getrand()->createunits(time);
	//	g1.getAA()->print();
	//	g1.getEA()->print();
	//}
}