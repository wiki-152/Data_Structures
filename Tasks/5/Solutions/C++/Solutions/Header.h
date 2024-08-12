#pragma once

#include <iostream>

using namespace std;

class Employee
{
	private:
		int empID;
		string NIC;
		double salary;
		double bonus;
	public:
		Employee();
		Employee(int empID_, string NIC_, double salary_, double bonus_);
		void print();

		int getEmpID();
		string getNIC();
		double getSalary();
		double getBonus();

		void setEmpID(int empID_);
		void setNIC(string NIC_);
		void setSalary(double salary_);
		void setBonus(double bonus_);
};

class Node
{
public:
	Employee* data;
	Node* next;

	Node();
};

class LinkedList
{
private:
	Node* head;

public:
	LinkedList();
	~LinkedList();

	void insert(const Employee& emp);
	void remove(int empID);
	void updateSalary(const double& salary, int empID);
	void updateBonus(const double& bonus, int empID);
	void clear();
	bool isEmpty();
	void display();
	void sort();
};

