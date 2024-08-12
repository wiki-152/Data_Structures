#include <iostream>
#include <Windows.h>

using namespace std;

class NodeForCityMap
{
public:
	int vertex;
	NodeForCityMap* next;
	int weight;

	NodeForCityMap();
};

NodeForCityMap::NodeForCityMap()
{
	vertex = 0;
	next = NULL;
	weight = 0;
}

class AdjacentListForCityMap
{
public:
	NodeForCityMap* head;
};

class GraphForCityMap
{
private:
	int V;
	AdjacentListForCityMap* array;

public:

	GraphForCityMap();

	// Function to add new vertex

	void addIntersectionID(int v);

	NodeForCityMap* createNode(int v, int w);

	void addRoads(int s, int d, int w);

	void printGraph();

	void dijkstra(int source, int destination);

	~GraphForCityMap();

};

GraphForCityMap::GraphForCityMap()
{
	V = 0;
	array = NULL;
}

// Function to add new vertex each time 

void GraphForCityMap::addIntersectionID(int v)
{
	V += 1;
	
	array = new AdjacentListForCityMap[V];

	for (int i = 0; i < V; i++)
	{
		array[i].head = NULL;
	}
}

NodeForCityMap* GraphForCityMap::createNode(int v, int w)
{
	NodeForCityMap* newNode = new NodeForCityMap;
	newNode->vertex = v;
	newNode->weight = w;
	newNode->next = NULL;
	return newNode;
}

void GraphForCityMap::addRoads(int s, int d, int w)
{
	// First we check if edge already exists

	NodeForCityMap* temp = array[s].head;
	while (temp != NULL)
	{
		if (temp->vertex == d)
		{
			cout << "Edge already exists" << endl;
			Sleep (2000);
			return;
		}
		temp = temp->next;
	}

	NodeForCityMap* newNode = createNode(d, w);
	newNode->next = array[s].head;
	array[s].head = newNode;

	newNode = createNode(s, w);
	newNode->next = array[d].head;
	array[d].head = newNode;
}

void GraphForCityMap::printGraph()
{
	for (int i = 0; i < V; i++)
	{
		NodeForCityMap* temp = array[i].head;
		cout << "Intersection ID " << i << " is connected to: " << endl;
		while (temp)
		{
			cout << temp->vertex << " (Length: " << temp->weight << ") ";
			temp = temp->next;
		}
		cout << endl;
	}
}

// Dijsktra's Algorithmon the basis of weight and using priority queue 
void GraphForCityMap::dijkstra(int source, int destination)
{
	int* distance = new int[V];
	int* parent = new int[V];
	bool* visited = new bool[V];

	for (int i = 0; i < V; i++)
	{
		distance[i] = INT_MAX;
		parent[i] = -1;
		visited[i] = false;
	}

	distance[source] = 0;

	for (int i = 0; i < V - 1; i++)
	{
		int minVertex = -1;
		for (int j = 0; j < V; j++)
		{
			if (!visited[j] && (minVertex == -1 || distance[j] < distance[minVertex]))
			{
				minVertex = j;
			}
		}

		visited[minVertex] = true;

		NodeForCityMap* temp = array[minVertex].head;
		while (temp)
		{
			int neighbor = temp->vertex;
			int weight = temp->weight;

			if (!visited[neighbor])
			{
				int dist = distance[minVertex] + weight;
				if (dist < distance[neighbor])
				{
					distance[neighbor] = dist;
					parent[neighbor] = minVertex;
				}
			}
			temp = temp->next;
		}
	}

	cout << "Shortest path from " << source << " to " << destination << " is: " << endl;
	cout << source << " ";
	int i = destination;
	while (i != source)
	{
		cout << parent[i] << " ";
		i = parent[i];
	}
	cout << endl;
	cout << "Length: " << distance[destination] << endl;

	delete[] distance;
	delete[] parent;
	delete[] visited;
}

GraphForCityMap::~GraphForCityMap()
{
	for (int i = 0; i < V; i++)
	{
		NodeForCityMap* temp = array[i].head;
		while (temp)
		{
			NodeForCityMap* prev = temp;
			temp = temp->next;
			delete prev;
		}
	}
	delete[] array;
}


int main()
{
	int input = -1;
	int sourceVertex, destinationVertex;

	GraphForCityMap graph;

	while (input != 0)
	{
		cout << "1. Add Intersection ID" << endl;
		cout << "2. Add Roads" << endl;
		cout << "3. Display Graph" << endl;
		cout << "4. Find Shortest Path" << endl;
		cout << "0. Exit" << endl;

		cout << "Enter your choice: ";
		cin >> input;

		while (input < 0 || input > 4)
		{
			cout << "Invalid input. Enter again: ";
			cin >> input;
		}

		switch (input)
		{
		case 1:
			int v;
			cout << "Enter Intersection ID: ";
			cin >> v;

			graph.addIntersectionID(v);

			break;

		case 2:
			int s, d, w;
			cout << "Enter source: ";
			cin >> s;
			cout << "Enter destination: ";
			cin >> d;
			cout << "Enter Length: ";
			cin >> w;

			graph.addRoads(s, d, w);

			break;

		case 3:
			graph.printGraph();

			Sleep (5000);

			break;

			case 4:

				cout << "Enter source: ";
				cin >> sourceVertex;

				cout << "Enter destination: ";
				cin >> destinationVertex;

				graph.dijkstra(sourceVertex, destinationVertex);

				Sleep (5000);

				break;
		

		}

		system("CLS");
	}


	return 0;
}