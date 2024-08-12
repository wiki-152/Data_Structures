// Task 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	int row = 0;
	int col = 0;

	cout << "Enter the number of rows: ";
	cin >> row;

	cout << "Enter the number of columns: ";
	cin >> col;

	float** matrix = new float* [row];

	for (int i = 0; i < row; i++)
	{
		matrix[i] = new float[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = 0;
			cin>> matrix[i][j];
		}
	}

	int counter = 0; 
	float sumOfRow = 0;
	bool One = false;

	for (int i = 0; i < row; i++)
	{
		sumOfRow = 0;
		for (int j = 0; j < col; j++)
		{
			sumOfRow += matrix[i][j];
		}
		
		if (sumOfRow == 1)
		{
			One = true;
			counter += 1;
		}
		else
		{
			One = false;
		}
	}

	if (counter == row)
	{
		cout << "The matrix is a Markov Matrix" << endl;
	}
	else
	{
		cout << "The matrix is not a Markov Matrix" << endl;
	}
}
