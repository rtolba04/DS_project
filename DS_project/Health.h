#pragma once
#include "Unitclass.h"
class Health : public Unitclass
{
private:
public:
	Health(int id = 0, int jt = 0, int h = 0, int p = 0, int ac = 0);
	void attack();
};

inline ostream& operator <<(ostream& out, Health*& h)
{
	out << h->Getid();
	return out;
}

