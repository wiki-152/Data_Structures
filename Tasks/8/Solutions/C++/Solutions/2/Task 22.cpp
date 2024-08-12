// Task 22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

/*1. Step 1: You start reading from the left most character (do this character by character)
a. If it is an alphabet put it in aplhabet queue -&gt; a,b
b. If it is a number put it in number queue -&gt; 2,3
c. If it is an operator put it in arithmatic queue -&gt; +,*
2. Step 2: From arithmatic queue, find the operator with highest precedence and then apply
that operation to all the numbers present in number queue -&gt; 2*3=6 

3. Step 3: Final decrypted password is concatenation of alphabet queue + number queue +
arithmetic queue-&gt;ab6+*

Your task is to take an encrypted password from the user in the form of a string. The password
must only contains Alphanumeric characters and Arithmetic operations +, -, *, / (No brackets
should be included).
Your decrypted password should be in the following format:
1. The alphabets must comes first.
2. Then comes the numbers.
3. At the end, there are arithmetic characters.*/

class Node
{
public:
	char data;
	Node* next;
	Node(char data);
};

Node::Node(char data)
{
	this->data = data;
	this->next = NULL;
}

class doublyLinkedList
{
private:

	Node* head;
	Node* tail;
	int size;

public:

	doublyLinkedList();
	void add(char data);
	void remove();
	void print();
	int getSize();
	char getHead();
	char getTail();
	bool isEmpty();
	void clear();
	~doublyLinkedList();
};

doublyLinkedList::doublyLinkedList()
{
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

void doublyLinkedList::add(char data)
{
	Node* newNode = new Node(data);

	if (this->head == NULL)
	{
		this->head = newNode;
		this->tail = newNode;
	}
	else
	{
		this->tail->next = newNode;
		this->tail = newNode;
	}

	this->size++;
}

void doublyLinkedList::remove()
{
	if (this->head == NULL)
	{
		return;
	}
	else if (this->head == this->tail)
	{
		delete this->head;
		this->head = NULL;
		this->tail = NULL;
	}
	else
	{
		Node* temp = this->head;
		this->head = this->head->next;
		delete temp;
	}

	this->size--;
}

void doublyLinkedList::print()
{
	Node* temp = this->head;

	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}

int doublyLinkedList::getSize()
{
	return this->size;
}

char doublyLinkedList::getHead()
{
	return this->head->data;
}

char doublyLinkedList::getTail()
{
	return this->tail->data;
}

bool doublyLinkedList::isEmpty()
{
	return this->size == 0;
}

void doublyLinkedList::clear()
{
	while (!this->isEmpty())
	{
		this->remove();
	}
}

doublyLinkedList::~doublyLinkedList()
{
	this->clear();
}


class Queue
{
private:
	doublyLinkedList* list;

public:

	Queue();
	void enqueue(char data);
	void dequeue();
	char peek();
	bool isEmpty();
	void print();
	int getSize();
	void clear();
	~Queue();
};

Queue::Queue()
{
	this->list = new doublyLinkedList();
}

void Queue::enqueue(char data)
{
	this->list->add(data);
}

void Queue::dequeue()
{
	this->list->remove();
}

char Queue::peek()
{
	return this->list->getHead();
}

bool Queue::isEmpty()
{
	return this->list->isEmpty();
}

void Queue::print()
{
	this->list->print();
}

int Queue::getSize()
{
	return this->list->getSize();
}

void Queue::clear()
{
	this->list->clear();
}

Queue::~Queue()
{
	delete this->list;
}







int main()
{
	string input = "a2b3+*";

	char in = ' ';

	Queue* alphabet = new Queue();
	Queue* number = new Queue();
	Queue* arithmetic = new Queue();

	for (int i = 0; i < input.length(); i++)
	{
		in = input[i];

		if (in >= 'a' && in <= 'z')
		{
			alphabet->enqueue(in);
		}
		else if (in >= '0' && in <= '9')
		{
			number->enqueue(in);
		}
		else
		{
			arithmetic->enqueue(in);
		}
	}

	int size = arithmetic->getSize();

	/*From arithmatic queue, find the operator with highest precedence and then apply
that operation to all the numbers present in number queue -&gt; 2*3=6*/

	char op = ' ';
	int num1 = 0;
	int num2 = 0;
	int result = 0;

	for (int i = 0; i < size; i++)
	{

	}

	/*Final decrypted password is concatenation of alphabet queue + number queue +*/

	alphabet->print();
	number->print();
	arithmetic->print();


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
