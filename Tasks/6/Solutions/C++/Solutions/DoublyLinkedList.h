#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

// Circular Doubly Linked List

class doublyLinkedList
{
public:
	Node* head;
	Node* tail;
	doublyLinkedList();

	void print();
	
	void insertNodeAtEnd(int data);
	void insertNodeAtStart(int data);
	void insertNodeBefore(int data,int position);
	void insertNodeAfter(int data, int position);
	
	void deleteFirstNode();
	void deleteMiddleNode();
	void deleteLastNode();
	void deleteSpecificNode(int position);

	void bubbleSort();
	
};
