// i222469_Waqas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<Windows.h>

#include "i222469_Waqas_E_BSSE_Q1.h"

using namespace std;

Node::Node(int v)
{
	name = "";
	vertex = v;
	next = NULL;
	weight = 0;
}

Graph::Graph(int t)
{
	V = t;
	array = new AdjacentList[V];

	for (int i = 0; i < V; i++)
	{
		array[i].head = new Node(i);
	}
}

Graph::~Graph()
{
	delete[] array;
}

Node* Graph::createNode(int v, int w)
{
	Node* newNode = new Node(v);
	newNode->vertex = v;
	newNode->weight = w;
	newNode->next = NULL;
	return newNode;
}

void Graph::addEdge(int source, int destination)
{
	Node* temp = array[source].head;

	while (temp != NULL)
	{
		if (temp->vertex == destination)
		{
			cout << "Edge already exists!" << endl;
			return;
		}
		temp = temp->next;
	}

	string n1 = array[destination].head->name;
	string n2 = array[source].head->name;

	/*array[destination].head->weight*/
	Node* newNode = createNode(destination, 0);
	newNode->name = n1;
	Node* temp1 = array[source].head;
	while (temp1->next != NULL)
	{
		temp1 = temp1->next;
	}
	temp1->next = newNode;

	/*newNode->next = array[source].head;
	array[source].head = newNode;*/


	newNode = createNode(source, 0);
	newNode->name = n2;
	Node* temp2 = array[destination].head;
	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp2->next = newNode;

	/*newNode->next = array[destination].head;
	array[destination].head = newNode;*/

	array[source].head->weight += 1;
	array[destination].head->weight += 1;
}

void Graph::printGraph()
{

	for (int i = 0; i < V; i++)
	{
		Node* temp = array[i].head;

		cout << endl << "Name : " << temp->name << endl;
		cout << "Total Friends : " << temp->weight << endl;
		cout << "Vertex " << i << " is linked to ";

		while (temp != NULL)
		{
			cout << "Vertex " << temp->vertex << "(" << temp->name << ")";

			if (temp->next != NULL && temp->next->next != NULL)
			{
				cout << ", ";
			}
			else if (temp->next != NULL && temp->next->next == NULL)
			{
				cout << " and ";
			}

			temp = temp->next;
		}
		cout << endl;
	}
}

inline void Graph::mostFriends()
{
	int max = -1;

	for (int i = 0; i < V; i++)
	{
		if (max < array[i].head->weight)
		{
			max = array[i].head->weight;
		}
	}

	cout << "Person(s) with most friends are : " << endl;
	for (int i = 0; i < V; i++)
	{
		if (max == array[i].head->weight)
		{
			cout << array[i].head->name << endl;
		}
	}

	cout << endl;

}

inline void Graph::leastFriends()
{
	int min = array[0].head->weight;

	for (int i = 0; i < V; i++)
	{
		if (min > array[i].head->weight)
		{
			min = array[i].head->weight;
		}
	}

	cout << "Person(s) with least friends are : " << min << endl;
	for (int i = 0; i < V; i++)
	{
		if (min == array[i].head->weight)
		{
			cout << array[i].head->name << endl;
		}
	}

	cout << endl;
}

inline void Graph::specifiedFriends()
{
	cout << "Enter Number of friends : ";
	int n = 0;
	cin >> n;

	cout << "Person(s) :";
	for (int i = 0; i < V; i++)
	{
		if (n == array[i].head->weight)
		{
			cout << array[i].head->name << endl;
		}
	}
	cout << endl;


}

inline void Graph::mutualFriends()
{
	string n1, n2;
	cout << "Name 1;";
	cin >> n1;

	cout << "Name 2;";
	cin >> n2;

	int v1 = getVertexAt(n1);
	int v2 = getVertexAt(n2);

	Node* temp = array[v1].head;

	cout << "Mutual Friends are" << endl;
	while (temp != NULL)
	{
		Node* temp2 = array[v1].head;
		while (temp2 != NULL)
		{
			if (temp->name == temp2->name && temp2->name != n1 && temp2->name != n2)
			{
				cout << temp->name << endl;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

inline int Graph::getTotalVertices()
{
	return V;
}

inline void Graph::setTotalVertices(int total)
{
	V = total;
}

inline void Graph::setArray()
{
	cout << "Enter Unique Names(Press Enter After Each Name) ";

	for (int i = 0; i < V; i++)
	{
		string na = "";
		cin >> na;
		array[i].head->name = na;
	}
}

inline AdjacentList* Graph::getArray()
{
	return nullptr;
}

inline int Graph::getVertexAt(string n)
{
	for (int i = 0; i < V; i++)
	{
		if (n == array[i].head->name)
		{
			return i;
		}
	}
	return -1;
}



int main()
{
	int totalVertices = 0;
	cout << "Enter Total Number of friends : ";
	cin >> totalVertices;

	Graph graph(totalVertices);

	graph.setArray();

	int input = -1;
	int v1 = -1;
	int v2 = -1;
	string n1 = "";
	string n2 ="";

	while (input != 0)
	{
		cout << endl;
		
		cout << "Graph Displaz" << endl;
		graph.printGraph();

		cout << "1. Add Friend" << endl;
		cout << "2. Most Friends" << endl;
		cout << "3. Least Friends" << endl;
		cout << "4. person with Specified  Friends Num " << endl;
		cout << "5. Mutual Friends" << endl;
		cout << "6. Largest Connected Community" << endl;
		
		cout << "0. Exit" << endl;

		cout << "Enter Choice : ";
		cin >> input;

		switch (input)
		{
		case 1:

			/*cout << "Enter Friend 1 Name : ";
			cin >> n1;

			cout << "Enter Friend 2 Name : ";
			cin >> n2;

			v1 = graph.getVertexAt(n1);

			if (v1 == -1)
			{
				cout << "Not Found";
				break;
			}

			v2 = graph.getVertexAt(n2);

			if (v2 == -1)
			{
				cout << "Not Found";
				break;
			}

			cout << v1 << v2;*/

			cout << "Enter Friend 1 Vertex :";
			cin >> v1;

			cout << "Enter Friend 2 Vertex :";
			cin >> v2;



			graph.addEdge(v1, v2);

			break;

		case 2:

			graph.mostFriends();
			break;

		case 3:
			graph.leastFriends();
			break;

		case 4:

			graph.specifiedFriends();
			break;

		case 5:
			graph.mutualFriends();
			break;

		case 6:
			break;

		case 0:

			break;

		default:
			cout << "Invalid Input!" << endl;
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
