// i222469_Lab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "Header.h"

using namespace std;

// Employee Represents a single employee


Employee::Employee()
{
	name = "";
	id = 0;
	department = "";
	designation = "";
}




DoublyLinkedList::DoublyLinkedList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

void DoublyLinkedList::insertAtEnd(Employee* employee)
{
	if (head == NULL)
	{
		head = employee;
		tail = employee;
	}
	else
	{
		tail->next = employee;
		employee->previous = tail;
		tail = employee;
	}
	size++;
}

Employee* DoublyLinkedList::showFront()
{
	return head;
}

void DoublyLinkedList::deleteHead()
{
	// Only Delete Head Node and keep rest list
	cout << "Deleting Head" << endl;
	if (head == NULL)
	{
		cout << "List is Empty" << endl;
	}
	else
	{
		Employee * temp = head;
		head = head->next;
		delete temp;
	}

}



Queue::Queue()
{
	list = new DoublyLinkedList();
}

void Queue::enqueue(Employee* employee)
{
	list->insertAtEnd(employee);
}

Employee* Queue::dequeue()
{
	Employee * employee = list->showFront();
	list->deleteHead();
	return employee;
}

Employee* Queue::showFront()
{
	return list->showFront();
}

bool Queue::isEmpty()
{
	if (list->showFront() == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Queue::print()
{
	Employee * temp = list->showFront();
	while (temp != NULL)
	{
		cout << temp->name << endl;
		temp = temp->next;
	}
}

int main()
{
	Employee * employee1 = new Employee();
	employee1->name = "Ali";
	employee1->id = 1;
	employee1->department = "IT";
	employee1->designation = "Manager";

	Employee * employee2 = new Employee();
	employee2->name = "Ahmed";
	employee2->id = 2;
	employee2->department = "IT";
	employee2->designation = "Manager";

	
	Queue * queue = new Queue();
	queue->enqueue(employee1);
	queue->enqueue(employee2);

	queue->print();

	queue->dequeue();

	cout << "After Dequeue" << endl;

	queue->print();

	

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
