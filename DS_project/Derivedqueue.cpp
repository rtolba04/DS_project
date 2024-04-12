#include "Derivedqueue.h"
#include "LinkedQueue.h"
using namespace std;
#include <iostream>
template <typename T>

bool Derivedqueue<T>::Enqueuefront(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		backPtr = newNodePtr; // The queue is empty
	else
		newNodePtr->setNext(frontPtr);
		 // The queue was not empty

	frontPtr = newNodePtr; // New node is the last node now
	return true;
} // end enqueue

template <typename T>
bool Derivedqueue<T>::Dequeueback(T& backEntry)
{

	Node<T>* currPtr = frontPtr;
	Node<T>* prevPtr = nullptr;
	while (currentPtr->getNext() != nullptr) {
		previousPtr = currentPtr;
		currentPtr = currentPtr->getNext();
	}
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = backPtr;
	backEntry = backtPtr->getItem();
	backPtr = prevPtr;
		backptr->setNext(NULL);
	// Queue is not empty; remove back
	if (nodeToDeletePtr == frontPtr)	 // Special case: last node in the queue
		frontPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return true;
}