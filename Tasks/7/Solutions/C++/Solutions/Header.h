#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <Windows.h>


using namespace std;

class student
{
public:

	string serialNo;
	string regDate;
	string rollNo;
	string name;
	string as1;
	string as2;
	string as3;
	string as4;
	string as;
	string si1;
	string si;
	string project1;
	string project;
	string final1;
	string final;
	string mid1;
	string mid;
	string gtotal;
	string grade;

	void print();

};

class Node
{
public:
	student data;
	Node* next;

	Node();
};

class stack
{
private:
	Node *head;
	Node* top;
	int size;

public:

	stack();
	void push(student data);
	void pop();
	student peek();
	bool isEmpty();

	void print();

};