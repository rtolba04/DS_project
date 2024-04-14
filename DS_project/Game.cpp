
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


Game::Game()
{
    time = 1;
    killed = new LinkedQueue<Unitclass*>;
}

randGen* Game::getrand()
{
    return &random;
}

earthArmy* Game::getEA()
{
    return &Earth;
}

alienArmy* Game::getAA()
{
    return &Alien;
}

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
	int N, Prob, ESpr, ETpr, EGpr, ASpr, AMpr, ADpr, Ep, Eh, Eac, Ap, Ah, Aac, e_minpower, e_maxpower, e_minhealth, e_maxhealth;
	int e_minac, e_maxac, a_minpower, a_maxpower, a_minhealth, a_maxhealth, a_minac, a_maxac;
        input >> N >> ESpr >> ETpr >> EGpr >> ASpr >> AMpr >> ADpr >> Prob >> e_minpower >> e_maxpower >> e_minhealth >> e_maxhealth;
        input >> e_minac >> e_maxac >> a_minpower >> a_maxpower >> a_minhealth >> a_maxhealth >> a_minac >> a_maxac;
        random.setN(N);
        random.setac(e_minac, e_maxac, a_minac, a_maxac);
        random.sethealth(e_minhealth, e_maxhealth, a_minhealth, a_maxhealth);
        random.setpwr(e_minpower, e_maxpower, a_minpower, a_maxpower);
        random.setpercentage(ESpr, ETpr, EGpr, ASpr, AMpr, ADpr);
        random.setProb(Prob);
        random.setstatusearth(Ep, Eh, Eac);
        random.setstatusalien(Ap, Ah, Aac);
        return true;
 
}

void Game::kill(Unitclass* u)
{
    killed->enqueue(u);
}

void Game::printKill()
{
    cout << "================ Killed Units ================ " << endl;
    cout << killed->getcount() << "units" << endl;
    killed->printqueue();
}
