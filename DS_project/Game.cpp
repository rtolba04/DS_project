
#include "Game.h"
#include "Earthsoldiers.h"
#include <fstream>
#include <iostream>
#include "earthArmy.h"
#include "Alienarmy.h"
using namespace std;

int main()
{
	int N, Prob, ESpr, ETpr, EGpr, ASpr, AMpr, ADpr, A, B;
	A = rand() % 100 + 1;
	cout << "Random number between 1 and 100: " << A << endl;
	ifstream input("inputfile.txt");
	input >> N;
	input >> Prob;
	if (A <= Prob) {
		B = rand() % 100 + 1;
		//cout << "Random number between 1 and 100: " << B << endl;
		for (int i = 0; i < N; i++) {
			earthArmy EA1;
			Alienarmy AA1;
		}
	}
	input >> ESpr;
	input >> ETpr;
	input >> EGpr;
	input >> ASpr;
	input >> AMpr;
	input >> ADpr;


	input.close();
	cout << "Loading N from input file: " << N << endl;
	cout << "Loading Prob from input file: " << Prob << endl;
	cout << "Loading ESpr from input file: " << ESpr << endl;
	cout << "Loading ETpr from input file: " << ETpr << endl;
	cout << "Loading EGpr from input file: " << EGpr << endl;
	cout << "Loading ASpr from input file: " << ASpr << endl;
	cout << "Loading AMpr from input file: " << AMpr << endl;
	cout << "Loading ADpr from input file: " << ADpr << endl;

	return 0;
}




