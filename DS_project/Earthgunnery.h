#pragma once
#include "Unitclass.h"
class Earthgunnery :
	public Unitclass
{
private:
	
public:
	Earthgunnery(int id, int jt, int h, int p, int ac);
	void attack();
	int getpri();
};

inline ostream& operator <<(ostream& out, Earthgunnery* eg)
{
	out << eg->Getid();
	return out;
}



