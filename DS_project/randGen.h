#pragma once
#include "Game.h"
#include "Unitclass.h"
class randGen
{
private:
	static int alien_counter;
	static int earth_counter;
	int N, Prob, ESpr, ETpr, EGpr, ASpr, AMpr, ADpr, Ep, Eh, Eac, Ap, Ah, Aac, A, B, e_minpower, e_maxpower, e_minhealth, e_maxhealth;
	int e_minac, e_maxac, a_minpower, a_maxpower, a_minhealth, a_maxhealth, a_minac, a_maxac;
	Game* game_ptr;

public:
	void setpwr(int ep1,int ep2,int ap1,int ap2);
	void sethealth(int eh1,int eh2, int ah1, int ah2);
	void setac(int eac1,int eac2, int aac1, int aac2);
	void setN(int n);
	void setpercentage(int e1,int e2,int e3,int a1, int a2, int a3);
	void setstatusearth(int& p, int& h, int& ac);
	void setstatusalien(int& p, int& h, int& ac);
	int random(int r);
	Unitclass* createunit();
	Unitclass* generateunitearth(int& t);
	Unitclass* generateunitalien(int& t);
};

