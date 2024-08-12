// Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*In this problem you have to implement a stack using multiple queues.
You know the concept of stacks and queues. Therefore, you have to follow all the rules of queues
to implement stack.
For example: if your input 1,2,3,4 respectively, your output should be 4,3,2,1. Now there are
multiple ways of doing it, but in this problem, you have to use multiple queues (use 2 different
queues). By using multiple queues, you should create such logic that gives you an output of
4,3,2,1 which is just like output of stack.
Note: You are not allowed to use stack. You have to implement the functionality of stack using
queues.*/

#include <iostream>
#include "Header.h"

using namespace std;



Node::Node()
{
	data = 0;
	next = NULL;
	previous = NULL;
}



DoublyLinkedList::DoublyLinkedList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

void DoublyLinkedList::insertAtEnd(Node* obj)
{
	if (head == NULL)
	{
		head = obj;
		tail = obj;
	}
	else
	{
		tail->next = obj;
		obj->previous = tail;
		tail = obj;
	}
	size++;
}

Node* DoublyLinkedList::showFront()
{
	return head;
}

void DoublyLinkedList::deleteHead()
{
	if (head == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
}



Queue::Queue()
{
	list = new DoublyLinkedList();
	size = 0;
}

void Queue::enqueue(Node* Node)
{
	list->insertAtEnd(Node);

	size = list->size;
}

int Queue::dequeue()
{
	int temp = list->showFront()->data;
	list->deleteHead();
	size = list->size;
	return temp;
}

Node* Queue::showFront()
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

void Queue::reverseTheQueue()
{
	static Queue* que2 = new Queue();


	if (isEmpty())
	{
		que2->print();
		return;
	}
	else
	{
		int temp = dequeue();
		reverseTheQueue();
		Node* obj = new Node();
		obj->data = temp;
		que2->enqueue(obj);
		cout << temp << " ";


	}
}


void Queue::print()
{
	Node* temp = list->showFront();
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Node * node1 = new Node();
	Node * node2 = new Node();
	Node * node3 = new Node();
	Node * node4 = new Node();

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;

	Queue* queue1 = new Queue();
	Queue* queue2 = new Queue();

	queue1->enqueue(node1);
	queue1->enqueue(node2);
	queue1->enqueue(node3);
	queue1->enqueue(node4);

	queue1->print();

	queue1->reverseTheQueue();

	queue1->print();

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
