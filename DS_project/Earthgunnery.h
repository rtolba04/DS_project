#pragma once
#include "Unitclass.h"
class Earthgunnery :
	public Unitclass
{
private:
	
public:
	Earthgunnery(int id = 0, int jt = 0, int h = 0, int p = 0, int ac = 0);
	void attack();
	int getpri();
};

inline ostream& operator <<(ostream& out, Earthgunnery* eg)
{
	out << eg->Getid();
	return out;
}



