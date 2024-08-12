#pragma once
#include <iostream>

using namespace std;

class Photo
{

	string serialNumber;
	string name;
	string location;
	string type;
	string size;
	string cameraName;
	string date;
	string category1;
	string category2;
	string category3;
	string category4;
	string category5;

public:

	Photo();

	void setSerialNumber(string n);
	void setName(string n);
	void setLocation(string n);
	void setType(string n);
	void setSize(string n);
	void setCameraName(string n);
	void setDate(string n);
	void setCategory1(string n);
	void setCategory2(string n);
	void setCategory3(string n);
	void setCategory4(string n);
	void setCategory5(string n);

	string getSerialNumber();
	string getName();
	string getLocation();
	string getType();
	string getSize();
	string getCameraName();
	string getDate();
	string getCategory1();
	string getCategory2();
	string getCategory3();
	string getCategory4();
	string getCategory5();

	void print();
};


class Node
{
public:
	Photo data;
	Node* next;

	Node(Photo d);
};

class LinkedList
{
	string categoryName;
	Node* head;
	Node* tail;
	int size;
public:

	LinkedList(string d = " ");

	void setCategoryName(string n);
	string getCategoryName();

	void addPhoto();
	void deletePhoto();

};

class Category
{
public:
	LinkedList categoryList;
	Category* next;
	Category* prev;


};


class LinkedlistOfLL
{
	Category* head;
	Category* tail;
	int size;

public:

	LinkedlistOfLL();

	void addCategory(Category* obj);
	void deleteCategory(Category* obj);

	void changeCategory();

	void displayGallery();

};

class stack
{
	Node* head;
	Node* top;
	int size;

public:

	stack();

	void push(Photo data);
	void pop();
	Photo peek();

	bool isEmpty();

	void print();

};

