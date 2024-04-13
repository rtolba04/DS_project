#pragma once
#include "Unitclass.h"
class Aliensoldiers :
	public Unitclass
{
private:

public:
	Aliensoldiers(int id, int jt, int h, int p, int ac);

	void attack();


};

inline ostream& operator <<(ostream& out, Aliensoldiers*& as)
{
	out << as->Getid();
	return out;
}



