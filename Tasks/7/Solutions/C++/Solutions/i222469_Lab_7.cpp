// i222469_Lab_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


/*
1. Read a given CSV file using file handling:  Open and read the CSV file.
2. Create a Student class and data members according to the CSV file:  Define a class to represent a student and create data members that match the 
CSV columns.
3. Implement constructors and setter/getter methods accordingly:  Define constructors and accessor methods for the Student class.
4. Push the elements into Stack:  Store student objects in a stack data structure.
5. Create an array named stdData and add all student objects to this array from 
the Stack:  Transfer student objects from the stack to an array. 6. Load CSV file:  Load the CSV file, separated for clarity in the menu.
7. Use a sorting algorithm to sort your array based on attributes like "Roll No," 
"Name," etc.  Select an attribute and sort the array accordingly. 8. Create a separate function for sorting by each attribute and save a separate 
sorted CSV file for each attribute:  Implement sorting functions for various attributes and save sorted CSV files.
9. Create a menu for this case accordingly:  Design a user interface to select sorting attributes and execute the sorting and 
saving operations.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <Windows.h>
#include "Header.h"

using namespace std;

void student::print()
{
	cout << serialNo << " " << regDate << " " << rollNo << " " << name << " " << as1 << " " << as2 << " " << as3 << " " << as4 << " " << as << " " << si1 << " " << si << " " << project1 << " " << project << " " << final1 << " " << final << " " << mid1 << " " << mid << " " << gtotal << " " << grade << endl;
}


Node::Node()
{
	next = NULL;
}


stack::stack()
{
	head = NULL;
	top = NULL;
	size = 0;
}

void stack::push(student data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		top = temp;
	}
	else
	{
		top->next = temp;
		top = temp;
	}
	size++;

}

void stack::pop()
{
	if (head == NULL)
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		Node* temp = head;
		while (temp->next != top)
		{
			temp = temp->next;
		}
		top = temp;
		top->next = NULL;
		size--;
	}
}

student stack::peek()
{
	return top->data;
}

bool stack::isEmpty()
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

void stack::print()
{
	Node* temp = head;
	int counter = 1;
	while (temp != NULL)
	{
		cout << "Student " << counter << endl;
		temp->data.print();
		temp = temp->next;
		counter ++;
	}
}

void sortingByRollNo(student* arrayOfStudents)
{
	cout << "Sorting of Array By Roll No" << endl;

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			if (arrayOfStudents[j].rollNo > arrayOfStudents[j + 1].rollNo)
			{
				student temp = arrayOfStudents[j];
				arrayOfStudents[j] = arrayOfStudents[j + 1];
				arrayOfStudents[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 30; i++)
	{
		arrayOfStudents[i].print();
	}

	// Write to csv file

	fstream file("sortedByRollNo.csv", ios::out);

	file << "Serial No,Registration Date,Roll No,Name,Assignment 1,Assignment 2,Assignment 3,Assignment 4,Assignment,Sessional 1,Sessional,Project 1,Project,Final 1,Final,Mid 1,Mid,Grand Total,Grade" << endl;

	for (int i = 0; i < 30; i++)
	{
		file << arrayOfStudents[i].serialNo << "," << arrayOfStudents[i].regDate << "," << arrayOfStudents[i].rollNo << "," << arrayOfStudents[i].name << "," << arrayOfStudents[i].as1 << "," << arrayOfStudents[i].as2 << "," << arrayOfStudents[i].as3 << "," << arrayOfStudents[i].as4 << "," << arrayOfStudents[i].as << "," << arrayOfStudents[i].si1 << "," << arrayOfStudents[i].si << "," << arrayOfStudents[i].project1 << "," << arrayOfStudents[i].project << "," << arrayOfStudents[i].final1 << "," << arrayOfStudents[i].final << "," << arrayOfStudents[i].mid1 << "," << arrayOfStudents[i].mid << "," << arrayOfStudents[i].gtotal << "," << arrayOfStudents[i].grade << endl;
	}

	file.close();
}

int main()
{
	fstream file("file.csv", ios::in);
	
	student s;

	stack st;

	string line, word;
	int count = 0;

	while (getline(file, line))
	{
		stringstream ss(line);

		while (getline(ss, word, ','))
		{
			if (count == 0)
			{
				s.serialNo = word;
			}
			 if (count == 1)
			{
				s.regDate = word;
			}
			 if (count == 2)
			{
				s.rollNo = word;
			}
			 if (count == 3)
			{
				s.name = word;
			}
			 if (count == 4)
			{
				s.as1 = word;
			}
			 if (count == 5)
			{
				s.as2 = word;
			}
			 if (count == 6)
			{
				s.as3 = word;
			}
			 if (count == 7)
			{
				s.as4 = word;
			}
			 if (count == 8)
			{
				s.as = word;
			}
			 if (count == 9)
			{
				s.si1 = word;
			}
			 if (count == 10)
			{
				s.si = word;
			}
			 if (count == 11)
			{
				s.project1 = word;
			}
			 if (count == 12)
			{
				s.project = word;
			}
			 if (count == 13)
			{
				s.final1 = word;
			}
			 if (count == 14)
			{
				s.final = word;
			}
			 if (count == 15)
			{
				s.mid1 = word;
			}
			 if (count == 16)
			{
				s.mid = word;
			}
			 if (count == 17)
			{
				s.gtotal = word;
			}
			 if (count == 18)
			{
				s.grade = word;
			}
			count++;
		}
		st.push(s);
		count = 0;
	}

	Sleep(2000);
	st.print();

	student arrayOfStudents[30];

	for (int i = 0; i < 30; i++)
	{
		arrayOfStudents[i] = st.peek();
		st.pop();
	}

	sortingByRollNo(arrayOfStudents);

	

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
