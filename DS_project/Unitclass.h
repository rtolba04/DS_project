#pragma once
#include <iostream>
class Game;
using namespace std;

class Unitclass
{
protected:
	string Type;
	int ID;
	int Jointime;
	int Health;
	int Power;
	int Attackcapacity;

	int ta; //time attacked
	int td;  //destruction time
	int df;  //first attack delay
	int dd;  //destruction delay
	int db;  //battle time


	Game* ptr; //needs a setter 

	
public:
	Unitclass(int id, int h, int ac, int p, int jt, string type);
	void Settype(string type);
	void SetHealth(int h);
	void Setattackcapacity(int n);
	void Setjointime(int jt);
	void SetPower(int p);
	int GetHealth();
	int Getid();
	void SetID(int id);
	int Getjointime();
	int GetPower();
	string Gettype();
	int Getattackcapacity();
	void print();
	void setgame(Game* ptr1);
	virtual void attack() = 0;


	void set_ta(int Ta);
	int get_ta();
	void set_td(int Td);
	int get_td();
	void set_df();
	int get_df();
	void set_dd();
	int get_dd();
	void set_db();
	int get_db();

	~Unitclass();
};


