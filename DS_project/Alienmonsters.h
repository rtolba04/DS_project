#pragma once
#include "Unitclass.h"
class Alienmonsters : public Unitclass
{
private:

public:
	Alienmonsters(int id = 0, int jt = 0, int h = 0, int p = 0, int ac = 0);
	void attack();
};
inline ostream& operator <<(ostream& out, Alienmonsters* am)
{
	out << am->Getid();
	return out;
}

