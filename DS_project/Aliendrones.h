#pragma once
#include "Unitclass.h"
class Aliendrones :
	public Unitclass
{
private:
	
public:
	Aliendrones(int id = 0, int jt = 0, int h = 0, int p = 0, int ac = 0);
	void attack();
};

inline ostream& operator <<(ostream& out, Aliendrones* ad)
{
	out << ad->Getid();
	return out;
}