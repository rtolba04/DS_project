
#include "Game.h"
#include "Earthsoldiers.h"
#include <fstream>
#include <iostream>
#include "earthArmy.h"
#include "Alienarmy.h"
#include "fstream"
#include "randGen.h"
#include "Randomgen.h"
using namespace std;


bool Game::loadfromfile() {
    ifstream input("inputfile.txt");
    if (!input) {
        cerr << "Error: Unable to open input file." << endl;
        return false; // Return error code
    }
    input.close();
    // Check if the read was successful
    if (input.fail()) {
        cerr << "Error: Failed to read range from input file." << endl;
        return false; // Return error code
    }
	int N, Prob, ESpr, ETpr, EGpr, ASpr, AMpr, ADpr, Ep, Eh, Eac, Ap, Ah, Aac, A, B, e_minpower, e_maxpower, e_minhealth, e_maxhealth;
	int e_minac, e_maxac, a_minpower, a_maxpower, a_minhealth, a_maxhealth, a_minac, a_maxac;
	input >> N >> ESpr >> ETpr >> EGpr >> ASpr >> AMpr >> ADpr >> Prob >> e_minpower >> e_maxpower >> e_minhealth >> e_maxhealth;
	input >> e_minac >> e_maxac >> a_minpower>> a_maxpower>> a_minhealth>> a_maxhealth>> a_minac>> a_maxac;





	return true;
}
