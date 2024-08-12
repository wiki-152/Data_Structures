// Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	char Crossword2D [3][3] = { {'C','E','M'},{'B','A','O'},{'X','W','T'} };
	char wordToFind [3] = {'C','A','T'};

	int indexArray[2][3] = { {0,0,0},{0,0,0} };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Crossword2D[i][j] == wordToFind[0])
			{
				indexArray[0][0] = i;
				indexArray[1][0] = j;
			}
			if (Crossword2D[i][j] == wordToFind[1])
			{
				indexArray[0][1] = i;
				indexArray[1][1] = j;
			}
			if (Crossword2D[i][j] == wordToFind[2])
			{
				indexArray[0][2] = i;
				indexArray[1][2] = j;
			}
		}
	}

	cout << "The indexes are : " << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << indexArray[i][j] << " ";
		}
		cout << endl;
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
