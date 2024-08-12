#pragma once

#include <iostream>

using namespace std;

class Puzzle
{
private:
	int *array1;
	int *array2;
	int *array3;
	int s1;
	int s2;
	int s3;

public:
	Puzzle(int size1, int size2, int size3);
	void array1Input();
	void array2Input();
	void array3Input();
	void insertionSort();
	void selectionSort();
	void bubbleSort();
	void print();
	~Puzzle();
};


