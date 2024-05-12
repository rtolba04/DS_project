#include <ostream>
#include<iostream>
using namespace std;
#ifndef ARR_BAG
#define ARR_BAG
#define MAX_COUNT 1000
template<class T>
class ArrBag
{
private:
	T items[MAX_COUNT];
	int count;
public:
	ArrBag();
	bool isEmpty()const;
	bool add(const T& newEntry);
	int getIndex(const T& anEntry);
	int getCount();
	bool remove(const T& anEntry);
	void printarr();
	T getelement(int index);
};

#include "ArrBag.h"
using namespace std;
#include <iostream>

template<class T>
ArrBag<T>::ArrBag() {
	count = 0;
}
template<class T>
int ArrBag<T>::getCount() {
	return count;

};

template<class T>
T ArrBag<T>::getelement(int index)
{
	return items[index];
}


template<class T>
void ArrBag<T>::printarr() {
	cout << "[";
	for (int i = 0; i < count; i++) {
		cout << items[i] ;
		cout << ", ";
	}
	cout << "]";
}

template<class T>
int ArrBag<T>::getIndex(const T& anEntry)
{
	bool found = false;
	int result = -1;
	int searchindex = 0;
	while (!found && (searchindex < count))
	{
		if (items[searchindex] == anEntry)
		{
			found = true;
			result = searchindex;
		}
		else
		{
			searchindex++;
		}
	}
	return result;
}
template<class T>
bool ArrBag<T>::add(const T& newEntry)
{
	if (count < MAX_COUNT)
	{
		items[count] = newEntry;
		count++;
		return true;
	}
	return false;
}

template<class T>
bool ArrBag<T>::isEmpty() const
{
	return count == 0;
}

template<class T>
bool ArrBag<T>::remove(const T& anEntry)
{
	int location = getIndex(anEntry);
	bool canRemove = !isEmpty() && (location > -1);
	if (canRemove)
	{
		count--;
		items[location] = items[count];
	}
	return canRemove;
}


template<class T>
inline ostream& operator<< (ostream& out, const ArrBag<T> *AB) {
	for (int i = 0; i < AB.getCount(); i++) {
		out << AB.items[i] << " "; // Assuming items is a public member of ArrBag containing the elements
	}
	return out;
}
#endif // !ARR_BAG
