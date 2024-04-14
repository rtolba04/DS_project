#pragma once
#include "Unitclass.h"
class Aliensoldiers :
	public Unitclass
{
private:

public:
	Aliensoldiers(int id=0, int jt=0, int h=0, int p=0, int ac=0);

	void attack();
};

inline ostream& operator <<(ostream& out, Aliensoldiers* as)
{
	out << as->Getid();
	return out;
}