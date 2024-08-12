#pragma once

#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node* prev;
	Node(int data);
};

Node::Node(int data)
{
	this->data = data;
	this->next = nullptr;
}

