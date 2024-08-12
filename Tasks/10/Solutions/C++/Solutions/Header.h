#pragma once

#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int d = -1111);
};

class BST
{
	Node* root;

	int heightleft;
	int heightright;
	int n;
	int kth;
	int kthcount;
	int range1;
	int range2;
	int count;


public:

	BST();
	Node* getRoot();

	void setN(int v);
	void setKth(int v);
	void setKthcount(int v);
	void setRange1(int v);
	void setRange2(int v);

	void insert(int value);
	void inOrderTraversal(Node* r);
	Node* findNode(int value);
	int findHeight(Node* r);
	int findDepth(Node* r);
	int smallestKth(Node* r);

	int countNodesInRange(Node* r);

};