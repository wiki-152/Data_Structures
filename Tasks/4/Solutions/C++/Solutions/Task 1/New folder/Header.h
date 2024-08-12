#pragma once

#include <iostream>

using namespace std;

class Puzzle
{
private:
	int **array1;
	int rows;
	int col1;
	int col2; 
	int col3;

public:
	Puzzle();
	void array1Input();
	void insertionSort();
	void selectionSort();
	void bubbleSort();
	void print();
	~Puzzle();
};


