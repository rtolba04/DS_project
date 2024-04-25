#pragma once
class Game
{private:
	
public:
	Game();
	randGen* getrand();
	earthArmy* getEA();
	alienArmy* getAA();
	bool loadfromfile();
	void PrintKilledList();

	void kill(Unitclass* unit);
	void test();
	//void testnew();
	~Game();
};

