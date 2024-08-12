#pragma once

#include <iostream>

using namespace std;

template <typename T1 , typename T2 , typename T3>
class Store
{
private:
	int counterInt;
	int counterDouble;
	int counterChar;

	T1 arrayInt[10];
	T2 arrayDouble[10];
	T3 arrayChar[10];


public:
	Store();

	void input();

	void add(T1 a);

	void add(T2 a);

	void add(T3 a);

	void display();
};


