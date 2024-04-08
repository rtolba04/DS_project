#include "Unitclass.h"
#include <iostream>
#include <sstream>
using namespace std;

Unitclass::Unitclass(int id, int h, int ac, int p, int jt, string type)
{
	ID = id;
	Jointime = h;
	Health = ac;
	Power = p;
	Attackcapacity = ac;
	Type = type;
}
void attack() {
}
void Unitclass::SetID(int id) {
	ID=id;
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
