#pragma once

#include <iostream>

using namespace std;


class Node
{
public:
	int data;
	Node* next;
	Node* previous;

	Node();
};

class DoublyLinkedList
{
private:

	Node* head;
	Node* tail;



public:
	int size;
	DoublyLinkedList();
	void insertAtEnd(Node* obj);
	Node* showFront();
	void deleteHead();

};

class Queue
{
private:
	DoublyLinkedList* list;
	int size;

public:

	Queue();
	void enqueue(Node* Node);
	int dequeue();
	Node* showFront();
	bool isEmpty();

	void reverseTheQueue();

	void print();
};