#pragma once

#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	string name;
	int vertex;
	Node* next;
	int weight; // friends Counter

	Node(int v);
};


class AdjacentList
{
public:
	Node* head;
};

class Graph
{
	int V;
	AdjacentList* array;

public:

	Graph(int t);

	~Graph();

	Node* createNode(int v, int w);

	void addEdge(int source, int dest);

	void printGraph();

	void mostFriends();

	void leastFriends();

	void specifiedFriends();

	void mutualFriends();

	// Getters Setters 

	int getTotalVertices();
	void setTotalVertices(int total);

	void setArray();
	AdjacentList* getArray();

	int getVertexAt(string n);

};





