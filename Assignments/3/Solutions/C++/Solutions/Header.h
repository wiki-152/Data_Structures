// Muhammad_Waqas_Shahid_Khan_22i2469
#pragma once

#include <iostream>

using namespace std;

// Can be a file or a directory
class Node
{
public:
	string name;
	string path;
	string type;
	Node* leftChild;
	Node* rightChild;
	bool searchStatus;
	string parentName;

	Node();
};

class BinarySearchTree
{
private:

	Node* root;

	int heightOfTree;

	queue <Node*> queueOfNodes;

	stack <Node*> stackOfNodes;

public:

	BinarySearchTree();
	~BinarySearchTree();

	void setRoot(Node* node);
	Node* getRoot();

	void deleteOnlyNodeFromTree(Node* node);

	void preorderTraversal(Node* node);
	void inorderTraversal(Node* node);
	void postorderTraversal(Node* node);

	void levelorderTraversal(Node* node, int previousCounter = 1, int currentCounter = 1);

	void mergeDirectory(Node* node1, Node* node2);

	int calculateHeight(Node* node);
	void setHeightOfTree(int height);
	int getHeightOfTree();

	void clearStackOfNodes();
	void clearQueueOfNodes();

	void search(Node* node, string name, Node*& found);
	void setAllSearchStatusToFalse(Node* node);
	void displaySearchResults(string type);

	void createDirectory(string name, string path);
	void deleteDirectory();

	void createFile(string name, string path);
	void deleteFile();

	void copyDirectory();
	void copyFile();

	void moveDirectory();
	void moveFile();

	void renameDirectory();
	void renameFile();

	void importDirectoryFromFile();
	void exportDirectoryToFile();

	void setAllPathsToNull(Node* node, string parentN);
	void updateAllPaths(Node* node);
};


