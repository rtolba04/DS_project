
#include "Game.h"
#include <fstream>
#include <iostream>
#include "earthArmy.h"
#include "Alienarmy.h"
#include "randGen.h"
using namespace std;


Game::Game()
{
    time = 1;
    killed = new LinkedQueue<Unitclass*>;
    temp = new LinkedQueue<Unitclass*>;
}

randGen* Game::getrand()
{
    return &randomgen;
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
        randomgen.setN(N);
        randomgen.setac(e_minac, e_maxac, a_minac, a_maxac);
        randomgen.sethealth(e_minhealth, e_maxhealth, a_minhealth, a_maxhealth);
        randomgen.setpwr(e_minpower, e_maxpower, a_minpower, a_maxpower);
        randomgen.setpercentage(ESpr, ETpr, EGpr, ASpr, AMpr, ADpr);
        randomgen.setProb(Prob);
        randomgen.setstatusearth(Ep, Eh, Eac);
        randomgen.setstatusalien(Ap, Ah, Aac);
        return true;
 
}

void Game::kill(Unitclass* unit)
{
    killed->enqueue(unit);
}

void Game::printKill()
{
    cout << killed->getcount() << "units" << endl;
    killed->printqueue();
}

void Game::test()
{
    Game();
    loadfromfile();
    for (time; time < 51; time++)
    {
        cout << "Current Timestep " << time << endl;
        randomgen.generateunitalien(time);
        randomgen.generateunitearth(time);
        int x;
        x = rand() % 100 + 1;
        if (x >= 0 && x <= 10)
        {
            Earthsoldiers* es;
            Earth.removeUnit(es);
            Earth.addUnit(es);
        }
        if (x > 10 && x <= 20)
        {
            Earthtanks* et;
            Earth.removeUnit(et);
            kill(et);
        }
        if (x > 20 && x <= 30)
        {
            Earthgunnery* eg;
            Earth.removeUnit(eg);
            int h = eg->GetHealth();
            h = h / 2;
            eg->SetHealth(h);
            Earth.addUnit(eg);
        }
        if (x > 30 && x <= 40)
        {
            Aliensoldiers* a1, * a2, * a3, * a4, * a5;

            Alien.removeUnit(a1);
            int h1 = a1->GetHealth();
            h1 = h1 / 2;
            a1->SetHealth(h1);
            Alien.addUnit(a1);

            Alien.removeUnit(a2);
            int h2 = a2->GetHealth();
            h2 = h2 / 2;
            a2->SetHealth(h2);
            Alien.addUnit(a2);

            Alien.removeUnit(a3);
            int h3 = a3->GetHealth();
            h3 = h3 / 2;
            a3->SetHealth(h3);
            Alien.addUnit(a3);

            Alien.removeUnit(a4);
            int h4 = a4->GetHealth();
            h4 = h4 / 2;
            a4->SetHealth(h4);
            Alien.addUnit(a4);

            Alien.removeUnit(a5);
            int h5 = a5->GetHealth();
            h5 = h5 / 2;
            a5->SetHealth(h5);
            Alien.addUnit(a5);
        }
        if (x > 40 && x <= 50)
        {
            Alienmonsters* a1, * a2, * a3, * a4, * a5;
            Alien.removeUnit(a1);
            Alien.removeUnit(a2);
            Alien.removeUnit(a3);
            Alien.removeUnit(a4);
            Alien.removeUnit(a5);
            Alien.addUnit(a1);
            Alien.addUnit(a2);
            Alien.addUnit(a3);
            Alien.addUnit(a4);
            Alien.addUnit(a5);
        }
        if (x > 50 && x <= 60)
        {
            Aliendrones* a1, * a2, * a3, * a4, * a5, * a6;
            Alien.removeUnit(a1, a6);
            Alien.removeUnit(a2, a5);
            Alien.removeUnit(a3, a4);
            kill(a1);
            kill(a2);
            kill(a3);
            kill(a4);
            kill(a5);
            kill(a6);
        }
        cout << "=========== Earth Army Alive Units ===========" << endl;
        Earth.print();
        cout << "=========== Alien Army Alive Units ===========" << endl;
        Alien.print();
        cout << "=========== Killed/Destructed Units ===========" << endl;
        printKill();
    }
}

Game::~Game()
{
    delete killed;
}
