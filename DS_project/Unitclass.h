#pragma once
#include <iostream>
#include "Game.h"
using namespace std;

class Unitclass
{
private:
	string Type;
	int ID;
	int Jointime;
	int Health;
	int Power;
	int Attackcapacity;
	Game* ptr;
public:
	Unitclass(int id, int h, int ac, int p, int jt, string type);
	void Settype(string type);
	void SetHealth(int h);
	void Setattackcapacity(int n);
	void Setjointime(int jt);
	void SetPower(int p);
	int GetHealth();
	void Getid();
	void SetID(int id);
	int Getjointime();
	int GetPower();
	string Gettype();
	int Getattackcapacity();
	virtual void attack() = 0;
	~Unitclass();

};


