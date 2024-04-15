#include<iostream>
using namespace std;
#include"Game.h"
int main()
{
	Game g1;
	g1.getrand()->setGame(&g1);
	g1.test();

	//for (int time=1; time <= 50; time++)
	//{
	//	cout << "Current Timestep " << time << endl;
	//	g1.getrand()->createunits(time);
	//	g1.getAA()->print();
	//	g1.getEA()->print();
	//}
}