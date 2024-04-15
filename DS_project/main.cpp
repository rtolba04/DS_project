#include<iostream>
using namespace std;
#include"Game.h"
int main()
{
//	Game g1;
//	g1.getrand()->setGame(&g1);
//	g1.test();

	Game g2;
	Unitclass* yoyo=nullptr;
	Earthsoldiers* es = new Earthsoldiers(7,8,8,8,8);
	g2.getEA()->addUnit(es);
	g2.getEA()->removeUnit(yoyo,"ES");

	cout << yoyo;

	//for (int time=1; time <= 50; time++)
	//{
	//	cout << "Current Timestep " << time << endl;
	//	g1.getrand()->createunits(time);
	//	g1.getAA()->print();
	//	g1.getEA()->print();
	//}
}