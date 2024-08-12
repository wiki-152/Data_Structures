// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"C:\Users\wiki8\Desktop\Task 1\Header.h"

using namespace std;

Puzzle::Puzzle()
{

}

void Puzzle::array1Input()
{
	rows = 3;
	col1 = 7;
	col2 = 12;
	col3 = 5;

	array1 = NULL;
	array1 = new int*[rows];

	array1[0] = new int [col1];
	array1[1] = new int [col2];
	array1[2] = new int [col3];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col1; j++)
		{
			cout << "Enter Value For Row " << i << " Column " << j << " : ";
			array1[i][j] = 0 ;
			cin >> array1[i][j];
		}
		
		for (int j = 0; j < col2; j++)
		{
			cout << "Enter Value For Row " << i << " Column " << j << " : ";
			array1[i][j] = 0;
			cin >> array1[i][j];
		}

		for (int j = 0; j < col3; j++)
		{
			cout << "Enter Value For Row " << i << " Column " << j << " : ";
			array1[i][j] = 0;
			cin >> array1[i][j];
		}
	}
}


void Puzzle::insertionSort()
{
	cout << "Insertion Sort" << endl;

	int temp;
	int j;
	int key;

	for (int i = 0; i < 1; i++)
	{
		key = array1[0][i];
		j = i - 1;

		while (j >= 0 && array1[0][j] > key)
		{
			array1[0][j + 1] = array1[0 ][j];
			j = j - 1;
		}
		array1[0][j + 1] = key;
	}

}

void Puzzle::selectionSort()
{
	int i;
	int j;
	int minIndex;
	int temp;

	for (i = 1; i < 2; i++)
	{
		minIndex = i;
		for (j = i + 1; j < 12; j++)
		{
			if (array1[1][j] < array1[1][minIndex])
			{
				minIndex = j;
			}
		}
		temp = array1[1][minIndex];
		array1[1][minIndex] = array1[1][i];
		array1[1][i] = temp;
	}
}

void Puzzle::bubbleSort()
{
	int i;
	int j;
	int temp;
	bool flag = false;

	for (i = 2; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (array1[2][j] > array1[2][j + 1])
			{
				temp = array1[2][j];
				array1[2][j] = array1[2][j + 1];
				array1[2][j + 1] = temp;
				flag = true;
			}
		}
	}
}

void Puzzle::print()
{
	for (int i = 0; i < rows; i++)
	{
		cout << endl;
		for (int j = 0; j < col1; j++)
		{
			cout << array1[i][j] << " ";
		}

		cout << endl;

		for (int j = 0; j < col2; j++)
		{
			cout << array1[i][j] << " ";
		}

		cout << endl;

		for (int j = 0; j < col3; j++)
		{
			cout << array1[i][j] << " ";
		}

		cout << endl;
	}
}

Puzzle::~Puzzle()
{

}


int main()
{
	

	Puzzle puzzle;

	puzzle.array1Input();

	puzzle.insertionSort();
	puzzle.selectionSort();
	puzzle.bubbleSort();

	puzzle.print();


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
