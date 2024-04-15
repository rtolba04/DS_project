#include<iostream>
using namespace std;
#include"Game.h"
int main()
{
//	Game g1;
//	g1.getrand()->setGame(&g1);
//	g1.test();

	Game g2;
	Unitclass* unit=nullptr;
	Earthtanks* et = new Earthtanks(7,8,8,8,8);
	g2.getEA()->addUnit(et);
	g2.getEA().

	cout << unit;
	cout << "wwwwwwwwwwwwwwwwwwwwwwwwwwwww";
	//for (int time=1; time <= 50; time++)
	//{
	//	cout << "Current Timestep " << time << endl;
	//	g1.getrand()->createunits(time);
	//	g1.getAA()->print();
	//	g1.getEA()->print();
	//}
}