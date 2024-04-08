#pragma once
#include "Unitclass.h"
class Earthtanks : public Unitclass
{

private:
	int ID;
	int Jointime;
	int Health;
	int Power;
	int Attackcapacity;
public:
	Earthtanks(int id, int jt, int h, int p, int ac);

};
