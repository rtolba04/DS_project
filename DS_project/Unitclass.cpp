#include "Unitclass.h"
#include <iostream>
#include <sstream>
using namespace std;
Unitclass::Unitclass() {
	ID = 0;
	Jointime = 0;
	Health = 0;
	Power = 0;
	Attackcapacity = 0;
	Type = "army";
}
Unitclass::Unitclass(int id, int h, int ac, int p, int jt, string type) : ID(id), Health(h), Attackcapacity(ac), Power(p), Jointime(jt), Type(type)
{
}
void Unitclass::print() {
	cout << "the unit ID is : " << ID << "With the Health :" << Health << " Power :" << Power << "and attack capacity= " << Attackcapacity << endl;
	cout << "the join time of the unit is :" << Jointime << endl;
}
void attack() {
}
void Unitclass::Settype(string type) {
	Type = type;
}
string Unitclass::Gettype() {
	return Type;
}
void Unitclass::SetID(int id) {
}
int Unitclass::Getid() {
	return ID;
}
void Unitclass::SetHealth(int n) {
	if (n > 0 && n <= 100) {
		Health = n;
	}
}
void Unitclass::Setattackcapacity(int ac) {
	Attackcapacity = ac;
}
void Unitclass::Setjointime(int jt) {
	Jointime = jt;
}
void Unitclass::SetPower(int p) {
	Power = p;
}
int Unitclass::GetHealth() {
	return Health;
}
int Unitclass::Getjointime() {
	return Jointime;
}
int Unitclass::GetPower() {
	return Power;
}
int Unitclass::Getattackcapacity() {
	return Attackcapacity;
}
Unitclass::~Unitclass()
{
}
