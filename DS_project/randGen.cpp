#include "randGen.h"

void randGen::setEpwr(int p)
{
	Ep = p;
}

void randGen::setEhealth(int h)
{
	Eh = h;
}
void randGen::setEattack(int ac)
{
	Eac = ac;
}
void randGen::setAattack(int ac)
{
	Aac = ac;
}
void randGen::setAhealth(int h)
{
	Ah=h;
}
void randGen::setApwr(int p)
{
	Ap=p;
}

Unitclass* randGen::createunit()
{
	if (B <= ESpr)
	{
		Earthsoldiers* es = new Earthsoldiers;
		return es;
	}

	if (B <= ESpr + ETpr)
	{
		Earthsoldiers* es = new Earthsoldiers;
		return es;
	}

	if (B <= ESpr + ETpr + EGpr)
	{
		Earthsoldiers* es = new Earthsoldiers;
		return es;
	}

	if (B <= ASpr)
	{
		Earthsoldiers* es = new Earthsoldiers;
		return es;
	}

	if (B <= AMpr)
	{
		Earthsoldiers* es = new Earthsoldiers;
		return es;
	}

	if (B <= ADpr)
	{
		Earthsoldiers* es = new Earthsoldiers;
		return es;
	}
		 

}
