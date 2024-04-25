#include "Earthgunnery.h"
#include <iostream>
using namespace std;

Earthgunnery::Earthgunnery(int id, int jt, int h, int p, int ac) :Unitclass(id, jt, h, p, ac, "EG")
{
}
void Earthgunnery::attack()
{
}
int Earthgunnery::getpri()
{	int pri = (GetHealth() + GetPower());
	return pri;
}
