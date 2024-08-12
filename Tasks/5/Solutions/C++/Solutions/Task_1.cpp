// Task_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"
#include "Windows.h"

using namespace std;

Employee::Employee()
{
	empID = 0;
	NIC = "";
	salary = 0.0;
	bonus = 0.0;
}

Employee::Employee(int empID_ = 0, string NIC_ = "", double salary_ = 0, double bonus_ = 0)
{
	empID = empID_;
	NIC = NIC_;
	salary = salary_;
	bonus = bonus_;
}

void Employee::print()
{
	cout << "Employee ID: " << empID << endl;
	cout << "NIC: " << NIC << endl;
	cout << "Salary: " << salary << endl;
	cout << "Bonus: " << bonus << endl;
	cout << endl;
}

int Employee::getEmpID()
{
	return empID;
}

string Employee::getNIC()
{
	return NIC;
}

double Employee::getSalary()
{
	return salary;
}

double Employee::getBonus()
{
	return bonus;
}

void Employee::setEmpID(int empID_)
{
	empID = empID_;
}

void Employee::setNIC(string NIC_)
{
	NIC = NIC_;
}

void Employee::setSalary(double salary_)
{
	salary = salary_;
}

void Employee::setBonus(double bonus_)
{
	bonus = bonus_;
}

Node::Node()
{
	data = NULL;
	next = NULL;
}

LinkedList::LinkedList()
{
	head = NULL;
}

LinkedList::~LinkedList()
{
	Node* temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		delete head;
		head = temp;
	}
}

void LinkedList::insert(const Employee& emp)
{
	Node* newNode = new Node;
	newNode->data = new Employee(emp);
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		Node* temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}
}

void LinkedList::remove(int empID)
{
	Node* temp = head;
	Node* prev = NULL;
	bool found = false;

	int checkID = 0;
	while (temp != NULL)
	{
		checkID = temp->data->getEmpID();
		if (checkID == empID)
		{
			found = true;
			if (prev == NULL)
			{
				head = temp->next;
			}
			else
			{
				prev->next = temp->next;
			}

			delete temp;
			return;
		}

		prev = temp;
		temp = temp->next;
	}

	if (found == false)
	{
		cout << "Record does not exist" << endl;
	}
	else
	{
		cout << "Employee ID : " << empID << " removed" << endl;
	}
}

void LinkedList::updateSalary(const double& salary, int empID)
{
	Node* temp = head;

	int checkID = 0;
	while (temp != NULL)
	{
		checkID = temp->data->getEmpID();
		if (checkID == empID)
		{
			temp->data->setSalary(salary);
			break;
		}
		temp = temp->next;
	}
}

void LinkedList::updateBonus(const double& bonus, int empID)
{
	Node* temp = head;

	int checkID = 0;
	while (temp != NULL)
	{
		checkID = temp->data->getEmpID();
		if (checkID == empID)
		{
			temp->data->setBonus(bonus);
			break;
		}

		temp = temp->next;
	}
}

void LinkedList::clear()
{
	Node* temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		delete head;
		head = temp;
	}
}

bool LinkedList::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void LinkedList::display()
{
	Node* temp = head;

	while (temp != NULL)
	{
		temp->data->print();
		temp = temp->next;
	}
}

void LinkedList::sort()
{
	// Bubble Sorting Algorithm

	Node* temp = head;

	int sizeOfList = 0;

	while (temp != NULL)
	{
		sizeOfList++;
		temp = temp->next;
	}

	temp = head;
	for (int p = 1; p < sizeOfList; p++)
	{
		for (int i = 0; i < sizeOfList - p; i++)
		{
			if (temp->data->getSalary() > temp->next->data->getSalary())
			{
				Employee* tempEmp = temp->data;
				temp->data = temp->next->data;
				temp->next->data = tempEmp;
			}

			temp = temp->next;
		}
	}
	display();
}

int main()
{
	LinkedList l1;

	cout << "Is Empty:";
	cout << l1.isEmpty() << endl;

	Employee E1(188079, "12345-1234567-1", 50000, 5000);
	Employee E2(188098, "12355-1034577-0", 30000, 0);
	Employee E3(184243, "10045-1200567-1", 70000, 10000);
	
	cout << "Inserting....." << endl;
	l1.insert(E1);
	l1.insert(E2);
	l1.insert(E3);
	
	Sleep(1000);
	l1.display();
	
	cout<< "Removing....." << endl;
	l1.remove(188098);
	Sleep(1000);
	l1.display();
	
	cout << "Updating....." << endl;
	l1.updateSalary(200, 188079);
	l1.updateBonus(150, 184243);
	Sleep(1000);
	l1.display();
	
	cout << "Is Empty : ";
	cout << l1.isEmpty();
	cout << endl;
	
	cout << "Sorting....." << endl;
	l1.sort();
	Sleep(1000);
	l1.display();
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
