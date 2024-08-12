#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node
{
public:

	string name;
	int occurence;
	Node* left;
	Node* right;
	int height;

	Node(string n);
};

class AVL
{
	Node* root;
public:

	AVL();
	~AVL();

	void inorderTraversal(Node* node);

	Node* getRoot();



	void readFile();

	int getHeight(Node* node);

	int getBalance(Node* node);

	void updateHeight(Node* node);

	Node* rightRotate(Node* y);

	Node* leftRotate(Node* x);

	Node* balance(Node* node, string name);
	Node* insert(Node* node, string name);
	void search(Node* node, string n, bool& flag);
	Node* findMin(Node* node);
	Node* deleteNode(Node* node, string n);

	void autoComplete(Node* node, char ch);
};