#pragma once
#include "Unitclass.h"

class Aliendrones :
	public Unitclass
{
private:
	
public:
	Aliendrones(int id, int jt, int h, int p, int ac);

	void attack();

};

inline ostream& operator <<(ostream& out, Aliendrones*& ad)
{
	out << ad->Getid();
	return out;
}



