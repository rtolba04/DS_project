#include<iostream>
using namespace std;
#include"Game.h"
int main()
{
	Game G;
	G.getrand()->setGame(&G);
	
	
	//AD1->attack();
	//AD2->attack();
//	E3->attack();
	//AS2->attack(); (tried AS attack)
	//AD1->attack();
	G.simulate();
	cout << "lol";
}

//Earthtanks* E1 = new Earthtanks(49, 2, 3, 90, 1);
//Earthtanks* E2 = new Earthtanks(4, 2, 73, 50, 4);
//Earthtanks* E3 = new Earthtanks(43, 2, 83, 50, 2);
//Earthtanks* E4 = new Earthtanks(421, 2, 63, 500, 4);
//Earthtanks* E5 = new Earthtanks(461, 2, 53, 500, 4);
//Earthsoldiers* ES1 = new Earthsoldiers(91, 2, 3, 430, 4);
//Earthsoldiers* ES2 = new Earthsoldiers(932, 2, 31, 10, 4);
//Earthsoldiers* ES3 = new Earthsoldiers(90, 2, 3, 300, 4);
//Earthsoldiers* ES4 = new Earthsoldiers(94, 2, 3, 100, 4);
//Earthsoldiers* ES5 = new Earthsoldiers(67, 2, 3, 40, 4);
//Earthgunnery* EG1 = new Earthgunnery(17, 2, 3, 1300, 3);
//Earthgunnery* EG2 = new Earthgunnery(87, 2, 3, 320, 4);
//Earthgunnery* EG3 = new Earthgunnery(27, 2, 3, 50, 4);
//Aliensoldiers* AS1 = new Aliensoldiers(1111, 15, 3, 500, 4);
//Aliensoldiers* AS2 = new Aliensoldiers(1112, 2, 100, 500, 4);
//Aliensoldiers* AS3 = new Aliensoldiers(1163, 2, 3, 50, 4);
//Aliensoldiers* AS4 = new Aliensoldiers(1211, 2, 3, 90, 4);
//Aliensoldiers* AS5 = new Aliensoldiers(1212, 2, 3, 50, 4);
//Aliensoldiers* AS6 = new Aliensoldiers(1263, 2, 3, 500, 4);
//Alienmonsters* a1 = new Alienmonsters(1145, 1, 60, 500, 4);
//Alienmonsters* a2 = new Alienmonsters(1456, 3, 4, 1, 1);
//Alienmonsters* a3 = new Alienmonsters(1189, 4, 3, 1, 1);
//Alienmonsters* a4 = new Alienmonsters(1407, 4, 4, 1, 1);
//Alienmonsters* a5 = new Alienmonsters(1404, 4, 5, 1, 1);
//Alienmonsters* a6 = new Alienmonsters(1544, 4, 2, 1, 1);
//Aliendrones* AD1 = new Aliendrones(1544, 4, 2, 1000, 3);
//Aliendrones* AD2 = new Aliendrones(1564, 4, 2, 1132, 12);
//Aliendrones* AD3 = new Aliendrones(1744, 4, 2, 1, 1);
//Aliendrones* AD4 = new Aliendrones(1888, 4, 2, 1, 1);
//G.getAA()->addUnit(AD1);
//G.getAA()->addUnit(AD2);
//G.getAA()->addUnit(AD3);
//G.getAA()->addUnit(AD4);
//G.getEA()->addUnit(ES1);
//G.getEA()->addUnit(ES2);
//G.getEA()->addUnit(ES3);
//G.getEA()->addUnit(ES4);
//G.getEA()->addUnit(ES5);
//G.getEA()->addUnit(EG1);
//G.getEA()->addUnit(EG2);
//G.getEA()->addUnit(EG3);
//G.getAA()->addUnit(AS1);
//G.getAA()->addUnit(AS2);
//G.getAA()->addUnit(AS3);
//G.getAA()->addUnit(AS4);
//G.getAA()->addUnit(AS5);
//G.getAA()->addUnit(AS6);
//G.getEA()->addUnit(E1);
//G.getEA()->addUnit(E2);
//G.getEA()->addUnit(E3);
//G.getEA()->addUnit(E4);
//G.getEA()->addUnit(E5);
//G.getAA()->addUnit(a1);
//G.getAA()->addUnit(a2);
//G.getAA()->addUnit(a3);
//G.getAA()->addUnit(a4);
//G.getAA()->addUnit(a5);
//G.getAA()->addUnit(a6);
//E1->setgame(&G);
//E2->setgame(&G);
//E3->setgame(&G);
//E4->setgame(&G);
//E5->setgame(&G);
//a1->setgame(&G);
//a2->setgame(&G);
//a3->setgame(&G);
//a4->setgame(&G);
//a5->setgame(&G);
//a6->setgame(&G);
//ES1->setgame(&G);
//ES2->setgame(&G);
//ES3->setgame(&G);
//ES4->setgame(&G);
//ES5->setgame(&G);
//EG1->setgame(&G);
//EG2->setgame(&G);
//EG3->setgame(&G);
//AS1->setgame(&G);
//AS2->setgame(&G);
//AS3->setgame(&G);
//AS4->setgame(&G);
//AS5->setgame(&G);
//AS6->setgame(&G);
//AD1->setgame(&G);
//AD2->setgame(&G);
//AD3->setgame(&G);
//AD4->setgame(&G);