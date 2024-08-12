#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	AVL tree;
	Node *root = NULL;
	root = tree.insert(5, tree.root);
	root = tree.insert(2, tree.root);
	root = tree.insert(7, tree.root);
	root = tree.insert(3, tree.root);
	root = tree.insert(15, tree.root);
	root = tree.insert(6, tree.root);

	cout << "Inorder traversal AVL tree is \n";
	tree.inorderTraversal(tree.root);

	return 0;
}
