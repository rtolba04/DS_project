#include "Game.h"
#include "Aliensoldiers.h"
#include "Alienmonsters.h"
#include "LinkedQueue.h"
#include "ArrBag.h"
#include "Derivedqueue.h"
#include "ArrayStack.h"
#include "Aliendrones.h"
#include "alienArmy.h"
#include "priQueue.h"

int main()
{
	alienArmy a1;
	Aliensoldiers* as1 = new Aliensoldiers(5, 2, 3, 4, 5);
	Aliensoldiers* as2 = new Aliensoldiers(1, 4, 6, 1, 6);
	Alienmonsters* am1 = new Alienmonsters(3, 2, 3, 4, 5);
	Alienmonsters* am2 = new Alienmonsters(4, 2, 3, 4, 5);
	Aliendrones* ad1 = new Aliendrones(5, 2, 3, 4, 5);
	Aliendrones* ad2 = new Aliendrones(6, 2, 7, 2, 5);
	Aliendrones* ad3 = new Aliendrones(6, 2, 7, 2, 5);
	Aliensoldiers* as3 = new Aliensoldiers(1, 4, 6, 1, 6);
	Aliensoldiers* as4 = new Aliensoldiers(1, 4, 6, 1, 6);
	Aliensoldiers* as5 = new Aliensoldiers(1, 4, 6, 1, 6);
	a1.addUnit(as1);
	a1.addUnit(as2);
	a1.addUnit(as3);
	a1.addUnit(as4);
	a1.addUnit(as3);
	a1.addUnit(am1);
	a1.addUnit(am2);
	a1.addUnit(ad1);
	a1.addUnit(ad2);
	a1.addUnit(ad3);
	a1.removeUnit(ad1,ad2);


	a1.print();

}
/*#include "Game.h"
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




*/