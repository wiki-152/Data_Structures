// Lab 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;


doublyLinkedList::doublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

void doublyLinkedList::print()
{
	Node* temp = head;
	if (head == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		do
		{
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != head);
		cout << endl;
	}
}

void doublyLinkedList::insertNodeAtEnd(int data)
{
	Node* newNode = new Node(data);

	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
		tail->next = head;
		head->next = tail;
		tail->prev = head;
		head->prev = tail;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		tail->next = head;
		head->prev = tail;

	}
}

void doublyLinkedList::insertNodeAtStart(int data)
{
	Node* newNode = new Node(data);

	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
		tail->next = head;
		head->next = tail;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		head->prev = tail;
		tail->next = head;
	}
}

void doublyLinkedList::insertNodeBefore(int data, int position)
{
	Node* newNode = new Node(data);
	Node* temp = head;

	int counter = 1;

	do
	{
		temp = temp->next;
		counter++;
	} while (temp != head);

	if ((position < 0) || (position >= counter))
	{
		cout << "Invalid Position" << endl;
		return;
	}

	temp = head;

	for (int i = 1; i <= position; i++)
	{
		temp = temp->next;
	}

	if (temp == head)
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		head->prev = tail;
		tail->next = head;
	}
	else
	{
		newNode->next = temp;
		newNode->prev = temp->prev;
		temp->prev->next = newNode;
		temp->prev = newNode;
	}

}

void doublyLinkedList::insertNodeAfter(int data, int position)
{
	Node* newNode = new Node(data);
	Node* temp = head;

	int counter = 1;

	do
	{
		temp = temp->next;
		counter++;
	} while (temp != head);

	if ((position < 0) || (position >= counter))
	{
		cout << "Invalid Position" << endl;
		return;
	}

	temp = head;

	for (int i = 1; i <= position; i++)
	{
		temp = temp->next;
	}

	if (temp == tail)
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		tail->next = head;
		head->prev = tail;
	}
	else
	{
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next->prev = newNode;
		temp->next = newNode;
	}
}

void doublyLinkedList::deleteFirstNode()
{
	if (head == NULL)
	{
		cout << "Empty List" << endl;
		return;
	}

	if (head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		head = head->next;
		head->prev = tail;
		tail->next = head;
	}
}

void doublyLinkedList::deleteMiddleNode()
{
	if (head == NULL)
	{
		cout << "Empty List" << endl;
		return;
	}

	if (head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		Node* temp = head;

		int counter = 0;

		do
		{
			temp = temp->next;
			counter++;
		} while (temp != head);

		temp = head;

		counter -= 1;

		for (int i = 1; i <= counter / 2; i++)
		{
			temp = temp->next;
		}

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
}

void doublyLinkedList::deleteLastNode()
{
	if (head == NULL)
	{
		cout << "Empty List" << endl;
		return;
	}

	if (head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;
	}
}

void doublyLinkedList::deleteSpecificNode(int position)
{
	if (head == NULL)
	{
		cout << "Empty List" << endl;
		return;
	}

	Node* temp = head;

	int counter = 1;

	do
	{
		temp = temp->next;
		counter++;
	} while (temp != head);

	counter -= 1;

	if ((position < 0) || (position >= counter))
	{
		cout << "Invalid Position" << endl;
		return;
	}

	if (position == 0 && counter == 1)
	{
		head = NULL;
		tail = NULL;
		return;
	}

	if (position == 0)
	{
		head = head->next;
		head->prev = tail;
		tail->next = head;
		return;

	}

	temp = head;

	for (int i = 1; i <= position; i++)
	{
		temp = temp->next;
	}

	if (temp == head)
	{
		head = head->next;
		head->prev = tail;
		tail->next = head;
	}
	else if (temp == tail)
	{
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
}

void doublyLinkedList::bubbleSort()
{
	// Bubble Sorting Of Nodes in Doubly Linked List

	int size = 1;
	Node* temp = head;

	do
	{
		temp = temp->next;
		size++;
	} while (temp != head);

	cout << "Size: " << size << endl;

	bool swapping = false;
	temp = head;

	for (int pass = 1; pass < size; pass++)
	{
		for (int i = 0; i < size - pass; i++)
		{
			if (temp->data > temp->next->data)
			{
				Node* temp1 = new Node(0);
				Node* temp2 = new Node(0);

				temp1->data = temp->data;
				temp1->next = temp->next;
				temp1->prev = temp->prev;

				temp2->data = temp->next->data;
				temp2->next = temp->next->next;
				temp2->prev = temp->next->prev;

				temp->data = temp2->data;
				temp->next = temp2->next;
				temp->prev = temp2->prev;


				temp2->data = temp1->data;
				temp2->next = temp1->next;
				temp2->prev = temp1->prev;

			}
		}
	}
}

int main()
{
	cout << "Insert At End";
	doublyLinkedList obj;
	obj.insertNodeAtEnd(1);
	obj.insertNodeAtEnd(2);

	obj.print();

	cout << "Insert At Start";
	obj.insertNodeAtStart(5);
	obj.insertNodeAtStart(6);

	obj.print();

	cout << "Insert Before";
	obj.insertNodeBefore(100 , 0);

	obj.print();

	cout << "Insert Before";
	obj.insertNodeAfter(200, 1);

	obj.print();

	cout << "Sorting" << endl;
	obj.bubbleSort();

	obj.print();

	cout << "Delete Furst";
	obj.deleteFirstNode();

	obj.print();

	cout << "Delete Middle";
	obj.deleteMiddleNode();
	
	obj.print();

	obj.deleteMiddleNode();

	obj.print();

	cout << "Delete Last ";
	obj.deleteLastNode();

	obj.print();

	cout << "W" << endl;
	obj.deleteSpecificNode(1);

	obj.print();

	cout << "N" << endl;
	obj.deleteSpecificNode(0);

	obj.print();

}


