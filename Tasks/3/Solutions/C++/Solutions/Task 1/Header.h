#pragma once

#include <iostream>

using namespace std;

int min(int* a, int size)
{
	int num = 0;

	for (int i = 0; i < size; i++)
	{
		if (a[i] < num)
		{
			num = a[i];
		}
	}

	return num;
}

int max(int* a, int size)
{
	int num = 0;

	for (int i = 0; i < size; i++)
	{
		if (a[i] > num)
		{
			num = a[i];
		}
	}

	return num;
}