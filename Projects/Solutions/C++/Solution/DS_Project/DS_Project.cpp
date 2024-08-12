// Muhammad_Waqas_Shahid_Khan_22I2469
// Abdul_Raffay_22I2546

// DS_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include <string>
#include "Header.h"
#include <conio.h>
#include <SFML/Audio.hpp>


using namespace std;

// Class Maze

Maze::Maze()
{
	rows = 0;
	columns = 0;
	maze = NULL;
}
void Maze::createEasyMaze()
{
	mode = 'E';
	// the rows and col will always be equal and greater than 10 and less than 15 for easy maze
	srand(time(0));

	int num = (rand() % (15 - 10 + 1)) + 10;

	// Only to Check if num is in range of 10 and 15 and always even
	/*for (int i = 0; i < 30; i++)
	{
		num = (rand() % (15 - 10 + 1)) + 10;
		if (num % 2 != 0)
		{
			num++;
		}
		cout << num << endl;
		Sleep(1000);
	}*/

	if (num % 2 != 0)
	{
		num++;
	}

	num += 1;

	rows = num;

	columns = num;

	// Display the rows and columns
	/*cout << "Rows: " << rows << endl;
	cout << "Columns: " << columns << endl;*/

	// Creating 2D Array
	maze = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		maze[i] = new int[columns];
	}

	// Initializing 
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			maze[i][j] = 35;
		}
	}

	srand(time(0));

	int rowI = 1;
	int colJ = 1;

	while (rowI < rows - 1)
	{
		colJ = 1;
		while (colJ < columns - 1)
		{
			maze[rowI][colJ] = 32;

			// Randomly Create Openings
			int randNum = rand() % 2;
			if (rowI > 1 && randNum == 0)
			{
				maze[rowI - 1][colJ] = 32;
			}

			randNum = rand() % 2;
			if (colJ > 1 && randNum == 0)
			{
				maze[rowI][colJ - 1] = 32;
			}

			// Randomly Create vertical or horizontal Paths between adjacents 
			randNum = rand() % 2;

			if (randNum == 0 && colJ < columns - 2)
			{
				maze[rowI][colJ + 1] = 32;
			}
			else if (rowI < rows - 2)
			{
				maze[rowI + 1][colJ] = 32;
			}
			colJ = colJ + 2;
		}

		rowI = rowI + 2;
	}

	// Creating the entrance and exit
	maze[0][1] = 83;
	maze[rows - 1][columns - 2] = 69;

	// Placing the Car at 1st path in the maze

	maze[1][1] = 67;
	maze[2][1] = 69;
}
void Maze::createMediumMaze()
{
	mode = 'M';
	// the rows and col will always be equal and greater than 16 and less than 26 for easy maze
	srand(time(0));

	int num = (rand() % (26 - 16 + 1)) + 16;

	// Only to Check if num is in range of 10 and 15 and always even
	/*for (int i = 0; i < 30; i++)
	{
		num = (rand() % (15 - 10 + 1)) + 10;
		if (num % 2 != 0)
		{
			num++;
		}
		cout << num << endl;
		Sleep(1000);
	}*/

	if (num % 2 != 0)
	{
		num++;
	}

	num += 1;

	rows = num;

	columns = num;

	// Display the rows and columns
	/*cout << "Rows: " << rows << endl;
	cout << "Columns: " << columns << endl;*/

	// Creating 2D Array
	maze = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		maze[i] = new int[columns];
	}

	// Initializing 
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			maze[i][j] = 35;
		}
	}

	srand(time(0));

	int rowI = 1;
	int colJ = 1;

	while (rowI < rows - 1)
	{
		colJ = 1;
		while (colJ < columns - 1)
		{
			maze[rowI][colJ] = 32;

			// Randomly Create Openings
			int randNum = rand() % 2;
			if (rowI > 1 && randNum == 0)
			{
				maze[rowI - 1][colJ] = 32;
			}

			randNum = rand() % 2;
			if (colJ > 1 && randNum == 0)
			{
				maze[rowI][colJ - 1] = 32;
			}

			// Randomly Create vertical or horizontal Paths between adjacents 
			randNum = rand() % 2;

			if (randNum == 0 && colJ < columns - 2)
			{
				maze[rowI][colJ + 1] = 32;
			}
			else if (rowI < rows - 2)
			{
				maze[rowI + 1][colJ] = 32;
			}
			colJ = colJ + 2;
		}

		rowI = rowI + 2;
	}

	// Creating the entrance and exit
	maze[0][1] = 83;
	maze[rows - 1][columns - 2] = 69;

	// Placing the Car at 1st path in the maze

	maze[1][1] = 67;
}
void Maze::createHardMaze()
{
	mode = 'H';
	// the rows and col will always be equal and greater than 26 and less than 35 for easy maze
	srand(time(0));

	int num = (rand() % (35 - 26 + 1)) + 26;

	// Only to Check if num is in range of 10 and 15 and always even
	/*for (int i = 0; i < 30; i++)
	{
		num = (rand() % (15 - 10 + 1)) + 10;
		if (num % 2 != 0)
		{
			num++;
		}
		cout << num << endl;
		Sleep(1000);
	}*/

	if (num % 2 != 0)
	{
		num++;
	}

	num += 1;

	rows = num;

	columns = num;

	// Display the rows and columns
	/*cout << "Rows: " << rows << endl;
	cout << "Columns: " << columns << endl;*/

	// Creating 2D Array
	maze = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		maze[i] = new int[columns];
	}

	// Initializing 
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			maze[i][j] = 35;
		}
	}

	srand(time(0));

	int rowI = 1;
	int colJ = 1;

	while (rowI < rows - 1)
	{
		colJ = 1;
		while (colJ < columns - 1)
		{
			maze[rowI][colJ] = 32;

			// Randomly Create Openings
			int randNum = rand() % 2;
			if (rowI > 1 && randNum == 0)
			{
				maze[rowI - 1][colJ] = 32;
			}

			randNum = rand() % 2;
			if (colJ > 1 && randNum == 0)
			{
				maze[rowI][colJ - 1] = 32;
			}

			// Randomly Create vertical or horizontal Paths between adjacents 
			randNum = rand() % 2;

			if (randNum == 0 && colJ < columns - 2)
			{
				maze[rowI][colJ + 1] = 32;
			}
			else if (rowI < rows - 2)
			{
				maze[rowI + 1][colJ] = 32;
			}
			colJ = colJ + 2;
		}

		rowI = rowI + 2;
	}

	// Creating the entrance and exit
	maze[0][1] = 83;
	maze[rows - 1][columns - 2] = 69;

	// Placing the Car at 1st path in the maze

	maze[1][1] = 67;
}
void Maze::printMaze()
{
	// Printing the maze
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << char(maze[i][j]) << " ";
		}
		cout << endl;
	}
}
int Maze::getRows()
{
	return rows;
}
void Maze::setRows(int r)
{
	rows = r;
}
int Maze::getColumns()
{
	return columns;
}
void Maze::setColumns(int c)
{
	columns = c;
}
void Maze::deleteMaze()
{
	// First we delete the previous maze
	for (int i = 0; i < rows; i++)
	{
		delete[] maze[i];
	}
	delete[] maze;

	maze = NULL;

}
int** Maze::getMaze()
{
	return maze;
}
void Maze::setMaze(int** m)
{
	// Now we set the new maze
	maze = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		maze[i] = new int[columns];
	}

	// Copy 

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			maze[i][j] = m[i][j];
		}
	}

}
char Maze::getMode()
{
	return mode;
}
void Maze::setMode(char m)
{
	mode = m;
}
Maze::~Maze() //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{
	/*cout << rows << endl;
	for (int i = 0; i < rows; i++)
	{
		delete[] maze[i];
	}
	delete[] maze;

	maze = NULL;*/
}

// Class NodeForGraph

NodeForGraph::NodeForGraph()
{
	path = false;
	wall = false;
	powerUp = false;
	obstacle = false;
	isHere = false;
	start = false;
	end = false;

	value = 0;

	up = NULL;
	down = NULL;
	left = NULL;
	right = NULL;

	x = 0;
	y = 0;
	weight = 1;
}
NodeForGraph::~NodeForGraph() //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{

}

// Class Graph
Graph::Graph()
{
	totalNodes = 0;
	array = NULL;

	rows = 0;
	columns = 0;

	completed = false;

	mode = '-';

	obstacles = 0;
	powerUps = 0;
	coins = 0;
	score = 0;
	lives = 0;

}
Graph::~Graph() //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{

}
void Graph::createGraphFromMaze(Maze mazeObj)
{
	mode = mazeObj.getMode();
	rows = mazeObj.getRows();
	columns = mazeObj.getColumns();

	if (mode == 'E')
	{
		lives = 10;
	}
	else if (mode == 'M')
	{
		lives = 15;
	}
	else if (mode == 'H')
	{
		lives = 20;
	}

	int** maze = mazeObj.getMaze();

	totalNodes = (rows * columns);

	array = new NodeForGraph * [rows];

	for (int i = 0; i < rows; i++)
	{
		array[i] = new NodeForGraph[columns];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i][j] = NodeForGraph();

			// Path
			if (maze[i][j] == 32)
			{
				array[i][j].path = true;
				array[i][j].value = '.';
			}
			// Wall
			else if (maze[i][j] == 35)
			{
				array[i][j].wall = true;
				array[i][j].path = false;
				array[i][j].value = 35;
			}
			// Car
			else if (maze[i][j] == 67)
			{
				array[i][j].path = true;
				array[i][j].isHere = true;
				array[i][j].value = 67;
			}
			// End
			else if (maze[i][j] == 69)
			{
				array[i][j].path = true;
				array[i][j].end = true;
				array[i][j].value = 69;
			}
			// Start
			else if (maze[i][j] == 83)
			{
				array[i][j].path = true;
				array[i][j].start = true;
				array[i][j].value = 83;
			}
			else if (maze[i][j] == 69)
			{
				array[i][j].path = true;
				array[i][j].value = 69;
			}
		}
	}

	// Creating the links between the nodes

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			// Up
			if (i > 0 && array[i - 1][j].path == true)
			{
				array[i][j].up = &array[i - 1][j];
			}

			// Down
			if (i < rows - 1 && array[i + 1][j].path == true)
			{
				array[i][j].down = &array[i + 1][j];
			}

			// Left
			if (j > 0 && array[i][j - 1].path == true)
			{
				array[i][j].left = &array[i][j - 1];
			}

			// Right
			if (j < columns - 1 && array[i][j + 1].path == true)
			{
				array[i][j].right = &array[i][j + 1];
			}

			if (maze[i][j] == 35)
			{
				// Up down left right all null
				array[i][j].up = NULL;
				array[i][j].down = NULL;
				array[i][j].left = NULL;
				array[i][j].right = NULL;
			}
		}
	}

	// Displaying the links between the nodes
	/*for (int i = 0; i < rows; i++)
	{
		cout << endl;
		for (int j = 0; j < columns; j++)
		{
			cout << "Row: " << i << endl;

			cout << array[i][j].value << " ";
			if (array[i][j].up != NULL)
			{
				cout << "Up: " << array[i][j].up->value << " ";
			}
			if (array[i][j].down != NULL)
			{
				cout << "Down: " << array[i][j].down->value << " ";
			}
			if (array[i][j].left != NULL)
			{
				cout << "Left: " << array[i][j].left->value << " ";
			}
			if (array[i][j].right != NULL)
			{
				cout << "Right: " << array[i][j].right->value << " ";
			}
			cout << endl<<endl;
		}
	}*/

	// Placing the obstacles
	placeRandomObstacles();

	// Placing the powerUps
	placeRandomPowerUps();

	// Placing the coins
	placeRandomCoins();

}
void Graph::deletePreviousGraphAndCopyNew(Maze mazeObj)
{
	// First we delete the previous graph

	for (int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}
	delete[] array;

	array = NULL;

	mode = mazeObj.getMode();
	rows = mazeObj.getRows();
	columns = mazeObj.getColumns();

	int** maze = mazeObj.getMaze();

	totalNodes = (rows * columns);

	array = new NodeForGraph * [rows];

	for (int i = 0; i < rows; i++)
	{
		array[i] = new NodeForGraph[columns];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i][j] = NodeForGraph();

			// We copy the maze to the graph

			// Path
			if (maze[i][j] == '.')
			{
				array[i][j].path = true;
				array[i][j].value = '.';
			}
			// Wall
			else if (maze[i][j] == 35)
			{
				array[i][j].wall = true;
				array[i][j].path = false;
				array[i][j].value = 35;
			}
			// Car
			else if (maze[i][j] == 67)
			{
				array[i][j].path = true;
				array[i][j].isHere = true;
				array[i][j].value = 67;
			}
			// End
			else if (maze[i][j] == 69)
			{
				array[i][j].path = true;
				array[i][j].end = true;
				array[i][j].value = 69;
			}
			// Start
			else if (maze[i][j] == 83)
			{
				array[i][j].path = true;
				array[i][j].start = true;
				array[i][j].value = 83;
			}
			// Obstacle
			else if (maze[i][j] == 37)
			{
				array[i][j].path = true;
				array[i][j].obstacle = true;
				array[i][j].value = 37;
			}
			// Power Up
			else if (maze[i][j] == 42)
			{
				array[i][j].path = true;
				array[i][j].powerUp = true;
				array[i][j].value = 42;
			}
			// Coin
			else if (maze[i][j] == 36)
			{
				array[i][j].path = true;
				array[i][j].coin = true;
				array[i][j].value = 36;
			}

		}
	}

	// Debugging
	/*mazeObj.printMaze();
	printGraph();

	Sleep(8000);*/

	// Creating the links between the nodes

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			// Up
			if (i > 0 && array[i - 1][j].path == true)
			{
				array[i][j].up = &array[i - 1][j];
			}

			// Down
			if (i < rows - 1 && array[i + 1][j].path == true)
			{
				array[i][j].down = &array[i + 1][j];
			}

			// Left
			if (j > 0 && array[i][j - 1].path == true)
			{
				array[i][j].left = &array[i][j - 1];
			}

			// Right
			if (j < columns - 1 && array[i][j + 1].path == true)
			{
				array[i][j].right = &array[i][j + 1];
			}

			if (maze[i][j] == 35)
			{
				// Up down left right all null
				array[i][j].up = NULL;
				array[i][j].down = NULL;
				array[i][j].left = NULL;
				array[i][j].right = NULL;
			}
		}
	}

	// Displaying the links between the nodes
	/*for (int i = 0; i < rows; i++)
	{
		cout << endl;
		for (int j = 0; j < columns; j++)
		{
			cout << "Row: " << i << endl;

			cout << array[i][j].value << " ";
			if (array[i][j].up != NULL)
			{
				cout << "Up: " << array[i][j].up->value << " ";
			}
			if (array[i][j].down != NULL)
			{
				cout << "Down: " << array[i][j].down->value << " ";
			}
			if (array[i][j].left != NULL)
			{
				cout << "Left: " << array[i][j].left->value << " ";
			}
			if (array[i][j].right != NULL)
			{
				cout << "Right: " << array[i][j].right->value << " ";
			}
			cout << endl<<endl;
		}
	}*/
}
void Graph::placeRandomObstacles()
{
	if (mode == 'E')
	{
		obstacles = (rows * columns) / 25;
	}
	else if (mode == 'M')
	{
		obstacles = (rows * columns) / 20;
	}
	else if (mode == 'H')
	{
		obstacles = (rows * columns) / 15;
	}

	char obstacle = '%';

	// Enqueue the obstacles in the queue
	for (int i = 0; i < obstacles; i++)
	{
		queueForObstacles.enqueue('%');
	}

	while (queueForObstacles.isEmpty() == false)
	{
		int randRow = rand() % rows;
		int randCol = rand() % columns;

		if (array[randRow][randCol].path == true && array[randRow][randCol].start == false && array[randRow][randCol].end == false && array[randRow][randCol].isHere == false)
		{
			// We First check if there is already an obstacle up down left or right if yes then we don't place the obstacle
			if (rows - rows + 1 == randRow)
			{
				continue;
			}

			if (array[randRow][randCol].up != NULL && array[randRow][randCol].up->obstacle == true)
			{
				continue;
			}
			if (array[randRow][randCol].down != NULL && array[randRow][randCol].down->obstacle == true)
			{
				continue;
			}
			if (array[randRow][randCol].left != NULL && array[randRow][randCol].left->obstacle == true)
			{
				continue;
			}
			if (array[randRow][randCol].right != NULL && array[randRow][randCol].right->obstacle == true)
			{
				continue;
			}
			array[randRow][randCol].obstacle = true;
			array[randRow][randCol].powerUp = false;
			array[randRow][randCol].coin = false;
			array[randRow][randCol].path = true;
			array[randRow][randCol].value = '%';
			queueForObstacles.dequeue();
		}
	}

}
void Graph::placeRandomPowerUps()
{
	if (mode == 'E')
	{
		powerUps = (rows * columns) / 20;
	}
	else if (mode == 'M')
	{
		powerUps = (rows * columns) / 30;
	}
	else if (mode == 'H')
	{
		powerUps = (rows * columns) / 40;
	}

	char powerUp = '*';

	// Enqueue the obstacles in the queue

	for (int i = 0; i < powerUps; i++)
	{
		queueForPowerUps.enqueue('*');
	}

	while (queueForPowerUps.isEmpty() == false)
	{
		int randRow = rand() % rows;
		int randCol = rand() % columns;

		if (array[randRow][randCol].path == true && array[randRow][randCol].start == false && array[randRow][randCol].end == false && array[randRow][randCol].isHere == false)
		{

			// We First check if there is already a power up at up down left or right if yes then we don't place the pwer up

			if (array[randRow][randCol].up != NULL && array[randRow][randCol].up->powerUp == true)
			{
				continue;
			}

			if (array[randRow][randCol].down != NULL && array[randRow][randCol].down->powerUp == true)
			{
				continue;
			}

			if (array[randRow][randCol].left != NULL && array[randRow][randCol].left->powerUp == true)
			{
				continue;
			}

			if (array[randRow][randCol].right != NULL && array[randRow][randCol].right->powerUp == true)
			{
				continue;
			}

			array[randRow][randCol].powerUp = true;
			array[randRow][randCol].obstacle = false;
			array[randRow][randCol].coin = false;
			array[randRow][randCol].path = true;
			array[randRow][randCol].value = '*';
			queueForPowerUps.dequeue();
		}
	}

}
void Graph::placeRandomCoins()
{
	if (mode == 'E')
	{
		coins = (rows * columns) / 10;
	}
	else if (mode == 'M')
	{
		coins = (rows * columns) / 15;
	}
	else if (mode == 'H')
	{
		coins = (rows * columns) / 20;
	}

	char coin = '$';

	// Push the coins in the stack

	for (int i = 0; i < coins; i++)
	{
		stackForCoins.push('$');
	}

	while (stackForCoins.isEmpty() == false)
	{
		int randRow = rand() % rows;
		int randCol = rand() % columns;

		if (array[randRow][randCol].path == true && array[randRow][randCol].start == false && array[randRow][randCol].end == false && array[randRow][randCol].isHere == false)
		{

			// We First check if there is already a coin at up down left or right if yes then we don't place the coin

			if (array[randRow][randCol].up != NULL && array[randRow][randCol].up->coin == true)
			{
				continue;
			}

			if (array[randRow][randCol].down != NULL && array[randRow][randCol].down->coin == true)
			{
				continue;
			}

			if (array[randRow][randCol].left != NULL && array[randRow][randCol].left->coin == true)
			{
				continue;
			}

			if (array[randRow][randCol].right != NULL && array[randRow][randCol].right->coin == true)
			{
				continue;
			}

			array[randRow][randCol].coin = true;
			array[randRow][randCol].obstacle = false;
			array[randRow][randCol].powerUp = false;
			array[randRow][randCol].path = true;
			array[randRow][randCol].value = '$';
			stackForCoins.pop();
		}
	}

}
bool Graph::moveUp()
{
	// Create a sound buffer to load the MP3 file
	sf::SoundBuffer buffer;

	if (!buffer.loadFromFile("hurt.mp3")) {
		// Failed to load the MP3 file
	}

	// Create a sound object and associate it with the loaded buffer
	sf::Sound sound;
	sound.setBuffer(buffer);

	bool moved = false;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns && moved == false; j++)
		{
			if (array[i][j].isHere == true)
			{
				if (array[i][j].up != NULL && array[i][j].up->path == true && array[i][j].up->start == false)
				{
					array[i][j].isHere = false;
					array[i][j].value = '.';

					// We check if there is an obstacle or power up or coin at the new position if yes then we update the score -5 for obstacle, *2 for power up and +5 for coin

					if (array[i][j].up->obstacle == true)
					{
						// Play the sound
						sound.play();
						// Keep the program running while the sound is playing
						while (sound.getStatus() == sf::Sound::Playing) {
							// Do nothing or perform other tasks
						}

						array[i][j].up->obstacle = false;
						if (score != 0)
						{
							score -= 5;
						}

						lives -= 1;
					}
					else if (array[i][j].up->powerUp == true)
					{
						if (score == 0)
						{
							score += 3;
						}
						score *= 2;
						array[i][j].up->powerUp = false;
					}
					else if (array[i][j].up->coin == true)
					{
						score += 5;
						array[i][j].up->coin = false;
					}

					array[i][j].up->isHere = true;
					array[i][j].up->value = 67;
					moved = true;
				}
			}
		}
	}

	return moved;
}
bool Graph::moveDown()
{
	// Create a sound buffer to load the MP3 file
	sf::SoundBuffer buffer;

	if (!buffer.loadFromFile("hurt.mp3")) {
		// Failed to load the MP3 file
	}

	// Create a sound object and associate it with the loaded buffer
	sf::Sound sound;
	sound.setBuffer(buffer);

	bool moved = false;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns && moved == false; j++)
		{
			if (array[i][j].isHere == true)
			{
				if (array[i][j].down != NULL && array[i][j].down->path == true && array[i][j].down->end == false)
				{
					array[i][j].isHere = false;
					array[i][j].value = '.';

					// We check if there is an obstacle or power up or coin at the new position if yes then we update the score -5 for obstacle, *2 for power up and +5 for coin

					if (array[i][j].down->obstacle == true)
					{
						// Play the sound
						sound.play();
						// Keep the program running while the sound is playing
						while (sound.getStatus() == sf::Sound::Playing) {
							// Do nothing or perform other tasks
						}

						array[i][j].down->obstacle = false;
						if (score != 0)
						{
							score -= 5;
						}

						lives -= 1;
					}
					else if (array[i][j].down->powerUp == true)
					{
						if (score == 0)
						{
							score += 3;
						}
						score *= 2;
						array[i][j].down->powerUp = false;
					}
					else if (array[i][j].down->coin == true)
					{
						score += 5;
						array[i][j].down->coin = false;
					}

					array[i][j].down->isHere = true;
					array[i][j].down->value = 67;
					moved = true;
				}
			}
		}
	}


	return moved;
}
bool Graph::moveLeft()
{
	// Create a sound buffer to load the MP3 file
	sf::SoundBuffer buffer;

	if (!buffer.loadFromFile("hurt.mp3")) {
		// Failed to load the MP3 file
	}

	// Create a sound object and associate it with the loaded buffer
	sf::Sound sound;
	sound.setBuffer(buffer);

	bool moved = false;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns && moved == false; j++)
		{
			if (array[i][j].isHere == true)
			{
				if (array[i][j].left != NULL && array[i][j].left->path == true)
				{
					array[i][j].isHere = false;
					array[i][j].value = '.';

					// We check if there is an obstacle or power up or coin at the new position if yes then we update the score -5 for obstacle, *2 for power up and +5 for coin

					if (array[i][j].left->obstacle == true)
					{
						// Play the sound
						sound.play();
						// Keep the program running while the sound is playing
						while (sound.getStatus() == sf::Sound::Playing) {
							// Do nothing or perform other tasks
						}

						array[i][j].left->obstacle = false;
						if (score != 0)
						{
							score -= 5;
						}

						lives -= 1;
					}
					else if (array[i][j].left->powerUp == true)
					{
						if (score == 0)
						{
							score += 3;
						}
						score *= 2;
						array[i][j].left->powerUp = false;
					}
					else if (array[i][j].left->coin == true)
					{
						score += 5;
						array[i][j].left->coin = false;
					}

					array[i][j].left->isHere = true;
					array[i][j].left->value = 67;
					moved = true;
				}
			}
		}
	}

	return moved;
}
bool Graph::moveRight()
{
	// Create a sound buffer to load the MP3 file
	sf::SoundBuffer buffer;

	if (!buffer.loadFromFile("warning.mp3")) {
		// Failed to load the MP3 file
	}

	// Create a sound object and associate it with the loaded buffer
	sf::Sound sound;
	sound.setBuffer(buffer);

	bool moved = false;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns && moved == false; j++)
		{
			if (array[i][j].isHere == true)
			{
				if (array[i][j].right != NULL && array[i][j].right->path == true)
				{
					array[i][j].isHere = false;
					array[i][j].value = '.';

					// We check if there is an obstacle or power up or coin at the new position if yes then we update the score -5 for obstacle, *2 for power up and +5 for coin

					if (array[i][j].right->obstacle == true)
					{
						// Play the sound
						sound.play();
						// Keep the program running while the sound is playing
						while (sound.getStatus() == sf::Sound::Playing) {
							// Do nothing or perform other tasks
						}
						array[i][j].right->obstacle = false;
						if (score != 0)
						{
							score -= 5;
						}

						lives -= 1;
					}
					else if (array[i][j].right->powerUp == true)
					{
						if (score == 0)
						{
							score += 3;
						}
						score *= 2;
						array[i][j].right->powerUp = false;
					}
					else if (array[i][j].right->coin == true)
					{
						score += 5;
						array[i][j].right->coin = false;
					}

					array[i][j].right->isHere = true;
					array[i][j].right->value = 67;
					moved = true;
				}
			}
		}
	}

	return moved;
}
const bool Graph::checkIfCompleted()
{
	bool flag = false;

	for (int i = 0; i < rows && flag == false; i++)
	{
		for (int j = 0; j < columns && flag == false; j++)
		{
			if (array[i][j].isHere == true)
			{
				if (array[i + 1][j].end == true)
				{
					flag = true;
					completed = true;
				}
			}
		}
	}

	return flag;
}
bool Graph::playGame()
{
	char input = '-';
	bool flag = false;

	while (input != 'e')
	{
		system("CLS");

		printGraph();

		// Find the car
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (array[i][j].isHere == true)
				{
					// We check if there is an obtacle up down left or right

					if (array[i + 1][j].obstacle == true || array[i - 1][j].obstacle == true || array[i][j + 1].obstacle == true || array[i][j - 1].obstacle == true)
					{
						// Play the sound
						sf::SoundBuffer buffer;

						if (!buffer.loadFromFile("warning.mp3")) {
							// Failed to load the MP3 file
						}

						// Create a sound object and associate it with the loaded buffer
						sf::Sound sound;
						sound.setBuffer(buffer);

						sound.play();
						// Keep the program running while the sound is playing
						while (sound.getStatus() == sf::Sound::Playing) {
							// Do nothing or perform other tasks
						}
						Sleep(1000);
					}
				}
			}
		}

		if (lives == 0)
		{
			cout << "You Lost!" << endl;
			flag = true;
			completed = false;
			input = 'e';
			Sleep(3000);
			system("CLS");
			break;
		}

		input = _getch();

		while (input != 'w' && input != 'a' && input != 's' && input != 'd' && input != 'e' && input != 'p')
		{
			input = _getch();
		}

		cout << input << endl;

		if (input == 'w')
		{
			moveUp();
		}
		else if (input == 'a')
		{
			moveLeft();
		}
		else if (input == 's')
		{
			moveDown();
		}
		else if (input == 'd')
		{
			moveRight();
		}
		else if (input == 'e')
		{
			cout << "You Exited the Game!" << endl;
			flag = true;
			completed = false;
		}
		else if (input == 'p')
		{
			cout << "Game Paused and Saved!" << endl;

			input = 'e';
			Sleep(3000);
			system("CLS");
			flag = false;
		}

		checkIfCompleted();

		if (completed == true)
		{

			system("CLS");
			printGraph();
			cout << endl;
			cout << "You Won!" << endl;
			flag = true;
			completed = true;
			input = 'e';
			Sleep(3000);
		}

	}

	return flag;
}
void Graph::printGraph()
{
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
	cout << redColor << "Lives : " << lives << resetColor << endl;
	cout << greenColor << "Score: " << score << resetColor << endl << endl;
	// Printing the maze
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (array[i][j].value == '#')
			{
				color = purpleColor;
			}
			else if (array[i][j].value == 'C')
			{
				color = lightYellowColor;
			}
			else if (array[i][j].value == 'S')
			{
				color = blueColor;
			}
			else if (array[i][j].value == 'E')
			{
				color = blueColor;
			}
			else if (array[i][j].value == '%')
			{
				color = redColor;
			}
			else if (array[i][j].value == '*')
			{
				color = cyanColor;
			}
			else if (array[i][j].value == '$')
			{
				color = greenColor;
			}
			else if (array[i][j].value == 'D')
			{
				color = whiteColor;
			}
			else
			{
				color = resetColor;
			}

			cout << color << char(array[i][j].value) << " ";
			color = resetColor;
			cout << color;
		}
		cout << endl;
	}

	cout << endl;

	// Instructions For the Player

	cout << magentaColor << "Instructions: " << resetColor << endl;
	cout << purpleColor << "# = Wall " << resetColor << "---" << lightYellowColor << " C = Coin " << resetColor << "---" << blueColor << " S = Start " << resetColor << "---" << blueColor << " E = End " << resetColor << "---" << redColor << " % = Obstacle " << resetColor << "---" << cyanColor << " * = Power Up " << resetColor << "---" << greenColor << " $ = Car " << resetColor << endl;
	cout << endl;
	cout << lightYellowColor << "Use W A S D to move the car" << resetColor << endl;
	cout << magentaColor << "Press E to exit the game" << resetColor << endl;
	cout << cyanColor << "Press P to pause and save the game" << resetColor << endl;

}
int Graph::getTotalNodes()
{
	return totalNodes;
}
void Graph::setTotalNodes(int t)
{
	totalNodes = t;
}
NodeForGraph** Graph::getArray()
{
	return array;
}
void Graph::setArray(NodeForGraph** a)
{
	array = a;
}
int Graph::getRows()
{
	return rows;
}
void Graph::setRows(int r)
{
	rows = r;
}
int Graph::getColumns()
{
	return columns;
}
void Graph::setColumns(int c)
{
	columns = c;
}
bool Graph::getCompleted()
{
	return completed;
}
void Graph::setCompleted(bool c)
{
	completed = c;
}
char Graph::getMode()
{
	return mode;
}
void Graph::setMode(char m)
{
	mode = m;
}
int Graph::getObstacles()
{
	return obstacles;
}
void Graph::setObstacles(int o)
{
	obstacles = o;
}
int Graph::getPowerUps()
{
	return powerUps;
}
void Graph::setPowerUps(int p)
{
	powerUps = p;
}
int Graph::getCoins()
{
	return coins;
}
void Graph::setCoins(int c)
{
	coins = c;
}
Queue<char> Graph::getQueueForObstacles()
{
	return queueForObstacles;
}
void Graph::setQueueForObstacles(Queue<char> q)
{
	queueForObstacles = q;
}
Queue<char> Graph::getQueueForPowerUps()
{
	return queueForPowerUps;
}
void Graph::setQueueForPowerUps(Queue<char> q)
{
	queueForPowerUps = q;
}
Stack<char> Graph::getStackForCoins()
{
	return stackForCoins;
}
void Graph::setStackForCoins(Stack<char> s)
{
	stackForCoins = s;
}
double Graph::getScore()
{
	return score;
}
void Graph::setScore(double s)
{
	score = s;
}
int Graph::getLives()
{
	return lives;
}
void Graph::setLives(int l)
{
	lives = l;
}

// Class NodeForGraphSolve

NodeForGraphSolve::NodeForGraphSolve(bool p, bool w, bool pu, bool o, bool c, bool ih, bool s, bool e, char v, int x, int y, int wgt)
{
	path = p;
	wall = w;
	powerUp = pu;
	obstacle = o;
	coin = c;
	isHere = ih;
	start = s;
	end = e;
	value = v;
	next = NULL;
	vertex = 0;
	this->x = x;
	this->y = y;
	weight = wgt;
}

// Class GraphSolve


GraphSolve::GraphSolve()
{
	/*array = NULL;

	mode = ' ';

	rows = 0;
	columns = 0;

	score = 0;

	obstacles = 0;
	powerUps = 0;
	coins = 0;

	totalNodes = 0;
	adjArray = NULL;*/
}
GraphSolve::~GraphSolve()
{

}
void GraphSolve::createGraph(Maze mazeObj)
{
	// First we delete the previous graph

	for (int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}
	delete[] array;

	array = NULL;

	mode = mazeObj.getMode();
	rows = mazeObj.getRows();
	columns = mazeObj.getColumns();

	int** maze = mazeObj.getMaze();

	totalNodes = (rows * columns);

	array = new NodeForGraphSolve * [rows];

	for (int i = 0; i < rows; i++)
	{
		array[i] = new NodeForGraphSolve[columns];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i][j] = NodeForGraphSolve();

			if (maze[i][j] == 32)
			{
				array[i][j].path = true;
				array[i][j].value = '.';
			}
			else if (maze[i][j] == 35)
			{
				array[i][j].wall = true;
				array[i][j].path = false;
				array[i][j].value = 35;
			}
			else if (maze[i][j] == 67)
			{
				array[i][j].path = true;
				array[i][j].isHere = true;
				array[i][j].value = 67;
			}
			else if (maze[i][j] == 69)
			{
				array[i][j].path = true;
				array[i][j].end = true;
				array[i][j].value = 69;
			}
			else if (maze[i][j] == 83)
			{
				array[i][j].path = true;
				array[i][j].start = true;
				array[i][j].value = 83;
			}
		}
	}

	// Placing the obstacles
	placeRandomObstacles();

	// Placing the powerUps
	placeRandomPowerUps();

	// Placing the coins
	placeRandomCoins();


}
void GraphSolve::placeRandomObstacles()
{
	if (mode == 'E')
	{
		obstacles = (rows * columns) / 25;
	}
	else if (mode == 'M')
	{
		obstacles = (rows * columns) / 20;
	}
	else if (mode == 'H')
	{
		obstacles = (rows * columns) / 15;
	}

	char obstacle = '%';

	// Enqueue the obstacles in the queue
	for (int i = 0; i < obstacles; i++)
	{
		queueForObstacles.enqueue('%');
	}

	while (queueForObstacles.isEmpty() == false)
	{
		int randRow = rand() % rows;
		int randCol = rand() % columns;

		if (array[randRow][randCol].path == true && array[randRow][randCol].start == false && array[randRow][randCol].end == false && array[randRow][randCol].isHere == false)
		{
			// We First check if there is already an obstacle up down left or right if yes then we don't place the obstacle

			if (rows - rows + 1 == randRow)
			{
				continue;
			}

			if (array[randRow + 1][randCol].obstacle == true)
			{
				continue;
			}

			if (array[randRow - 1][randCol].obstacle == true)
			{
				continue;
			}

			if (array[randRow][randCol + 1].obstacle == true)
			{
				continue;
			}

			if (array[randRow][randCol - 1].obstacle == true)
			{
				continue;
			}

			array[randRow][randCol].obstacle = true;
			array[randRow][randCol].powerUp = false;
			array[randRow][randCol].coin = false;
			array[randRow][randCol].path = true;
			array[randRow][randCol].value = '%';
			queueForObstacles.dequeue();
		}
	}

}
void GraphSolve::placeRandomPowerUps()
{
	if (mode == 'E')
	{
		powerUps = (rows * columns) / 50;
	}
	else if (mode == 'M')
	{
		powerUps = (rows * columns) / 40;
	}
	else if (mode == 'H')
	{
		powerUps = (rows * columns) / 30;
	}

	char powerUp = '*';

	// Enqueue the obstacles in the queue
	for (int i = 0; i < powerUps; i++)
	{
		queueForPowerUps.enqueue('*');
	}

	while (queueForPowerUps.isEmpty() == false)
	{
		int randRow = rand() % rows;
		int randCol = rand() % columns;

		if (array[randRow][randCol].path == true && array[randRow][randCol].start == false && array[randRow][randCol].end == false && array[randRow][randCol].isHere == false)
		{
			// We First check if there is already an obstacle up down left or right if yes then we don't place the obstacle

			if (array[randRow + 1][randCol].powerUp == true)
			{
				continue;
			}

			if (array[randRow - 1][randCol].powerUp == true)
			{
				continue;
			}

			if (array[randRow][randCol + 1].powerUp == true)
			{
				continue;
			}

			if (array[randRow][randCol - 1].powerUp == true)
			{
				continue;
			}

			array[randRow][randCol].obstacle = false;
			array[randRow][randCol].powerUp = true;
			array[randRow][randCol].coin = false;
			array[randRow][randCol].path = true;
			array[randRow][randCol].value = '*';
			queueForPowerUps.dequeue();
		}
	}
}
void GraphSolve::placeRandomCoins()
{
	if (mode == 'E')
	{
		coins = (rows * columns) / 10;
	}
	else if (mode == 'M')
	{
		coins = (rows * columns) / 8;
	}
	else if (mode == 'H')
	{
		coins = (rows * columns) / 6;
	}

	char coin = '$';

	// Enqueue the obstacles in the queue
	for (int i = 0; i < coins; i++)
	{
		stackForCoins.push('$');
	}

	while (stackForCoins.isEmpty() == false)
	{
		int randRow = rand() % rows;
		int randCol = rand() % columns;

		if (array[randRow][randCol].path == true && array[randRow][randCol].start == false && array[randRow][randCol].end == false && array[randRow][randCol].isHere == false)
		{
			// We First check if there is already an obstacle up down left or right if yes then we don't place the obstacle

			if (array[randRow + 1][randCol].coin == true)
			{
				continue;
			}

			if (array[randRow - 1][randCol].coin == true)
			{
				continue;
			}

			if (array[randRow][randCol + 1].coin == true)
			{
				continue;
			}

			if (array[randRow][randCol - 1].coin == true)
			{
				continue;
			}

			array[randRow][randCol].obstacle = false;
			array[randRow][randCol].powerUp = false;
			array[randRow][randCol].coin = true;
			array[randRow][randCol].path = true;
			array[randRow][randCol].value = '$';
			stackForCoins.pop();
		}
	}
}
void GraphSolve::printGraph()
{
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

	cout << "Score: " << score << endl << endl;
	// Printing the maze
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (array[i][j].value == '#')
			{
				color = purpleColor;
			}
			else if (array[i][j].value == 'C')
			{
				color = lightYellowColor;
			}
			else if (array[i][j].value == 'S')
			{
				color = blueColor;
			}
			else if (array[i][j].value == 'E')
			{
				color = blueColor;
			}
			else if (array[i][j].value == '%')
			{
				color = redColor;
			}
			else if (array[i][j].value == '*')
			{
				color = cyanColor;
			}
			else if (array[i][j].value == '$')
			{
				color = greenColor;
			}
			else
			{
				color = resetColor;
			}

			cout << color << char(array[i][j].value) << " ";
			color = resetColor;
			cout << color;
		}
		cout << endl;
	}

	cout << endl;

	// Instructions For the Player

	cout << "Instructions: " << endl;
	cout << "# = Wall --- C = Car --- S = Start --- E = End --- % = Obstacle --- * = Power Up --- $ = Coin" << endl << endl;
	cout << "Use W A S D to move the car" << endl;
	cout << "Press E to exit the game" << endl;
	cout << "Press P to pause and save the game" << endl;
}
NodeForGraphSolve* GraphSolve::createNode(int vertex, int input_weight)
{
	NodeForGraphSolve* newNode = new NodeForGraphSolve();

	newNode->vertex = vertex;
	newNode->weight = input_weight;

	return newNode;

}
void GraphSolve::addEdge(int source, int destination, int weight)
{
	// First We Check if edge already exists
	/*cout << "Source " << source << " Destination " << destination << " Weight " << weight << endl;*/
	NodeForGraphSolve* temp = adjArray[source].head;
	while (temp != NULL)
	{
		if (temp->vertex == destination)
		{
			/*cout << "Edge already exists" << endl;*/
			/*Sleep(2000);*/
			return;
		}
		temp = temp->next;
	}

	NodeForGraphSolve* newNode = createNode(destination, weight);
	newNode->next = adjArray[source].head;
	adjArray[source].head = newNode;

	// For undirected graph

	newNode = createNode(source, weight);
	newNode->next = adjArray[destination].head;
	adjArray[destination].head = newNode;

}
void GraphSolve::createAdjacentMatrix()
{
	// New Logic
	totalNodes = 0;

	// The Total nodes will be from S to E and only the path nodes will be counted

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (array[i][j].path == true)
			{
				totalNodes += 1;
			}
		}
	}

	adjArray = new AdjacentMatrix[totalNodes];

	for (int i = 0; i < totalNodes; i++)
	{
		adjArray[i].head = NULL;
	}


	// Update Vertex Values
	int vertex = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (array[i][j].path == true)
			{
				array[i][j].vertex = vertex;
				vertex += 1;
			}

		}
	}


	/*Sleep(2000);

	cout << "rows " << rows << " columns " << columns << endl;*/
	// Creating the adjacent matrix
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (array[i][j].path == true)
			{
				//cout << array[i][j].value << endl;
				//// We check for the adjacent nodes
				//cout << array[i][j].vertex << endl;
				// For the top node
				if (i - 1 >= 0 && array[i - 1][j].path == true)
				{
					addEdge(array[i][j].vertex, array[i - 1][j].vertex, 1);
				}

				// For the bottom node
				if (i + 1 < rows && array[i + 1][j].path == true)
				{
					addEdge(array[i][j].vertex, array[i + 1][j].vertex, 1);
				}

				// For the left node
				if (j - 1 >= 0 && array[i][j - 1].path == true)
				{
					addEdge(array[i][j].vertex, array[i][j - 1].vertex, 1);
				}

				// For the right node
				if (j + 1 < columns && array[i][j + 1].path == true)
				{
					addEdge(array[i][j].vertex, array[i][j + 1].vertex, 1);
				}
			}
		}
	}
}
void GraphSolve::printEdges()
{
	/*for (int i = 0; i < totalNodes; i++)
	{
		NodeForGraphSolve* temp = adjArray[i].head;
		cout << "Intersection ID " << i << " is connected to: " << endl;
		while (temp)
		{
			cout << temp->vertex << " (Length: " << temp->weight << ") ";
			temp = temp->next;
		}
		cout << endl;
	}*/
	for (int i = 0; i < totalNodes; i++)
	{
		NodeForGraphSolve* temp = adjArray[i].head;
		cout << "Vertex " << i << " : ";
		while (temp != NULL)
		{
			cout << temp->vertex << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}
// The shortest path will be where '.' is present and the path will be marked with 'X' and cannot pass through walls #
void GraphSolve::dijkstra(char source, char destination) {

}
void GraphSolve::shortestPath()
{

}
int GraphSolve::getRows()
{
	return rows;
}
void GraphSolve::setRows(int r)
{
	rows = r;
}
int GraphSolve::getColumns()
{
	return columns;
}
void GraphSolve::setColumns(int c)
{
	columns = c;
}
NodeForGraphSolve** GraphSolve::getMazeObj()
{
	return array;
}
void GraphSolve::setMazeObj(NodeForGraphSolve** m)
{
	array = m;
}
int GraphSolve::getTotalNodes()
{
	return totalNodes;
}
void GraphSolve::setTotalNodes(int t)
{
	totalNodes = t;
}

// Class NodeForVector

template <class T>
NodeForVector<T>::NodeForVector()
{
	next = NULL;
}

// Class Vector

template <class T>
Vector<T>::Vector()
{
	head = NULL;
	tail = NULL;

	size = 0;
}
template <class T>
void Vector<T>::push(T value)
{
	NodeForVector<T>* temp = new NodeForVector<T>();
	temp->value = value;

	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}

	size++;
}
template <class T>
void Vector<T>::pop()
{
	if (head == NULL)
	{
		cout << "The vector is empty" << endl;
	}
	else
	{
		NodeForVector<T>* temp = head;

		while (temp->next != tail)
		{
			temp = temp->next;
		}

		temp->next = NULL;
		tail = temp;

		size--;
	}
}
template <class T>
void Vector<T>::insert(int index, T value)
{
	if (index < 0 || index > size)
	{
		cout << "Index out of bounds" << endl;
	}
	else
	{
		NodeForVector<T>* temp = new NodeForVector<T>();
		temp->value = value;

		if (index == 0)
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			NodeForVector<T>* temp2 = head;

			for (int i = 0; i < index - 1; i++)
			{
				temp2 = temp2->next;
			}

			temp->next = temp2->next;
			temp2->next = temp;
		}

		size++;
	}
}
template <class T>
void Vector<T>::remove(int index)
{
	if (index < 0 || index > size)
	{
		cout << "Index out of bounds" << endl;
	}
	else
	{
		if (index == 0)
		{
			NodeForVector<T>* temp = head;
			head = head->next;

			delete temp;
		}
		else
		{
			NodeForVector<T>* temp = head;

			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->next;
			}

			NodeForVector<T>* temp2 = temp->next;
			temp->next = temp2->next;

			delete temp2;
		}

		size--;
	}
}
template <class T>
void Vector<T>::clear()
{
	while (head != NULL)
	{
		NodeForVector<T>* temp = head;
		head = head->next;

		delete temp;
	}

	size = 0;
}
template <class T>
void Vector<T>::print()
{
	NodeForVector<T>* temp = head;

	while (temp != NULL)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}

	cout << endl;
}
template <class T>
bool Vector<T>::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <class T>
int Vector<T>::getSize()
{
	return size;
}
template <class T>
void Vector<T>::setSize(int s)
{
	size = s;
}
template <class T>
NodeForVector<T>* Vector<T>::getHead()
{
	return head;
}
template <class T>
void Vector<T>::setHead(NodeForVector<T>* h)
{
	head = h;
}
template <class T>
NodeForVector<T>* Vector<T>::getTail()
{
	return tail;
}
template <class T>
void Vector<T>::setTail(NodeForVector<T>* t)
{
	tail = t;
}
template <class T>
Vector<T>::~Vector()
{
	clear();
}

// Class NodeForQueue

template <class T>
NodeForQueue<T>::NodeForQueue()
{

	next = NULL;
}

// Class Queue

template <class T>
Queue<T>::Queue()
{
	head = NULL;
	tail = NULL;

	size = 0;
}
template <class T>
Queue <T>::~Queue()
{
	clear();
}
template <class T>
void Queue<T>::enqueue(T value)
{
	NodeForQueue<T>* temp = new NodeForQueue<T>();
	temp->value = value;

	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}

	size++;
}
template <class T>
void Queue<T>::dequeue()
{
	if (head == NULL)
	{
		cout << "The queue is empty" << endl;
	}
	else
	{
		NodeForQueue<T>* temp = head;
		head = head->next;

		delete temp;

		size--;
	}
}
template <class T>
void Queue<T>::clear()
{
	while (head != NULL)
	{
		NodeForQueue<T>* temp = head;
		head = head->next;

		delete temp;
	}

	size = 0;
}
template <class T>
void Queue<T>::print()
{
	NodeForQueue<T>* temp = head;

	while (temp != NULL)
	{
		cout << temp->value << endl;
		temp = temp->next;
	}

	cout << endl;
}
template<class T>
bool Queue<T>::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template<class T>
bool Queue<T>::find(T value)
{
	NodeForQueue<T>* temp = head;

	while (temp != NULL)
	{
		if (temp->value == value)
		{
			return true;
		}

		temp = temp->next;
	}

	return false;
}
template <class T>
int Queue<T>::getSize()
{
	return size;
}
template <class T>
void Queue<T>::setSize(int s)
{
	size = s;
}
template <class T>
NodeForQueue<T>* Queue<T>::getHead()
{
	return head;
}
template <class T>
void Queue<T>::setHead(NodeForQueue<T>* h)
{
	head = h;
}
template <class T>
NodeForQueue<T>* Queue<T>::getTail()
{
	return tail;
}
template <class T>
void Queue<T>::setTail(NodeForQueue<T>* t)
{
	tail = t;
}

// Class NodeForStack

template <class T>
NodeForStack<T>::NodeForStack()
{
	next = NULL;
}

// Class Stack

template <class T>
Stack<T>::Stack()
{
	head = NULL;

	size = 0;
}
template <class T>
Stack<T>::~Stack()
{
	clear();
}
template <class T>
void Stack<T>::push(T value)
{
	NodeForStack<T>* temp = new NodeForStack<T>();
	temp->value = value;

	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}

	size++;
}
template <class T>
void Stack<T>::pop()
{
	if (head == NULL)
	{
		cout << "The stack is empty" << endl;
	}
	else
	{
		NodeForStack<T>* temp = head;
		head = head->next;

		delete temp;

		size--;
	}
}
template <class T>
void Stack<T>::clear()
{
	while (head != NULL)
	{
		NodeForStack<T>* temp = head;
		head = head->next;

		delete temp;
	}

	size = 0;
}
template <class T>
void Stack<T>::print()
{
	NodeForStack<T>* temp = head;

	while (temp != NULL)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}

	cout << endl;
}
template <class T>
bool Stack<T>::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <class T>
T Stack<T>::top()
{
	if (head == NULL)
	{
		cout << "The stack is empty" << endl;
	}
	else
	{
		return head->value;
	}
}
template <class T>
int Stack<T>::getSize()
{
	return size;
}
template <class T>
void Stack<T>::setSize(int s)
{
	size = s;
}
template <class T>
NodeForStack<T>* Stack<T>::getHead()
{
	return head;
}
template <class T>
void Stack<T>::setHead(NodeForStack<T>* h)
{
	head = h;
}

//Class Player

Player::Player()
{
	name = "";
	date = "";
	time = "";
	score = 0;

	currentMaze = NULL;
}
void Player::updateDateAndTime()
{
	// We get the current date and time
	auto now = chrono::system_clock::now();

	double as;
	time_t current_time = chrono::system_clock::to_time_t(now);
	double asd;

	char asda;
	tm local_time;
	char qq;
	localtime_s(&local_time, &current_time);
	char trc;

	char a;
	stringstream date_stream, time_stream;
	char aa;

	int f = 0;
	date_stream << put_time(&local_time, "%Y-%m-%d");
	int d = 0;
	string date = date_stream.str();
	setDate(date);

	int e = 0;
	time_stream << put_time(&local_time, "%H:%M:%S");
	int t = 0;
	string time = time_stream.str();
	setTime(time);
}
Player::~Player()
{

}
string Player::getName()
{
	return name;
}
void Player::setName(string name)
{
	this->name = name;
}
string Player::getDate()
{
	return date;
}
void Player::setDate(string date)
{
	this->date = date;
}
string Player::getTime()
{
	return time;
}
void Player::setTime(string time)
{
	this->time = time;
}
double Player::getScore()
{
	return score;
}
void Player::setScore(double score)
{
	this->score = score;
}
NodeForGraph** Player::getCurrentMaze()
{
	return currentMaze;
}
void Player::setCurrentMaze(NodeForGraph** maze)
{
	currentMaze = maze;
}

// Class NodeForBinarySearchTree

NodeForBinarySearchTree::NodeForBinarySearchTree()
{
	left = NULL;
	right = NULL;
}
NodeForBinarySearchTree::~NodeForBinarySearchTree()
{

}

// Class BinarySearchTree

BinarySearchTree::BinarySearchTree()
{
	root = NULL;

	size = 0;

}
BinarySearchTree::~BinarySearchTree()
{

}
void BinarySearchTree::insert(Player player)
{
	NodeForBinarySearchTree* newNode = new NodeForBinarySearchTree();
	newNode->player = player;

	NodeForBinarySearchTree* nodePtr;

	if (root == NULL)
	{
		root = newNode;
	}
	else
	{
		nodePtr = root;

		while (nodePtr != NULL)
		{
			if (newNode->player.getScore() < nodePtr->player.getScore())
			{
				if (nodePtr->left == NULL)
				{
					nodePtr->left = newNode;
					break;
				}
				else
				{
					nodePtr = nodePtr->left;
				}
			}
			else if (newNode->player.getScore() > nodePtr->player.getScore())
			{
				if (nodePtr->right == NULL)
				{
					nodePtr->right = newNode;
					break;
				}
				else
				{
					nodePtr = nodePtr->right;
				}
			}
			else
			{
				// If the 2 scores are equal then we compare names

				if (newNode->player.getName() < nodePtr->player.getName())
				{
					if (nodePtr->left == NULL)
					{
						nodePtr->left = newNode;
						break;
					}
					else
					{
						nodePtr = nodePtr->left;
					}
				}
				else if (newNode->player.getName() > nodePtr->player.getName())
				{
					if (nodePtr->right == NULL)
					{
						nodePtr->right = newNode;
						break;
					}
					else
					{
						nodePtr = nodePtr->right;
					}
				}
			}
		}
	}

}
void BinarySearchTree::printInOrder(NodeForBinarySearchTree* node)
{
	if (node != NULL)
	{
		printInOrder(node->left);

		/*cout << node->player.getName() << "\t\t\t" << node->player.getScore() << "\t\t\t" << node->player.getDate() << "\t\t" << node->player.getTime() << endl;*/

		if (size == 0)
		{
			playersArray = new Player[1];
			playersArray[0] = node->player;
			size++;
		}
		else
		{
			Player* temp = new Player[size + 1];

			for (int i = 0; i < size; i++)
			{
				temp[i] = playersArray[i];
			}

			temp[size] = node->player;

			size++;

			delete[] playersArray;

			playersArray = temp;
		}

		players.enqueue(node->player);

		printInOrder(node->right);
	}
}
void BinarySearchTree::printPreOrder(NodeForBinarySearchTree* node)
{
	if (node != NULL)
	{
		cout << node->player.getName() << " " << node->player.getScore() << " " << node->player.getDate() << " " << node->player.getTime() << endl;

		printPreOrder(node->left);

		printPreOrder(node->right);
	}
}
void BinarySearchTree::printPostOrder(NodeForBinarySearchTree* node)
{
	if (node != NULL)
	{
		printPostOrder(node->left);

		printPostOrder(node->right);

		cout << node->player.getName() << " " << node->player.getScore() << " " << node->player.getDate() << " " << node->player.getTime() << endl;
	}
}
void BinarySearchTree::displayHighestScoreDescending(NodeForBinarySearchTree* node)
{
	printInOrder(node);

	char yellowColor[] = "\x1b[33m";
	char resetColor[] = "\x1b[0m";

	bubbleSort();
	selectionSort();
	insertionSort();

	for (int i = 0; i < size; i++)
	{
		cout << yellowColor << playersArray[i].getName() << "\t\t\t" << playersArray[i].getScore() << "\t\t\t" << playersArray[i].getDate() << "\t\t" << playersArray[i].getTime() << endl << endl;
		cout << resetColor;
	}

	/*cout << node->player.getName() << "\t\t\t" << node->player.getScore() << "\t\t\t" << node->player.getDate() << "\t\t" << node->player.getTime() << endl;*/
}
void BinarySearchTree::bubbleSort()
{
	if (size == 0)
	{
		/*cout << "No players in the leader board" << endl;*/
	}
	else
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 2; j++)
			{
				if (playersArray[j].getScore() < playersArray[j + 1].getScore())
				{
					Player temp = playersArray[j];
					playersArray[j] = playersArray[j + 1];
					playersArray[j + 1] = temp;
				}
			}
		}
	}
}
void BinarySearchTree::selectionSort()
{
	if (size == 0)
	{
		/*cout << "No players in the leader board" << endl;*/
	}
	else
	{
		for (int i = 0; i < size - 1; i++)
		{
			int minIndex = i;

			for (int j = i + 1; j < size; j++)
			{
				if (playersArray[j].getScore() > playersArray[minIndex].getScore())
				{
					minIndex = j;
				}
			}

			Player temp = playersArray[i];
			playersArray[i] = playersArray[minIndex];
			playersArray[minIndex] = temp;
		}
	}
}
void BinarySearchTree::insertionSort()
{
	if (size == 0)
	{
		/*cout << "No players in the leader board" << endl;*/
	}
	else
	{
		for (int i = 1; i < size; i++)
		{
			Player temp = playersArray[i];

			int j = i - 1;

			while (j >= 0 && playersArray[j].getScore() < temp.getScore())
			{
				playersArray[j + 1] = playersArray[j];
				j--;
			}

			playersArray[j + 1] = temp;
		}
	}
}
NodeForBinarySearchTree* BinarySearchTree::getRoot()
{
	return root;
}
void BinarySearchTree::setRoot(NodeForBinarySearchTree* r)
{
	root = r;
}

// Class File

File::File()
{

}
File::~File()
{

}
void File::writeToFileForLeaderBoard(BinarySearchTree tree)
{
	ofstream file("LeaderBoard.csv");

	if (file.is_open() == false)
	{
		cout << "Error opening file" << endl;
		Sleep(2000);
	}

	file << "Name,Score,Date,Time," << endl;

	Queue<NodeForBinarySearchTree*> queue;

	queue.enqueue(tree.getRoot());

	while (queue.isEmpty() == false)
	{
		NodeForBinarySearchTree* temp = queue.getHead()->value;

		file << temp->player.getName() << "," << temp->player.getScore() << "," << temp->player.getDate() << "," << temp->player.getTime() << "," << endl;

		if (temp->left != NULL)
		{
			queue.enqueue(temp->left);
		}

		if (temp->right != NULL)
		{
			queue.enqueue(temp->right);
		}

		queue.dequeue();
	}

	file.close();
}
void File::readFromFileForLeaderBoard(BinarySearchTree& tree)
{
	ifstream file("LeaderBoard.csv");

	string line;

	if (file.is_open() == false)
	{
		cout << "Error opening file" << endl;
		Sleep(2000);
	}
	else
	{
		getline(file, line);

		while (getline(file, line))
		{

			string name = "";
			string score = "";
			string date = "";
			string time = "";

			int i = 0;

			while (line[i] != ',')
			{
				name += line[i];
				i++;
			}

			i++;

			while (line[i] != ',')
			{
				score += line[i];
				i++;
			}
			i++;

			while (line[i] != ',')
			{
				date += line[i];
				i++;
			}


			i++;

			while (line[i] != ',')
			{
				time += line[i];
				i++;
			}


			Player player;

			player.setName(name);
			player.setScore(stod(score));
			player.setDate(date);
			player.setTime(time);


			tree.insert(player);

		}
	}




	file.close();
}
void File::writeToFileForResumeGame(Player player, Graph graph)
{
	// We get the current date and time
	auto now = chrono::system_clock::now();

	double as;
	time_t current_time = chrono::system_clock::to_time_t(now);
	double asd;

	char asda;
	tm local_time;
	char qq;
	localtime_s(&local_time, &current_time);
	char trc;

	char a;
	stringstream date_stream, time_stream;
	char aa;

	int e = 0;
	date_stream << put_time(&local_time, "%Y-%m-%d");
	int d = 0;
	string date = date_stream.str();
	player.setDate(date);

	int eas = 0;
	time_stream << put_time(&local_time, "%H:%M:%S");
	int t = 0;
	string time = time_stream.str();
	player.setTime(time);

	// We consider the possibily that multiple users can pause the game and resume it later

	ofstream file("ResumeGame.txt", ios::app);

	if (file.is_open() == false)
	{
		cout << "Error opening file" << endl;
		Sleep(2000);
	}

	file << "Player" << endl;
	file << player.getName() << endl;
	file << player.getDate() << endl;
	file << player.getTime() << endl;
	file << player.getScore() << endl;

	file << graph.getRows() << endl;
	file << graph.getColumns() << endl;
	file << graph.getMode() << endl;
	file << graph.getLives() << endl;

	file << graph.getObstacles() << endl;
	file << graph.getPowerUps() << endl;
	file << graph.getCoins() << endl;

	file << graph.getCompleted() << endl;

	file << graph.getQueueForObstacles().getSize() << endl;
	file << graph.getQueueForPowerUps().getSize() << endl;
	file << graph.getStackForCoins().getSize() << endl;

	NodeForGraph** maze = graph.getArray();

	for (int i = 0; i < graph.getRows(); i++)
	{
		for (int j = 0; j < graph.getColumns(); j++)
		{
			file << maze[i][j].value << " ";
		}

		file << endl;
	}

	file.close();
}
void File::readFromFileForResumeGame(Player& playerObj, Graph& graphObj, Maze& mazeObj)
{
	ifstream file("ResumeGame.txt");

	if (file.is_open() == false)
	{
		cout << "Error opening file" << endl;
		Sleep(2000);
	}

	// First we read only all player names and ask user which user wants to resume the game

	Queue<string> queueForNames;
	while (file.eof() == false)
	{
		string line;

		getline(file, line);

		if (line == "Player")
		{
			getline(file, line);
			queueForNames.enqueue(line);
		}
	}

	file.close();

	// We ask user which user wants to resume the game

	cout << "Which user wants to resume the game?" << endl;

	queueForNames.print();

	cout << "Enter name: ";
	string name;
	cin >> name;

	while (queueForNames.find(name) == false)
	{
		cout << "Invalid Name!";
		cout << "Enter Name:";
		cin >> name;
	}

	// We open the file again and read the data of the user	

	ifstream file2("ResumeGame.txt");

	if (file2.is_open() == false)
	{
		cout << "Error opening file" << endl;
		Sleep(2000);
	}

	int prevRows = 0;
	int prevColumns = 0;
	while (file2.eof() == false)
	{
		string line;

		getline(file2, line);

		if (line == "Player")
		{
			getline(file2, line);

			if (line == name)
			{
				playerObj.setName(line);

				getline(file2, line);
				playerObj.setDate(line);

				getline(file2, line);
				playerObj.setTime(line);

				getline(file2, line);
				playerObj.setScore(stod(line));

				getline(file2, line);
				prevRows = graphObj.getRows();
				graphObj.setRows(stoi(line));

				getline(file2, line);
				prevColumns = graphObj.getColumns();
				graphObj.setColumns(stoi(line));

				getline(file2, line);
				graphObj.setMode(line[0]);

				getline(file2, line);
				graphObj.setLives(stoi(line));

				getline(file2, line);
				graphObj.setObstacles(stoi(line));

				getline(file2, line);
				graphObj.setPowerUps(stoi(line));

				getline(file2, line);
				graphObj.setCoins(stoi(line));

				getline(file2, line);
				graphObj.setCompleted(stoi(line));

				getline(file2, line);
				int size = stoi(line);

				for (int i = 0; i < size; i++)
				{
					getline(file2, line);
					graphObj.getQueueForObstacles().enqueue(line[0]);
				}

				getline(file2, line);
				size = stoi(line);

				for (int i = 0; i < size; i++)
				{
					getline(file2, line);
					graphObj.getQueueForPowerUps().enqueue(line[0]);
				}

				getline(file2, line);
				size = stoi(line);

				for (int i = 0; i < size; i++)
				{
					getline(file2, line);
					graphObj.getStackForCoins().push(line[0]);
				}

				NodeForGraph** maze = new NodeForGraph * [graphObj.getRows()];

				for (int i = 0; i < graphObj.getRows(); i++)
				{
					maze[i] = new NodeForGraph[graphObj.getColumns()];
				}

				for (int i = 0; i < graphObj.getRows(); i++)
				{
					for (int j = 0; j < graphObj.getColumns(); j++)
					{
						file2 >> maze[i][j].value;
					}
				}

				// We Also copy the maze to mazeObj by creating a int** array and setting it 
				mazeObj.deleteMaze();
				mazeObj.setRows(graphObj.getRows());
				mazeObj.setColumns(graphObj.getColumns());

				int** mazeArray = new int* [graphObj.getRows()];

				for (int i = 0; i < graphObj.getRows(); i++)
				{
					mazeArray[i] = new int[graphObj.getColumns()];
				}

				for (int i = 0; i < graphObj.getRows(); i++)
				{
					for (int j = 0; j < graphObj.getColumns(); j++)
					{
						mazeArray[i][j] = maze[i][j].value;
					}
				}
				mazeObj.setMode(graphObj.getMode());
				mazeObj.setMaze(mazeArray);


				graphObj.setRows(prevRows);
				graphObj.setColumns(prevColumns);
				graphObj.deletePreviousGraphAndCopyNew(mazeObj);

			}
		}
	}

}


int main()
{
	char resetColor[] = "\x1b[0m";
	char lightRed[] = "\x1b[91m";
	char lightGreen[] = "\x1b[92m";
	char lightBlue[] = "\x1b[94m";

	Maze mazeObj;

	Graph graphObj;
	bool pause = true;

	GraphSolve graphSolveObj;

	Player playerObj;
	string name;

	File fileObj;

	BinarySearchTree bstObj;
	/*fileObj.writeToFileForLeaderBoard(bstObj);*/

	// Testing the maze
	/*mazeObj.createEasyMaze();

	graphObj.createGraphFromMaze(mazeObj);
	graphObj.printGraph();*/

	// Menu.mp3

	sf::SoundBuffer buffer;

	if (!buffer.loadFromFile("menu.mp3")) {
		// Failed to load the MP3 file
	}

	// Create a sound object and associate it with the loaded buffer
	sf::Sound sound;
	sound.setBuffer(buffer);

	// Win.mp3

	sf::SoundBuffer buffer2;

	if (!buffer2.loadFromFile("win.mp3")) {
		// Failed to load the MP3 file
	}

	// Create a sound object and associate it with the loaded buffer
	sf::Sound sound2;
	sound2.setBuffer(buffer2);


	bool inputFlag = false;
	int input = -1;
	while (input != 0)
	{
		inputFlag = false;

		sound.play();
		// Keep the program running while the sound is playing
		while (sound.getStatus() == sf::Sound::Playing && inputFlag == false) {
			// Do nothing or perform other tasks

			system("CLS");
			cout << lightGreen;
			cout << "||   __________    __________   _________   ___                ___   ___________    __________         __         __________   ____       _____       ||" << endl;
			cout << "||  ||         \\   ||       ||      ||       \\                //    ||            ||        \\         //\\        | _________|  |   |      |   |       ||" << endl;
			cout << "||  ||         ||  ||       ||      ||        \\              //     ||            ||         ||      //  \\       | |           |   |      |   |       ||" << endl;
			cout << "||  ||         ||  ||      //       ||         \\            //      ||            ||         ||     //    \\      | |_______    |   |______|   |       ||" << endl;
			cout << "||  ||         ||  ||_____//        ||          \\          //       ||_______     ||         ||    //------\\     |_________|   |              |       ||" << endl;
			cout << "||  ||         ||  ||     \\         ||           \\        //        ||            ||         ||   //        \\            | |   |    _______   |       ||" << endl;
			cout << "||  ||         ||  ||      \\        ||            \\      //         ||            ||         ||  //          \\           | |   |   |      |   |       ||" << endl;
			cout << "||  ||        //   ||       \\       ||             \\    //          ||            ||        //  //            \\   _______| |   |   |      |   |       ||" << endl;
			cout << "||  ||_______//    ||        \\   ___||___           \\__//           ||_________   ||_______//  //              \\ |_______|_|   |___|      |___|       ||" << endl;
			cout << resetColor;
			cout << endl << endl << endl;

			cout << lightRed;
			cout << "\t\t\t\t\t\t\t\t1. Start New Game" << endl << endl;
			cout << "\t\t\t\t\t\t\t\t2. Load Game" << endl << endl;
			cout << "\t\t\t\t\t\t\t\t3. Leaderboard" << endl << endl;
			cout << "\t\t\t\t\t\t\t\t0. Exit" << endl << endl;


			cout << "\t\t\t\t\t\t\t\tEnter your choice: ";
			cin >> input;

			while (input < 0 || input > 3)
			{
				cout << "Invalid Input! Please enter again: ";
				cin >> input;
			}
			inputFlag = true;
		}
		cout << resetColor;

		system("CLS");

		switch (input)
		{
		case 1:
			mazeObj = Maze();
			graphObj = Graph();

			cout << lightBlue;
			cout << "Select Difficulty: " << endl << endl;
			cout << "1. Easy" << endl << endl;
			cout << "2. Medium" << endl << endl;
			cout << "3. Hard" << endl << endl;

			cout << "Enter your choice: ";
			cin >> input;

			while (input < 1 || input > 3)
			{
				cout << "Invalid Input! Please enter again: ";
				cin >> input;
			}
			cout << resetColor;

			if (input == 1)
			{
				mazeObj.createEasyMaze();
			}
			else if (input == 2)
			{
				mazeObj.createMediumMaze();
			}
			else if (input == 3)
			{
				mazeObj.createHardMaze();
			}

			graphObj.createGraphFromMaze(mazeObj);

			system("CLS");

			cout << lightBlue;
			cout << "Select Mode: " << endl << endl;
			cout << "1. Manual" << endl << endl;
			cout << "2. Auto" << endl << endl;

			cout << "Enter your choice: ";
			cin >> input;

			while (input < 1 || input > 2)
			{
				cout << "Invalid Input! Please enter again: ";
				cin >> input;
			}

			cout << resetColor;

			if (input == 1)
			{
				cout << "Enter Player Name: ";
				cin >> name;
				playerObj.setName(name);

				pause = graphObj.playGame();

				if (pause == false)
				{
					fileObj.writeToFileForResumeGame(playerObj, graphObj);
				}

				pause = true;

				if (graphObj.getCompleted() == true)
				{
					sound2.play();
					while (sound2.getStatus() == sf::Sound::Playing) {
						// Do nothing or perform other tasks
					}

					playerObj.setScore(graphObj.getScore());
					playerObj.updateDateAndTime();

					/*bstObj.printInOrder(bstObj.getRoot());*/
					bstObj.setRoot(NULL);
					fileObj.readFromFileForLeaderBoard(bstObj);
					bstObj.insert(playerObj);
					fileObj.writeToFileForLeaderBoard(bstObj);

					Sleep(5000);
				}

			}
			else if (input == 2)
			{
				system("CLS");

				graphSolveObj.createGraph(mazeObj);

				graphSolveObj.printGraph();

				graphSolveObj.createAdjacentMatrix();

				graphSolveObj.copyToTwoDArray();

				/*graphSolveObj.printEdges();*/
				//------------------------------------------------------------------------------

				/*graphSolveObj.dijkstra(1, graphSolveObj.getTotalNodes() - 1);*/

				/*graphSolveObj.dijkstra('S', 'E');*/

				/*graphSolveObj.shortestPath();*/

				Sleep(10000);

			}

			break;
		case 2:

			cout << lightGreen << "------------------------------------------Resume Game------------------------------------------" << resetColor << endl << endl;

			fileObj.readFromFileForResumeGame(playerObj, graphObj, mazeObj);

			graphObj.playGame();

			break;
		case 3:

			cout << lightGreen << "------------------------------------------Leaderboard------------------------------------------" << resetColor << endl << endl;

			cout << lightBlue << "Name\t\t\tScore\t\t\tDate\t\t\tTime" << resetColor << endl << endl;

			bstObj.setRoot(NULL);

			fileObj.readFromFileForLeaderBoard(bstObj);

			bstObj.displayHighestScoreDescending(bstObj.getRoot());

			Sleep(5000);

			break;

		case 0:
			break;
		}
	}

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
