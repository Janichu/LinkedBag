//	LinkedBag340.cpp
//	Created by: CSC340
#include "LinkedBag.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
	Node<ItemType>* toDelete = headPtr->getNext();
	headPtr->setNext(toDelete->getNext());
	delete toDelete;
	toDelete = nullptr;
	itemCount--;
	return true;
}

template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry) {
	Node<ItemType>* toAdd = headPtr;
	while (toAdd->getNext() != nullptr) {
		toAdd = toAdd->getNext();
	}
	Node<ItemType>* newNext = new Node <ItemType>();
	newNext->setItem(newEntry);
	toAdd->setNext(newNext);
	itemCount++;
	return true;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
	if (headPtr == nullptr) return 0;
	int count = 1;
	Node<ItemType>* toCount = headPtr;
	while (toCount->getNext() != nullptr) {
		count++;
		toCount = toCount->getNext();
	}
	return count;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
	if (headPtr == nullptr) return 0;
	else return 1 + getCurrentSize340RecursiveHelper(headPtr);
}
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* nextNode) const {
	if (nextNode->getNext() == nullptr) return 0;
	else return 1 + getCurrentSize340RecursiveHelper(nextNode->getNext());
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
	if (headPtr == nullptr) return 0;
	static Node<ItemType>* nextNode;
	if (nextNode == nullptr) nextNode = headPtr;
	if (nextNode->getNext() == nullptr) return 1;
	else {
		nextNode = nextNode->getNext();
		return 1 + getCurrentSize340RecursiveNoHelper();
	}
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& anEntry) const {
	if (headPtr == nullptr) return 0;
	return getFrequencyOf340RecursiveHelper(headPtr,anEntry);
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* nextNode, const ItemType& anEntry) const {
	if (nextNode->getItem() == anEntry && nextNode->getNext() == nullptr) return 1;
	else if (nextNode->getItem() != anEntry && nextNode->getNext() == nullptr) return 0;
	else if (nextNode->getItem() == anEntry && nextNode->getNext() != nullptr) {
		return 1 + getFrequencyOf340RecursiveHelper(nextNode->getNext(), anEntry);
	}
	else return 0 + getFrequencyOf340RecursiveHelper(nextNode->getNext(), anEntry);
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& anEntry) const {
	if (headPtr == nullptr) return 0;
	static Node<ItemType>* nextNode = headPtr;
	//if (nextNode == nullptr) nextNode = headPtr;
	if (nextNode->getItem() == anEntry && nextNode->getNext() == nullptr) {
		nextNode = headPtr;
		return 1;
	}
	else if (nextNode->getItem() == anEntry && nextNode->getNext() != nullptr) {
		nextNode = nextNode->getNext();
		return 1 + getFrequencyOf340RecursiveNoHelper(anEntry);
	}
	else if (nextNode->getItem() != anEntry && nextNode->getNext() != nullptr) {
		nextNode = nextNode->getNext();
		return 0 + getFrequencyOf340RecursiveNoHelper(anEntry);
	}
	else {
		nextNode = headPtr;
		return 0;
	}
}

template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
	srand(static_cast<unsigned int>(time(NULL)));
	int random = rand() % itemCount + 1;
	Node<ItemType>* currentNode = headPtr;
	Node<ItemType>* prevNode = headPtr;
	while (random > 1) {
		prevNode = currentNode;
		currentNode = currentNode->getNext();
		random--;
	}
	if (currentNode == headPtr && itemCount > 1) {
		prevNode = prevNode->getNext();
		headPtr = prevNode;
	}
	else if (currentNode->getNext() == nullptr)prevNode->setNext(nullptr);
	else prevNode->setNext(currentNode->getNext());
	itemCount--;
	return currentNode->getItem();

}
template<typename ItemType>
void LinkedBag<ItemType>::removeLastThree(const ItemType& item) const {
	Node <ItemType>* temp = headPtr;
	Node <ItemType>* remove1 = nullptr;
	Node <ItemType>* remove2 = nullptr;
	Node <ItemType>* remove3 = nullptr;
	for (int i = 0; i < itemCount; i++) {
		if (temp->getItem() == item) {
			if (remove1 == nullptr) remove1 = temp;
			if (remove2 == nullptr) remove2 = temp;
			if (remove3 == nullptr) {
				remove1 = remove2;
				remove2 = remove3;
				remove3 = temp;
			}
		}
	}
	if (headPtr == remove1 || headPtr == remove2 || headPtr == remove3) {
		headPtr = headPtr->getNext();
		itemCount--;
	}
	temp = headPtr;
	Node<ItemType>* before = temp->getNext();
	for (int i = 1; i < itemCount; i++) {
		if (headPtr == remove1 || headPtr == remove2 || headPtr == remove3) {
			headPtr = headPtr->getNext();
			temp = headPtr;
		}
		else if (temp == remove1 || temp == remove2 || temp == remove3) {
			Node <ItemType>* next = temp.getNext();
		}
	}
}

