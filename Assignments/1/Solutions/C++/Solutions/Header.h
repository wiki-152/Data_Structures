// Muhammad_Waqas_Shahid_Khan_22i2469
#pragma once

#include <iostream>

using namespace std;

template <typename T, typename D, typename I>
class Employee
{
private:
	T employeeName;
	T employeeID;
	T salary;
	T dateOfJoining;
	T designation;

public:
	Employee(T employeeName = "-", T employeeID = "-", T salary = "-", T dateOfJoining = "-", T designation = "-");

	void setEmployeeName(T employeeName);

	void setEmployeeID(T employeeID);

	void setSalary(T salary);

	void setDateOfJoining(T dateOfJoining);

	void setDesignation(T designation);

	T getEmployeeName();

	T getEmployeeID();

	T getSalary();

	T getDateOfJoining();

	T getDesignation();

	D getSalarayConverted();

	I tenureDays();

	void print();
};

