#include "Earthsoldiers.h"
#include "Aliensoldiers.h"
#include "Game.h"
#include <iostream>
#include "alienArmy.h"
#include  "earthArmy.h"
using namespace std;

Earthsoldiers::Earthsoldiers(int id, int jt, int h, int p, int ac) :Unitclass(id, jt, h, p, ac,"ES")
{

}
void Earthsoldiers :: attack() {
//int damage= (unit1power*unit1health/100)/rootunithealth2
	LinkedQueue<Aliensoldiers*>* temp = nullptr;  // since earth soldiers only attack soldiers alien thentemp list doesnt  have to e unit class
	Earthsoldiers* Esoldierpicked;
	int ac1 = Getattackcapacity();
	while(ac1!=0){
		getea
		int oldsoldierhealth = Asoldierpicked->GetHealth();
		int Damage = ((Esoldierpicked->GetPower()) * (Esoldierpicked->GetHealth()) / 100) / sqrt(oldsoldierhealth);
		if (Damage < oldsoldierhealth) {
			Asoldierpicked->SetHealth(oldsoldierhealth - Damage);
			temp->enqueue(Asoldierpicked);
		}
		else{
			ptr->kill(Asoldierpicked);
		}
		ac1--;
	}

}