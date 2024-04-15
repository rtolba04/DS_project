
#include "Game.h"
#include <fstream>
#include <iostream>

using namespace std;


Game::Game()
{
    loadfromfile();
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
        input.close();
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
   
    for (time; time < 51; time++)
    {
        cout << "Current Timestep " << time << endl;
        randomgen.generateunitalien(time);
        randomgen.generateunitearth(time);
        int x;
        x = rand() % 100 + 1;
        if (x >= 0 && x <= 10)
        {
            Earthsoldiers* es= nullptr;
            Earth.removeUnit(es,"ES");
            if (es) {
                Earth.addUnit(es);
            }
            }
        if (x > 10 && x <= 20)
        {
            Earthtanks* et = nullptr;
            Earth.removeUnit(et,"ET");
            if(et)
            kill(et);
        }
        if (x > 20 && x <= 30)
        {
            Earthgunnery* eg = nullptr;
            Earth.removeUnit(eg,"EG");
            if (eg) {
                int h = eg->GetHealth();
                h = h / 2;
                eg->SetHealth(h);

                Earth.addUnit(eg);
            }
           }
        if (x > 30 && x <= 40)
        {
            Aliensoldiers* a1 = nullptr, * a2 = nullptr, * a3 = nullptr, * a4 = nullptr, * a5 = nullptr;

            Alien.removeUnit(a1,"AS");
            if (a1) {
                int h1 = a1->GetHealth();
                h1 = h1 / 2;
                a1->SetHealth(h1);
                Alien.addUnit(a1);
            }
            Alien.removeUnit(a2,"AS");
            if (a2) {
                int h2 = a2->GetHealth();
                h2 = h2 / 2;
                a2->SetHealth(h2);
                Alien.addUnit(a2);
            }
            
            Alien.removeUnit(a3,"AS");
            if (a3) {
                int h3 = a3->GetHealth();
                h3 = h3 / 2;
                a3->SetHealth(h3);
                Alien.addUnit(a3);
            }
            Alien.removeUnit(a4,"AS");
            if (a4) {
                int h4 = a4->GetHealth();
                h4 = h4 / 2;
                a4->SetHealth(h4);
                Alien.addUnit(a4);
            }
            Alien.removeUnit(a5, "AS");
            if (a5) {
                int h5 = a5->GetHealth();
                h5 = h5 / 2;
                a5->SetHealth(h5);
                Alien.addUnit(a5);
            }
            }
        if (x > 40 && x <= 50)
        {
            Alienmonsters* am1 = nullptr, * am2 = nullptr, * am3 = nullptr, * am4 = nullptr, * am5 = nullptr;
            Alien.removeUnit(am1,"AM");
            Alien.removeUnit(am2, "AM");
            Alien.removeUnit(am3, "AM");
            Alien.removeUnit(am4, "AM");
            Alien.removeUnit(am5, "AM");
            if(am1)
            Alien.addUnit(am1);
            if(am2)
             Alien.addUnit(am2);
            if (am3) Alien.addUnit(am3);
            if (am4) Alien.addUnit(am4);
            if (am5) Alien.addUnit(am5);
        }
        if (x > 50 && x <= 60)
        {
            Aliendrones* ad1 = nullptr, * ad2 = nullptr, * ad3 = nullptr, * ad4 = nullptr, * ad5 = nullptr, * ad6 = nullptr;
            Alien.removeUnit(ad1, ad6);
            Alien.removeUnit(ad2, ad5);
            Alien.removeUnit(ad3, ad4);
            if(ad1) kill(ad1);
            if (ad2) kill(ad2);
            if (ad3) kill(ad3);
            if (ad4) kill(ad4);
            if (ad5) kill(ad5);
            if (ad6) kill(ad6);
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
