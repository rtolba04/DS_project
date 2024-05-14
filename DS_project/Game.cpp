
#include "Game.h"
#include <fstream>
#include <iostream>

using namespace std;


Game::Game()
{
    loadfromfile();
    time = 1;
    killed = new LinkedQueue<Unitclass*>;
    //temp = new LinkedQueue<Unitclass*>;
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

int Game::getTime()
{
    return time;
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
	int N, Prob, ESpr, ETpr, EGpr, HUpr, ASpr, AMpr, ADpr, Ep, Eh, Eac, Ap, Ah, Aac, e_minpower, e_maxpower, e_minhealth, e_maxhealth;
	int e_minac, e_maxac, a_minpower, a_maxpower, a_minhealth, a_maxhealth, a_minac, a_maxac;
        input >> N >> ESpr >> ETpr >> EGpr >> HUpr >> ASpr >> AMpr >> ADpr >> Prob >> e_minpower >> e_maxpower >> e_minhealth >> e_maxhealth;
        input >> e_minac >> e_maxac >> a_minpower >> a_maxpower >> a_minhealth >> a_maxhealth >> a_minac >> a_maxac;
        randomgen.setN(N);
        randomgen.setac(e_minac, e_maxac, a_minac, a_maxac);
        randomgen.sethealth(e_minhealth, e_maxhealth, a_minhealth, a_maxhealth);
        randomgen.setpwr(e_minpower, e_maxpower, a_minpower, a_maxpower);
        randomgen.setpercentage(ESpr, ETpr, EGpr,HUpr, ASpr, AMpr, ADpr);
        randomgen.setProb(Prob);
        randomgen.setstatusearth(Ep, Eh, Eac);
        randomgen.setstatusalien(Ap, Ah, Aac);
        input.close();
        return true;
       //
}

void Game::addHeal(Health* h)
{
    HLstack.push(h);
}

void Game::removeHeal(Health*& hu)
{
    HLstack.pop(hu);
}

void Game::addUMLtank(Earthtanks* et)
{
    UMLtanks.enqueue(et);
}

void Game::addUMLsold(Earthsoldiers* es, int pri)
{
    UMLsoldiers.enqueue(es,pri);
}

void Game::removeUMLsold(Earthsoldiers* es, int pri)
{
    UMLsoldiers.dequeue(es, pri);
}

void Game::removeUMLtank(Earthtanks* et)
{
    UMLtanks.dequeue(et);
}

void Game::printUMLtank()
{
    if (checkUMLtank())
        return;
    cout << "[";
    Node<Earthtanks*> *ptr = UMLtanks.getfrontPtr();

    while (ptr)
    {
        cout << ptr->getItem()->Getid() << ", ";
        ptr = ptr->getNext();
    }
    cout << "]";
}

bool Game::checkUMLsold()
{
    return UMLsoldiers.isEmpty();
}

bool Game::checkUMLtank()
{
    return UMLtanks.isEmpty();
}

Earthsoldiers* Game::UMLsoldHead()
{
    int pri;
    return UMLsoldiers.getHead()->getItem(pri);
}

Earthtanks* Game::UMLtankHead()
{
    return UMLtanks.getfrontPtr()->getItem();
}



void Game::kill(Unitclass* unit)
{
    killed->enqueue(unit);
}

void Game::PrintKilledList() {
    cout << "=======================killed/destructed units=================" << endl;
    cout << killed->getcount() << " units ";

    if (killed->isEmpty())
        return;
    cout << "[";
    Node<Unitclass*>* ptr = killed->getfrontPtr();

    while (ptr)
    {
        if (ptr->getNext() == nullptr) {
            cout << ptr->getItem()->Getid();
            ptr = ptr->getNext();
        }
        else {
            cout << ptr->getItem()->Getid() << ", ";
            ptr = ptr->getNext();
        }
    }
    cout << "]" << endl;
}

void Game::printscreen()
{
    cout << "Current Timestep " << time << endl;
    getAA()->print();
    getEA()->print();
    //units fighting
    PrintKilledList();
    cout << "=======================Healing units=================" << endl;
    cout << HLstack.getcount() << " units";
    HLstack.printstack();
    cout << endl;
    cout << "=======================UML for earth soldiers=================" << endl;
    cout << UMLsoldiers.getcount() << " units";
    UMLsoldiers.printpri();
    cout << endl;
    cout << "=======================UML for earth tanks=================" << endl;
    cout << UMLtanks.getcount() << " units";
    printUMLtank();
    cout << endl;
    cout << "Press enter to move to next timestep" << endl;
}

void Game::simulate()
{
    
  
    for (time; time < 25; time++)
    {
        loadfromfile();        
        getrand()->createunits(time);    
       //if(!Earth.getEGpriqueue().isEmpty()|| !Earth.getESqueue().isEmpty()|| !Earth.getETstack().isEmpty())
       Earth.attack();

      // if (!Alien.getADqueue().isEmpty() || !Alien.getAMarray().isEmpty() || !Alien.getASqueue().isEmpty())
         Alien.attack();
         printscreen();
       //Earth.print();
       //Alien.print();
       //
       //PrintKilledList();
    }
}



Game::~Game()
{
    delete killed;
}

//    int x;
    //    x = rand() % 100 + 1;
    //    if (x >= 0 && x <= 10)
    //    {
    //        Earthsoldiers* es= nullptr;
    //        
    //        Earth.ES_remove(es);
    //        if (es) {
    //            Earth.addUnit(es);
    //        }
    //        }
    //    if (x > 10 && x <= 20)
    //    {
    //        Earthtanks* et = nullptr;
    //      
    //        Earth.ET_remove(et);
    //        if(et)
    //        kill(et);
    //    }
    //    if (x > 20 && x <= 30)
    //    {
    //        Earthgunnery* eg = new Earthgunnery();
    //        int pri = eg->getpri();
    //        Earth.EG_remove(eg,pri);
    //        if (eg) {
    //            int h = eg->GetHealth();
    //            h = h / 2;
    //            eg->SetHealth(h);

    //            Earth.addUnit(eg);
    //        }
    //       }
    //    if (x > 30 && x <= 40)
    //    {
    //        Aliensoldiers* a1 = nullptr, * a2 = nullptr, * a3 = nullptr, * a4 = nullptr, * a5 = nullptr;
    //   /*     Unitclass* u1 = nullptr;
    //        Unitclass* u2= nullptr;
    //        Unitclass* u3 = nullptr;
    //        Unitclass* u4 = nullptr;
    //        Unitclass* u5 = nullptr;

    //        a1 = dynamic_cast<Aliensoldiers*>(u1);
    //        a2 = dynamic_cast<Aliensoldiers*>(u2);
    //        a3 = dynamic_cast<Aliensoldiers*>(u3);
    //        a4 = dynamic_cast<Aliensoldiers*>(u4);
    //        a5 = dynamic_cast<Aliensoldiers*>(u5);*/
    //        Alien.AS_remove(a1);
    //        if (a1) {
    //            int h1 = a1->GetHealth();
    //            h1 = h1 / 2;
    //            a1->SetHealth(h1);
    //            Alien.addUnit(a1);
    //        }
    //        Alien.AS_remove(a2);
    //        if (a2) {
    //            int h2 = a2->GetHealth();
    //            h2 = h2 / 2;
    //            a2->SetHealth(h2);
    //            Alien.addUnit(a2);
    //        }
    //        
    //        Alien.AS_remove(a3);
    //        if (a3) {
    //            int h3 = a3->GetHealth();
    //            h3 = h3 / 2;
    //            a3->SetHealth(h3);
    //            Alien.addUnit(a3);
    //        }
    //        Alien.AS_remove(a4);
    //        if (a4) {
    //            int h4 = a4->GetHealth();
    //            h4 = h4 / 2;
    //            a4->SetHealth(h4);
    //            Alien.addUnit(a4);
    //        }
    //        Alien.AS_remove(a5);
    //        if (a5) {
    //            int h5 = a5->GetHealth();
    //            h5 = h5 / 2;
    //            a5->SetHealth(h5);
    //            Alien.addUnit(a5);
    //        }
    //        }
    //    if (x > 40 && x <= 50)
    //    {
    //        Alienmonsters* am1 = nullptr, * am2 = nullptr, * am3 = nullptr, * am4 = nullptr, * am5 = nullptr;
    //    /*    Unitclass* u1 = nullptr;
    //        Unitclass* u2 = nullptr;
    //        Unitclass* u3 = nullptr;
    //        Unitclass* u4 = nullptr;
    //        Unitclass* u5 = nullptr;

    //        am1 = dynamic_cast<Alienmonsters*>(u1);
    //        am2 = dynamic_cast<Alienmonsters*>(u2);
    //        am3 = dynamic_cast<Alienmonsters*>(u3);
    //        am4 = dynamic_cast<Alienmonsters*>(u4);
    //        am5 = dynamic_cast<Alienmonsters*>(u5);

    //        Alien.removeUnit(u1,"AM");
    //        Alien.removeUnit(u2, "AM");
    //        Alien.removeUnit(u3, "AM");
    //        Alien.removeUnit(u4, "AM");
    //        Alien.removeUnit(u5, "AM");*/
    //        Alien.AM_remove(am1);
    //        Alien.AM_remove(am2);
    //        Alien.AM_remove(am3);
    //        Alien.AM_remove(am4);
    //        Alien.AM_remove(am5);
    //        if(am1)
    //        Alien.addUnit(am1);
    //        if(am2)
    //         Alien.addUnit(am2);
    //        if (am3) Alien.addUnit(am3);
    //        if (am4) Alien.addUnit(am4);
    //        if (am5) Alien.addUnit(am5);
    //    }
    //    if (x > 50 && x <= 60)
    //    {
    //        Aliendrones* ad1 = nullptr, * ad2 = nullptr, * ad3 = nullptr, * ad4 = nullptr, * ad5 = nullptr, * ad6 = nullptr;
    //     /*   Unitclass* u1 = nullptr;
    //        Unitclass* u2= nullptr;
    //        Unitclass* u3 = nullptr;
    //        Unitclass* u4 = nullptr;
    //        Unitclass* u5 = nullptr;
    //        Unitclass* u6 = nullptr;
    //        ad1 = dynamic_cast<Aliendrones*>(u1);
    //        ad2 = dynamic_cast<Aliendrones*>(u2);
    //        ad3 = dynamic_cast<Aliendrones*>(u3);
    //        ad4 = dynamic_cast<Aliendrones*>(u4);
    //        ad5 = dynamic_cast<Aliendrones*>(u5);
    //        ad6 = dynamic_cast<Aliendrones*>(u6);

    //        Alien.removeUnit(u1, u6);
    //        Alien.removeUnit(u2, u5);
    //        Alien.removeUnit(u3, u4);*/
    //        Alien.AD_remove(ad1,ad6);
    //        Alien.AD_remove(ad2,ad5);
    //        Alien.AD_remove(ad3,ad4);
    //        if(ad1) kill(ad1);
    //        if (ad2) kill(ad2);
    //        if (ad3) kill(ad3);
    //        if (ad4) kill(ad4);
    //        if (ad5) kill(ad5);
    //        if (ad6) kill(ad6);
    //    }
    //    