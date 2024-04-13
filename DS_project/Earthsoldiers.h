#pragma once
#include "Unitclass.h"
#include <iostream>
using namespace std;

class Earthsoldiers : public Unitclass
{
private:
public:
	Earthsoldiers(int id, int jt, int h, int p, int ac);
	void attack();
	
	


};

 inline ostream& operator <<(ostream& out, Earthsoldiers* es)
{
	out << es->Getid();
	return out;
}


