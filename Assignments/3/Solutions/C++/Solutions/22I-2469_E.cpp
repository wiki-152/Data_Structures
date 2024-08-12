// Muhammad_Waqas_Shahid_Khan_22i2469
// 22I-2469_E.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <queue>
#include <string>
#include <fstream>
#include <stack>
#include "Header.h"

using namespace std;

Node::Node()
{
	name = "";
	path = "";
	type = "";
	leftChild = NULL;
	rightChild = NULL;
	searchStatus = false;
	parentName = "";
}

// In contructor we create a root and its left child as PatientData and right child as Logs
BinarySearchTree::BinarySearchTree()
{
	heightOfTree = 0;

	root = new Node();
	root->name = "root";
	root->path = "/";
	root->type = "Directory";
	root->leftChild = NULL;
	root->rightChild = NULL;

	Node* patientData = new Node();
	patientData->name = "PatientsData";
	patientData->path = root->name + root->path;
	patientData->type = "Directory";
	patientData->leftChild = NULL;
	patientData->rightChild = NULL;

	Node* patientsHome = new Node();
	patientsHome->name = "PatientsHome";
	patientsHome->path = patientData->path + patientData->name;
	patientsHome->type = "Directory";
	patientsHome->leftChild = NULL;
	patientsHome->rightChild = NULL;

	patientData->leftChild = patientsHome;


	Node* logs = new Node();
	logs->name = "Logs";
	logs->path = root->name + root->path;
	logs->type = "Directory";
	logs->leftChild = NULL;
	logs->rightChild = NULL;

	Node* logsHome = new Node();
	logsHome->name = "LogsHome";
	logsHome->path = logs->path + logs->name;
	logsHome->type = "Directory";
	logsHome->leftChild = NULL;
	logsHome->rightChild = NULL;

	logs->leftChild = logsHome;

	root->leftChild = patientData;
	root->rightChild = logs;
}

BinarySearchTree::~BinarySearchTree()
{
	delete root;
}

void BinarySearchTree::setRoot(Node* node)
{
	root = node;
}

Node* BinarySearchTree::getRoot()
{
	return root;
}

void BinarySearchTree::deleteOnlyNodeFromTree(Node* node)
{
	// We delete only the node and not its children from the tree by traversing from root to the node

	// We first check if the node is the root or not

	if (node == root)
	{
		root = NULL;
		return;
	}

	// We traverse to the parent of the node

	char checkPath[200];

	for (int i = 0; i < 200; i++)
	{
		checkPath[i] = ' ';
	}

	strcpy_s(checkPath, node->path.c_str());

	checkPath[node->path.length()] = '\0';

	string tempName;

	int counter = 0;

	queue <string> q;

	for (int i = 0; i < node->path.length() + 1; i++)
	{
		if (checkPath[i] == '/' || checkPath[i] == '\0')
		{
			q.push(tempName);
			tempName = "";
		}
		else
		{
			tempName += checkPath[i];
		}
	}

	/*cout << "Display Queue" << endl;*/

	string check = "";

	Node* found = root;

	while (!q.empty())
	{
		check = q.front();
		q.pop();

		/*cout << "Check: " << check << " " << "Found: " << found->name << endl;*/

		if (found->name == check)
		{
		}
		else if (found->leftChild != NULL && found->leftChild->name == check)
		{
			found = found->leftChild;
		}
		else if (found->rightChild != NULL && found->rightChild->name == check)
		{
			found = found->rightChild;
		}
		else
		{
			cout << "Path does not exist!" << endl;
			Sleep(3000);
			return;
		}
	}

	// Deletion of node

	/*cout << "Found: " << found->name << endl;*/

	if (found->leftChild != NULL)
	{
		// We attach the left child of the node to its parent

		if (found->leftChild->name == node->name)
		{
			found->leftChild = NULL;
			cout << "Node deleted successfully!" << endl;
		}
		else
		{
			cout << "Node not found!" << endl;
		}
	}
}

void BinarySearchTree::preorderTraversal(Node* node)
{
	if (node != NULL)
	{
		cout << node->name << " ";
		preorderTraversal(node->leftChild);
		preorderTraversal(node->rightChild);
	}
}

void BinarySearchTree::inorderTraversal(Node* node)
{
	if (node != NULL)
	{
		inorderTraversal(node->leftChild);
		cout << node->name << " ";
		inorderTraversal(node->rightChild);
	}
}

void BinarySearchTree::postorderTraversal(Node* node)
{
	if (node != NULL)
	{
		postorderTraversal(node->leftChild);
		postorderTraversal(node->rightChild);
		cout << node->name << " ";
	}
}

void BinarySearchTree::levelorderTraversal(Node* node, int previousCounter, int currentCounter) {

	int level = 0;
	int counter = 0;
	Node* temp = NULL;
	queue<Node*> q;

	if (node != NULL) {
		q.push(node);

		while (q.empty() != true)
		{
			level = q.size();
			/*cout << "Level " << level << ": ";*/
			counter = 0;
			while (counter < level)
			{
				counter++;
				temp = q.front();
				q.pop();

				/*cout << temp->path << " --- ";--------------------------------------------------------------------------------------------------------------------------------------------------------*/
				cout << temp->name << " ";

				if (temp->leftChild != NULL) {
					q.push(temp->leftChild);
				}

				if (temp->rightChild != NULL) {
					q.push(temp->rightChild);
				}
			}
			/*cout << "Level " << level << ": ";*/
			cout << endl << endl;
		}
	}
	else
	{
		cout << "Tree is empty!" << endl;
		return;
	}

	Sleep(5000);
}

void BinarySearchTree::mergeDirectory(Node* destination, Node* source)
{
	// Considering the case in which either of the directories is empty meaning it has no right child

	if (destination->rightChild == NULL && source->rightChild != NULL)
	{
		destination->rightChild = source->rightChild;
	}
	else if (destination->rightChild != NULL && source->rightChild == NULL)
	{
		// We do not have to do anything
	}
	else if (destination->rightChild == NULL && source->rightChild == NULL)
	{
		// This means both have no right child and we do not have to do anything
	}
	else if (destination->rightChild != NULL && source->rightChild != NULL)
	{
		// Both have right child so no merging can occur

		cout << "Both directories have right child so no merging can occur!" << endl;
		Sleep(3000);
		return;
	}

	// Now we attach the left child of source if it is not null to its parent and delete the source node

	// Check if path is full or not
	string directoryPath = source->path;
	char checkPath[200];
	for (int i = 0; i < 200; i++)
	{
		checkPath[i] = ' ';
	}
	strcpy_s(checkPath, directoryPath.c_str());
	checkPath[directoryPath.length()] = '\0';
	string tempName;
	int counter = 0;
	queue <string> q;
	for (int i = 0; i < directoryPath.length() + 1; i++)
	{
		if (checkPath[i] == '/' || checkPath[i] == '\0')
		{
			q.push(tempName);
			tempName = "";
		}
		else
		{
			tempName += checkPath[i];
		}
	}

	// Check if path exists or not
	/*cout << "Display Queue" << endl;*/
	string check = "";
	Node* found = root;
	while (!q.empty())
	{

		check = q.front();
		q.pop();

		/*cout << "Check: " << check << " " << "Found: " << found->name << endl;*/
		if (found->name == check)
		{
		}
		else if (found->leftChild != NULL && found->leftChild->name == check)
		{
			found = found->leftChild;
		}
		else if (found->rightChild != NULL && found->rightChild->name == check)
		{
			found = found->rightChild;
		}
		else
		{
			cout << "Path does not exist!" << endl;
			Sleep(3000);
			return;
		}
	}

	cout << "Found Parent: " << found->name << endl;

	Node* leftChildOfSource = new Node();
	leftChildOfSource->name = source->leftChild->name;
	leftChildOfSource->path = source->leftChild->path;
	leftChildOfSource->type = source->leftChild->type;
	leftChildOfSource->leftChild = source->leftChild->leftChild;
	leftChildOfSource->rightChild = source->leftChild->rightChild;


	if (found->leftChild != NULL)
	{
		found->leftChild = leftChildOfSource;
		cout << "Directory overwritten successfully!" << endl;

		string directoryName = found->name;

		found->name = directoryName;

		// Now We Have To Change The Path Of All The Nodes In The Subtree

		queue <Node*> q;

		q.push(found);

		while (q.empty() != true)
		{
			Node* temp = q.front();
			q.pop();

			if (temp->leftChild != NULL)
			{
				temp->leftChild->path = temp->path + "/" + temp->name;
				q.push(temp->leftChild);
			}

			if (temp->rightChild != NULL)
			{
				temp->rightChild->path = temp->path + "/" + temp->name;
				q.push(temp->rightChild);
			}
		}
	}
	else
	{
		found->leftChild = leftChildOfSource;
		cout << "Directory created successfully!" << endl;

		string directoryName = found->name;

		found->name = directoryName;

		// Now We Have To Change The Path Of All The Nodes In The Subtree

		queue <Node*> q;

		q.push(found);

		while (q.empty() != true)
		{
			Node* temp = q.front();
			q.pop();

			if (temp->leftChild != NULL)
			{
				temp->leftChild->path = temp->path + "/" + temp->name;
				q.push(temp->leftChild);
			}

			if (temp->rightChild != NULL)
			{
				temp->rightChild->path = temp->path + "/" + temp->name;
				q.push(temp->rightChild);
			}
		}
	}

	cout << "Directory merged successfully!" << endl;

	// Now we ask the user if he wants to rename the destination directory

	cout << "Do you want to rename the destination directory? (Y/N): ";
	char rename;
	cin >> rename;

	while (rename != 'Y' && rename != 'y' && rename != 'N' && rename != 'n')
	{
		cout << "Invalid input! Please enter again: ";
		cin >> rename;
	}

	if (rename == 'Y' || rename == 'y')
	{
		string newName;
		cout << "Enter new name of directory: ";
		cin >> newName;

		destination->name = newName;
		cout << "Directory renamed successfully!" << endl;
	}
	else
	{
		cout << "Directory not renamed!" << endl;
	}

	// Now we update paths of all the nodes in the tree

	Sleep(3000);
}

int BinarySearchTree::calculateHeight(Node* node)
{
	if (node != NULL) {
		int leftHeight = 0;
		leftHeight = calculateHeight(node->leftChild);
		int rightHeight = 0;
		rightHeight = calculateHeight(node->rightChild);

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

void BinarySearchTree::setHeightOfTree(int height)
{
	heightOfTree = height;
}

int BinarySearchTree::getHeightOfTree()
{
	return heightOfTree;
}

void BinarySearchTree::clearStackOfNodes()
{
	while (stackOfNodes.empty() != true)
	{
		stackOfNodes.pop();
	}
}

void BinarySearchTree::clearQueueOfNodes()
{
	while (queueOfNodes.empty() != true)
	{
		queueOfNodes.pop();
	}
}

void BinarySearchTree::search(Node* node, string name, Node*& found)
{
	if (node != NULL)
	{
		search(node->leftChild, name, found);
		search(node->rightChild, name, found);

		/*cout << "HHH" << node->name << " and " << name << endl;*/
		if (node->name == name && node->searchStatus == false)
		{
			/*cout << "Node: " << node->name << endl;*/
			node->searchStatus = true;
			/*cout << "gaödaföglkdjölf";
			cout << node->path << endl;*/
			stackOfNodes.push(node);
			found = node;
			/*cout << found->name << endl;*/
		}
	}
}

void BinarySearchTree::setAllSearchStatusToFalse(Node* node)
{
	if (node != NULL)
	{
		setAllSearchStatusToFalse(node->leftChild);
		setAllSearchStatusToFalse(node->rightChild);
		node->searchStatus = false;
	}
}

void BinarySearchTree::displaySearchResults(string type)
{
	if (type == "Directories")
	{
		if (stackOfNodes.empty() == true)
		{
			cout << "No " << type << " found!" << endl;
		}
		else
		{
			cout << "List of " << type << " found!" << endl;
			while (stackOfNodes.empty() != true)
			{
				cout << "Name: " << stackOfNodes.top()->name << endl;
				cout << "Path: " << stackOfNodes.top()->path << endl;
				stackOfNodes.pop();
			}
		}
	}
	else if (type == "Files")
	{
		if (stackOfNodes.empty() == true)
		{
			cout << "No " << type << " found!" << endl;
		}
		else
		{
			cout << "List of " << type << " found!" << endl;
			while (stackOfNodes.empty() != true)
			{
				cout << "Name: " << stackOfNodes.top()->name << endl;
				cout << "Path: " << stackOfNodes.top()->path << endl;
				stackOfNodes.pop();
			}
		}
	}
	else
	{
		cout << "Invalid type!" << endl;
		return;
	}
}

void BinarySearchTree::createDirectory(string name = "", string path = "")
{
	string directoryName = name;
	string directoryPath = path;

	if (directoryName == "" && directoryPath == "")
	{
		cout << "Enter directory name: ";
		cin >> directoryName;

		cout << "Enter directory path: ";
		cin >> directoryPath;
	}

	Node* newNode = new Node();
	newNode->name = directoryName;
	newNode->path = directoryPath;
	newNode->type = "Directory";
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	newNode->searchStatus = false;

	if (root == NULL)
	{
		root = newNode;
		cout << "Directory created successfully!" << endl;

		Sleep(1000);

		return;
	}

	if (root->leftChild == NULL)
	{
		root->leftChild = newNode;
		cout << "Root L Directory created successfully!" << endl;

		Sleep(1000);

		return;
	}

	if (root->rightChild == NULL)
	{
		root->rightChild = newNode;
		cout << "Root R Directory created successfully!" << endl;

		Sleep(3000);

		return;
	}

	// Check if path is full or not
	char checkPath[200];
	for (int i = 0; i < 200; i++)
	{
		checkPath[i] = ' ';
	}
	strcpy_s(checkPath, directoryPath.c_str());
	checkPath[directoryPath.length()] = '\0';
	string tempName;
	int counter = 0;
	queue <string> q;
	for (int i = 0; i < directoryPath.length() + 1; i++)
	{
		if (checkPath[i] == '/' || checkPath[i] == '\0')
		{
			q.push(tempName);
			tempName = "";
		}
		else
		{
			tempName += checkPath[i];
		}
	}

	// Check if path exists or not
	/*cout << "Display Queue" << endl;*/
	string check = "";
	Node* found = root;
	while (!q.empty())
	{

		check = q.front();
		q.pop();

		/*cout << "Check: " << check << " " << "Found: " << found->name << endl;*/
		if (found->name == check)
		{
		}
		else if (found->leftChild != NULL && found->leftChild->name == check)
		{
			found = found->leftChild;
		}
		else if (found->rightChild != NULL && found->rightChild->name == check)
		{
			found = found->rightChild;
		}
		else
		{
			cout << "Path does not exist!" << endl;
			Sleep(3000);
			return;
		}
	}

	/*cout << "Found: " << found->name << endl;*/
	if (found->leftChild != NULL)
	{
		if (found->leftChild->name == newNode->name)
		{
			cout << "Directory with same name already exists!" << endl;

			cout << "Do You want to overwrite it? (Y/N): ";
			char overwrite;
			cin >> overwrite;

			while (overwrite != 'Y' && overwrite != 'y' && overwrite != 'N' && overwrite != 'n')
			{
				cout << "Invalid input! Please enter again: ";
				cin >> overwrite;
			}

			if (overwrite == 'Y' || overwrite == 'y')
			{
				found->leftChild = newNode;
				cout << "Directory overwritten successfully!" << endl;
			}
			else
			{
				cout << "Directory not overwritten!" << endl;
			}
		}
		else
		{
			cout << "Directory already exists!" << endl;
			cout << "Name of directory already present: " << found->leftChild->name << endl;

			cout << "Do You want to overwrite it? (Y/N): ";
			char overwrite;
			cin >> overwrite;

			while (overwrite != 'Y' && overwrite != 'y' && overwrite != 'N' && overwrite != 'n')
			{
				cout << "Invalid input! Please enter again: ";
				cin >> overwrite;
			}

			if (overwrite == 'Y' || overwrite == 'y')
			{
				found->leftChild = newNode;
				cout << "Directory overwritten successfully!" << endl;
			}
			else
			{
				cout << "Directory not overwritten!" << endl;

				// If the user does not want to overwrite then we ask if he wants to add it as a child of the directory
				cout << "Do you want to add directory as a child of " << found->name << "? (Y/N): ";
				char add;
				cin >> add;

				while (add != 'Y' && add != 'y' && add != 'N' && add != 'n')
				{
					cout << "Invalid input! Please enter again: ";
					cin >> add;
				}

				if (add == 'Y' || add == 'y')
				{
					newNode->leftChild = found->leftChild;
					found->leftChild = newNode;
					cout << "Directory added successfully!" << endl;

					string directoryName = found->name;

					found->name = directoryName;

					// Now We Have To Change The Path Of All The Nodes In The Subtree

					queue <Node*> q;

					q.push(found);

					while (q.empty() != true)
					{
						Node* temp = q.front();
						q.pop();

						if (temp->leftChild != NULL)
						{
							temp->leftChild->path = temp->path + "/" + temp->name;
							q.push(temp->leftChild);
						}

						if (temp->rightChild != NULL)
						{
							temp->rightChild->path = temp->path + "/" + temp->name;
							q.push(temp->rightChild);
						}
					}


				}
				else
				{
					cout << "Directory not added as child!" << endl;
				}

			}
		}
	}
	else
	{
		found->leftChild = newNode;
		cout << "Directory created successfully!" << endl;
	}

	/*levelorderTraversal(root);*/
	/*preorderTraversal(root);*/

	Sleep(1000);

}

void BinarySearchTree::deleteDirectory()
{
	string directoryName;

	cout << "Enter directory name: ";
	cin >> directoryName;

	Node* found = NULL;
	Node* deletionNode = NULL;


	//Check if directory exis or not
	search(root, directoryName, found);


	if (found == NULL || found->type != "Directory")
	{
		cout << "Directory not found!" << endl;
		Sleep(3000);
		return;
	}

	deletionNode = found;

	/*cout << "W " << found->name << deletionNode->name << endl;*/

	// Traverse to its parent

	char checkPath[200];
	for (int i = 0; i < 200; i++)
	{
		checkPath[i] = ' ';
	}
	strcpy_s(checkPath, found->path.c_str());
	checkPath[found->path.length()] = '\0';
	string tempName;
	int counter = 0;
	queue <string> q;
	for (int i = 0; i < found->path.length() + 1; i++)
	{
		if (checkPath[i] == '/' || checkPath[i] == '\0')
		{
			q.push(tempName);
			tempName = "";
		}
		else
		{
			tempName += checkPath[i];
		}
	}

	// Check if path exists or not
	/*cout << "Display Queue" << endl;*/
	string check = "";
	found = root;
	while (!q.empty())
	{
		check = q.front();
		q.pop();

		/*cout << "Check: " << check << " " << "Found: " << found->name << endl;*/
		if (found->name == check)
		{
		}
		else if (found->leftChild != NULL && found->leftChild->name == check)
		{
			found = found->leftChild;
		}
		else if (found->rightChild != NULL && found->rightChild->name == check)
		{
			found = found->rightChild;
		}
		else
		{
			/*cout << "Path does not exist!" << endl;
			Sleep(5000);
			return;*/
		}
	}

	// Deletion of directory
	/*cout << "Found: " << found->name << endl;*/

	if (found->leftChild == root->leftChild)
	{
		cout << "Cannot delete root left child directory!" << endl;
		Sleep(3000);
		return;
	}

	cout << "Found: " << found->name << endl;
	if (found->leftChild != NULL)
	{
		if (found->leftChild->name == directoryName)
		{
			cout << "Directory found!" << endl;

			if (found->leftChild != NULL || found->rightChild != NULL)
			{
				cout << "Directory is not empty!" << endl;
			}

			cout << "Do You want to delete it? (Y/N): ";
			char deleteInput;
			cin >> deleteInput;

			while (deleteInput != 'Y' && deleteInput != 'y' && deleteInput != 'N' && deleteInput != 'n')
			{
				cout << "Invalid input! Please enter again: ";
				cin >> deleteInput;
			}

			if (deleteInput == 'Y' || deleteInput == 'y')
			{
				/*cout << "Seach for deletion node:"<< endl;
				search(root, directoryName, deletionNode);
				cout << directoryName << endl;
				cout << "Deletion Node: " << deletionNode->name << endl;*/
				if (deletionNode->leftChild == NULL)
				{
					found->leftChild = NULL;
				}
				else
				{
					Node* leftOfDeletionNode = deletionNode->leftChild;
					leftOfDeletionNode->name = deletionNode->leftChild->name;
					leftOfDeletionNode->path = deletionNode->leftChild->path;
					leftOfDeletionNode->type = deletionNode->leftChild->type;
					leftOfDeletionNode->leftChild = deletionNode->leftChild->leftChild;
					leftOfDeletionNode->rightChild = deletionNode->leftChild->rightChild;

					found->leftChild = leftOfDeletionNode;
				}
				cout << "Directory deleted successfully!" << endl;
			}
			else
			{
				cout << "Directory not deleted!" << endl;
			}
		}
		else
		{
			cout << "ADirectory not found!" << endl;
		}
	}
	else
	{
		found->leftChild = NULL;
		cout << "Directory deleted successfully!" << endl;
	}

	Sleep(3000);

}



void BinarySearchTree::createFile(string name = "", string path = "")
{
	string fileName = name;
	string filePath = path;


	if (fileName == "" && filePath == "")
	{
		cout << "Enter file name: ";
		cin >> fileName;

		cout << "Enter file path: ";
		cin >> filePath;
	}

	string type;
	
	if (name == "")
	{
		cout << "Type of file (txt, pdf, doc, etc): ";
		cin >> type;
	}

	Node* newNode = new Node();
	newNode->name = fileName;
	newNode->path = filePath;
	newNode->type = "File";
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	// Check if path exists or not

	char checkPath[200];
	for (int i = 0; i < 200; i++)
	{
		checkPath[i] = ' ';
	}
	strcpy_s(checkPath, filePath.c_str());
	checkPath[filePath.length()] = '\0';
	string tempName;
	int counter = 0;
	queue <string> q;
	for (int i = 0; i < filePath.length() + 1; i++)
	{
		if (checkPath[i] == '/' || checkPath[i] == '\0')
		{
			q.push(tempName);
			tempName = "";
		}
		else
		{
			tempName += checkPath[i];
		}
	}

	// Check if path exists or not
	/*cout << "Display Queue" << endl;*/
	string check = "";
	Node* found = root;
	while (!q.empty())
	{
		check = q.front();
		q.pop();

		/*cout << "Check: " << check << " " << "Found: " << found->name << endl;*/
		if (found->name == check)
		{
		}
		else if (found->leftChild != NULL && found->leftChild->name == check)
		{
			found = found->leftChild;
		}
		else if (found->rightChild != NULL && found->rightChild->name == check)
		{
			found = found->rightChild;
		}
		else
		{
			cout << "Path does not exist!" << endl;
			Sleep(3000);
			return;
		}
	}

	/*cout << "Found: " << found->name << endl;*/

	if (found->rightChild != NULL)
	{
		if (found->rightChild->name == newNode->name)
		{
			cout << "File with same name already exists!" << endl;

			cout << "Do You want to overwrite it? (Y/N): ";
			char overwrite;
			cin >> overwrite;

			while (overwrite != 'Y' && overwrite != 'y' && overwrite != 'N' && overwrite != 'n')
			{
				cout << "Invalid input! Please enter again: ";
				cin >> overwrite;
			}

			if (overwrite == 'Y' || overwrite == 'y')
			{
				found->rightChild = newNode;
				cout << "File overwritten successfully!" << endl;
			}
			else
			{
				cout << "File not overwritten!" << endl;
			}
		}
		else
		{
			cout << "File already exists!" << endl;
			cout << "Name of file already present: " << found->rightChild->name << endl;

			cout << "Do You want to overwrite it? (Y/N): ";
			char overwrite;
			cin >> overwrite;

			while (overwrite != 'Y' && overwrite != 'y' && overwrite != 'N' && overwrite != 'n')
			{
				cout << "Invalid input! Please enter again: ";
				cin >> overwrite;
			}

			if (overwrite == 'Y' || overwrite == 'y')
			{
				found->rightChild = newNode;
				cout << "File overwritten successfully!" << endl;
			}
			else
			{
				cout << "File not overwritten!" << endl;

				/*cout << "Do you want to add file as a child of " << found->name << "? (Y/N): ";
				char add;
				cin >> add;

				while (add != 'Y' && add != 'y' && add != 'N' && add != 'n')
				{
					cout << "Invalid input! Please enter again: ";
					cin >> add;
				}

				if (add == 'Y' || add == 'y')
				{
					newNode->leftChild = found->rightChild;
					found->rightChild = newNode;
					cout << "File added successfully!" << endl;
				}
				else
				{
					cout << "File not added!" << endl;
				}*/
			}
		}
	}
	else
	{
		found->rightChild = newNode;
		cout << "File created successfully!" << endl;
	}

	/*levelorderTraversal(root);*/
	/*preorderTraversal(root);*/

	Sleep(4000);
}

void BinarySearchTree::deleteFile()
{
	string fileName;

	cout << "Enter file name: ";
	cin >> fileName;

	Node* found = NULL;

	search(root, fileName, found);

	if (found == NULL || found->type != "File")
	{
		cout << "File not found!" << endl;
		Sleep(3000);
		return;
	}

	// Traverse to its parent

	char checkPath[200];
	for (int i = 0; i < 200; i++)
	{
		checkPath[i] = ' ';
	}

	strcpy_s(checkPath, found->path.c_str());

	checkPath[found->path.length()] = '\0';

	string tempName;

	int counter = 0;

	queue <string> q;

	for (int i = 0; i < found->path.length() + 1; i++)
	{
		if (checkPath[i] == '/' || checkPath[i] == '\0')
		{
			q.push(tempName);
			tempName = "";
		}
		else
		{
			tempName += checkPath[i];
		}
	}

	// Check if path exists or not

	/*cout << "Display Queue" << endl;*/

	string check = "";

	found = root;

	while (!q.empty())
	{
		check = q.front();
		q.pop();

		/*cout << "Check: " << check << " " << "Found: " << found->name << endl;*/

		if (found->name == check)
		{
		}
		else if (found->leftChild != NULL && found->leftChild->name == check)
		{
			found = found->leftChild;
		}
		else if (found->rightChild != NULL && found->rightChild->name == check)
		{
			found = found->rightChild;
		}
		else
		{
			cout << "Path does not exist!" << endl;
			Sleep(3000);
			return;
		}
	}

	// Deletion of file

	/*cout << "Found: " << found->name << endl;*/

	if (found->rightChild != NULL)
	{
		if (found->rightChild->name == fileName)
		{
			cout << "File found!" << endl;

			cout << "Do You want to delete it? (Y/N): ";
			char deleteInput;
			cin >> deleteInput;

			while (deleteInput != 'Y' && deleteInput != 'y' && deleteInput != 'N' && deleteInput != 'n')
			{
				cout << "Invalid input! Please enter again: ";
				cin >> deleteInput;
			}

			if (deleteInput == 'Y' || deleteInput == 'y')
			{
				found->rightChild = NULL;
				cout << "File deleted successfully!" << endl;
			}
			else
			{
				cout << "File not deleted!" << endl;
			}
		}
		else
		{
			cout << "File not found!" << endl;
		}
	}
	else
	{
		found->rightChild = NULL;
		cout << "File deleted successfully!" << endl;
	}
}

void BinarySearchTree::copyDirectory()
{
	string directoryName;
	string destinationPath;

	cout << "Enter name of directory to be copied: ";
	cin >> directoryName;

	cout << "Enter destination path: ";
	cin >> destinationPath;

	Node* found = NULL;

	search(root, directoryName, found);

	if (found == NULL || found->type != "Directory")
	{
		cout << "Directory not found!" << endl;
		Sleep(3000);
		return;
	}

	// Check if path exists or not

	char checkPath[200];
	for (int i = 0; i < 200; i++)
	{
		checkPath[i] = ' ';
	}
	strcpy_s(checkPath, destinationPath.c_str());
	checkPath[destinationPath.length()] = '\0';
	string tempName;
	int counter = 0;
	queue <string> q;
	for (int i = 0; i < destinationPath.length() + 1; i++)
	{
		if (checkPath[i] == '/' || checkPath[i] == '\0')
		{
			q.push(tempName);
			tempName = "";
		}
		else
		{
			tempName += checkPath[i];
		}
	}

	// Check if path exists or not
	/*cout << "Display Queue" << endl;*/
	string check = "";
	Node* destination = root;
	while (!q.empty())
	{
		check = q.front();
		q.pop();

		/*cout << "Check: " << check << " " << "Found: " << found->name << endl;*/
		if (destination->name == check)
		{
		}
		else if (destination->leftChild != NULL && destination->leftChild->name == check)
		{
			destination = destination->leftChild;
		}
		else if (destination->rightChild != NULL && destination->rightChild->name == check)
		{
			destination = destination->rightChild;
		}
		else
		{
			cout << "Path does not exist!" << endl;
			Sleep(3000);
			return;
		}
	}

	/*cout << "Found: " << found->name << endl;*/
	if (destination->leftChild != NULL)
	{
		if (destination->leftChild->name == found->name)
		{
			cout << "Directory with same name already exists!" << endl;

			cout << "Do You want to overwrite it? (Y/N): ";
			char overwrite;
			cin >> overwrite;

			while (overwrite != 'Y' && overwrite != 'y' && overwrite != 'N' && overwrite != 'n')
			{
				cout << "Invalid input! Please enter again: ";
				cin >> overwrite;
			}

			if (overwrite == 'Y' || overwrite == 'y')
			{
				destination->leftChild = found;
				cout << "Directory overwritten successfully!" << endl;
			}
			else
			{
				cout << "Directory not overwritten!" << endl;
			}
		}
		else
		{
			cout << "Directory already exists!" << endl;
			cout << "Name of directory already present: " << destination->leftChild->name << endl;

			cout << "Do You want to overwrite it? (Y/N): ";
			char overwrite;
			cin >> overwrite;

			while (overwrite != 'Y' && overwrite != 'y' && overwrite != 'N' && overwrite != 'n')
			{
				cout << "Invalid input! Please enter again: ";
				cin >> overwrite;
			}

			if (overwrite == 'Y' || overwrite == 'y')
			{
				destination->leftChild = found;
				cout << "Directory overwritten successfully!" << endl;
			}
			else
			{
				cout << "Directory not overwritten!" << endl;
			}
		}

	}
	else
	{
		destination->leftChild = found;
		cout << "Directory copied successfully!" << endl;
	}

	Sleep(4000);
}

void BinarySearchTree::copyFile()
{
	string fileToBeCopied;
	string destinationPath;

	cout << "Enter name of file to be copied: ";
	cin >> fileToBeCopied;

	cout << "Enter destination path: ";
	cin >> destinationPath;

	Node* found = NULL;

	search(root, fileToBeCopied, found);

	if (found == NULL || found->type != "File")
	{
		cout << "File not found!" << endl;
		Sleep(3000);
		return;
	}

	// Check if path exists or not

	char checkPath[200];
	for (int i = 0; i < 200; i++)
	{
		checkPath[i] = ' ';
	}
	strcpy_s(checkPath, destinationPath.c_str());
	checkPath[destinationPath.length()] = '\0';
	string tempName;
	int counter = 0;
	queue <string> q;
	for (int i = 0; i < destinationPath.length() + 1; i++)
	{
		if (checkPath[i] == '/' || checkPath[i] == '\0')
		{
			q.push(tempName);
			tempName = "";
		}
		else
		{
			tempName += checkPath[i];
		}
	}

	// Check if path exists or not
	/*cout << "Display Queue" << endl;*/
	string check = "";
	Node* destination = root;
	while (!q.empty())
	{
		check = q.front();
		q.pop();

		/*cout << "Check: " << check << " " << "Found: " << found->name << endl;*/
		if (destination->name == check)
		{
		}
		else if (destination->leftChild != NULL && destination->leftChild->name == check)
		{
			destination = destination->leftChild;
		}
		else if (destination->rightChild != NULL && destination->rightChild->name == check)
		{
			destination = destination->rightChild;
		}
		else
		{
			cout << "Path does not exist!" << endl;
			Sleep(3000);
			return;
		}
	}

	/*cout << "Found: " << found->name << endl;*/

	if (destination->rightChild != NULL)
	{
		if (destination->rightChild->name == found->name)
		{
			cout << "File with same name already exists!" << endl;

			cout << "Do You want to overwrite it? (Y/N): ";
			char overwrite;
			cin >> overwrite;

			while (overwrite != 'Y' && overwrite != 'y' && overwrite != 'N' && overwrite != 'n')
			{
				cout << "Invalid input! Please enter again: ";
				cin >> overwrite;
			}

			if (overwrite == 'Y' || overwrite == 'y')
			{
				destination->rightChild = found;
				cout << "File overwritten successfully!" << endl;
			}
			else
			{
				cout << "File not overwritten!" << endl;
			}
		}
		else
		{
			cout << "File already exists!" << endl;
			cout << "Name of file already present: " << destination->rightChild->name << endl;

			cout << "Do You want to overwrite it? (Y/N): ";
			char overwrite;
			cin >> overwrite;

			while (overwrite != 'Y' && overwrite != 'y' && overwrite != 'N' && overwrite != 'n')
			{
				cout << "Invalid input! Please enter again: ";
				cin >> overwrite;
			}

			if (overwrite == 'Y' || overwrite == 'y')
			{
				destination->rightChild = found;
				cout << "File overwritten successfully!" << endl;
			}
			else
			{
				cout << "File not overwritten!" << endl;
			}
		}
	}
	else
	{
		destination->rightChild = found;
		cout << "File copied successfully!" << endl;
	}

	Sleep(4000);
}

void BinarySearchTree::moveDirectory()
{
	string directoryName;

	cout << "Enter name of directory to be moved: ";
	cin >> directoryName;

	Node* found = NULL;

	search(root, directoryName, found);

	if (found == NULL || found->type != "Directory")
	{
		cout << "Directory not found!" << endl;
		Sleep(3000);
		return;
	}

	string destinationPath;

	cout << "Enter destination path: ";
	cin >> destinationPath;

	// Check if path exists or not

	char checkPath[200];

	for (int i = 0; i < 200; i++)
	{
		checkPath[i] = ' ';
	}

	strcpy_s(checkPath, destinationPath.c_str());

	checkPath[destinationPath.length()] = '\0';

	string tempName;

	int counter = 0;

	queue <string> q;

	for (int i = 0; i < destinationPath.length() + 1; i++)
	{
		if (checkPath[i] == '/' || checkPath[i] == '\0')
		{
			q.push(tempName);
			tempName = "";
		}
		else
		{
			tempName += checkPath[i];
		}
	}

	// Check if path exists or not

	/*cout << "Display Queue" << endl;*/

	string check = "";

	Node* destination = root;

	while (!q.empty())
	{
		check = q.front();
		q.pop();

		/*cout << "Check: " << check << " " << "Found: " << found->name << endl;*/

		if (destination->name == check)
		{
		}
		else if (destination->leftChild != NULL && destination->leftChild->name == check)
		{
			destination = destination->leftChild;
		}
		else if (destination->rightChild != NULL && destination->rightChild->name == check)
		{
			destination = destination->rightChild;
		}
		else
		{
			cout << "Path does not exist!" << endl;
			Sleep(3000);
			return;
		}
	}

	/*cout << "Found: " << found->name << endl;*/

	if (destination->leftChild == NULL)
	{
		destination->leftChild = found;
		cout << "Directory moved successfully!" << endl;

		// Traverse to parent of found and delete found from there

		char checkPath[200];

		for (int i = 0; i < 200; i++)
		{
			checkPath[i] = ' ';
		}

		strcpy_s(checkPath, found->path.c_str());

		checkPath[found->path.length()] = '\0';

		string tempName;

		int counter = 0;

		queue <string> q;

		for (int i = 0; i < found->path.length() + 1; i++)
		{
			if (checkPath[i] == '/' || checkPath[i] == '\0')
			{
				q.push(tempName);
				tempName = "";
			}
			else
			{
				tempName += checkPath[i];
			}
		}

		// Check if path exists or not

		/*cout << "Display Queue" << endl;*/

		string check = "";

		Node* parent = root;

		while (!q.empty())
		{
			check = q.front();
			q.pop();

			/*cout << "Check: " << check << " " << "Found: " << found->name << endl;*/

			if (parent->name == check)
			{
			}
			else if (parent->leftChild != NULL && parent->leftChild->name == check)
			{
				parent = parent->leftChild;
			}
			else if (parent->rightChild != NULL && parent->rightChild->name == check)
			{
				parent = parent->rightChild;
			}
			else
			{
				cout << "Path does not exist!" << endl;
				Sleep(3000);
				return;
			}
		}

		cout << "Parent: " << parent->name << endl;

		if (parent->leftChild != NULL && parent->leftChild->name == found->name)
		{
			// If left of parent has no left child then we delete it otherwise attach the left of found to the left of parent

			if (found->leftChild == NULL)
			{
				parent->leftChild = NULL;
			}
			else
			{
				parent->leftChild = found->leftChild;
			}
		}

	}
	else
	{
		// We shift the directory to the left child of destination and attach the left of found to the left of old destination

		if (found->leftChild != NULL)
		{
			Node* leftOfFound = found->leftChild;

			leftOfFound->name = found->leftChild->name;
			leftOfFound->path = found->leftChild->path;
			leftOfFound->type = found->leftChild->type;
			leftOfFound->leftChild = found->leftChild->leftChild;
			leftOfFound->rightChild = found->leftChild->rightChild;

			Node* leftOfDestination = destination->leftChild;

			leftOfDestination->name = destination->leftChild->name;
			leftOfDestination->path = destination->leftChild->path;
			leftOfDestination->type = destination->leftChild->type;
			leftOfDestination->leftChild = destination->leftChild->leftChild;
			leftOfDestination->rightChild = destination->leftChild->rightChild;

			leftOfDestination->leftChild = leftOfFound;

			destination->leftChild = found;

			destination->leftChild->leftChild = leftOfDestination;

			/*found = NULL;*/
		}
		else
		{
			cout << "dfslksd" << destination->leftChild->name << endl;
			found->leftChild = new Node();
			found->leftChild->name = destination->leftChild->name;
			found->leftChild->path = destination->leftChild->path;
			found->leftChild->type = destination->leftChild->type;

			if (destination->leftChild->leftChild != NULL && destination->leftChild->leftChild != found)
			{
				cout << "here" << endl;
				found->leftChild->leftChild = destination->leftChild->leftChild;
			}

			if (destination->leftChild->rightChild != NULL)
			{
				cout << "here2" << endl;
				found->leftChild->rightChild = destination->leftChild->rightChild;
			}


			destination->leftChild = found;

			/*found = NULL;*/
		}

		// Traverse to parent of found and delete found from there-------------------------------------------------------------------------------------------------------------------------------------------------------

		char checkPath[200];

		for (int i = 0; i < 200; i++)
		{
			checkPath[i] = ' ';
		}

		strcpy_s(checkPath, found->path.c_str());

		checkPath[found->path.length()] = '\0';

		string tempName;

		int counter = 0;

		queue <string> q;

		for (int i = 0; i < found->path.length() + 1; i++)
		{
			if (checkPath[i] == '/' || checkPath[i] == '\0')
			{
				q.push(tempName);
				tempName = "";
			}
			else
			{
				tempName += checkPath[i];
			}
		}

		// Check if path exists or not

		/*cout << "Display Queue" << endl;*/

		string check = "";

		Node* parent = root;

		while (!q.empty())
		{
			check = q.front();
			q.pop();

			/*cout << "Check: " << check << " " << "Found: " << found->name << endl;*/

			if (parent->name == check)
			{
			}
			else if (parent->leftChild != NULL && parent->leftChild->name == check)
			{
				parent = parent->leftChild;
			}
			else if (parent->rightChild != NULL && parent->rightChild->name == check)
			{
				parent = parent->rightChild;
			}
			else
			{
				cout << "Path does not exist!" << endl;
				Sleep(3000);
				return;
			}
		}

		cout << "Parent: " << parent->name << endl;
		if (parent->leftChild != NULL && parent->leftChild->name == found->name)
		{
			// If left of parent has no left child then we delete it otherwise attach the left of found to the left of parent
			cout << "here" << endl;
			if (found->leftChild == NULL)
			{
				cout << "here2" << endl;
				parent->leftChild = NULL;
			}
			else
			{
				cout << "here3" << endl;
				parent->leftChild = found->leftChild;
			}
		}


		/*cout << endl << " destination: " << destination->name << endl;
		cout << " found: " << found->name << endl;
		cout << "Directory moved successfully!" << endl;*/
	}

	Sleep(3000);
}

void BinarySearchTree::moveFile()
{
	string fileName;

	cout << "Enter name of file to be moved: ";

	cin >> fileName;

	Node* found = NULL;

	search(root, fileName, found);

	if (found == NULL || found->type != "File")
	{
		cout << "File not found!" << endl;
		Sleep(3000);
		return;
	}

	string destinationPath;

	cout << "Enter destination path: ";

	cin >> destinationPath;

	// Check if path exists or not

	char checkPath[200];

	for (int i = 0; i < 200; i++)
	{
		checkPath[i] = ' ';
	}

	strcpy_s(checkPath, destinationPath.c_str());

	checkPath[destinationPath.length()] = '\0';

	string tempName;

	int counter = 0;

	queue <string> q;

	for (int i = 0; i < destinationPath.length() + 1; i++)
	{
		if (checkPath[i] == '/' || checkPath[i] == '\0')
		{
			q.push(tempName);
			tempName = "";
		}
		else
		{
			tempName += checkPath[i];
		}
	}

	// Check if path exists or not

	/*cout << "Display Queue" << endl;*/

	string check = "";

	Node* destination = root;

	while (!q.empty())
	{
		check = q.front();
		q.pop();

		/*cout << "Check: " << check << " " << "Found: " << found->name << endl;*/

		if (destination->name == check)
		{
		}
		else if (destination->leftChild != NULL && destination->leftChild->name == check)
		{
			destination = destination->leftChild;
		}
		else if (destination->rightChild != NULL && destination->rightChild->name == check)
		{
			destination = destination->rightChild;
		}
		else
		{
			cout << "Path does not exist!" << endl;
			Sleep(3000);
			return;
		}
	}

	/*cout << "Found: " << found->name << endl;*/

	if (destination->rightChild != NULL)
	{
		if (destination->rightChild->name == found->name)
		{
			cout << "File with same name already exists!" << endl;

			cout << "Do You want to overwrite it? (Y/N): ";
			char overwrite;
			cin >> overwrite;

			while (overwrite != 'Y' && overwrite != 'y' && overwrite != 'N' && overwrite != 'n')
			{
				cout << "Invalid input! Please enter again: ";
				cin >> overwrite;
			}

			if (overwrite == 'Y' || overwrite == 'y')
			{
				destination->rightChild = found;
				cout << "File overwritten successfully!" << endl;
			}
			else
			{
				cout << "File not overwritten!" << endl;
			}
		}
		else
		{
			cout << "File already exists!" << endl;
			cout << "Name of file already present: " << destination->rightChild->name << endl;

			cout << "Do You want to overwrite it? (Y/N): ";
			char overwrite;
			cin >> overwrite;

			while (overwrite != 'Y' && overwrite != 'y' && overwrite != 'N' && overwrite != 'n')
			{
				cout << "Invalid input! Please enter again: ";
				cin >> overwrite;
			}

			if (overwrite == 'Y' || overwrite == 'y')
			{
				destination->rightChild = found;
				cout << "File overwritten successfully!" << endl;
			}
			else
			{
				cout << "File not overwritten!" << endl;
			}
		}
	}
	else
	{
		destination->rightChild = found;
		cout << "File moved successfully!" << endl;

		// Traverse to parent of found and delete found from there

		char checkPath[200];

		for (int i = 0; i < 200; i++)
		{
			checkPath[i] = ' ';
		}

		strcpy_s(checkPath, found->path.c_str());

		checkPath[found->path.length()] = '\0';

		string tempName;

		int counter = 0;

		queue <string> q;

		for (int i = 0; i < found->path.length() + 1; i++)
		{
			if (checkPath[i] == '/' || checkPath[i] == '\0')
			{
				q.push(tempName);
				tempName = "";
			}
			else
			{
				tempName += checkPath[i];
			}
		}

		// Check if path exists or not

		/*cout << "Display Queue" << endl;*/

		string check = "";

		Node* parent = root;

		while (!q.empty())
		{
			check = q.front();
			q.pop();

			/*cout << "Check: " << check << " " << "Found: " << found->name << endl;*/

			if (parent->name == check)
			{
			}
			else if (parent->leftChild != NULL && parent->leftChild->name == check)
			{
				parent = parent->leftChild;
			}
			else if (parent->rightChild != NULL && parent->rightChild->name == check)
			{
				parent = parent->rightChild;
			}
			else
			{
				cout << "Path does not exist!" << endl;
				Sleep(3000);
				return;
			}
		}

		cout << "Parent: " << parent->name << endl;

		if (parent->rightChild != NULL && parent->rightChild->name == found->name)
		{
			// If left of parent has no left child then we delete it otherwise attach the left of found to the left of parent

			if (found->leftChild == NULL)
			{
				parent->rightChild = NULL;
			}
			else
			{
				parent->rightChild = found->leftChild;
			}
		}
	}

	// Now we traverse to the parent of found and check if there are any children if not we ask the user if he wants to delete the directory

	checkPath[0] = '\0';

	for (int i = 0; i < 200; i++)
	{
		checkPath[i] = ' ';
	}

	strcpy_s(checkPath, found->path.c_str());

	checkPath[found->path.length()] = '\0';

	tempName = "";

	counter = 0;

	while (!q.empty())
	{
		q.pop();
	}

	for (int i = 0; i < found->path.length() + 1; i++)
	{
		if (checkPath[i] == '/' || checkPath[i] == '\0')
		{
			q.push(tempName);
			tempName = "";
		}
		else
		{
			tempName += checkPath[i];
		}
	}

	// Check if path exists or not

	/*cout << "Display Queue" << endl;*/

	check = "";

	Node* parent = root;

	while (!q.empty())
	{
		check = q.front();
		q.pop();

		/*cout << "Check: " << check << " " << "Found: " << found->name << endl;*/

		if (parent->name == check)
		{
		}
		else if (parent->leftChild != NULL && parent->leftChild->name == check)
		{
			parent = parent->leftChild;
		}
		else if (parent->rightChild != NULL && parent->rightChild->name == check)
		{
			parent = parent->rightChild;
		}
		else
		{
			cout << "Path does not exist!" << endl;
			Sleep(3000);
			return;
		}
	}

	cout << "Parent: " << parent->name << endl;

	if (parent->rightChild == NULL && parent->leftChild == NULL)
	{
		cout << "Directory is empty!" << endl;

		cout << "Do You want to delete it? (Y/N): ";
		char deleteInput;
		cin >> deleteInput;

		while (deleteInput != 'Y' && deleteInput != 'y' && deleteInput != 'N' && deleteInput != 'n')
		{
			cout << "Invalid input! Please enter again: ";
			cin >> deleteInput;
		}

		if (deleteInput == 'Y' || deleteInput == 'y')
		{

			// Delete the parent from tree

			deleteOnlyNodeFromTree(parent);

			cout << "Directory deleted successfully!" << endl;
		}
		else
		{
			cout << "Directory not deleted!" << endl;
		}
	}

	Sleep(3000);
}


void BinarySearchTree::renameDirectory()
{
	string directoryName;

	cout << "Enter name of directory to be renamed: ";
	cin >> directoryName;

	Node* found = NULL;

	search(root, directoryName, found);

	if (found == NULL || found->type != "Directory")
	{
		cout << "Directory not found!" << endl;
		Sleep(3000);
		return;
	}

	cout << "Enter new name of directory: ";
	cin >> directoryName;

	found->name = directoryName;

	// Now We Have To Change The Path Of All The Nodes In The Subtree

	queue <Node*> q;

	q.push(found);

	while (q.empty() != true)
	{
		Node* temp = q.front();
		q.pop();

		if (temp->leftChild != NULL)
		{
			temp->leftChild->path = temp->path + "/" + temp->name;
			q.push(temp->leftChild);
		}

		if (temp->rightChild != NULL)
		{
			temp->rightChild->path = temp->path + "/" + temp->name;
			q.push(temp->rightChild);
		}
	}

	//// Now we remove all the / in the paths of nodes who have nothing after / except for the left and right child of root
	//q.push(root);

	//while (q.empty() != true)
	//{
	//	Node* temp = q.front();
	//	q.pop();

	//	if (temp->leftChild != NULL)
	//	{
	//		if (temp->leftChild->leftChild == NULL && temp->leftChild->rightChild == NULL)
	//		{
	//			temp->leftChild->path.erase(temp->leftChild->path.length() - 1, 1);
	//		}
	//		q.push(temp->leftChild);
	//	}

	//	if (temp->rightChild != NULL)
	//	{
	//		if (temp->rightChild->leftChild == NULL && temp->rightChild->rightChild == NULL)
	//		{
	//			temp->rightChild->path.erase(temp->rightChild->path.length() - 1, 1);
	//		}
	//		q.push(temp->rightChild);
	//	}
	//}

	//// Now we remove the first / in path string of all nodes in tree

	//q.push(root);

	//while (q.empty() != true)
	//{
	//	Node* temp = q.front();
	//	q.pop();

	//	if (temp->leftChild != NULL)
	//	{
	//		temp->leftChild->path.erase(0, 1);
	//		q.push(temp->leftChild);
	//	}

	//	if (temp->rightChild != NULL)
	//	{
	//		temp->rightChild->path.erase(0, 1);
	//		q.push(temp->rightChild);
	//	}
	//}



	cout << "Directory renamed successfully!" << endl;

	Sleep(3000);
}

void BinarySearchTree::renameFile()
{
	string fileName;

	cout << "Enter name of file to be renamed: ";
	cin >> fileName;

	Node* found = NULL;

	search(root, fileName, found);

	if (found == NULL || found->type != "File")
	{
		cout << "File not found!" << endl;
		Sleep(3000);
		return;
	}

	cout << "Enter new name of file: ";
	cin >> fileName;

	found->name = fileName;

	cout << "File renamed successfully!" << endl;

	Sleep(3000);
}

void BinarySearchTree::importDirectoryFromFile()
{
	// Import The Tree From A File

	ifstream file("exportedTree.txt");

	if (file.is_open())
	{
		string line;
		getline(file, line);

		while (getline(file, line))
		{
			string name = "";
			string path = "";
			string type = "";

			int counter = 0;



			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == ',')
				{
					counter++;
					continue;
				}

				if (counter == 0)
				{
					name += line[i];
				}
				else if (counter == 1)
				{
					path += line[i];
				}
				else if (counter == 2)
				{
					type += line[i];
				}
			}
			cout << "Name: " << name << " Path: " << path << " Type: " << type << endl;
			if (type == "Directory")
			{
				createDirectory(name, path);
			}
			else if (type == "File")
			{
				createFile(name, path);
			}
		}
	}

}

void BinarySearchTree::exportDirectoryToFile()
{
	// Export The Tree To A File

	Node* temp = NULL;

	ofstream file("exportedTree.txt");

	file << "Name,Path,Type" << endl;

	queue <Node*> q;

	q.push(root);

	while (q.empty() != true)
	{
		temp = q.front();
		q.pop();

		file << temp->name << "," << temp->path << "," << temp->type << endl;

		if (temp->leftChild != NULL)
		{
			q.push(temp->leftChild);
		}

		if (temp->rightChild != NULL)
		{
			q.push(temp->rightChild);
		}
	}

	file.close();
}

void BinarySearchTree::setAllPathsToNull(Node* node, string parentN = "/")
{
	if (node != NULL)
	{
		setAllPathsToNull(node->leftChild, node->name);
		setAllPathsToNull(node->rightChild, node->name);
		node->path = "";
		node->parentName = parentN;
		/*cout << "Name: " << node->name << " Parent: " << node->parentName << endl;*/
	}
}

// Using Level Order Traversal To Set All Paths For Left and Right Child of Root
void BinarySearchTree::updateAllPaths(Node* node)
{
	Node* found = NULL;
	if (node != NULL)
	{
		// We use the parentName string to update the path of all nodes and using level order traversal

		queue <Node*> q;

		q.push(node);

		while (q.empty() != true)
		{
			Node* temp = q.front();
			q.pop();

			if (temp->parentName == "/")
			{
				temp->path = "/";

				if (temp->leftChild != NULL)
				{
					temp->leftChild->parentName = temp->name;
				}

				if (temp->rightChild != NULL)
				{
					temp->rightChild->parentName = temp->name;
				}
			}
			else
			{
				temp->path = temp->parentName + "/";
				if (temp->leftChild != NULL)
				{
					temp->leftChild->parentName = temp->parentName + "/" + temp->name;
				}

				if (temp->rightChild != NULL)
				{
					temp->rightChild->parentName = temp->parentName + "/" + temp->name;
				}
				/*cout << "Path: " << temp->path << endl;*/
			}

			cout << "NameQ: " << temp->name << " Parent: " << temp->parentName << endl;
			if (temp->leftChild != NULL)
			{
				q.push(temp->leftChild);
			}

			if (temp->rightChild != NULL)
			{
				q.push(temp->rightChild);
			}
		}



		//found = node;
		//
		//found->name = "root";

		//// Now We Have To Change The Path Of All The Nodes In The Subtree

		//queue <Node*> q;

		//q.push(found);

		//while (q.empty() != true)
		//{
		//	Node* temp = q.front();
		//	q.pop();

		//	if (temp->leftChild != NULL)
		//	{
		//		temp->leftChild->path = temp->path  + temp->name + "/";
		//		q.push(temp->leftChild);
		//	}

		//	if (temp->rightChild != NULL)
		//	{
		//		temp->rightChild->path = temp->path  + temp->name + "/";
		//		q.push(temp->rightChild);
		//	}
		//}

		// Now we have to remove the last and first slash from the path of all nodes except root node

		q.push(node);

		while (q.empty() != true)
		{
			Node* temp = q.front();
			q.pop();

			if (temp != root)
			{
				temp->path.erase(temp->path.length() - 1, 1);
				/*temp->path.erase(0, 1);*/
			}

			if (temp->leftChild != NULL)
			{
				q.push(temp->leftChild);
			}

			if (temp->rightChild != NULL)
			{
				q.push(temp->rightChild);
			}
		}

		root->path = "/";
		root->leftChild->path += "/";
		root->rightChild->path += "/";

		//root->leftChild->path = root->name + "/";
		//root->rightChild->path = root->name + "/";

		//queue <Node*> q;

		//// First We Update The Path Of Left and Right Child Of Root
		//
		//q.push(root->leftChild);

		//while (q.empty() != true)
		//{
		//	Node* temp = q.front();
		//	q.pop();

		//	temp->path = temp->path + temp->name + "/";

		//	if (temp->leftChild != NULL)
		//	{
		//		q.push(temp->leftChild);
		//	}

		//	if (temp->rightChild != NULL)
		//	{
		//		q.push(temp->rightChild);
		//	}
		//}

		//q.push(root->rightChild);

		//while (q.empty() != true)
		//{
		//	Node* temp = q.front();
		//	q.pop();

		//	temp->path = temp->path + temp->name + "/";

		//	if (temp->leftChild != NULL)
		//	{
		//		q.push(temp->leftChild);
		//	}

		//	if (temp->rightChild != NULL)
		//	{
		//		q.push(temp->rightChild);
		//	}
		//}

		////// Now we have to remove the last and first slash from the path of all nodes except root node

		////q.push(node);

		////while (q.empty() != true)
		////{
		////	Node* temp = q.front();
		////	q.pop();

		////	if (temp != root)
		////	{
		////		temp->path.erase(temp->path.length() - 1, 1);
		////		temp->path.erase(0, 1);
		////	}

		////	if (temp->leftChild != NULL)
		////	{
		////		q.push(temp->leftChild);
		////	}

		////	if (temp->rightChild != NULL)
		////	{
		////		q.push(temp->rightChild);
		////	}
		////}

	}
}

int main()
{
	int userMainInput = -1;

	Node* search = NULL;
	string searchName;

	BinarySearchTree* bst = new BinarySearchTree();
	int heightOfTree = 0;

	Node* destination = NULL;
	Node* source = NULL;

	while (userMainInput != 0)
	{
		string type = "";
		search = NULL;

		bst->setAllSearchStatusToFalse(bst->getRoot());

		heightOfTree = bst->calculateHeight(bst->getRoot());

		bst->clearQueueOfNodes();
		bst->clearStackOfNodes();

		/*bst->levelorderTraversal(bst->getRoot());*/

		/*Sleep (100000);*/
		system("cls");

		cout << "------------------------ Medical Device Embedded System ------------------------" << endl;
		cout << "1. Create Directory" << endl;
		cout << "2. Create File" << endl;
		cout << "3. Delete Directory" << endl;
		cout << "4. Delete File" << endl;
		cout << "5. List File Directory" << endl;
		cout << "6. Merge Directories" << endl;
		cout << "7. Search Directory" << endl;
		cout << "8. Search File" << endl;
		cout << "9. Copy Directory" << endl;
		cout << "10. Copy File" << endl;
		cout << "11. Move Directory" << endl;
		cout << "12. Move File" << endl;
		cout << "13. Rename Directory" << endl;
		cout << "14. Rename File" << endl;
		cout << "15. Import Directory From File" << endl;
		cout << "16. Export Directory To File" << endl;
		cout << "17. Update All Paths" << endl;

		cout << "0. Exit" << endl;

		cout << endl;

		cout << "Enter your choice: ";
		cin >> userMainInput;

		switch (userMainInput)
		{
		case 1:
			bst->createDirectory();

			break;

		case 2:

			bst->createFile();

			break;

		case 3:

			bst->deleteDirectory();

			break;

		case 4:

			bst->deleteFile();

			break;

		case 5:

			cout << endl << endl;
			bst->levelorderTraversal(bst->getRoot());
			cout << endl << endl;

			Sleep(5000);

			break;


		case 6:

			cout << "Enter name of destination directory: ";
			cin >> searchName;

			bst->search(bst->getRoot(), searchName, search);

			if (search == NULL || search->type != "Directory")
			{
				cout << "Destination Directory not found!" << endl;
				Sleep(3000);
				break;
			}

			destination = search;

			bst->clearStackOfNodes();

			cout << "Enter name of source directory: ";
			cin >> searchName;

			bst->search(bst->getRoot(), searchName, search);

			if (search == NULL || search->type != "Directory")
			{
				cout << "Source Directory not found!" << endl;
				Sleep(3000);
				break;
			}

			source = search;

			bst->clearStackOfNodes();

			bst->mergeDirectory(destination, source);
			break;


		case 7:

			// Stored in Stack
			cout << "Enter name of directory to search: ";
			cin >> searchName;

			bst->search(bst->getRoot(), searchName, search);

			bst->displaySearchResults("Directories");

			Sleep(3000);
			break;


		case 8:

			cout << "Enter name of file to search: ";
			cin >> searchName;

			bst->search(bst->getRoot(), searchName, search);

			bst->displaySearchResults("Files");

			Sleep(3000);

			break;

		case 9:

			bst->copyDirectory();

			break;

		case 10:

			bst->copyFile();

			break;

		case 11:

			bst->moveDirectory();

			break;

		case 12:

			bst->moveFile();

			break;

		case 13:

			bst->renameDirectory();

			break;

		case 14:

			bst->renameFile();

			break;

		case 15:

			bst->setRoot(NULL);
			bst->importDirectoryFromFile();

			break;

		case 16:

			bst->exportDirectoryToFile();

			break;

		case 17:

			bst->setAllPathsToNull(bst->getRoot()->rightChild);
			bst->setAllPathsToNull(bst->getRoot()->leftChild);
			bst->levelorderTraversal(bst->getRoot());
			bst->updateAllPaths(bst->getRoot());
			/*Sleep(10000);*/
			break;
		default:

			break;

		}

		/*bst->setAllPathsToNull(bst->getRoot()->rightChild);----------------------------------------------------------------------------------------------------------------------------------------------------------
		bst->setAllPathsToNull(bst->getRoot()->leftChild);
		bst->levelorderTraversal(bst->getRoot());
		bst->updateAllPaths(bst->getRoot());*/
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
