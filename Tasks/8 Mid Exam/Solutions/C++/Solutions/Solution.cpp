// i222469_Waqas_Section-E_BS(SE).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Header.h"

using namespace std;

Photo::Photo()
{

}

void Photo::setSerialNumber(string n)
{
	serialNumber = n;
}

void Photo::setName(string n)
{
	name = n;
}

void Photo::setLocation(string n)
{
	location = n;
}

void Photo::setType(string n)
{
	type = n;
}

void Photo::setSize(string n)
{
	size = n;
}

void Photo::setCameraName(string n)
{
	cameraName = n;
}

void Photo::setDate(string n)
{
	date = n;
}

void Photo::setCategory1(string n)
{
	category1 = n;
}

void Photo::setCategory2(string n)
{
	category2 = n;
}

void Photo::setCategory3(string n)
{
	category3 = n;
}

void Photo::setCategory4(string n)
{
	category4 = n;
}

void Photo::setCategory5(string n)
{
	category5 = n;
}

string Photo::getSerialNumber()
{
	return serialNumber;
}

string Photo::getName()
{
	return name;
}

string Photo::getLocation()
{
	return location;
}

string Photo::getType()
{
	return type;
}

string Photo::getSize()
{
	return size;
}

string Photo::getCameraName()
{
	return cameraName;
}

string Photo::getDate()
{
	return date;
}

string Photo::getCategory1()
{
	return category1;
}

string Photo::getCategory2()
{
	return category2;
}

string Photo::getCategory3()
{
	return category3;
}

string Photo::getCategory4()
{
	return category4;
}

string Photo::getCategory5()
{
	return category5;
}

void Photo::print()
{
	cout << serialNumber << " " << name << " " << location << " "
		<< type << " "
		<< size << " "
		<< cameraName << " "
		<< date << " "
		<< category1 << " "
		<< category2 << " "
		<< category3 << " "
		<< category4 << " "
		<< category5;
}


Node::Node(Photo d)
{
	data = d;
	next = NULL;
}



LinkedList::LinkedList(string d)
{
	categoryName = d;
	head = NULL;
	tail = NULL;
	size = 0;
}

void LinkedList::setCategoryName(string n)
{
	categoryName = n;
}

string LinkedList::getCategoryName()
{
	return categoryName;
}



void LinkedlistOfLL::addCategory(Category* obj)
{
	if (head == NULL)
	{
		head == obj;
		tail == obj;
		size += 1;
	}
	else
	{
		tail->next = obj;
		obj->prev = tail;
		tail = obj;
	}
}

void LinkedlistOfLL::deleteCategory(Category* obj)
{
	if (head == NULL)
	{
		return;
	}
	else
	{
		Category* temp = head;
		while (temp != obj)
		{
			temp = temp->next;
		}


	}
}




stack::stack()
{
	head = NULL;
	top = NULL;
	size = 0;
}

void stack::push(Photo data)
{
	Node* temp = new Node(data);
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

Photo stack::peek()
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
		counter++;
	}
}

int main()
{
	int categoryCounter = 0;

	stack fileStack;

	fstream file("picture_data.csv", ios::in);

	/*if (file.is_open() == true)
	{
		cout << "here";
	}*/

	string line;
	string word;

	Photo p;

	int colCount = 0;
	/*Sleep(2000);*/
	while (getline(file, line))
	{
		
		stringstream ss(line);

		while (getline(ss, word, ','))
		{
			if (colCount == 0)
			{
				p.setSerialNumber(word);
			}
			if (colCount == 1)
			{
				p.setName(word);
			}
			if (colCount == 2)
			{
				p.setLocation(word);
			}
			if (colCount == 3)
			{
				p.setType(word);
			}
			if (colCount == 4)
			{
				p.setSize(word);
			}
			if (colCount == 5)
			{
				p.setCameraName(word);
			}
			if (colCount == 6)
			{
				p.setDate(word);
			}
			if (colCount == 7)
			{
				p.setCategory1(word);
			}
			if (colCount == 8)
			{
				p.setCategory2(word);
			}
			if (colCount == 9)
			{
				p.setCategory3(word);
			}
			if (colCount == 10)
			{
				p.setCategory4(word);
			}
			if (colCount == 11)
			{
				p.setCategory5(word);
			}
			
			colCount++;
		}
		fileStack.push(p);
		colCount = 0;
		p.print();
		cout << endl;
		
	}
	categoryCounter = 5;
	
	LinkedList* ll = new LinkedList[5];

	ll[0].setCategoryName("Category1");
	ll[1].setCategoryName("Category2");
	ll[2].setCategoryName("Category3");
	ll[3].setCategoryName("Category4");
	ll[4].setCategoryName("Category5");
	
	/*string s = "Category" + to_string(1);
	cout << s;*/

	stack deletedPhotos;
	stack deletedCategories;

	int choice = -1;
	while (true)
	{
		cout << "\n0. Display Gallery \n1. Add Photo \n2. Delete Photo \n3. Add Category \n4. Delete Category \n5. Change Category \n6. Undo Deleted Photo \n7. Undo Deleted Category \n8. Exit \n";
		cin >> choice;

		if (choice == 0)
		{

		}
		else if (choice == 1)
		{

		}
		else if (choice == 2)
		{

		}
		else if (choice == 3)
		{

		}
		else if (choice == 4)
		{

		}
		else if (choice == 5)
		{

		}

		else if (choice == 6)
		{

		}
		else if (choice == 7)
		{

		}

		else if (choice == 8)
		{
			break;
		}

	}
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


