#pragma once
#include "Unitclass.h"
#include <iostream>
using namespace std;

class Earthsoldiers : public Unitclass
{
private:
	int ID;
	int Jointime;
	int Health;
	int Power;
	int Attackcapacity;
public:
	Earthsoldiers(int id, int jt, int h, int p, int ac);

};

