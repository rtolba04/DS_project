#include<conio.h>
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

void Game::savetofile(const string& filename)
{
    ofstream outFile(filename);
    if (!outFile.is_open())
    {
        cerr<<"Error: Unable to open input file." << endl;
        return;
    }
    outFile << "Td    " << "ID      " << "Tj      " << "Df    " << "Dd    " << "Db      " << endl;
    Node<Unitclass*>* ptr = killed->getfrontPtr();
    float Earthtotal, Alientotal, ES_killed = 0, ET_killed = 0, EG_killed = 0, AS_killed = 0, AM_killed = 0, AD_killed = 0, earthkilled = 0, alienkilled = 0,
        EtotDf = 0, EtotDd = 0, EtotDb = 0, AtotDf = 0, AtotDd = 0, AtotDb = 0;
    while (ptr)
    {
        outFile << ptr->getItem()->get_td() << "    " << ptr->getItem()->Getid() << "      " << ptr->getItem()->Getjointime() << "      " 
            << ptr->getItem()->get_df() << "    " << ptr->getItem()->get_dd() << "    " << ptr->getItem()->get_db() << endl;
        if (ptr->getItem()->Gettype() == "ES" || ptr->getItem()->Gettype() == "ET" || ptr->getItem()->Gettype() == "EG")
        {
            earthkilled++;
            EtotDf = EtotDf + ptr->getItem()->get_df();
            EtotDd = EtotDd + ptr->getItem()->get_dd();
            EtotDb = EtotDb + ptr->getItem()->get_db();
            if (ptr->getItem()->Gettype() == "ES")
                ES_killed++;
            else if (ptr->getItem()->Gettype() == "ET")
            {
                ET_killed++;
            }
            else if (ptr->getItem()->Gettype() == "EG")
            {
                EG_killed++;
            }
        }
        else
        {
            alienkilled++;
            AtotDf = AtotDf + ptr->getItem()->get_df();
            AtotDd = AtotDd + ptr->getItem()->get_dd();
            AtotDb = AtotDb + ptr->getItem()->get_db();
            if (ptr->getItem()->Gettype() == "AS")
                AS_killed++;
            else if (ptr->getItem()->Gettype() == "AM")
            {
                AM_killed++;
            }
            else if (ptr->getItem()->Gettype() == "AD")
            {
                AD_killed++;
            }

        }
        ptr = ptr->getNext();
    }
    Earthtotal = getEA()->getESqueue().getcount() + ES_killed + getEA()->getETstack().getcount() + ET_killed + getEA()->getEGpriqueue().getcount() + EG_killed;
    Alientotal = getAA()->getASqueue().getcount() + AS_killed + getAA()->getAMarray().getCount() + AM_killed + getAA()->getADqueue().getcount() + AD_killed;

    outFile << "Battle result: " << status << endl;
    outFile << "For Earth army:" << endl;
    outFile << "Total ES: " << getEA()->getESqueue().getcount() + ES_killed << endl;
    outFile << "Total ET: " << getEA()->getETstack().getcount() + ET_killed << endl;
    outFile << "Total EG: " << getEA()->getEGpriqueue().getcount() + EG_killed << endl;
    outFile << "Percentage of killed ES to ES total: " << ES_killed / getEA()->getESqueue().getcount() + ES_killed << endl;
    outFile << "Percentage of killed ET to ET total: " << ET_killed / getEA()->getETstack().getcount() + ET_killed << endl;
    outFile << "Percentage of killed EG to EG total: " << EG_killed / getEA()->getEGpriqueue().getcount() + EG_killed << endl;
    outFile << "Percentage of total killed to total units" << earthkilled / Earthtotal << endl;
    outFile << "Average Df: " << EtotDf / earthkilled << endl;
    outFile << "Average Dd: " << EtotDd / earthkilled << endl;
    outFile << "Average Db: " << EtotDb / earthkilled << endl;
    outFile << "Df/Db % = " << EtotDf / EtotDb << "%" << endl;
    outFile << "Dd/Db % = " << EtotDd / EtotDb << "%" << endl << endl;

    outFile << "For Alien army:" << endl;
    outFile << "Total AS: " << getAA()->getASqueue().getcount() + AS_killed << endl;
    outFile << "Total AM: " << getAA()->getAMarray().getCount() + AM_killed << endl;
    outFile << "Total EG: " << getAA()->getADqueue().getcount() + AD_killed << endl;
    outFile << "Percentage of killed AS to AS total: " << AS_killed / getAA()->getASqueue().getcount() + AS_killed << endl;
    outFile << "Percentage of killed AM to AM total: " << ET_killed / getAA()->getAMarray().getCount() + AM_killed << endl;
    outFile << "Percentage of killed AD to AD total: " << EG_killed / getAA()->getADqueue().getcount() + AD_killed << endl;
    outFile << "Percentage of total killed to total units" << alienkilled / Alientotal << endl;
    outFile << "Average Df: " << AtotDf / alienkilled << endl;
    outFile << "Average Dd: " << AtotDd / alienkilled << endl;
    outFile << "Average Db: " << AtotDb / alienkilled << endl;
    outFile << "Df/Db % = " << AtotDf / AtotDb << "%" << endl;
    outFile << "Dd/Db % = " << AtotDd / AtotDb << "%" << endl << endl;


    outFile.close();
}

void Game::addHeal(Health* h)
{
    HLstack.push(h);
}

void Game::removeHeal(Health* &hu)
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

void Game::removeUMLsold(Earthsoldiers*& es, int &pri)
{
    UMLsoldiers.dequeue(es, pri);
}

void Game::removeUMLtank(Earthtanks* &et)
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
    getEA()->print();
    cout << endl;
    getAA()->print();
    cout << endl;
    //units fighting
    PrintKilledList();
    cout << endl;
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
    cout << endl;
}

ArrayStack<Health*>& Game::getHLstack()
{
    return HLstack;
}

void Game::simulate()
{
    cout << "Press 1 for silent mode or 2 for interactive mode" << endl;
    char mode;
    while (true) 
    {
        mode = _getch();
        if (mode == '1' || mode == '2') 
        {
            break;
        }
    }
    if (mode == '1') //silent mode
    {
        cout << "Silent Mode" << endl << "Simulation Starts..." << endl;
        while (time)
        {
            loadfromfile();
            getrand()->createunits(time);
            Earth.attack();
            Alien.attack();
            time++;
            if (time > 50)
            {
                if (Earth.getEGpriqueue().isEmpty() && Earth.getESqueue().isEmpty() && Earth.getETstack().isEmpty())
                {
                    status = "Earth Army Lost :(";
                    break;
                }
                else if (Alien.getADqueue().isEmpty() && Alien.getAMarray().isEmpty() && Alien.getASqueue().isEmpty())
                {
                    status = "Earth Army Won!";
                    break;
                }
            }
            if (time > 500)
            {
                status = "Draw";
                break;
            }
        }
        cout << "Enter the name of the output file.";
        string filename;
        cin >> filename;

        savetofile(filename);

        cout << "Simulation ends, Output file is created";
    }
    else if (mode == '2') //interactive mode
    {
        while (time)
        {
            loadfromfile();
            getrand()->createunits(time);    
            Earth.attack();
            Alien.attack();

            printscreen();
            while (_getch() != 13);
            time++;
            if (time > 50)
            {
                if (Earth.getEGpriqueue().isEmpty() && Earth.getESqueue().isEmpty() && Earth.getETstack().isEmpty())
                {
                    status = "Earth Army Lost :(";
                    break;
                }
                else if (Alien.getADqueue().isEmpty() && Alien.getAMarray().isEmpty() && Alien.getASqueue().isEmpty())
                {
                    status = "Earth Army Won!";
                    break;
                }
            }
            if (time > 500)
            {
                status = "Draw";
                break;
            }
        }
        cout << "Enter the name of the output file.";
        string filename;
        cin >> filename;

        savetofile(filename);
        cout << "Simulation ends, Output file is created";
    }
// for (time; time < 50; time++)
//    {
//        loadfromfile();        
//        getrand()->createunits(time);    
//       //if(!Earth.getEGpriqueue().isEmpty()|| !Earth.getESqueue().isEmpty()|| !Earth.getETstack().isEmpty())
//       Earth.attack();
//
//      // if (!Alien.getADqueue().isEmpty() || !Alien.getAMarray().isEmpty() || !Alien.getASqueue().isEmpty())
//         Alien.attack();
//         printscreen();
//       //Earth.print();
//       //Alien.print();
//       //
//       //PrintKilledList();
//    }
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