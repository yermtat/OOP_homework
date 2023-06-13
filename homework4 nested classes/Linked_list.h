#pragma once

#include<iostream>

using namespace std;


//template <class T1>
//class Node;

template <class T>
class LinkedList
{

public:

	template <class T>
	class Node
	{
	public:
		T value;
		Node* next;

		Node(const T& value) : value(value), next(nullptr) {}

		void print() const
		{
			cout << value;
		}
	};

	Node<T>* head;
	LinkedList() : head{ nullptr } {}

	void add(const T& value);
	void remove();
	Node<T>* find(const T& value) const {
			for (Node<T>* nodePtr = head; nodePtr != nullptr; nodePtr = nodePtr->next)
			{
				if (nodePtr->value == value) {
					return nodePtr;
				}
			}

			return nullptr;
	}
	Node<T>* addAfter(const T& value, Node<T>* afterPtr)
	{
			if (afterPtr == nullptr) return nullptr;

			Node<T>* nodePtr = new Node<T>(value);
			nodePtr->next = afterPtr->next;
			afterPtr->next = nodePtr;
			return afterPtr->next;
	}
	Node<T>* removeAfter(Node<T> afterPtr)
	{

		if (afterPtr != nullptr && afterPtr->next != nullptr)
		{
			Node<T>* nodePtr = afterPtr->next;
			afterPtr->next = afterPtr->next->next;
			delete nodePtr;
		}

		return afterPtr;
	}
	void clear();
	void doForEach(void(*func)(Node<T>* nodePtr));
	static void printNode(Node<T>* nodePtr)
	{
		nodePtr->print();
		cout << " -> ";
	}

	void print() {
		cout << " -> ";
		doForEach(printNode);
		cout << '\n';

	}

};


template <class T>
void LinkedList<T>::add(const T& value)
{
	Node<T>* nodePtr = new Node<T>(value);
	nodePtr->next = head;
	head = nodePtr;
}

template <class T>
void LinkedList<T>::remove()
{
	if (head != nullptr)
	{
		Node<T>* nodePtr = head;
		head = head->next;
		delete nodePtr;
	}
}


//template <class T>
//LinkedList<T>::Node<T>* LinkedList<T>::find(const T& value) const
//{
//	for (Node<T>* nodePtr = head; nodePtr != nullptr; nodePtr = nodePtr->next)
//	{
//		if (nodePtr->value == value) {
//			return nodePtr;
//		}
//	}
//
//	return nullptr;
//}

//template <class T>
//LinkedList<T>::Node<T>* LinkedList<T>::addAfter(const T& value, Node<T>* afterPtr)
//{
//	if (afterPtr == nullptr) return nullptr;
//
//	Node<T>* nodePtr = new Node<T>(value);
//	nodePtr->next = afterPtr->next;
//	afterPtr->next = nodePtr;
//	return afterPtr->next;
//}

//template <class T>
//LinkedList<T>::Node<T>* LinkedList<T>::removeAfter(Node<T> afterPtr)
//{
//	if (afterPtr != nullptr && afterPtr->next != nullptr)
//	{
//		Node<T>* nodePtr = afterPtr->next;
//		afterPtr->next = afterPtr->next->next;
//		delete nodePtr;
//	}
//
//	return afterPtr;
//}

template <class T>
void LinkedList<T>::clear()
{
	while (head != nullptr) remove();
}

template <class T>
void LinkedList<T>::doForEach(void(*func)(Node<T>* nodePtr))
{
	for (Node<T>* nodePtr = head; nodePtr != nullptr; nodePtr = nodePtr->next)
	{
		func(nodePtr);
	}
}
