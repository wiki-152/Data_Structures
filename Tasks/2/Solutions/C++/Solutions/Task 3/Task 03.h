#pragma once

#include <iostream>

using namespace std;

template <typename T>
void sameElements(T a)
{
	T array1[5];
	T array2[5];

	for (int i = 0; i < 5; i++)
	{
		array1[i] = 0;
		array2[i] = 0;
	}

	cout << "Give elements array 1: " << endl;

	for (int i = 0; i < 5; i++)
	{
		cin >> array1[i];
	}

	cout << "Give elements array 2: " << endl;

	for (int i = 0; i < 5; i++)
	{
		cin >> array2[i];
	}

	for (int i = 0; i < 5; i++)
	{
		
		for (int j = 0 ; j < 5; j++)
		{
			
			if (array1[i] == array2[j])
			{
				cout << "Same elements: " << array1[i] << endl;
			}
		}
	}
}

template <typename T>
void concatenateArrays(T a)
{
	T array1[5];
	T array2[5];

	for (int i = 0; i < 5; i++)
	{
		array1[i] = 0;
		array2[i] = 0;
	}

	cout << "Give elements array 1: " << endl;

	for (int i = 0; i < 5; i++)
	{
		cin >> array1[i];
	}

	cout << "Give elements array 2: " << endl;

	for (int i = 0; i < 5; i++)
	{
		cin >> array2[i];
	}

	T array3[10];

	for (int i = 0; i < 5; i++)
	{
		array3[i] = 0;
	}

	int array3Counter = 0;

	for (int i = 0; i < 5; i++)
	{
		array3[array3Counter] = array1[i];
		array3Counter++;
	}

	for (int i = 0; i < 10; i++)
	{
		cout<< array3[i] << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			
			if (array3[j] != array2[i])
			{
				cout << array3[j] << " and  " << array2[i] << endl;
				array3[array3Counter] = array2[i];
				array3Counter++;
				break;
			}
		}
	}



	cout<< "Array 3" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << array3[i] << endl;
	}

	
}