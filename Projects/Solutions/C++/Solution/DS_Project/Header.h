// Muhammad_Waqas_Shahid_Khan_22I2469
// Abdul_Raffay_22I2546

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

using namespace std;

// Class Vector 
template <class T>
class NodeForVector
{
public:

	T value;
	NodeForVector<T>* next;

	NodeForVector();
};

template <class T>
class Vector
{
	NodeForVector<T>* head;
	NodeForVector<T>* tail;

	int size;

public:

	Vector();

	void push(T value);

	void pop();

	void insert(int index, T value);

	void remove(int index);

	void clear();

	void print();

	bool isEmpty();

	// Getters and Setters

	int getSize();
	void setSize(int s);

	NodeForVector<T>* getHead();
	void setHead(NodeForVector<T>* h);

	NodeForVector<T>* getTail();
	void setTail(NodeForVector<T>* t);

	~Vector();
};



// Class Queue using template and linked list
template <class T>
class NodeForQueue
{
public:

	T value;
	NodeForQueue<T>* next;

	NodeForQueue();
};

template <class T>
class Queue
{
	NodeForQueue<T>* head;
	NodeForQueue<T>* tail;

	int size;

public:

	Queue();

	void enqueue(T value);

	void dequeue();

	void clear();

	void print();

	bool isEmpty();

	bool find(T value);

	// Getters and Setters

	int getSize();
	void setSize(int s);

	NodeForQueue<T>* getHead();
	void setHead(NodeForQueue<T>* h);

	NodeForQueue<T>* getTail();
	void setTail(NodeForQueue<T>* t);

	~Queue();
};

// Class Stack using template and linked list
template <class T>
class NodeForStack
{
public:

	T value;
	NodeForStack<T>* next;

	NodeForStack();
};


template <class T>
class Stack
{
	NodeForStack<T>* head;

	int size;

public:

	Stack();

	void push(T value);

	void pop();

	void clear();

	void print();

	bool isEmpty();

	// Top

	T top();

	// Getters and Setters

	int getSize();
	void setSize(int s);

	NodeForStack<T>* getHead();
	void setHead(NodeForStack<T>* h);

	~Stack();
};

// Class Maze
class Maze
{
private:

	int rows;
	int columns;
	int** maze;
	char mode;

public:

	Maze();

	void createEasyMaze();

	void createMediumMaze();

	void createHardMaze();

	void printMaze();

	// Getters and Setters

	int getRows();
	void setRows(int r);

	int getColumns();
	void setColumns(int c);

	void deleteMaze();

	int** getMaze();
	void setMaze(int** m);

	char getMode();
	void setMode(char m);

	int getObstacles();
	void setObstacles(int o);

	int getPowerUps();
	void setPowerUps(int p);

	int getCoins();
	void setCoins(int c);

	~Maze();
};

// Class Graph
class NodeForGraph
{
public:

	bool path;
	bool wall;
	bool powerUp;
	bool obstacle;
	bool coin;
	bool isHere;
	bool start;
	bool end;


	char value;

	NodeForGraph* up;
	NodeForGraph* down;
	NodeForGraph* left;
	NodeForGraph* right;

	int x;
	int y;
	int weight;



	NodeForGraph();

	~NodeForGraph();
};

class Graph
{
private:
	int totalNodes;

	NodeForGraph** array;
	int rows;
	int columns;
	char mode;
	int lives;

	bool completed;

	int obstacles;
	int powerUps;
	int coins;

	Queue<char> queueForObstacles;

	Queue<char> queueForPowerUps;

	Stack<char> stackForCoins;

	double score;

public:

	Graph();
	~Graph();

	void createGraphFromMaze(Maze mazeObj);

	void deletePreviousGraphAndCopyNew(Maze mazeObj);

	void placeRandomObstacles();

	void placeRandomPowerUps();

	void placeRandomCoins();

	bool moveUp();
	bool moveDown();
	bool moveLeft();
	bool moveRight();

	const bool checkIfCompleted();

	bool playGame();

	void printGraph();

	// Getters and Setters

	int getTotalNodes();
	void setTotalNodes(int t);

	NodeForGraph** getArray();
	void setArray(NodeForGraph** a);

	int getRows();
	void setRows(int r);

	int getColumns();
	void setColumns(int c);

	char getMode();
	void setMode(char m);

	bool getCompleted();
	void setCompleted(bool c);

	int getObstacles();
	void setObstacles(int o);

	int getPowerUps();
	void setPowerUps(int p);

	int getCoins();
	void setCoins(int c);

	Queue<char> getQueueForObstacles();
	void setQueueForObstacles(Queue<char> q);

	Queue<char> getQueueForPowerUps();
	void setQueueForPowerUps(Queue<char> q);

	Stack<char> getStackForCoins();
	void setStackForCoins(Stack<char> s);

	double getScore();
	void setScore(double s);

	int getLives();
	void setLives(int l);

};

class Player
{
	string name;
	string date;
	string time;

	double score;

	NodeForGraph** currentMaze;

public:

	Player();

	void updateDateAndTime();

	~Player();

	// Getters and Setters

	string getName();
	void setName(string name);

	string getDate();
	void setDate(string date);

	string getTime();
	void setTime(string time);

	double getScore();
	void setScore(double score);

	NodeForGraph** getCurrentMaze();
	void setCurrentMaze(NodeForGraph** maze);
};

// We store Player name and score in a binary search tree
class NodeForBinarySearchTree
{
public:

	Player player;

	NodeForBinarySearchTree* left;
	NodeForBinarySearchTree* right;

	NodeForBinarySearchTree();

	~NodeForBinarySearchTree();
};

// Class Binary Search Tree

class BinarySearchTree
{
	NodeForBinarySearchTree* root;

	Queue <Player> players;

	Player* playersArray;

	int size;

public:

	BinarySearchTree();
	~BinarySearchTree();

	void insert(Player player);

	void printInOrder(NodeForBinarySearchTree* node);
	void printPreOrder(NodeForBinarySearchTree* node);
	void printPostOrder(NodeForBinarySearchTree* node);

	void displayHighestScoreDescending(NodeForBinarySearchTree* node);

	void bubbleSort();
	void selectionSort();
	void insertionSort();

	void writeToFileForLeaderBoard(BinarySearchTree tree);

	void readFromFileForLeaderBoard(BinarySearchTree& tree);

	// Getters and Setters

	NodeForBinarySearchTree* getRoot();

	void setRoot(NodeForBinarySearchTree* r);
};

class File
{

public:

	File();
	~File();

	void writeToFileForLeaderBoard(BinarySearchTree tree);
	void readFromFileForLeaderBoard(BinarySearchTree& tree);

	void writeToFileForResumeGame(Player player, Graph graph);
	void readFromFileForResumeGame(Player& playerObj, Graph& graphObj, Maze& mazeObj);
};

// Solving the maze using Dijkstra's Algorithm
class NodeForGraphSolve
{
public:

	bool path;
	bool wall;
	bool powerUp;
	bool obstacle;
	bool coin;
	bool isHere;
	bool start;
	bool end;

	char value;

	NodeForGraphSolve* next;

	int vertex;
	int x;
	int y;
	int weight;

	NodeForGraphSolve(bool p = false, bool w = false, bool pu = false, bool o = false, bool c = false, bool ih = false, bool s = false, bool e = false, char v = ' ', int x = 0, int y = 0, int wgt = 0);
};

class AdjacentMatrix
{
public:
	NodeForGraphSolve* head;
};

class GraphSolve
{
	NodeForGraphSolve** array;

	char mode;
	int rows;
	int columns;

	double score;

	int obstacles;
	int powerUps;
	int coins;

	Queue<char> queueForObstacles;

	Queue<char> queueForPowerUps;

	Stack<char> stackForCoins;

	int totalNodes;
	AdjacentMatrix* adjArray;

	char** twoDArray;

public:

	GraphSolve();
	~GraphSolve();

	void createGraph(Maze mazeObj);
	
	void placeRandomObstacles();
	void placeRandomPowerUps();
	void placeRandomCoins();

	NodeForGraphSolve* createNode(int vertex, int input_weight);

	void printGraph();

	void addEdge(int source, int destination, int weight);

	void createAdjacentMatrix();

	void printEdges();

	int findMinVertex(int* distance, bool* visited)
	{
		int minVertex = -1;

		for (int i = 0; i < totalNodes; i++)
		{
			if (visited[i] == false && (minVertex == -1 || distance[i] < distance[minVertex]))
			{
				minVertex = i;
			}
		}

		return minVertex;
	}

	void dijkstra(char source, char destination);

	void shortestPath();

	void copyToTwoDArray();

	// Getters and Setters

	int getRows();
	void setRows(int r);

	int getColumns();
	void setColumns(int c);

	NodeForGraphSolve** getMazeObj();
	void setMazeObj(NodeForGraphSolve** m);

	int getTotalNodes();
	void setTotalNodes(int t);

};


#include <queue>

typedef pair<int, int> pii;

// Function to find the shortest path and mark it as 'X'
void findShortestPath(char** matrix, int row, int columns) {
	int rows = row;
	int cols = columns;

	pii start, end;

	// Find the start and end positions
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (matrix[i][j] == 'S') {
				start = { i, j };
			}
			else if (matrix[i][j] == 'E') {
				end = { i, j };
			}
		}
	}

	// Dijkstra's algorithm
	int** distance = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		distance[i] = new int[cols];
	}

	pii** parent = new pii * [rows];
	for (int i = 0; i < rows; ++i) {
		parent[i] = new pii[cols];
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			distance[i][j] = INT_MAX;
		}
	}

	// Initialize parent array
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			parent[i][j] = { -1, -1 };  // Directly initialize the pair without using make_pair
		}
	}


	auto isValid = [&](int x, int y) {
		return x >= 0 && x < rows && y >= 0 && y < cols && matrix[x][y] != '#';
		};

	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
	pq.push({ 0, start });
	distance[start.first][start.second] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		pii current = pq.top().second;
		pq.pop();

		int x = current.first;
		int y = current.second;

		if (current == end) {
			// Reconstruct the path and mark it in the matrix
			while (current.first != -1) {
				matrix[current.first][current.second] = 'X';
				current = parent[current.first][current.second];
			}
			break;
		}

		int dx[] = { -1, 0, 1, 0 };
		int dy[] = { 0, 1, 0, -1 };

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isValid(nx, ny)) {
				int newCost = cost + 1;

				if (newCost < distance[nx][ny]) {
					distance[nx][ny] = newCost;
					parent[nx][ny] = { x, y };
					pq.push({ newCost, {nx, ny} });
				}
			}
		}
	}
}

void GraphSolve::copyToTwoDArray()
{
	twoDArray = new char* [rows];

	for (int i = 0; i < rows; i++)
	{
		twoDArray[i] = new char[columns];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)

		{
			twoDArray[i][j] = array[i][j].value;
		}
	}

	char** matrix = new char* [rows];

	for (int i = 0; i < rows; ++i) {
		matrix[i] = new char[columns];
	}

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] = twoDArray[i][j];
		}
	}

	findShortestPath(matrix, rows, columns);

	cout << endl << endl;

	char greenColor[] = "\x1b[32m";
	char redColor[] = "\x1b[31m";
	char yellowColor[] = "\x1b[33m";
	char blueColor[] = "\x1b[34m";
	char magentaColor[] = "\x1b[35m";
	char cyanColor[] = "\x1b[36m";
	char whiteColor[] = "\x1b[37m";
	char lightYellowColor[] = "\x1b[93m";
	char purpleColor[] = "\x1b[95m";
	char resetColor[] = "\x1b[0m";

	string color = "";

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; j++) {

			if (matrix[i][j] == 'X')
			{
				color = greenColor;
			}
			else if (matrix[i][j] == 'S')
			{
				color = redColor;
			}
			else if (matrix[i][j] == 'E')
			{
				color = yellowColor;
			}
			else if (matrix[i][j] == '#')
			{
				color = blueColor;
			}
			else if (matrix[i][j] == '$')
			{
				color = magentaColor;
			}
			else if (matrix[i][j] == '*')
			{
				color = cyanColor;
			}
			else if (matrix[i][j] == 'C')
			{
				color = whiteColor;
			}
			else if (matrix[i][j] == '%')
			{
				color = redColor;
			}

			cout << color << matrix[i][j] << " " ;
			color = resetColor;
			cout << color;
		}
		cout << endl;
	}






}



