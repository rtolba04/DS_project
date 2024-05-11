#include "Earthtanks.h"
#include <iostream>
using namespace std;

Earthtanks::Earthtanks(int id, int jt, int h, int p, int ac) :Unitclass(id, jt, h, p, ac, "ET")
{

}
void Earthtanks::attack()
{
}

void Earthtanks::set_tj_uml(int tjuml)
{
	tj_uml = tjuml;
}

int Earthtanks::get_tj_uml()
{
	return tj_uml;
}