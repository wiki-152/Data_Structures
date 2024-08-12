#pragma once

#include <iostream>

using namespace std;

class Node
{
public:
	int key;
	Node* left;
	Node* right;
	int height;
};

class AVL
{
public:

	Node* root;

	AVL()
	{
		root = NULL;
	}

    int height(Node* node)
    {
        if (node == NULL)
        {
             return 0;
        }
        return node->height;
    }

    int getBalance(Node* node)
    {
        if (node == NULL)
        {
			return 0;
		}

        return height(node->left) - height(node->right);

	}

    Node* leftRotate(Node* x)
    {
        Node *y = x->right;
        Node *z = x->left;
        y->left = x;
        x->right = z;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* rightRotate(Node* x)
    {
        Node *y = x->left;
        Node *z = x->right;
        y->right = x;
        x->left = z;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(int input_key, Node* r)
    {
        Node* node = new Node;
        if (r == NULL)
        {
            Node* new_node = new Node;
            new_node->key = input_key;
            new_node->left = NULL;
            new_node->right = NULL;
            new_node->height = 1;

            if (root == NULL)
            {
                root = new_node;
            }
            node = new_node;
            return new_node;
        }
        

        if (input_key < r->key)
        {
            r->left = insert(input_key, r->left);
        }
        else if (input_key > r->key)
        {
            r->right = insert(input_key, r->right);
        }

        r->height = 1 + max(height(r->left), height(r->right));

        int balance = getBalance(r);
        // Left Left Case
        if (balance > 1 && input_key < r->left->key)
        {
			return rightRotate(r);
		}
        // Right Right Case
        else if (balance < -1 && input_key > r->right->key)
        {
            return leftRotate(r);
        }
        // Left Right Case
        else if (balance > 1 && input_key > r->left->key)
        {
			r->left = leftRotate(r->left);
			return rightRotate(r);
		}
        // Right Left Case
        else if (balance < -1 && input_key < r->right->key)
        {
			r->right = rightRotate(r->right);
			return leftRotate(r);
		}

        return r;
    }


	void inorderTraversal(Node* r)
	{
		if (r != NULL)
		{
			inorderTraversal(r->left);
			cout << r->key << " ";
			inorderTraversal(r->right);
		}
	}

};


