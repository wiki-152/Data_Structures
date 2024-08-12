#pragma once

#include <iostream>

using namespace std;



class Node
{
public:
	int vertex;
	Node* next;
	int weight;
};

class AdjacentList
{
public:
	Node* head;
};

class Graph
{
private:
	int V;
	AdjacentList* array;

public:

	Graph(int t);

	Node* createNode(int v, int w);

	void addEdge(int source, int dest);

	void printGraph();

	~Graph();

};