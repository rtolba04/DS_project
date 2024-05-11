#include "Earthsoldiers.h"
#include <iostream>
using namespace std;

Earthsoldiers::Earthsoldiers(int id, int jt, int h, int p, int ac) :Unitclass(id, jt, h, p, ac,"ES")
{

}
void Earthsoldiers :: attack() {}

void Earthsoldiers::set_tj_uml(int tjuml)
{
	tj_uml = tjuml;
}

int Earthsoldiers::get_tj_uml()
{
	return tj_uml;
}