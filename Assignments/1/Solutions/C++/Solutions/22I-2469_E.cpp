// Muhammad_Waqas_Shahid_Khan_22i2469
// Assignment # 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <ctime>
#include<chrono>
#include "C:\Users\wiki8\Desktop\22I-2469_E\Header.h"

using namespace std;

template <typename T, typename D, typename I>
Employee<T, D, I>::Employee(T employeeName, T employeeID, T salary, T dateOfJoining, T designation)
{
	this->employeeName = employeeName;
	this->employeeID = employeeID;
	this->salary = salary;
	this->dateOfJoining = dateOfJoining;
	this->designation = designation;
}

template <typename T, typename D, typename I>
void Employee<T, D, I>::setEmployeeName(T employeeName)
{
	this->employeeName = employeeName;
}

template <typename T, typename D, typename I>
void Employee<T, D, I>::setEmployeeID(T employeeID)
{
	this->employeeID = employeeID;
}

template <typename T, typename D, typename I>
void Employee<T, D, I>::setSalary(T salary)
{
	this->salary = salary;
}

template <typename T, typename D, typename I>
void Employee<T, D, I>::setDateOfJoining(T dateOfJoining)
{
	this->dateOfJoining = dateOfJoining;
}

template <typename T, typename D, typename I>
void Employee<T, D, I>::setDesignation(T designation)
{
	this->designation = designation;
}

template <typename T, typename D, typename I>
T Employee<T, D, I>::getEmployeeName()
{
	return employeeName;
}

template <typename T, typename D, typename I>
T Employee<T, D, I>::getEmployeeID()
{
	return employeeID;
}

template <typename T, typename D, typename I>
T Employee<T, D, I>::getSalary()
{
	return salary;
}

template <typename T, typename D, typename I>
T Employee<T, D, I>::getDateOfJoining()
{
	return dateOfJoining;
}

template <typename T, typename D, typename I>
T Employee<T, D, I>::getDesignation()
{
	return designation;
}

template <typename T, typename D, typename I>
D Employee<T, D, I>::getSalarayConverted()
{
	T salaryNum = salary.substr(1, salary.length() - 1);

	T salaryNum2 = " ";

	for (int i = 0; i < salaryNum.length(); i++)
	{
		if (salaryNum[i] == ',')
		{
			continue;
		}
		else
		{
			salaryNum2 += salaryNum[i];
		}
	}

	D salaryConverted = stof(salaryNum2);
	// cout << salaryConverted << endl;
	return salaryConverted;
}

template <typename T, typename D, typename I>
I Employee<T, D, I>::tenureDays()
{
	I currentDay = 15;
	I currentMonth = 9;
	I currentYear = 2023;

	T sjoiningDay;
	T sjoiningMonth;
	T sjoiningYear;


	int counter = 0;
	for (int i = 0; i < dateOfJoining.length(); i++)
	{
		if (dateOfJoining[i] == '-')
		{
			continue;
		}
		else
		{
			if (counter < 4)
			{
				sjoiningYear += dateOfJoining[i];
			}
			else if (counter >= 4 && counter < 6)
			{
				sjoiningMonth += dateOfJoining[i];
			}
			else if (counter >= 6 && counter < 9)
			{
				sjoiningDay += dateOfJoining[i];
			}
		}
		counter += 1;
	}

	I joiningDay = stoi(sjoiningDay);
	I joiningMonth = stoi(sjoiningMonth);
	I joiningYear = stoi(sjoiningYear);

	I tenureDays = 0;

	if (joiningDay != 1)
	{
		if (joiningYear % 4 != 0)
		{
			if (joiningMonth == 1 || joiningMonth == 3 || joiningMonth == 5 || joiningMonth == 7 || joiningMonth == 8 || joiningMonth == 10 || joiningMonth == 12)
			{
				tenureDays += (31 - joiningDay);
			}
			else if (joiningMonth == 4 || joiningMonth == 6 || joiningMonth == 9 || joiningMonth == 11)
			{
				tenureDays += (30 - joiningDay);
			}
			else if (joiningMonth == 2)
			{
				tenureDays += (28 - joiningDay);
			}
		}
		else
		{
			if (joiningMonth == 1 || joiningMonth == 3 || joiningMonth == 5 || joiningMonth == 7 || joiningMonth == 8 || joiningMonth == 10 || joiningMonth == 12)
			{
				tenureDays += (31 - joiningDay);
			}
			if (joiningMonth == 4 || joiningMonth == 6 || joiningMonth == 9 || joiningMonth == 11)
			{
				tenureDays += (30 - joiningDay);
			}
			if (joiningMonth == 2)
			{
				tenureDays += (29 - joiningDay);
			}
		}
	}

	if (joiningMonth != 12)
	{
		for (int i = joiningMonth + 1; i <= 12; i++)
		{

			if (joiningYear % 4 != 0)
			{
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				{
					tenureDays += 31;
				}
				else if (i == 4 || i == 6 || i == 9 || i == 11)
				{
					tenureDays += 30;
				}
				else if (i == 2)
				{
					tenureDays += 28;
				}
			}
			else
			{
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				{
					tenureDays += 31;
				}
				if (i == 4 || i == 6 || i == 9 || i == 11)
				{
					tenureDays += 30;
				}
				if (i == 2)
				{
					tenureDays += 29;
				}
			}
		}
	}

	if (joiningYear != currentYear)
	{
		for (int i = joiningYear + 1; i < currentYear; i++)
		{
			if (i % 4 != 0)
			{
				tenureDays += 365;
			}
			else
			{
				tenureDays += 366;
			}
		}
	}

	if (currentMonth != 1)
	{
		for (int i = 1; i < currentMonth; i++)
		{
			if (currentYear % 4 != 0)
			{
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				{
					tenureDays += 31;
				}
				else if (i == 4 || i == 6 || i == 9 || i == 11)
				{
					tenureDays += 30;
				}
				else if (i == 2)
				{
					tenureDays += 28;
				}
			}
			else
			{
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				{
					tenureDays += 31;
				}
				if (i == 4 || i == 6 || i == 9 || i == 11)
				{
					tenureDays += 30;
				}
				if (i == 2)
				{
					tenureDays += 29;
				}
			}
		}
	}

	tenureDays += currentDay;

	return tenureDays;
}

template <typename T, typename D, typename I>
void Employee<T, D, I>::print()
{
	cout << "Employee Name: " << employeeName << endl;
	cout << "Employee ID: " << employeeID << endl;
	cout << "Salary: " << salary << endl;
	cout << "Date of Joining: " << dateOfJoining << endl;
	cout << "Designation: " << designation << endl;
}



int main()
{
	// ------------------------------------Scenario 1: Initial Employee Performance Metrics------------------------------------

	///*Employee<string> obj("John", "123", "1000", "01/01/2020", "Manager");
	//obj.print();*/
	///*
	//int input;
	//cout << "Enter 1 to enter data manually or 2 to read data from file: ";
	//cin >> input;
	//Employee<string> *obj = new Employee<string>[input];*/

	//int detailsCounter = 0;
	//int employeeCounter = 0;
	//string line;
	//bool lineEmpty = false;
	//string data;

	//ifstream file;
	//file.open("Employeedata.txt");

	//if (!file.is_open())
	//{
	//	cout << "File not found" << endl;
	//}
	//else
	//{
	//	while (getline(file, line))
	//	{
	//		/*cout << line.length() << " LINE : " << line << endl;*/

	//		/*for (int i = 0; i < line.length(); i++)
	//		{
	//			if ((line[i] >= 48 && line[i] <= 57) || (line[i] >= 65 && line[i] <= 90) || (line[i] >= 97 && line[i] <= 122))
	//			{
	//				lineEmpty = false;
	//			}
	//			else
	//			{
	//				lineEmpty = true;
	//			}
	//		}*/

	//		if (line.length() == 0)
	//		{
	//			lineEmpty = true;
	//		}
	//		else
	//		{
	//			lineEmpty = false;
	//		}

	//		/*cout << "Line Empty : " << lineEmpty << endl;*/
	//		if (lineEmpty == false)
	//		{
	//			for (int i = 0; i < line.length(); i++)
	//			{
	//				if (line[i] == ':')
	//				{
	//					for (int j = i + 2; j < line.length(); j++)
	//					{
	//						data += line[j];
	//					}

	//					/*cout << "Data : " << data << endl;*/

	//					/*for (int k = 0; k < data.length(); k++)
	//					{
	//						cout<< "." <<data[k] << endl;
	//					}*/
	//					break;
	//				}
	//			}
	//			detailsCounter += 1;
	//			data = "\0";

	//			if (detailsCounter % 5 == 0)
	//			{
	//				/*cout << detailsCounter << endl;*/
	//				employeeCounter += 1;
	//				/*cout << "Employee " << employeeCounter << endl << endl;*/
	//			}
	//		}
	//	}
	//}
	//file.close();
	//Employee<string , double , int>* obj = new Employee<string,double, int>[employeeCounter];

	//employeeCounter = 0;
	//detailsCounter = 0;

	//file.open("Employeedata.txt");

	//if (!file.is_open())
	//{
	//	cout << "File not found" << endl;
	//}
	//else
	//{
	//	while (getline(file, line))
	//	{
	//		/*cout << line << endl;*/
	//		if (line.length() == 0)
	//		{
	//			lineEmpty = true;
	//		}
	//		else
	//		{
	//			lineEmpty = false;
	//		}

	//		/*cout << "Line Empty : " << lineEmpty << endl;*/
	//		if (lineEmpty == false)
	//		{

	//			for (int i = 0; i < line.length(); i++)
	//			{
	//				if (line[i] == ':')
	//				{
	//					for (int j = i + 2; j < line.length(); j++)
	//					{
	//						data += line[j];
	//					}

	//					/*cout << data << endl;*/

	//					if (detailsCounter == 0)
	//					{
	//						obj[employeeCounter].setEmployeeName(data);
	//					}
	//					else if (detailsCounter == 1)
	//					{
	//						obj[employeeCounter].setEmployeeID(data);
	//					}
	//					else if (detailsCounter == 2)
	//					{
	//						obj[employeeCounter].setSalary(data);
	//					}
	//					else if (detailsCounter == 3)
	//					{
	//						obj[employeeCounter].setDateOfJoining(data);
	//					}
	//					else if (detailsCounter == 4)
	//					{
	//						obj[employeeCounter].setDesignation(data);
	//					}


	//					/*cout << "Data : " << data << endl;*/

	//					/*for (int k = 0; k < data.length(); k++)
	//					{
	//						cout<< "." <<data[k] << endl;
	//					}*/
	//					break;
	//				}
	//			}
	//			detailsCounter += 1;
	//			data = "\0";

	//			if (detailsCounter % 5 == 0)
	//			{
	//				detailsCounter -= 5;
	//				employeeCounter += 1;
	//				/*cout << "Employee " << employeeCounter << endl << endl;*/
	//			}
	//		}
	//	}


	//}

	///*system("CLS");
	//Sleep (2000);
	// for (int i = 0; i < employeeCounter; i++)
	// {
	// 	cout << obj[i].tenureDays() << endl;
	//	cout << obj[i].getSalarayConverted() << endl;
	//	obj[i].print();

	// 	cout << "----------" << endl;
	// }*/


	//cout << "----------------------------- Scenario 1 : Initial Employee Performance Metrics -----------------------------" << endl << endl;

	//float n = 0;
	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	n += obj[i].getSalarayConverted();
	//}

	//n = n / employeeCounter;
	//cout << "1) Average Salary in the company : $" << n << endl << endl ;

	//cout << "2) Total Number of Employees : " << employeeCounter << endl << endl;

	//cout << "3) Average tenure (in years) of employees in the company : ";
	//
	//double avgTenure = 0;
	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	avgTenure += obj[i].tenureDays();
	//}

	//avgTenure = avgTenure / employeeCounter;
	//cout << avgTenure / 365 << endl << endl;

	//cout << "4) Distribution of employees based on their designations " << endl;

	//string* designationArray = new string[employeeCounter];

	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	designationArray[i] = obj[i].getDesignation();

	//}

	//string* designationArray2 = new string [employeeCounter];
	//
	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	designationArray2[i] = "-";
	//}

	//bool repeat = false;
	//int array2Counter = 0;
	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	for (int j = 0; j < employeeCounter; j++)
	//	{
	//		if (designationArray[i] == designationArray2[j])
	//		{
	//			repeat = true;
	//		}
	//	}

	//	if (repeat == false)
	//	{
	//		int counter = 0;
	//		for (int k = 0; k < employeeCounter; k++)
	//		{
	//			if (designationArray[i] == designationArray[k])
	//			{
	//				counter += 1;
	//			}
	//		}
	//		cout << designationArray[i] << " : " << counter << endl;
	//		designationArray2[array2Counter] = designationArray[i];
	//		array2Counter += 1;
	//	}

	//	repeat = false;
	//}

	//delete [] designationArray;
	//delete [] designationArray2;

	//cout << endl ;

	//cout << "5) Employee with longest tenure : ";
	//int greatestTenure = 0;

	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	if (obj[greatestTenure].tenureDays() < obj[i].tenureDays())
	//	{
	//		greatestTenure = i;
	//	}
	//}

	//cout << obj[greatestTenure].getEmployeeName() << " ( " << obj[greatestTenure].tenureDays() / 365.0 << " Year (s) OR " << obj[greatestTenure].tenureDays() << " Days )" << endl;

	//obj[greatestTenure].print();

	//delete[] obj;

	//file.close();

	// ---------------------------------------------------- Scenario 2: Salaray Comparison ---------------------------------------------------
	
	//int detailsCounter = 0;
	//int employeeCounter = 0;
	//string line;
	//bool lineEmpty = false;
	//string data;

	//ifstream file;
	//file.open("Employeedata.txt");

	//if (!file.is_open())
	//{
	//	cout << "File not found" << endl;
	//}
	//else
	//{
	//	while (getline(file, line))
	//	{
	//		/*cout << line.length() << " LINE : " << line << endl;*/

	//		/*for (int i = 0; i < line.length(); i++)
	//		{
	//			if ((line[i] >= 48 && line[i] <= 57) || (line[i] >= 65 && line[i] <= 90) || (line[i] >= 97 && line[i] <= 122))
	//			{
	//				lineEmpty = false;
	//			}
	//			else
	//			{
	//				lineEmpty = true;
	//			}
	//		}*/

	//		if (line.length() == 0)
	//		{
	//			lineEmpty = true;
	//		}
	//		else
	//		{
	//			lineEmpty = false;
	//		}

	//		/*cout << "Line Empty : " << lineEmpty << endl;*/
	//		if (lineEmpty == false)
	//		{
	//			for (int i = 0; i < line.length(); i++)
	//			{
	//				if (line[i] == ':')
	//				{
	//					for (int j = i + 2; j < line.length(); j++)
	//					{
	//						data += line[j];
	//					}

	//					/*cout << "Data : " << data << endl;*/

	//					/*for (int k = 0; k < data.length(); k++)
	//					{
	//						cout<< "." <<data[k] << endl;
	//					}*/
	//					break;
	//				}
	//			}
	//			detailsCounter += 1;
	//			data = "\0";

	//			if (detailsCounter % 5 == 0)
	//			{
	//				/*cout << detailsCounter << endl;*/
	//				employeeCounter += 1;
	//				/*cout << "Employee " << employeeCounter << endl << endl;*/
	//			}
	//		}
	//	}
	//}
	//file.close();
	//Employee<string, double , int>* obj = new Employee<string, double , int>[employeeCounter];

	//employeeCounter = 0;
	//detailsCounter = 0;

	//file.open("Employeedata.txt");

	//if (!file.is_open())
	//{
	//	cout << "File not found" << endl;
	//}
	//else
	//{
	//	while (getline(file, line))
	//	{
	//		/*cout << line << endl;*/
	//		if (line.length() == 0)
	//		{
	//			lineEmpty = true;
	//		}
	//		else
	//		{
	//			lineEmpty = false;
	//		}

	//		/*cout << "Line Empty : " << lineEmpty << endl;*/
	//		if (lineEmpty == false)
	//		{

	//			for (int i = 0; i < line.length(); i++)
	//			{
	//				if (line[i] == ':')
	//				{
	//					for (int j = i + 2; j < line.length(); j++)
	//					{
	//						data += line[j];
	//					}

	//					/*cout << data << endl;*/

	//					if (detailsCounter == 0)
	//					{
	//						obj[employeeCounter].setEmployeeName(data);
	//					}
	//					else if (detailsCounter == 1)
	//					{
	//						obj[employeeCounter].setEmployeeID(data);
	//					}
	//					else if (detailsCounter == 2)
	//					{
	//						obj[employeeCounter].setSalary(data);
	//					}
	//					else if (detailsCounter == 3)
	//					{
	//						obj[employeeCounter].setDateOfJoining(data);
	//					}
	//					else if (detailsCounter == 4)
	//					{
	//						obj[employeeCounter].setDesignation(data);
	//					}


	//					/*cout << "Data : " << data << endl;*/

	//					/*for (int k = 0; k < data.length(); k++)
	//					{
	//						cout<< "." <<data[k] << endl;
	//					}*/
	//					break;
	//				}
	//			}
	//			detailsCounter += 1;
	//			data = "\0";

	//			if (detailsCounter % 5 == 0)
	//			{
	//				detailsCounter -= 5;
	//				employeeCounter += 1;
	//				/*cout << "Employee " << employeeCounter << endl << endl;*/
	//			}
	//		}
	//	}


	//}

	///*system("CLS");
	//Sleep (2000);
	// for (int i = 0; i < employeeCounter; i++)
	// {
	// 	obj[i].print();

	// 	cout << "----------" << endl;
	// }*/

	//cout << "----------------------------- Scenario 2 : Salaray Comparisons -----------------------------" << endl << endl;

	//float highestSalary = -1;
	//int highestSalaryIndex = 0;
	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	if (obj[i].getSalarayConverted() > highestSalary)
	//	{
	//		highestSalary = obj[i].getSalarayConverted();
	//		highestSalaryIndex = i;
	//	}
	//}

	//cout << "1) The highest salary among all employees : " << obj[highestSalaryIndex].getSalary() << endl;

	//float lowestSalary = highestSalary;
	//int lowestSalaryIndex = 0;
	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	if (obj[i].getSalarayConverted() < lowestSalary )
	//	{
	//		lowestSalary = obj[i].getSalarayConverted();
	//		lowestSalaryIndex = i;
	//	}
	//}

	//cout << "2) The lowest salary among all employees : " << obj[lowestSalaryIndex].getSalary() << endl;

	//cout << "3) Salary Range : $" << lowestSalary << " - $" << highestSalary << endl;

	//double *allSalaries = new double [employeeCounter];

	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	allSalaries[i] = 0.0;
	//}

	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	allSalaries[i] = obj[i].getSalarayConverted();
	//}

	//bool flag = false;
	//float temp = 0 ;
	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	for (int j = 0; j < employeeCounter - 1; j++)
	//	{
	//		if (allSalaries[j] > allSalaries[j + 1])
	//		{
	//			temp = allSalaries[j];
	//			allSalaries[j] = allSalaries[j + 1];
	//			allSalaries[j + 1] = temp;
	//			flag = true;
	//		}
	//	}
	//}
	//
	///*Sleep(2000);
	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	cout << allSalaries[i] << endl;
	//}*/

	//if (employeeCounter % 2 == 0)
	//{
	//	double medianSalary = (allSalaries[employeeCounter / 2] + allSalaries[(employeeCounter / 2) - 1]) / 2;
	//	cout << "4) The median salary : $" << medianSalary << endl;
	//}
	//else
	//{
	//	double medianSalary = allSalaries[employeeCounter / 2];
	//	cout << "4) The median salary: $" << medianSalary << endl;
	//}

	//delete [] allSalaries;

	//cout << endl <<  "5) The average salary for each designation category : " << endl ;
	//string* designationArray = new string[employeeCounter];

	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	designationArray[i] = obj[i].getDesignation();

	//}

	//string* designationArray2 = new string[employeeCounter];
	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	designationArray2[i] = "-";
	//}

	//bool repeat = false;
	//int array2Counter = 0;
	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	for (int j = 0; j < employeeCounter; j++)
	//	{
	//		if (designationArray[i] == designationArray2[j])
	//		{
	//			repeat = true;
	//		}
	//	}

	//	if (repeat == false)
	//	{
	//		float counter = 0;
	//		float totalSalary = 0;
	//		for (int k = 0; k < employeeCounter; k++)
	//		{
	//			if (designationArray[i] == designationArray[k])
	//			{
	//				counter += 1;
	//				totalSalary += obj[k].getSalarayConverted();
	//			}
	//		}
	//		cout << designationArray[i] << " : $" << totalSalary / counter << endl;
	//		designationArray2[array2Counter] = designationArray[i];
	//		array2Counter += 1;
	//	}

	//	repeat = false;
	//}

	//cout << endl << "6) Employee with Highest Salary : " << endl << endl ; 
	//obj[highestSalaryIndex].print();
	//cout << endl;
	
	// --------------------------------------------------- Scenario 3: Employee Tenure Analysis ---------------------------------------------------
	
	//int detailsCounter = 0;
	//int employeeCounter = 0;
	//string line;
	//bool lineEmpty = false;
	//string data;

	//ifstream file;
	//file.open("Employeedata.txt");

	//if (!file.is_open())
	//{
	//	cout << "File not found" << endl;
	//}
	//else
	//{
	//	while (getline(file, line))
	//	{
	//		/*cout << line.length() << " LINE : " << line << endl;*/

	//		/*for (int i = 0; i < line.length(); i++)
	//		{
	//			if ((line[i] >= 48 && line[i] <= 57) || (line[i] >= 65 && line[i] <= 90) || (line[i] >= 97 && line[i] <= 122))
	//			{
	//				lineEmpty = false;
	//			}
	//			else
	//			{
	//				lineEmpty = true;
	//			}
	//		}*/

	//		if (line.length() == 0)
	//		{
	//			lineEmpty = true;
	//		}
	//		else
	//		{
	//			lineEmpty = false;
	//		}

	//		/*cout << "Line Empty : " << lineEmpty << endl;*/
	//		if (lineEmpty == false)
	//		{
	//			for (int i = 0; i < line.length(); i++)
	//			{
	//				if (line[i] == ':')
	//				{
	//					for (int j = i + 2; j < line.length(); j++)
	//					{
	//						data += line[j];
	//					}

	//					/*cout << "Data : " << data << endl;*/

	//					/*for (int k = 0; k < data.length(); k++)
	//					{
	//						cout<< "." <<data[k] << endl;
	//					}*/
	//					break;
	//				}
	//			}
	//			detailsCounter += 1;
	//			data = "\0";

	//			if (detailsCounter % 5 == 0)
	//			{
	//				/*cout << detailsCounter << endl;*/
	//				employeeCounter += 1;
	//				/*cout << "Employee " << employeeCounter << endl << endl;*/
	//			}
	//		}
	//	}
	//}
	//file.close();
	//Employee<string, double , int>* obj = new Employee<string, double , int>[employeeCounter];

	//employeeCounter = 0;
	//detailsCounter = 0;

	//file.open("Employeedata.txt");

	//if (!file.is_open())
	//{
	//	cout << "File not found" << endl;
	//}
	//else
	//{
	//	while (getline(file, line))
	//	{
	//		/*cout << line << endl;*/
	//		if (line.length() == 0)
	//		{
	//			lineEmpty = true;
	//		}
	//		else
	//		{
	//			lineEmpty = false;
	//		}

	//		/*cout << "Line Empty : " << lineEmpty << endl;*/
	//		if (lineEmpty == false)
	//		{

	//			for (int i = 0; i < line.length(); i++)
	//			{
	//				if (line[i] == ':')
	//				{
	//					for (int j = i + 2; j < line.length(); j++)
	//					{
	//						data += line[j];
	//					}

	//					/*cout << data << endl;*/

	//					if (detailsCounter == 0)
	//					{
	//						obj[employeeCounter].setEmployeeName(data);
	//					}
	//					else if (detailsCounter == 1)
	//					{
	//						obj[employeeCounter].setEmployeeID(data);
	//					}
	//					else if (detailsCounter == 2)
	//					{
	//						obj[employeeCounter].setSalary(data);
	//					}
	//					else if (detailsCounter == 3)
	//					{
	//						obj[employeeCounter].setDateOfJoining(data);
	//					}
	//					else if (detailsCounter == 4)
	//					{
	//						obj[employeeCounter].setDesignation(data);
	//					}


	//					/*cout << "Data : " << data << endl;*/

	//					/*for (int k = 0; k < data.length(); k++)
	//					{
	//						cout<< "." <<data[k] << endl;
	//					}*/
	//					break;
	//				}
	//			}
	//			detailsCounter += 1;
	//			data = "\0";

	//			if (detailsCounter % 5 == 0)
	//			{
	//				detailsCounter -= 5;
	//				employeeCounter += 1;
	//				/*cout << "Employee " << employeeCounter << endl << endl;*/
	//			}
	//		}
	//	}
	//}

	///*system("cls");
	//Sleep (2000);
	// for (int i = 0; i < employeeCounter; i++)
	// {
	// 	obj[i].print();

	// 	cout << "----------" << endl;
	// }*/

	//cout << "----------------------------- Scenario 3 : Employee Tenure Analysis -----------------------------" << endl << endl;

	//cout << "1) The employee with the longest tenure (most years of service) : ";
	//int greatestTenure = 0;
	//int greatestTenureIndex = 0;

	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	if (obj[i].tenureDays() > greatestTenure )
	//	{
	//		greatestTenure = obj[i].tenureDays();
	//		greatestTenureIndex = i;
	//	}
	//}

	//cout << obj[greatestTenureIndex].getEmployeeName() << " with " << obj[greatestTenureIndex].tenureDays()/365.0 << " Years ( ~ "<< obj[greatestTenureIndex].tenureDays() / 365 << " Year (s) ) OR " << obj[greatestTenureIndex].tenureDays() << " Days" << endl;

	//cout  << endl << "2) The employee with the shortest tenure (fewest years of service) : " ;
	//int shortestTenure = greatestTenure;
	//int shortestTenureIndex = 0;

	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	if (obj[i].tenureDays() < shortestTenure)
	//	{
	//		shortestTenure = obj[i].tenureDays();
	//		shortestTenureIndex = i;
	//	}
	//}

	//cout << obj[shortestTenureIndex].getEmployeeName() << " with " << obj[shortestTenureIndex].tenureDays()/365.0 << " Years ( ~ " << obj[shortestTenureIndex].tenureDays() / 365 << " Year (s) ) OR " << obj[shortestTenureIndex].tenureDays() << " Days" << endl;

	//cout << endl << "3) The average tenure for each designation category : " << endl ;
	//
	//string* designationArray = new string[employeeCounter];

	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	designationArray[i] = obj[i].getDesignation();

	//}

	//string* designationArray2 = new string[employeeCounter];

	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	designationArray2[i] = "-";
	//}

	//bool repeat = false;
	//int array2Counter = 0;

	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	for (int j = 0; j < employeeCounter; j++)
	//	{
	//		if (designationArray[i] == designationArray2[j])
	//		{
	//			repeat = true;
	//		}
	//	}

	//	if (repeat == false)
	//	{
	//		double counter = 0;
	//		double totalTenure = 0;
	//		for (int k = 0; k < employeeCounter; k++)
	//		{
	//			if (designationArray[i] == designationArray[k])
	//			{
	//				counter += 1;
	//				totalTenure += obj[k].tenureDays();
	//			}
	//		}
	//		cout << designationArray[i] << " : " << (totalTenure / counter) / 365.0 << " Years" << " OR " << totalTenure / counter << " Days" << endl;
	//		designationArray2[array2Counter] = designationArray[i];
	//		array2Counter += 1;
	//	}
	//	repeat = false;
	//}

	//delete[] designationArray;
	//delete[] designationArray2;

	//cout << endl << "4) The highest paying designation : ";

	//int index = 0;

	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	if (obj[i].getSalarayConverted() > obj[index].getSalarayConverted())
	//	{
	//		index = i;
	//	}
	//}

	//cout << obj[index].getDesignation() << " with " << obj[index].getSalary() << endl;

	//file.close();

	// --------------------------------------------------- Scenario 4: Employee Ranking By Salary ---------------------------------------------------

	//int detailsCounter = 0;
	//int employeeCounter = 0;
	//string line;
	//bool lineEmpty = false;
	//string data;

	//ifstream file;
	//file.open("Employeedata.txt");

	//if (!file.is_open())
	//{
	//	cout << "File not found" << endl;
	//}
	//else
	//{
	//	while (getline(file, line))
	//	{
	//		/*cout << line.length() << " LINE : " << line << endl;*/

	//		/*for (int i = 0; i < line.length(); i++)
	//		{
	//			if ((line[i] >= 48 && line[i] <= 57) || (line[i] >= 65 && line[i] <= 90) || (line[i] >= 97 && line[i] <= 122))
	//			{
	//				lineEmpty = false;
	//			}
	//			else
	//			{
	//				lineEmpty = true;
	//			}
	//		}*/

	//		if (line.length() == 0)
	//		{
	//			lineEmpty = true;
	//		}
	//		else
	//		{
	//			lineEmpty = false;
	//		}

	//		/*cout << "Line Empty : " << lineEmpty << endl;*/
	//		if (lineEmpty == false)
	//		{
	//			for (int i = 0; i < line.length(); i++)
	//			{
	//				if (line[i] == ':')
	//				{
	//					for (int j = i + 2; j < line.length(); j++)
	//					{
	//						data += line[j];
	//					}

	//					/*cout << "Data : " << data << endl;*/

	//					/*for (int k = 0; k < data.length(); k++)
	//					{
	//						cout<< "." <<data[k] << endl;
	//					}*/
	//					break;
	//				}
	//			}
	//			detailsCounter += 1;
	//			data = "\0";

	//			if (detailsCounter % 5 == 0)
	//			{
	//				/*cout << detailsCounter << endl;*/
	//				employeeCounter += 1;
	//				/*cout << "Employee " << employeeCounter << endl << endl;*/
	//			}
	//		}
	//	}
	//}
	//file.close();
	//Employee<string , double , int>* obj = new Employee<string,double, int>[employeeCounter];

	//employeeCounter = 0;
	//detailsCounter = 0;

	//file.open("Employeedata.txt");

	//if (!file.is_open())
	//{
	//	cout << "File not found" << endl;
	//}
	//else
	//{
	//	while (getline(file, line))
	//	{
	//		/*cout << line << endl;*/
	//		if (line.length() == 0)
	//		{
	//			lineEmpty = true;
	//		}
	//		else
	//		{
	//			lineEmpty = false;
	//		}

	//		/*cout << "Line Empty : " << lineEmpty << endl;*/
	//		if (lineEmpty == false)
	//		{

	//			for (int i = 0; i < line.length(); i++)
	//			{
	//				if (line[i] == ':')
	//				{
	//					for (int j = i + 2; j < line.length(); j++)
	//					{
	//						data += line[j];
	//					}

	//					/*cout << data << endl;*/

	//					if (detailsCounter == 0)
	//					{
	//						obj[employeeCounter].setEmployeeName(data);
	//					}
	//					else if (detailsCounter == 1)
	//					{
	//						obj[employeeCounter].setEmployeeID(data);
	//					}
	//					else if (detailsCounter == 2)
	//					{
	//						obj[employeeCounter].setSalary(data);
	//					}
	//					else if (detailsCounter == 3)
	//					{
	//						obj[employeeCounter].setDateOfJoining(data);
	//					}
	//					else if (detailsCounter == 4)
	//					{
	//						obj[employeeCounter].setDesignation(data);
	//					}


	//					/*cout << "Data : " << data << endl;*/

	//					/*for (int k = 0; k < data.length(); k++)
	//					{
	//						cout<< "." <<data[k] << endl;
	//					}*/
	//					break;
	//				}
	//			}
	//			detailsCounter += 1;
	//			data = "\0";

	//			if (detailsCounter % 5 == 0)
	//			{
	//				detailsCounter -= 5;
	//				employeeCounter += 1;
	//				/*cout << "Employee " << employeeCounter << endl << endl;*/
	//			}
	//		}
	//	}


	//}

	///*system("CLS");
	//Sleep (2000);
	// for (int i = 0; i < employeeCounter; i++)
	// {
	// 	obj[i].print();

	// 	cout << "----------" << endl;
	// }*/


	//cout << "----------------------------- Scenario 4 : Employee Ranking By Salary -----------------------------" << endl << endl;

	//cout << " Sorting The Object Array According To Salary " << endl ;

	//// Bubble Sort Algorithm

	//int swapCounter = 0;
	//int comparisonCounter = 0;
	//Employee<string , double , int> temp;

	//int counter = 1;
	//bool flag = false;

	//

	//auto start = chrono::high_resolution_clock::now();

	//do
	//{
	//	flag = false;
	//	for (int i = 0; i < employeeCounter - counter; i++)
	//	{
	//		if (obj[i].getSalarayConverted() > obj[i + 1].getSalarayConverted())
	//		{
	//			temp = obj[i];
	//			obj[i] = obj[i + 1];
	//			obj[i + 1] = temp;
	//			swapCounter += 1;
	//			flag = true;
	//		}
	//		comparisonCounter += 1;
	//	}
	//	counter += 1;
	//} while (flag == true);

	//auto end = chrono::high_resolution_clock::now();

	//auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

	//double execution_time = duration.count();

	//cout << " " << execution_time/1000000 << " Seconds" << endl << endl;

	//cout << "Number of Swaps : " << swapCounter << endl;
	//cout << "Number of Comparisons : " << comparisonCounter << endl << endl;

	//// Selection Sort Algorithm

	///*int swapCounter = 0;
	//int comparisonCounter = 0;
	//Employee<string, double, int> temp;

	//int counter = 0;
	//int maxIndex = 0;

	//auto start = std::chrono::high_resolution_clock::now();

	//for (int rightmost = employeeCounter - 1; rightmost > 0; rightmost--)
	//{
	//	maxIndex = 0;
	//	for (int i = 1; i <= rightmost; i++)
	//	{
	//		if (obj[i].getSalarayConverted() > obj[maxIndex].getSalarayConverted())
	//		{
	//			maxIndex = i;
	//		}
	//		comparisonCounter += 1;
	//	}
	//	if (obj[maxIndex].getSalarayConverted() > obj[rightmost].getSalarayConverted())
	// {
	//	temp = obj[rightmost];
	//	obj[rightmost] = obj[maxIndex];
	//	obj[maxIndex] = temp;
	//	swapCounter += 1;
	// }
	//}

	//auto end = std::chrono::high_resolution_clock::now();

	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	//
	//double execution_time = duration.count();

	//cout << " Time : " << execution_time/1000000 << " Seconds" << endl << endl;

	//cout << "Number of Swaps : " << swapCounter << endl;
	//cout << "Number of Comparisons : " << comparisonCounter << endl << endl;*/

	//// Insertion Sort Algorithm

	///*int swapCounter = 0;
	//int comparisonCounter = 0;
	//Employee<string, double, int> temp;

	//int counter = 0;
	//int i, j;

	//auto start = std::chrono::high_resolution_clock::now();

	//for (i = 1; i < employeeCounter; i++)
	//{
	//	temp = obj[i];

	//	for (j = i; j > 0 && obj[j - 1].getSalarayConverted() > temp.getSalarayConverted(); j--)
	//	{
	//		obj[j] = obj[j - 1];
	//		comparisonCounter += 1;
	//		swapCounter += 1;
	//	}
	//	obj[j] = temp;
	//}

	//auto end = std::chrono::high_resolution_clock::now();

	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	//double execution_time = duration.count();

	//cout << " Time : " << execution_time / 1000000 << " Seconds" << endl << endl;*/

	//cout << "Employee Ranking According To Salary : " << endl << endl;
	//Sleep (2000);
	// for (int i = 0; i < employeeCounter; i++)
	// {
	//	cout << "Rank " << i + 1 << " : " << endl;
	//	obj[i].print();

	//	cout << "----------" << endl << endl ;
	// }
	//
	// --------------------------------------------------- Scenario 5: Employee Ranking By Tenure ---------------------------------------------------//

	//int detailsCounter = 0;
	//int employeeCounter = 0;
	//string line;
	//bool lineEmpty = false;
	//string data;

	//ifstream file;
	//file.open("Employeedata.txt");

	//if (!file.is_open())
	//{
	//	cout << "File not found" << endl;
	//}
	//else
	//{
	//	while (getline(file, line))
	//	{
	//		/*cout << line.length() << " LINE : " << line << endl;*/

	//		/*for (int i = 0; i < line.length(); i++)
	//		{
	//			if ((line[i] >= 48 && line[i] <= 57) || (line[i] >= 65 && line[i] <= 90) || (line[i] >= 97 && line[i] <= 122))
	//			{
	//				lineEmpty = false;
	//			}
	//			else
	//			{
	//				lineEmpty = true;
	//			}
	//		}*/

	//		if (line.length() == 0)
	//		{
	//			lineEmpty = true;
	//		}
	//		else
	//		{
	//			lineEmpty = false;
	//		}

	//		/*cout << "Line Empty : " << lineEmpty << endl;*/
	//		if (lineEmpty == false)
	//		{
	//			for (int i = 0; i < line.length(); i++)
	//			{
	//				if (line[i] == ':')
	//				{
	//					for (int j = i + 2; j < line.length(); j++)
	//					{
	//						data += line[j];
	//					}

	//					/*cout << "Data : " << data << endl;*/

	//					/*for (int k = 0; k < data.length(); k++)
	//					{
	//						cout<< "." <<data[k] << endl;
	//					}*/
	//					break;
	//				}
	//			}
	//			detailsCounter += 1;
	//			data = "\0";

	//			if (detailsCounter % 5 == 0)
	//			{
	//				/*cout << detailsCounter << endl;*/
	//				employeeCounter += 1;
	//				/*cout << "Employee " << employeeCounter << endl << endl;*/
	//			}
	//		}
	//	}
	//}
	//file.close();
	//Employee<string , double , int>* obj = new Employee<string,double, int>[employeeCounter];

	//employeeCounter = 0;
	//detailsCounter = 0;

	//file.open("Employeedata.txt");

	//if (!file.is_open())
	//{
	//	cout << "File not found" << endl;
	//}
	//else
	//{
	//	while (getline(file, line))
	//	{
	//		/*cout << line << endl;*/
	//		if (line.length() == 0)
	//		{
	//			lineEmpty = true;
	//		}
	//		else
	//		{
	//			lineEmpty = false;
	//		}

	//		/*cout << "Line Empty : " << lineEmpty << endl;*/
	//		if (lineEmpty == false)
	//		{

	//			for (int i = 0; i < line.length(); i++)
	//			{
	//				if (line[i] == ':')
	//				{
	//					for (int j = i + 2; j < line.length(); j++)
	//					{
	//						data += line[j];
	//					}

	//					/*cout << data << endl;*/

	//					if (detailsCounter == 0)
	//					{
	//						obj[employeeCounter].setEmployeeName(data);
	//					}
	//					else if (detailsCounter == 1)
	//					{
	//						obj[employeeCounter].setEmployeeID(data);
	//					}
	//					else if (detailsCounter == 2)
	//					{
	//						obj[employeeCounter].setSalary(data);
	//					}
	//					else if (detailsCounter == 3)
	//					{
	//						obj[employeeCounter].setDateOfJoining(data);
	//					}
	//					else if (detailsCounter == 4)
	//					{
	//						obj[employeeCounter].setDesignation(data);
	//					}


	//					/*cout << "Data : " << data << endl;*/

	//					/*for (int k = 0; k < data.length(); k++)
	//					{
	//						cout<< "." <<data[k] << endl;
	//					}*/
	//					break;
	//				}
	//			}
	//			detailsCounter += 1;
	//			data = "\0";

	//			if (detailsCounter % 5 == 0)
	//			{
	//				detailsCounter -= 5;
	//				employeeCounter += 1;
	//				/*cout << "Employee " << employeeCounter << endl << endl;*/
	//			}
	//		}
	//	}


	//}

	///*system("CLS");
	//Sleep (2000);
	// for (int i = 0; i < employeeCounter; i++)
	// {
	// 	obj[i].print();

	// 	cout << "----------" << endl;
	// }*/

	//cout << "----------------------------- Scenario 5 : Employee Ranking By Tenure -----------------------------" << endl << endl;

	//int swapCounter = 0;
	//int comparisonCounter = 0;

	//// Bubble Sort Algorithm

	///*int counter = 0;
	//bool flag = false;
	//Employee<string,double,int> temp;

	//auto start = chrono::high_resolution_clock::now();

	//do {
	//	flag = false;
	//	for (int i = 0; i < employeeCounter - 1 - counter; i++)
	//	{
	//		comparisonCounter += 1;
	//		if (obj[i].tenureDays() > obj[i + 1].tenureDays())
	//		{
	//			temp = obj[i];
	//			obj[i] = obj[i + 1];
	//			obj[i + 1] = temp;
	//			swapCounter += 1;
	//			flag = true;
	//		}
	//	}
	//	counter += 1;
	//} while (flag == true);

	//auto end = chrono::high_resolution_clock::now();

	//auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

	//double execution_time = duration.count();

	//cout << " Time : " << execution_time / 1000000 << " Seconds" << endl << endl;
	//
	//cout << "Number of Swaps : " << swapCounter << endl;
	//cout << "Number of Comparisons : " << comparisonCounter << endl << endl;*/

	//// Descending Order

	//// Bubble Sort Algorithm

	//int counter = 0;
	//bool flag = false;
	//Employee<string, double, int> temp;

	//auto start = chrono::high_resolution_clock::now();

	//do {
	//	flag = false;
	//	for (int i = 0; i < employeeCounter - 1 - counter; i++)
	//	{
	//		comparisonCounter += 1;
	//		if (obj[i].tenureDays() < obj[i + 1].tenureDays())
	//		{
	//			temp = obj[i];
	//			obj[i] = obj[i + 1];
	//			obj[i + 1] = temp;
	//			swapCounter += 1;
	//			flag = true;
	//		}
	//	}
	//	counter += 1;
	//} while (flag == true);

	//auto end = chrono::high_resolution_clock::now();

	//auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

	//double execution_time = duration.count();

	//cout << " Time : " << execution_time / 1000000 << " Seconds" << endl << endl;

	//cout << "Number of Swaps : " << swapCounter << endl;

	//cout << "Number of Comparisons : " << comparisonCounter << endl << endl;


	//// Selection Sort Algorithm

	///*int maxIndex = 0;
	//Employee<string,double,int> temp;

	//auto start = chrono::high_resolution_clock::now();

	//for (int rightMost = employeeCounter - 1; rightMost > 0; rightMost--)
	//{
	//	maxIndex = 0;
	//	for (int i = 1; i <= rightMost; i++)
	//	{
	//		comparisonCounter += 1;
	//		if (obj[i].tenureDays() > obj[maxIndex].tenureDays())
	//		{
	//			maxIndex = i;
	//		}
	//	}
	//	if (obj[maxIndex].tenureDays() > obj[rightMost].tenureDays())
	//	{
	//		temp = obj[rightMost];
	//		obj[rightMost] = obj[maxIndex];
	//		obj[maxIndex] = temp;
	//		swapCounter += 1;
	//	}
	//}

	//auto end = chrono::high_resolution_clock::now();

	//auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

	//double execution_time = duration.count();

	//cout << " Time : " << execution_time / 1000000 << " Seconds" << endl << endl;*/
	//
	//// Insertion Sort Algorithm

	///*int i, j;
	//Employee<string,double,int> temp;

	//auto start = std::chrono::high_resolution_clock::now();

	//for (i = 1; i < employeeCounter; i++)
	//{
	//	temp = obj[i];

	//	for (j = i; j > 0 && temp.tenureDays() < obj[j-1].tenureDays() ; j--)
	//	{
	//		comparisonCounter += 1;
	//		obj[j] = obj[j - 1];
	//		swapCounter += 1;
	//	}

	//	obj[j] = temp;
	//}

	//auto end = std::chrono::high_resolution_clock::now();

	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	//double execution_time = duration.count();

	//cout << " Time : " << execution_time / 1000000 << " Seconds" << endl << endl;

	//cout << "Number of Swaps : " << swapCounter << endl;
	//cout << "Number of Comparisons : " << comparisonCounter << endl << endl;*/

	//cout << "Employee Ranking According To Tenure : " << endl << endl;
	//Sleep (2000);
	//for (int i = 0; i < employeeCounter; i++)
	//{
	//	cout << "Rank " << i + 1 << " : " << endl;
	//	obj[i].print();
	//	cout << "----------" << endl;
	// }

	return 0;
}
