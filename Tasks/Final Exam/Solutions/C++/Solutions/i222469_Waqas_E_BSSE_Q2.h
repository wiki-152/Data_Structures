#pragma once

#include <iostream>
#include <string>

using namespace std;

class Algo
{
	

public:
	int frequency[28];
	Algo();
	~Algo();

	void updateFrequency(string a);


};

Algo::Algo()
{
	for (int i = 0; i < 28; i++)
	{
		frequency[i] = 0;
	}
}

Algo::~Algo()
{

}

void Algo::updateFrequency(string a)
{
	cout << a;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == ' ')
		{
			frequency[27] += 1;
		}
		else
		{
			int n = a[i] - 65;
			frequency[n]  += 1;
		}
	}

	char alpha = 65;
	for (int i = 0; i < 28; i++)
	{
		if (i == 27)
		{
			cout<< "Space :" << frequency[i] << endl;
			break;

		}
		cout << alpha << " : ";
		cout<< frequency[i]<<endl;

		alpha += 1;
	}

}

class Binary
{
	string binary;

public:
	Binary();
	~Binary();

	void toBinary(int n);

	void setBinary(string a);
	string getBinary();
};

inline Binary::Binary()
{
	binary = "";
}

inline Binary::~Binary()
{

}

void Binary::toBinary(int n)
{
	string result = "";
	while (n > 0)
	{
		int remainder = n % 2;
		result = to_string(remainder) + result;
		n /= 2;
	}

	binary += result;
}


inline void Binary::setBinary(string a)
{
	binary = a;
}

inline string Binary::getBinary()
{
	return binary;
}

class Node
{
public:

	char alpha;
	int num;
	Node* left;
	Node* right;
};

class priorityQueue
{
public:

	priorityQueue();

	void addNode(int v1, char c1, int v2, char c2)
	{

	}

};






