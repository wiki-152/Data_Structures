#pragma once

#include <iostream>

using namespace std;


class Employee
{
public:

	string name;
	int id;
	string department;
	string designation;

	Employee* next;
	Employee* previous;

	Employee();
};

class DoublyLinkedList
{
private:

	Employee* head;
	Employee* tail;

	int size;

public:

	DoublyLinkedList();
	void insertAtEnd(Employee * employee);
	Employee* showFront();
	void deleteHead();

};

class Queue
{
private:
	DoublyLinkedList* list;

public:

	Queue();
	void enqueue(Employee* employee);
	Employee* dequeue();
	Employee* showFront();
	bool isEmpty();

	void print();
};