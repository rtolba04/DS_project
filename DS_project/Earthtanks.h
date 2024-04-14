#pragma once
#include "Unitclass.h"
class Earthtanks : public Unitclass
{

private:
	
public:
	Earthtanks(int id=0, int jt=0, int h=0, int p=0, int ac=0);
	void attack();
};

inline ostream& operator <<(ostream& out, Earthtanks*& et)
{
	out << et->Getid();
	return out;
}


