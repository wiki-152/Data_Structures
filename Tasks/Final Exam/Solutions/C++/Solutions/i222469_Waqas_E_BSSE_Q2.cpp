#include <iostream>
#include <string>
#include "i222469_Waqas_E_BSSE_Q2.h"

using namespace std;

// Assume word is all capital
int main()
{
	string a;
	cout << "Enter Sentence: ";
	getline(cin, a);

	Algo sen;
	sen.updateFrequency(a);

	Binary obj;

	for (int i = 0; i < 28; i++)
	{
		if (sen.frequency[i] != 0)
		{
			obj.toBinary(sen.frequency[i]);
		}
	}

	cout << obj.getBinary();

	bool freq[28];

	for (int i = 0; i < 28; i++)
	{

	}




	return 0;
}

