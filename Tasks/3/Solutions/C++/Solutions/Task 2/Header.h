#pragma once

#include <iostream>

using namespace std;

void print(char * stringArray , char ch)
{
	int i = 0;

	int index = -1;
	
	while (stringArray[i] != '\0')
	{
		if (stringArray[i] == ch)
		{
			index = i;
			break;
		}
		i++;
	}

	while (stringArray[index] != '\0')
	{
		cout << stringArray[index];
		index++;
	}
	
}