#pragma once
#include "LinkedQueue.h"
template <typename T>
class Derivedqueue :  public LinkedQueue<T>
{
private:

public:

	bool Enqueuefront(const T& newEntry);

	bool Dequeueback(T& backEntry);

};
