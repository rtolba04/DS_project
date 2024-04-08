#pragma once
#include "Unitclass.h"
class Alienmonsters : public Unitclass
{
private:
	int ID;
	int Jointime;
	int Health;
	int Power;
	int Attackcapacity;
public:
	Alienmonsters(int id, int jt, int h, int p, int ac);

};

