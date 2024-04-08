#pragma once
#include "Unitclass.h"
class Aliendrones :
	public Unitclass
{
private:
	int ID;
	int Jointime;
	int Health;
	int Power;
	int Attackcapacity;
public:
	Aliendrones(int id, int jt, int h, int p, int ac);

};

