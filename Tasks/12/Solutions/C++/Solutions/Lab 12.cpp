// Lab 12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include"Header.h"

using namespace std;

Node::Node(string n)
{
	name = n;
	occurence = 0;
	left = NULL;
	right = NULL;
	height = 1;
}

AVL::AVL()
{
	root = NULL;
}

AVL::~AVL()
{
	root = NULL;
	delete root;
}

void AVL::inorderTraversal(Node* node)
{
	if (node != NULL)
	{
		inorderTraversal(node->left);
		cout << node->name;
		cout << " and ";
		cout << node->occurence;
		cout << endl;
		inorderTraversal(node->right);
	}
}

Node* AVL:: getRoot()
{
	return root;
}

void AVL::search(Node *node, string n, bool &flag)
{
	if (node != NULL)
	{
		if (node->name == n)
		{
			flag = true;
			node->occurence += 1;
		}
		search(node->left, n, flag);
		search(node->right, n, flag);
	}
}

Node* AVL::deleteNode(Node *node,string name)
{
	if (node == NULL)
	{
		return node;
	}

	if (name < node->name)
	{
		node->left = deleteNode(node->left, name);
	}
	else if (name > node->name)
	{
		node->right = deleteNode(node->right, name);

	}
	else 
	{
		if (node->left == NULL || node->right == NULL) 
		{

			Node* temp;

			if (node->left != NULL)
			{
				temp = node->left;
			}
			else
			{
				temp = node->right;
			}

			if (temp == NULL)
			{

				temp = node;

				node = NULL;

			}
			else
			{
				*node = *temp;
			}
			delete temp;

		}
		else 
		{

			Node* temp = findMin(node->right);

			node->name = temp->name;

			node->right = deleteNode(node->right, temp->name);

		}

	}

	if (node == NULL)
	{
		return node;
	}

	return balance(node, name);
}

Node* AVL:: findMin(Node* node) 
{

	while (node->left != NULL)

		node = node->left;

	return node;

}

int AVL::getHeight(Node* node)
{

	if (node == NULL)
	{
		return 0;
	}
	else
	{
		return node->height;
	}

}

int AVL:: getBalance(Node* node) {

	if (node == NULL)

		return 0;

	return getHeight(node->left) - getHeight(node->right);

}

void AVL::updateHeight(Node* node) {

	if (node != NULL)

		node->height = 1 + max(getHeight(node->left), getHeight(node->right));

}

Node* AVL::rightRotate(Node* y) {

	Node* x = y->left;

	Node* T2 = x->right;

	x->right = y;

	y->left = T2;

	updateHeight(y);

	updateHeight(x);

	return x;
}

Node* AVL::leftRotate(Node* x) {

	Node* y = x->right;

	Node* T2 = y->left;

	y->left = x;

	x->right = T2;

	updateHeight(x);

	updateHeight(y);

	return y;

}

Node* AVL::balance(Node* node, string name) {

	updateHeight(node);

	int balance = getBalance(node);

	// LH RH

	if (balance > 1 && name < node->left->name)

		return rightRotate(node);

	if (balance < -1 && name > node->right->name)

		return leftRotate(node);

	// LRH RLH
	if (balance > 1 && name > node->left->name) {

		node->left = leftRotate(node->left);

		return rightRotate(node);

	}

	if (balance < -1 && name < node->right->name) {

		node->right = rightRotate(node->right);

		return leftRotate(node);

	}

	return node;

}

Node* AVL::insert(Node* node, string name) {

	Node* temp;
	bool duplicate=false;

	search(root, name, duplicate);

	if (duplicate == true)
	{
		/*cout << name << " is duplicate" << endl;*/
		return root;
	}
	else
	{
		/*cout << "here";*/
	}

	if (node == NULL)
	{
		temp = new Node(name);
		return temp;
	}

	if (name < node->name)
	{
		node->left = insert(node->left, name);
	}
	else if (name > node->name)
	{
		node->right = insert(node->right, name);
	}
	else
	{
		return node;
	}

	return balance(node, name);

}

void AVL::readFile()
{
	fstream file("dictionary.txt");

	if (file.is_open() != false)
	{
		string word;
		while (file >> word)
		{
			root = insert(root, word);
		}
	}
	else
	{
		cout << "File Not Open" << endl;
	}
}

void AVL::autoComplete(Node* node, char ch)
{
	if (node != NULL)
	{
		autoComplete(node->left, ch);
		if (node->name.at(0) == ch)
		{
			cout << node->name;
		}
		autoComplete(node->right,ch);
	}
}

int main()
{
	AVL tree;

	int userInput=-1;
	char ch;
	string n;

	while (userInput != 5)
	{
		/*tree.inorderTraversal(tree.getRoot());*/

		cout << endl;
		cout << "1. Load Dictionary into AVL " << endl;
		cout << "2. View Tree " << endl;
		cout << "3. Display Autocomplete Suggestions " << endl;
		cout << "4. Delete word from dictionary " << endl;
		cout << "5. Exit " << endl;

		cout << "Enter : ";
		cin >> userInput;

		switch (userInput)
		{
		case 1:

			tree.readFile();

			break;

		case 2:

			tree.inorderTraversal(tree.getRoot());

			break;

		case 3:
			cout << "Enter Character : ";
			cin >> ch;
			cout << "List :" << endl;
			tree.autoComplete(tree.getRoot(), ch);
			break;

		case 4:
			cout << "Enter Word";
			cin >> n;
			tree.deleteNode(tree.getRoot(), n);

			break;

		case 5:
			
			break;
		}
	}

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
