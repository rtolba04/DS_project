#include "Unitclass.h"
#include <iostream>
#include <sstream>
using namespace std;
Unitclass::Unitclass(int id, int jt, int h, int p, int ac, string type)
{
	ID = id;
	Jointime = jt;
	Health = h;
	Power = p;
	Attackcapacity = ac;
	Type = type;
}
void Unitclass::attack() {
}
void Unitclass::set_ta(int Ta)
{
	ta = Ta;
}
int Unitclass::get_ta()
{
	return ta;
}
void Unitclass::set_td(int Td)
{
	td = Td;
}
int Unitclass::get_td()
{
	return td;
}
void Unitclass::set_df()
{
	df = ta - Jointime;
}
int Unitclass::get_df()
{
	return df;
}
void Unitclass::set_dd()
{
	dd = td - ta;
}
int Unitclass::get_dd()
{
	return dd;
}
void Unitclass::set_db()
{
	db = td - Jointime;
}
int Unitclass::get_db()
{
	return db;
}
Game* Unitclass::getgameptr()
{
	return ptr;
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

void Unitclass::print()
{
	cout <<"ID: "<< ID << endl;
	cout <<"Join time: "<< Jointime << endl;
	cout <<"Health: " << Health << endl;
	cout <<"Power: "<< Power<< endl;
	cout <<"Attack capacity: " <<  Attackcapacity<< endl;
	cout <<"Type: "<<  Type<< endl;


}

void Unitclass::setgame(Game* ptr1)
{
	ptr = ptr1;
}


Unitclass::~Unitclass()
{
}
