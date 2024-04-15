#include<iostream>
using namespace std;
#include"Game.h"
int main()
{
	Game g1;
	g1.getrand()->setGame(&g1);
	g1.test();
}