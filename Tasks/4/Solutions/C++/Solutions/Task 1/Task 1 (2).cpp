// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"C:\Users\wiki8\Desktop\Task 1\Header.h"

using namespace std;

Puzzle::Puzzle(int size1, int size2, int size3)
{
	array1 = new int[size1];
	array2 = new int[size2];
	array3 = new int[size3];

	s1 = size1;
	s2 = size2;
	s3 = size3;

	for (int i = 0; i < size1; i++)
	{
		array1[i] = 0;
	}

	for (int i = 0; i < size2; i++)
	{
		array2[i] = 0;
	}

	for (int i = 0; i < size3; i++)
	{
		array3[i] = 0;
	}
}

void Puzzle::array1Input()
{
	cout << "Enter the elements of the first array: ";
	for (int i = 0; i < s1; i++)
	{
		cin >> array1[i];
	}

	for (int i = 0; i < s1; i++)
	{
		cout << array1[i];
	}
}

void Puzzle::array2Input()
{
	cout << "Enter the elements of the second array: ";
	for (int i = 0; i < s2; i++)
	{
		cin >> array2[i];
	}

	for (int i = 0; i < s2; i++)
	{
		cout << array2[i];
	}
}

void Puzzle::array3Input()
{
	cout << "Enter the elements of the third array: ";
	for (int i = 0; i < s3; i++)
	{
		cin >> array3[i];
	}

	for (int i = 0; i < s3; i++)
	{
		cout << array3[i];
	}
}

void Puzzle::insertionSort()
{
	int i;
	int j;
	int key;
	int size1 = s1;
	for (i = 1; i < size1; i++)
	{
		key = array1[i];
		j = i - 1;

		while (j >= 0 && array1[j] > key)
		{
			array1[j + 1] = array1[j];
			j = j - 1;
		}
		array1[j + 1] = key;
	}
}

void Puzzle::selectionSort()
{
	int i;
	int j;
	int minIndex;
	int temp;
	int size2 = s2;

	for (i = 0; i < size2 - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < size2; j++)
		{
			if (array2[j] < array2[minIndex])
			{
				minIndex = j;
			}
		}
		temp = array2[minIndex];
		array2[minIndex] = array2[i];
		array2[i] = temp;
	}
}

void Puzzle::bubbleSort()
{
	int i;
	int j;
	int temp;
	int size3 = s3;
	bool flag = false;

	for (i = 0; i < size3 - 1; i++)
	{
		for (j = 0; j < size3 - i - 1; j++)
		{
			if (array3[j] > array3[j + 1])
			{
				temp = array3[j];
				array3[j] = array3[j + 1];
				array3[j + 1] = temp;
				flag = true;
			}
		}
	}
}

void Puzzle::print()
{
	cout << "The first array is: ";
	for (int i = 0; i < s1; i++)
	{
		cout << array1[i];
		cout << " ";
	}
	cout << endl << endl;

	cout << "The second array is: ";
	for (int i = 0; i < s2; i++)
	{
		cout << array2[i];
		cout << " ";
	}
	cout << endl << endl;

	cout << "The third array is: ";
	for (int i = 0; i < s3; i++)
	{
		cout << array3[i];
		cout << " ";
	}
	cout << endl << endl;
}

Puzzle::~Puzzle()
{
	delete[] array1;
	delete[] array2;
	delete[] array3;
}


int main()
{
	cout << "Enter the size of the first array: ";
	int size1;
	cin >> size1;

	cout << "Enter the size of the second array: ";
	int size2;
	cin >> size2;

	cout << "Enter the size of the third array: ";
	int size3;
	cin >> size3;

	Puzzle puzzle(size1, size2, size3);

	puzzle.array1Input();
	puzzle.array2Input();
	puzzle.array3Input();

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
