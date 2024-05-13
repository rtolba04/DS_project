#include "randGen.h"
#include "Game.h"
void randGen::setpwr(int ep1, int ep2, int ap1, int ap2)
{
	e_minpower = ep1;
	e_maxpower = ep2;
	a_minpower = ap1;
	a_maxpower = ap2;
}

void randGen::sethealth(int eh1, int eh2, int ah1, int ah2)
{
	e_minhealth = eh1;
	e_maxhealth = eh2;
	a_minhealth = ah1;
	a_maxhealth = ah2;

}

void randGen::setac(int eac1, int eac2, int aac1, int aac2)
{
	e_minac = eac1;
	e_maxac = eac2;
	a_minac = aac1;
	a_maxac = aac2;

}

void randGen::setN(int n)
{
	N = n;
}

void randGen::setpercentage(int e1, int e2, int e3,int h, int a1, int a2, int a3)
{
	ESpr = e1;
	ETpr = e2;
	EGpr = e3;
	HUpr = h;
	ASpr = a1;
	AMpr = a2;
	ADpr = a3;
}
void randGen::setstatusalien(int& p, int& h, int& ac)
{
	Ap = a_minpower + random(a_maxpower - a_minpower + 1);
	Ah = a_minhealth + random(a_maxhealth - a_minhealth + 1);
	Aac = a_minac + random(a_maxac - a_minac + 1);
}
void randGen::setProb(int p)
{
	Prob = p;
}
void randGen::setstatusearth(int& p, int& h, int& ac)
{
	Ep = e_minpower + random(e_maxpower - e_minpower + 1);      
	Eh = e_minhealth + random(e_maxhealth - e_minhealth + 1);
	Eac = e_minac + random(e_maxac - e_minac + 1);
}

int randGen::random(int r) 
{
	return rand()%r ;
}

void randGen::setGame(Game* g)
{
	game_ptr = g;
}


void randGen::generateunitearth(int& t) //adjusted so it creates and adds unit
{
	
		for (int i = 0; i < N; i++)
		{
			int B = random(100) + 1;
			Health* hu = new Health(earth_counter++, t, Eh, Ep, Eac);
			game_ptr->addHeal(hu);
			if (B <= ESpr)
			{
				Earthsoldiers* es = new Earthsoldiers(earth_counter++, t, Eh, Ep, Eac);
				game_ptr->getEA()->addUnit(es);
				es->setgame(game_ptr);
			}

			else if (B <= ESpr + ETpr)
			{
				Earthtanks* et = new Earthtanks(earth_counter++, t, Eh, Ep, Eac);
				game_ptr->getEA()->addUnit(et);
				et->setgame(game_ptr);
			
			}

			else
			{
				Earthgunnery* eg = new Earthgunnery(earth_counter++, t, Eh, Ep, Eac);
				game_ptr->getEA()->addUnit(eg);
				eg->setgame(game_ptr);
				//dont forget to tcalculate el function priority
			}
		}
	
}

void randGen::generateunitalien(int& t) //adjusted so it creates and adds unit
{
		for (int i = 0; i < N; i++)
		{
			int B = random(100) + 1;
			if (B <= ASpr)
			{
				Aliensoldiers* as = new Aliensoldiers(alien_counter++, t, Eh, Ep, Eac);
				game_ptr->getAA()->addUnit(as);
				as->setgame(game_ptr);
			}
			else	if (B <= ASpr + AMpr)
			{
				Alienmonsters* am = new Alienmonsters(alien_counter++, t, Eh, Ep, Eac);
				game_ptr->getAA()->addUnit(am);
				am->setgame(game_ptr);
			}
			else
			{
				Aliendrones* ad = new Aliendrones(alien_counter++, t, Eh, Ep, Eac);
				game_ptr->getAA()->addUnit(ad);
				ad->setgame(game_ptr);
			}
		}

}
void randGen::createunits(int &t) {
	int A = random(100) + 1;
	if (A <= Prob) {
		generateunitalien(t);
		generateunitearth(t);		
	}
}

int randGen::alien_counter{ 2000 };
int randGen::earth_counter{ 1};