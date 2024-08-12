#include <iostream>
#include "Header.h"

using namespace std;

Node::Node(int d)
{
	data = d;
	left = NULL;
	right = NULL;
}



BST::BST()
{
	root = NULL;
	heightleft = 0;
	heightright = 0;
	n = 0;
	kth = 0;
	kthcount = 0;
	range1 = 0;
	range2 = 0;
	count = 0;
}

Node* BST::getRoot()
{
	return root;
}

void BST::setN(int v)
{
	n = v;
}

void BST::setKth(int v)
{
	kth = v;
}

void BST::setKthcount(int v)
{
	kthcount = v;
}

void BST::setRange1(int v)
{
	range1 = v;
}

void BST::setRange2(int v)
{
	range2 = v;
}

void BST::insert(int value)
{
	Node* newNode = NULL;
	Node * temp = NULL;

	newNode = new Node();
	newNode->data = value;

	if (root == NULL)
	{
		root = newNode;
		return;
	}
	else
	{
		temp = root;
		while (temp != NULL)
		{
			if (value < temp->data)
			{
				if (temp->left != NULL)
				{
					temp = temp->left;
				}
				else
				{
					temp->left = newNode;
					break;
				}
			}
			else if (value > temp->data)
			{
				if (temp->right != NULL)
				{
					temp = temp->right;
				}
				else
				{
					temp->right = newNode;
					break;
				}
			}
			else
			{
				cout << "Duplicate!!!!!!!" << endl;
				break;
			}
		}
	}
}

void BST::inOrderTraversal(Node* r)
{
	if (r != NULL)
	{
		inOrderTraversal(r->left);
		cout << r->data << " ";
		inOrderTraversal(r->right);
	}
}

Node* BST::findNode(int value)
{
	Node * temp = NULL;

	temp = root;

	while (temp != NULL)
	{
		if (value < temp->data)
		{
			temp = temp->left;
		}
		else if (value > temp->data)
		{
			temp = temp->right;
		}
		else
		{
			return temp;
		}
	}

	return NULL;
}

int BST::findHeight(Node* r)
{
	if (r != NULL) {
		int leftHeight = 0;
		leftHeight= findHeight(r->left);
		int rightHeight = 0;
		rightHeight = findHeight(r->right);

		leftHeight += 1;
		rightHeight += 1;

		if (leftHeight > rightHeight)
		{
			return leftHeight;
		}
		else
		{
			return rightHeight;
		}
	}
	else 
	{
		return 0; 
	}
}

int BST:: findDepth(Node* r)
{
	int h = findHeight(r);
	return h;
}

int BST::smallestKth(Node* r)
{
	if (r != NULL)
	{
		smallestKth(r->left);
		kthcount+=1;
		if (kthcount == kth)
		{
			n = r->data;
		}
		smallestKth(r->right);
	}
	return n;
}

int BST::countNodesInRange(Node* r)
{
	if (r != NULL)
	{
		countNodesInRange(r->left);
		if (r->data >= range1 && r->data <= range2)
		{
			cout << r->data << " ";
			count++;
		}
		countNodesInRange(r->right);
	}
	return count;
}


int main()
{
	int choice = -1;
	int treeHeight = 0;
	int nodeHeight = 0;

	BST tree;

	tree.insert(10);
	tree.insert(5);
	tree.insert(15);
	tree.insert(3);
	tree.insert(7);
	tree.insert(12);
	tree.insert(1);
	
	
	tree.inOrderTraversal(tree.getRoot());

	Node * temp = NULL;

	cout << endl << endl;

	while (choice != 5)
	{
		cout << "1. Find Height of BST" << endl;
		cout << "2. Find depth of node in BST" << endl;
		cout << "3. Count nodes in range" << endl;
		cout << "4. Find the kth smallest number in BST" << endl;
		cout << "5. Exit" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Height of BST: " << tree.findHeight(tree.getRoot()) << endl;
			cout << endl << endl;
			break;

		case 2:

			int value;

			cout << "Enter value to find depth of: ";
			cin >> value;

			temp = tree.findNode(value);

			treeHeight = tree.findHeight(tree.getRoot());
			nodeHeight = tree.findDepth(temp);
			cout << "Depth of node: " << (treeHeight - nodeHeight) << endl;
			break;

		case 3:
			tree.inOrderTraversal(tree.getRoot());

			int selection1;
			int selection2;

			cout << endl;

			cout << "Enter first number: ";
			cin >> selection1;

			cout << "Enter second number: ";
			cin >> selection2;

			tree.setRange1(selection1);
			tree.setRange2(selection2);

			cout << "Number of nodes in range: " << tree.countNodesInRange(tree.getRoot()) << endl;

			break;

		case 4:

			int kth = 0;

			cout << "Enter kth smallest number: ";
			cin >> kth;

			tree.setKth(kth);

			tree.setN(tree.getRoot()->data);
			int n = tree.smallestKth(tree.getRoot());
			cout << "Smallest Kth: " << n << endl;

			tree.setKth(0);
			tree.setKthcount(0);

			break;
		}
	}


	return 0;
}