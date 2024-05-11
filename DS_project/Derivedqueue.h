#pragma once
#include "LinkedQueue.h"
#include "QueueADT.h"
#include "Derivedqueue.h"


using namespace std;
#include <iostream>
template <typename T>
class Derivedqueue :  public LinkedQueue<T>
{
private:
	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	bool isEmpty() const;
	bool Enqueuefront(const T& newEntry);
	void printqueue();
	bool Dequeueback(T& backEntry);
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peekback(T& backEntry);
	int getcount();
};

template<typename T>
bool Derivedqueue<T>::peekback(T& backEntry)
{

	if (isEmpty())
		return false;

	backEntry = backPtr->getItem();
	return true;

}
template <typename T>
int Derivedqueue<T>::getcount()
{
	int count = 0;
	if (isEmpty())
		return count;

	Node<T>* ptr = frontPtr;


	while (ptr)
	{

		count++;
		ptr = ptr->getNext();

	}
	return count;
}
template <typename T>
void Derivedqueue<T>::printqueue()
{

	if (isEmpty())
		return;
	cout << "[";
	Node<T>* ptr = frontPtr;

	while (ptr)
	{
		cout << ptr->getItem() << ", ";
		ptr = ptr->getNext();
	}
	cout << "]";

}
template <typename T>
bool Derivedqueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

template <typename T>

bool Derivedqueue<T>::Enqueuefront(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (this->isEmpty())	//special case if this is the first node to insert
		this->backPtr = newNodePtr; // The queue is empty
	else
		newNodePtr->setNext(this->frontPtr);
	// The queue was not empty

	this->frontPtr = newNodePtr; // New node is the last node now
	return true;
} // end enqueue

template <typename T>
bool Derivedqueue<T>::Dequeueback(T& backEntry)
{
	if (this->isEmpty())
		return false;

	Node<T>* currPtr = this->frontPtr;
	Node<T>* prevPtr = nullptr;
	while (currPtr->getNext() != nullptr) {
		prevPtr = currPtr;
		currPtr = currPtr->getNext();
	}

	backEntry = currPtr->getItem();

	this->backPtr = prevPtr;

	if (prevPtr == nullptr)
		this->frontPtr = nullptr; 
	delete currPtr;

	if (prevPtr != nullptr)
		prevPtr->setNext(nullptr);

	return true;
}
template <typename T>
bool Derivedqueue<T>::enqueue(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty

	backPtr = newNodePtr; // New node is the last node now
	return true;
} // end enqueue


template <typename T>
bool Derivedqueue<T>:: dequeue(T& frntEntry)  
{
	if(isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr ;	
		
	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return true;
}
