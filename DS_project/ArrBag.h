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
	int ArrBag<T>::getIndex(const T& anEntry);
	bool remove(const T& anEntry);
};

#endif // !ARR_BAG
