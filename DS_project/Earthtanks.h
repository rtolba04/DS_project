#pragma once
#include "Unitclass.h"
class Earthtanks : public Unitclass
{

private:
	
public:
	Earthtanks(int id, int jt, int h, int p, int ac);
	void attack();
};

inline ostream& operator <<(ostream& out, Earthtanks*& et)
{
	out << et->Getid();
	return out;
}


