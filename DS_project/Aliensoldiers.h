#pragma once
#include "Unitclass.h"
class Earthgunnery :
	public Unitclass
{
private:
	int ID;
	int Jointime;
	int Health;
	int Power;
	int Attackcapacity;
public:
	Earthgunnery(int id, int jt, int h, int p, int ac);


};

