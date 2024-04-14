
#include "Game.h"
#include "Earthsoldiers.h"
#include <fstream>
#include <iostream>
#include "earthArmy.h"
#include "Alienarmy.h"
using namespace std;

int main()
{// for one timestep
	int N, Prob, ESpr, ETpr, EGpr, ASpr, AMpr, ADpr,Ep,Eh,Ea,Ap,Ah,Ac, A, B,eminrangepower,emaxrangepower, eminrangehealth, emaxrangehealth;
	int eminrangeeac, emaxrangeac, aminrangepower, amaxrangepower,aminrangehealth, amaxrangehealth, aminrangeeac, amaxrangeac
	A = rand() % 100 + 1;
	cout << "Random number between 1 and 100: " << A << endl;
	ifstream input("inputfile.txt");
	input >> N;
	input >> ESpr;
	input >> ETpr;
	input >> EGpr;
	input >> ASpr;
	input >> AMpr;
	input >> ADpr;
	input >> Prob;
	input >> eminrangepower;
	input >> emaxrangepower;
	
	input >> eminrangehealth;
	input >> emaxrangehealth;
	
	input >> eminrangeeac;
	input >> emaxrangeac;
	
	input >> aminrangepower;
	input >> amaxrangepower;

	input >> aminrangehealth;
	input >> amaxrangehealth;
	
	input >> aminrangeeac;
	input >> amaxrangeac;
	

	if (A <= Prob) {
		B = rand() % 100 + 1;
		//cout << "Random number between 1 and 100: " << B << endl;
		for (int i = 0; i < N; i++) {
			earthArmy EA1;
			alienArmy AA1;
			Ep = rand() % (emaxrangepower - eminrangepower + 1) + eminrangepower;
			Eh = rand() % (emaxrangehealth - eminrangehealth + 1) + eminrangehealth;
			Ea = rand() % (emaxrangeac - eminrangeeac + 1) + eminrangeeac;
			Ap = rand() % (amaxrangepower - aminrangepower + 1) + aminrangepower;
			Ah = rand() % (amaxrangehealth - aminrangehealth + 1) + aminrangehealth;
			Ac = rand() % (amaxrangeac - aminrangeeac + 1) + aminrangeeac;
			EA1
		}
	}
	


	input.close();
	cout << "Loading N from input file: " << N << endl;
	cout << "Loading Prob from input file: " << Prob << endl;
	cout << "Loading ESpr from input file: " << ESpr << endl;
	cout << "Loading ETpr from input file: " << ETpr << endl;
	cout << "Loading EGpr from input file: " << EGpr << endl;
	cout << "Loading ASpr from input file: " << ASpr << endl;
	cout << "Loading AMpr from input file: " << AMpr << endl;
	cout << "Loading ADpr from input file: " << ADpr << endl;
	cout << "Loading health  of es from input file: " << Eh << endl;
	cout << "Loading power pf es from input file: " << Ep << endl;


	return 0;
}




