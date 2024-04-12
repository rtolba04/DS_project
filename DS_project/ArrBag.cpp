#include "ArrBag.h"
template<class T>
inline ArrBag<T>::ArrBag()
{
	count = 0;
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


