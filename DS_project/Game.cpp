#include "Game.h"
#include "Earthsoldiers.h"
#include "LinkedQueue.h"
#include "ArrayStack.h"
#include "Earthtanks.h"
#include "Earthgunnery.h"
#include "priQueue.h"
#include "earthArmy.h"

int main()
{
	earthArmy e1;
	Earthsoldiers* es1 = new Earthsoldiers(1, 2, 3, 4, 5);
	Earthsoldiers* es2 = new Earthsoldiers(2, 7, 3, 4, 5);
	Earthtanks* et1 = new Earthtanks(3, 2, 3, 4, 5);
	Earthtanks* et2 = new Earthtanks(4, 2, 3, 4, 5);
	Earthgunnery* eg1 = new Earthgunnery(5, 2, 3, 4, 5);
	Earthgunnery* eg2 = new Earthgunnery(6, 2, 7, 2, 5);



	e1.addUnit(es1);
	e1.addUnit(es2);
	e1.addUnit(et1);
	e1.addUnit(et2);

	e1.addUnit(eg1);
	e1.addUnit(eg2);

	e1.print();


}




