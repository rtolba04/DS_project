#pragma once
#include "Game.h"
#include "Unitclass.h"
class randGen
{
private:
	int N, Prob, ESpr, ETpr, EGpr, ASpr, AMpr, ADpr, Ep, Eh, Eac, Ap, Ah, Aac, A, B, e_minpower, e_maxpower, e_minhealth, e_maxhealth;
	int e_minac, e_maxac, a_minpower, a_maxpower, a_minhealth, a_maxhealth, a_minac, a_maxac;
	Game* game_ptr;

public:
	void setEpwr(int p);
	void setEhealth(int h);
	void setEac(int ac);
	void setApwr(int p);
	void setAhealth(int h);
	void setAac(int ac);
	void setN(int n);
	void setpercentage(int);
	Unitclass* createunit();

};

