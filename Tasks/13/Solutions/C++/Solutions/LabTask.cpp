// LabTask.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"

using namespace std;


Graph::Graph(int t)
{
	V = t;
	array = new AdjacentList[V];

	for (int i = 0; i < V; i++)
	{
		array[i].head = NULL;
	}
}

Node* Graph::createNode(int v, int w)
{
	Node* newNode = new Node;
	newNode->vertex = v;
	newNode->weight = w;
	newNode->next = NULL;
	return newNode;
}

void Graph::addEdge(int source, int destination)
{
	// Condition to check if already exists

	Node* temp = array[source].head;
	while (temp != NULL)
	{
		if (temp->vertex == destination)
		{
			cout << "Edge already exists" << endl;
			return;
		}
		temp = temp->next;
	}

	cout << "Enter weight: ";
	int w;
	cin >> w;
	Node* newNode = createNode(destination,w);
	newNode->next = array[source].head;
	array[source].head = newNode;


	/*cout << "Enter weight: ";
	cin >> w;*/
	newNode = createNode(source, w);
	newNode->next = array[destination].head;
	array[destination].head = newNode;


}

void Graph::printGraph()
{
	Node* temp = new Node;
	for (int i = 0; i < V; i++)
	{
		temp = array[i].head;

		cout << endl << "Vertex " << i << " is linked to ";
		while (temp != NULL)
		{
			cout<< "Vertex " << temp->vertex;

			cout << " ( weight : " << temp->weight << " ) ";

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

Graph::~Graph()
{
	delete[] array;
}

int main()
{
	int vertices = -1;
	int edges = -1;
	int sourceVertex = -1;
	int destinationVertex = -1;

	cout << "Enter number of vertices: ";
	cin >> vertices;
	
	Graph g(vertices);
	
	cout << "Enter number of edges: ";
	cin >> edges;
	
	
	for (int i = 0; i < edges; i++)
	{
		cout << "Enter source: ";
		cin >> sourceVertex;
		cout << "Enter destination: ";
		cin >> destinationVertex;
		g.addEdge(sourceVertex, destinationVertex);
	}

	g.printGraph();
	
	return 0;
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
