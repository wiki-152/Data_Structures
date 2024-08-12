// Muhammad_Waqas_22i2469_Assignment2
// Final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>
#include "C:\Users\wiki8\Desktop\Final\Header.h"

using namespace std;

// Class Skill

Skill::Skill()
{
	skillId = "";
	proficiency = 0;
}

string Skill::getSkillId()
{
	return skillId;
}

void Skill::setSkillId(string skillId)
{
	this->skillId = skillId;
}

double Skill::getProficiency()
{
	return proficiency;
}

void Skill::setProficiency(double proficiency)
{
	this->proficiency = proficiency;
}

// Class Resource 

ResourceList::ResourceList()
{
	resourceHead = NULL;

}

ResourceList::~ResourceList()
{
	Resource* temp = resourceHead;

	while (temp != NULL)
	{
		Resource* temp2 = temp->resourceNext;
		delete temp;
		temp = temp2;
	}
}

Resource* ResourceList::getResourceHead()
{
	return resourceHead;
}

void ResourceList::addResource(string resourceId, bool available, string skill, double proficiency)
{

	Resource* temp = new Resource();
	temp->resourceId = resourceId;
	temp->available = available;
	temp->skill = skill;
	temp->proficiency = proficiency;


	if (resourceHead == NULL)
	{
		resourceHead = temp;
	}
	else
	{
		Resource* temp2 = resourceHead;

		while (temp2->resourceNext != NULL)
		{
			temp2 = temp2->resourceNext;
		}

		temp2->resourceNext = temp;
	}
}

void ResourceList::setAvailable(string resourceId)
{
	Resource* temp = resourceHead;

	while (temp->resourceId != resourceId)
	{
		temp = temp->resourceNext;
	}

	temp->available = true;
}

void ResourceList::setUnavailable(string resourceId)
{
	Resource* temp = resourceHead;

	while (temp->resourceId != resourceId)
	{
		temp = temp->resourceNext;
	}

	temp->available = false;
}

bool ResourceList::isAvailable(string resourceId)
{
	Resource* temp = resourceHead;

	while (temp->resourceId != resourceId)
	{
		temp = temp->resourceNext;
	}

	return temp->available;
}

void ResourceList::printResourceList()
{
	Resource* temp = resourceHead;

	while (temp != NULL)
	{
		cout << "Resource Id: " << temp->resourceId << endl;
		cout << "Resource Availability: " << temp->available << endl;
		cout << "Resource Skill: " << temp->skill << endl;

		temp = temp->resourceNext;
	}
}

// Class Dependency Tasks

DependencyTasks::DependencyTasks()
{
	dependencyTask = NULL;
	dependencyNext = NULL;
}

DependencyTasks::~DependencyTasks()
{
	DependencyTasks* temp = dependencyNext;

	while (temp != NULL)
	{
		DependencyTasks* temp2 = temp->dependencyNext;
		delete temp;
		temp = temp2;
	}
}

// Class Task

Task::Task()
{
	taskId = -1;
	duration = 0;
	earlyStart = 0;
	earlyFinish = 0;
	lateStart = 0;
	lateFinish = 0;
	slack = 0;
	requiredSkill = "-";
	criticalTask = false;

	dependents = NULL;

	taskNext = NULL;
	taskPrev = NULL;

	resourceAssigned = NULL;

	newTaskId = -1;

	done = false;
}

// Class Project

Project::Project()
{
	/*head = new Task();
	head->taskId = -1;
	head->duration = 0;
	head->earlyStart = 0;
	head->earlyFinish = 0;
	head->lateStart = 0;
	head->lateFinish = 0;
	head->slack = 0;
	head->requiredSkill = "-";
	head->criticalTask = false;


	tail = new Task();
	tail->taskId = -2;
	tail->duration = 0;
	tail->earlyStart = 0;
	tail->earlyFinish = 0;
	tail->lateStart = 0;
	tail->lateFinish = 0;
	tail->slack = 0;
	tail->requiredSkill = "-";
	tail->criticalTask = false;

	head->taskNext = tail;
	tail->taskPrev = head;*/

	head = NULL;
	tail = NULL;


	size = 0;

	skill1 = "Developer";
	proficiency1 = -1;
	skill2 = "Tester";
	proficiency2 = -1;
	skill3 = "Requirements Engineer";
	proficiency3 = -1;

	resourceList = new ResourceList();

	taskcounter = 0;

	projectCompletionTime = 0;

}

Project::~Project()
{
	Task* temp = head;

	while (temp != NULL)
	{
		Task* temp2 = temp->taskNext;
		delete temp;
		temp = temp2;
	}

	delete resourceList;
}

void Project::setSkill1(string skill1)
{
	this->skill1 = skill1;
}

void Project::setProficiency1(double proficiency1)
{
	this->proficiency1 = proficiency1;
}

void Project::setSkill2(string skill2)
{
	this->skill2 = skill2;
}

void Project::setProficiency2(double proficiency2)
{
	this->proficiency2 = proficiency2;
}

void Project::setSkill3(string skill3)
{
	this->skill3 = skill3;
}

void Project::setProficiency3(double proficiency3)
{
	this->proficiency3 = proficiency3;
}

string Project::getSkill1()
{
	return skill1;
}

double Project::getProficiency1()
{
	return proficiency1;
}

string Project::getSkill2()
{
	return skill2;
}

double Project::getProficiency2()
{
	return proficiency2;
}

string Project::getSkill3()
{
	return skill3;
}

double Project::getProficiency3()
{
	return proficiency3;
}

int Project::getSize()
{
	return size;
}

int Project::getTaskCounter()
{
	return taskcounter;
}

ResourceList* Project::getResourceList()
{
	return resourceList;
}

void Project::addResource()
{
	string resourceId;
	bool available;
	string skill;

	cout << "Enter Resource Id: ";
	cin >> resourceId;

	cout << "Enter Resource Availability (1 for available and 0 for unavailable): ";
	cin >> available;

	int input = -1;

	cout << "1. Developer" << endl;
	cout << "2. Tester" << endl;
	cout << "3. Requirements Engineer" << endl;

	while (input < 1 || input > 3)
	{
		cout << "Enter Resource Skill: ";
		cin >> input;
	}

	if (input == 1)
	{
		skill = skill1;
	}
	if (input == 2)
	{
		skill = skill2;
	}
	if (input == 3)
	{
		skill = skill3;
	}

	cout << "Enter Resource Proficiency: ";
	double proficiency;
	cin >> proficiency;

	resourceList->addResource(resourceId, available, skill , proficiency);

	cout << "Resource Added Successfully" << endl;

	resourceList->printResourceList();

	Sleep(2000);
}

void Project::addTask()
{
	double input_duration;
	int input_skill;
	string sendSkill;

	cout << "How Many Tasks You Want To Add? :";
	int totalinput;
	cin >> totalinput;

	for (int i = 0; i < totalinput; i++)
	{
		taskcounter++;

		cout << "Enter Details For Task " << taskcounter << endl;
		cout << "Enter Task Duration: ";
		cin >> input_duration;

		cout << "1. Developer" << endl;
		cout << "2. Tester" << endl;
		cout << "3. Requirements Engineer" << endl;
		cout << "Enter Task Skill: ";
		cin >> input_skill;

		while (input_skill < 1 || input_skill > 3)
		{
			cout << "Invalid Input" << endl;
			cout << "Enter Task Skill: ";
			cin >> input_skill;
		}

		if (input_skill == 1)
		{
			sendSkill = skill1;
		}

		if (input_skill == 2)
		{
			sendSkill = skill2;
		}

		if (input_skill == 3)
		{
			sendSkill = skill3;
		}

		Task* temp = new Task();
		temp->taskId = taskcounter;
		temp->duration = input_duration;
		temp->requiredSkill = sendSkill;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->taskNext = temp;
			temp->taskPrev = tail;
			tail = temp;
		}

		size++;

		char input = '-';
		int dependencyId = -1;

		DependencyTasks* dependencyList = NULL; 

		while (input != 'N' && input != 'n')
		{
			cout << "Do You Want To Add Dependency For This Task # " << size << " ? (Y/N): ";
			cin >> input;

			while (input != 'Y' && input != 'y' && input != 'N' && input != 'n')
			{
				cout << "Invalid Input" << endl;
				cout << "Do You Want To Add Dependency For This Task # " << size << " ? (Y / N) : ";
				cin >> input;
			}

			if (input == 'Y' || input == 'y')
			{
				printAllTasks();
				cout << "Enter Dependency Task Id: ";
				cin >> dependencyId;

				while (dependencyId < 1 || dependencyId > taskcounter || dependencyId == size)
				{
					cout << "Invalid Input" << endl;
					cout << "Enter Dependency Task Id: ";
					cin >> dependencyId;
				}

				Task* dependentTask = head;

				while (dependentTask->taskId != dependencyId)
				{
					dependentTask = dependentTask->taskNext;
				}

				DependencyTasks* newDependencyNode = new DependencyTasks();
				newDependencyNode->dependencyTask = dependentTask;
				newDependencyNode->dependencyNext = NULL;
				
				if (dependencyList == NULL)
				{
					dependencyList = newDependencyNode;
					temp->dependents = dependencyList; 
				}
				else
				{
					DependencyTasks* temp2 = dependencyList;

					while (temp2->dependencyNext != NULL)
					{
						temp2 = temp2->dependencyNext;
					}

					temp2->dependencyNext = newDependencyNode;
				}
			}
			else
			{
				break;
			}
		}
	}
}


void Project::printAllTasks()
{
	Task* temp = head;

	while (temp != NULL)
	{
		cout << endl;
		cout << "Task Id: " << temp->taskId << endl;
		cout << "Task Duration: " << temp->duration << endl;
		cout << "Task Required Skill: " << temp->requiredSkill << endl;
		cout << "Early Start: " << temp->earlyStart << endl;
		cout << "Early Finish: " << temp->earlyFinish << endl;
		cout << "Late Start: " << temp->lateStart << endl;
		cout << "Late Finish: " << temp->lateFinish << endl;
		cout << "Slack: " << temp->slack << endl;
		cout << "Critical Task: " << temp->criticalTask << endl;

		DependencyTasks* temp2 = temp->dependents;

		while (temp2 != NULL)
		{
			cout << "Dependency Task Id: " << temp2->dependencyTask->taskId << endl;
			cout << "Dependency Task Duration: " << temp2->dependencyTask->duration << endl;
			cout << "Dependency Task Required Skill: " << temp2->dependencyTask->requiredSkill << endl;

			temp2 = temp2->dependencyNext;
		}

		temp = temp->taskNext;
	}
}

void Project::setAllTasksDuration()
{
	Task* temp = head;

	while (temp != NULL)
	{
		cout << "Enter Duration For Task " << temp->taskId << ": ";
		cin >> temp->duration;

		temp = temp->taskNext;
	}

	/*printAllTasks();

	Sleep (5000);*/
}

void Project::set_nth_TaskDuration(int taskId, double duration)
{
	Task* temp = head;

	while (temp->taskId != taskId)
	{
		temp = temp->taskNext;
	}

	temp->duration = duration;
}

void Project::printDependencyList()
{
	Task* temp = head;

	while (temp != NULL)
	{
		cout << "Task Id: " << temp->taskId << endl;/*
		cout << "Task Duration: " << temp->duration << endl;
		cout << "Task Required Skill: " << temp->requiredSkill << endl;*/

		DependencyTasks* temp2 = temp->dependents;

		while (temp2 != NULL)
		{
			cout << "Dependency Task Id: " << temp2->dependencyTask->taskId << endl;
			//cout << "Dependency Task Duration: " << temp2->dependencyTask->duration << endl;
			///*cout << "Dependency Task Required Skill: " << temp2->dependencyTask->requiredSkill << endl;*/

			temp2 = temp2->dependencyNext;
		}

		temp = temp->taskNext;

		cout << endl << endl << endl;
	}
}

void Project::frontTrack()
{
	Task* temp = head;

	while (temp != NULL)
	{
		if (temp->dependents == NULL)
		{
			/*temp->earlyStart = 0;*/
			double tempDuration = temp->duration;
			temp->earlyFinish = tempDuration;
		}

		if (temp->dependents != NULL)
		{
			DependencyTasks* temp2 = temp->dependents;

			while (temp2 != NULL)
			{
				if (temp2->dependencyTask->earlyFinish > temp->earlyStart)
				{
					temp->earlyStart = temp2->dependencyTask->earlyFinish;
				}

				temp2 = temp2->dependencyNext;
			}

			temp->earlyFinish = temp->earlyStart + temp->duration;
		}
		temp = temp->taskNext;
	}

	
}

void Project::backTrack()
{
	double n = 0;
	Task* temp = tail;
	temp->lateFinish = temp->earlyFinish;
	temp->lateStart = temp->lateFinish - temp->duration;

	double tailLF = temp->lateFinish;
	double tailLS = temp->lateStart;

	int dependenyTaskCounter = 0;


	temp = tail;
	while (temp != NULL)
	{
		DependencyTasks* temp2 = temp->dependents;

		/*cout << "Task Id: " << temp->taskId << endl;
		*/while (temp2 != NULL)
		{
			/*cout << "Dependency Task Id: " << temp2->dependencyTask->taskId << endl;
			cout << "Early Start: " << temp2->dependencyTask->earlyStart << endl;
			cout << "Early Finish: " << temp2->dependencyTask->earlyFinish << endl;
			cout << "Late Start: " << temp2->dependencyTask->lateStart << endl;
			cout << "Late Finish: " << temp2->dependencyTask->lateFinish << endl;

			cout << "Updateddddd" << endl;
			*/
			if (temp->lateFinish == 0)
			{
				temp->lateFinish = tailLF;
				n = temp->lateFinish - temp->duration;
				temp->lateStart = n;
			}

			if (temp2->dependencyTask->lateFinish == 0)
			{
				temp2->dependencyTask->lateFinish = temp->lateStart;
				n = temp2->dependencyTask->lateFinish - temp2->dependencyTask->duration;
				temp2->dependencyTask->lateStart = n;
			}

			
			/*cout << "Dependency Task Id: " << temp2->dependencyTask->taskId << endl;
			cout << "Early Start: " << temp2->dependencyTask->earlyStart << endl;
			cout << "Early Finish: " << temp2->dependencyTask->earlyFinish << endl;
			cout << "Late Start: " << temp2->dependencyTask->lateStart << endl;
			cout << "Late Finish: " << temp2->dependencyTask->lateFinish << endl;
			cout << "End" << endl;*/

			temp2 = temp2->dependencyNext;
		}

		temp->lateStart = temp->lateFinish - temp->duration;

		/*cout << "Task Id: " << temp->taskId << endl;
		cout << "Early Start: " << temp->earlyStart << endl;
		cout << "Early Finish: " << temp->earlyFinish << endl;
		cout << "Late Start: " << temp->lateStart << endl;
		cout << "Late Finish: " << temp->lateFinish << endl;*/


		temp = temp->taskPrev;
	}

	/*Sleep (10000);*/
}


void Project::calculateBasicSchedule()
{
	// First We Go From Start to End and Calculate Early Start and Early Finish

	frontTrack();

	// Then We Go From End to Start and Calculate Late Start and Late Finish

	backTrack();

	// Then We Calculate Slack and Critical Task

	 Task *temp = head;

	while (temp != NULL)
	{
		temp->slack = temp->lateStart - temp->earlyStart;

		if (temp->slack == 0)
		{
			temp->criticalTask = true;
		}

		temp = temp->taskNext;
	}

	// Print Schedule

	temp = head;

	system ("CLS");

	cout << "-----------------------Project Basic Schedule-----------------------" << endl;

	while (temp != NULL)
	{
		
		cout << "Id : " << temp->taskId << "  Duration : " << temp->duration << "  Early Start : " << temp->earlyStart << "  Early Finish : " << temp->earlyFinish << "  Late Start : " << temp->lateStart << "  Late Finish : " << temp->lateFinish << "  Slack : " << temp->slack << "  Critical Task : " << temp->criticalTask << endl;

		temp = temp->taskNext;
	}

	cout << endl << endl;

	cout << "The Project Completion Time is " << tail->earlyFinish << endl << endl;

	projectCompletionTime = tail->earlyFinish;

	Sleep (2000);

}

void Project::printCriticalTasks()
{
	Task* temp = head;

	double totalDurationOfCriticalTasks = 0;

	while (temp != NULL)
	{
		if (temp->criticalTask == true)
		{
			cout << "Task Id: " << temp->taskId << endl;
			cout << "Task Duration: " << temp->duration << endl;
			cout << "Task Required Skill: " << temp->requiredSkill << endl;
			cout << "Early Start: " << temp->earlyStart << endl;
			cout << "Early Finish: " << temp->earlyFinish << endl;
			cout << "Late Start: " << temp->lateStart << endl;
			cout << "Late Finish: " << temp->lateFinish << endl;
			cout << "Slack: " << temp->slack << endl;
			cout << "Critical Task: " << temp->criticalTask << endl;

			DependencyTasks* temp2 = temp->dependents;

			while (temp2 != NULL)
			{
				cout << "Dependency Task Id: " << temp2->dependencyTask->taskId << endl;
				cout << "Dependency Task Duration: " << temp2->dependencyTask->duration << endl;
				/*cout << "Dependency Task Required Skill: " << temp2->dependencyTask->requiredSkill << endl;*/

				temp2 = temp2->dependencyNext;
			}

			totalDurationOfCriticalTasks += temp->duration;

			cout << endl << endl << endl;
		}


		temp = temp->taskNext;
	}

	cout << "Total Duration of Critical Tasks is " << totalDurationOfCriticalTasks << endl << endl;

}

void Project::completionTimeWithResources()
{
	// Make Copy of Head and Tail For Later

	Task* tempHead = new Task();
	tempHead = head;
	Task* tempTail = new Task();
	tempTail = tail;

	calculateBasicSchedule();

	int total = size;
	int counter = 0;
	int iterationCounter = 1;

	Task* temp = head;
	Task* lowest = temp;

	int totalTime = 0;
	while (counter != total)
	{
		iterationCounter = 1;
		temp = head;
		lowest = temp;
		while (lowest->done == true)
		{
			temp = temp->taskNext;
			lowest = temp;
		}
		temp = head;
		temp = temp->taskNext;
		while (iterationCounter != total)
		{	
			if (temp->done == false)
			{
				/*cout << "Task #" << lowest->taskId << endl;
				cout << "compared to " << temp->taskId << endl;*/

				if (lowest->lateStart > temp->lateStart)
				{
					lowest = temp;
				}

				if (lowest->lateStart == temp->lateStart)
				{
					if (lowest->slack > temp->slack)
					{
						lowest = temp;
					}
				}

				if (lowest->lateStart == temp->lateStart && lowest->slack == temp->slack)
				{
					if (lowest->duration == temp->duration)
					{
						lowest = temp;
					}
				}
			}

			temp = temp->taskNext;
			iterationCounter++;
		}

		lowest->earlyStart = totalTime;
		lowest->earlyFinish = totalTime + lowest->duration;
		totalTime = lowest->earlyFinish;
		lowest->done = true;

		counter++;
	}

	// Print Schedule

	temp = head;
	cout << "-----------------------Project Schedule With Resources-----------------------" << endl;

	while (temp != NULL)
	{

		cout << "Id : " << temp->taskId << "  Duration : " << temp->duration << "  Early Start : " << temp->earlyStart << "  Early Finish : " << temp->earlyFinish << "  Slack : " << temp->slack << " Resource Assigned : " << temp->requiredSkill << endl;

		temp = temp->taskNext;
	}

	cout << "The Project Completion Time With Resources is " << totalTime << endl << endl;

	Sleep(2000);

	// Restore Head and Tail

	head = tempHead;
	tail = tempTail;
}

void Project::completionTimeWithProficiency()
{
	// Make Copy of Head and Tail For Later

	Task* tempHead = head;
	Task* tempTail = tail;

	calculateBasicSchedule();


	int total = size;
	int counter = 0;
	int iterationCounter = 1;
	double proficencyFactor = 0;

	Task* temp = head;
	Task* lowest = temp;

	double totalTime = 0;
	while (counter != total)
	{
		iterationCounter = 1;
		temp = head;
		lowest = temp;
		proficencyFactor = 0;
		while (lowest->done == true)
		{
			temp = temp->taskNext;
			lowest = temp;
		}
		temp = head;
		temp = temp->taskNext;
		while (iterationCounter != total)
		{
			if (temp->done == false)
			{
				/*cout << "Task #" << lowest->taskId << endl;
				cout << "compared to " << temp->taskId << endl;*/

				if (lowest->lateStart > temp->lateStart)
				{
					lowest = temp;
				}

				if (lowest->lateStart == temp->lateStart)
				{
					if (lowest->slack > temp->slack)
					{
						lowest = temp;
					}
				}

				if (lowest->lateStart == temp->lateStart && lowest->slack == temp->slack)
				{
					if (lowest->duration == temp->duration)
					{
						lowest = temp;
					}
				}
			}

			temp = temp->taskNext;
			iterationCounter++;
		}

		if (lowest->requiredSkill == skill1)
		{
			proficencyFactor = 1 / proficiency1;
		}

		if (lowest->requiredSkill == skill2)
		{
			proficencyFactor = 1 / proficiency2;
		}

		if (lowest->requiredSkill == skill3)
		{
			proficencyFactor = 1 / proficiency3;
		}

		
		lowest->earlyStart = totalTime;
		totalTime = totalTime + (lowest->duration * proficencyFactor);
		totalTime = ceil (totalTime);
		lowest->earlyFinish = totalTime;
		totalTime = lowest->earlyFinish;
		lowest->done = true;

		counter++;
	}

	// Print Schedule

	temp = head;
	cout << "-----------------------Project Schedule With Resources and Their Proficiency-----------------------" << endl;

	while (temp != NULL)
	{

		cout << "Id : " << temp->taskId << "  Duration : " << temp->duration << "  Early Start : " << temp->earlyStart << "  Early Finish : " << temp->earlyFinish << "  Slack : " << temp->slack << " Resource Assigned : " << temp->requiredSkill << endl;

		temp = temp->taskNext;
	}

	cout << "The Project Completion Time With Resources and Proficiency is " << totalTime << endl << endl;

	Sleep(2000);

	// Restore Head and Tail

	head = tempHead;
	tail = tempTail;
}


int main()
{

	Resource* resourceHead = NULL;

	Project* project = new Project();

	string skill;
	double proficiency;

	int input = -1;

	while (input != 10)
	{
		cout << "-----------------------Project Schedule Management System-----------------------" << endl;
		cout << "1. Add Resource" << endl;
		cout << "2. Add Tasks" << endl;
		cout << "3. Set All Tasks Durations " << endl;
		cout << "4. Set nth Task Duration" << endl;
		cout << "5. Print Dependency List" << endl;
		cout << "6. Display Basic Schedule" << endl;
		cout << "7. Display Critical Tasks" << endl;
		cout << "8. Display Completion Time With Resources" << endl;
		cout << "9. Display Completion Time With Proficiency" << endl;
		cout << "10. Exit" << endl;

		cin >> input;

		while (input < 1 || input > 10)
		{
			cout << "Invalid Input" << endl;
			cin >> input;
		}

		switch (input)
		{
		case 1:
		{
			project->addResource();
			system("CLS");
			break;
		}

		case 2:
		{
			project->addTask();

			/*project->printAllTasks();

			Sleep (1000);*/

			system("CLS");
			break;
		}

		case 3:
		{
			if (project->getSize() == 0)
			{
				cout << "Please Add Tasks First" << endl;
				Sleep (1000);
				system("CLS");
				break;
			}

			project->setAllTasksDuration();

			system ("CLS");
			break;
		}

		case 4:
		{
			if (project->getSize() == 0)
			{
				cout << "Please Add Tasks First" << endl;
				Sleep (1000);
				system("CLS");
				break;
			}

			int taskId;
			double duration;

			project->printAllTasks();

			cout << endl << "Enter Task Id: ";
			cin >> taskId;

			while (taskId < 1 || taskId > project->getTaskCounter())
			{
				cout << "Invalid Input" << endl;
				cout << "Enter Task Id: ";
				cin >> taskId;
			}

			cout << "Enter Duration: ";
			cin >> duration;

			project->set_nth_TaskDuration(taskId, duration);

			project->printAllTasks();

			Sleep (10000);

			system("CLS");
			break;
		}

		case 5:
		{
			if (project->getSize() == 0)
			{
				cout << "Please Add Tasks First" << endl;
				Sleep (1000);
				system("CLS");
				break;
			}

			project->printDependencyList();
			
			Sleep (10000);

			system("CLS");

			break;
		}

		case 6:
		{
			if (project->getSize() == 0)
			{
				cout << "Please Add Tasks First" << endl;
				Sleep (1000);
				system("CLS");
				break;
			}

			project->calculateBasicSchedule();


			break;
		}

		case 7 :
		{
			if (project->getSize() == 0)
			{
				cout << "Please Add Tasks First" << endl;
				Sleep (1000);
				system("CLS");
				break;
			}
			project->printCriticalTasks();

			Sleep (10000);

			system("CLS");
			break;
		}

		case 8:
		{
			if (project->getResourceList()->getResourceHead() == NULL)
			{
				cout << "Please Add Resources First" << endl;
				Sleep (1000);
				system("CLS");
				break;
			}

			project->completionTimeWithResources();
			break;
		}

		case 9:
		{
			if (project->getResourceList()->getResourceHead() == NULL)
			{
				cout << "Please Add Resources First" << endl;
				Sleep (1000);
				system("CLS");
				break;
			}

			cout << "Enter Proficiency For " << project->getSkill1() << ": ";
			cin >> proficiency;

			while (proficiency < 0 || proficiency > 1)
			{
				cout << "Invalid Input" << endl;
				cout << "Enter Proficiency For " << project->getSkill1() << ": ";
				cin >> proficiency;
			}

			project->setProficiency1(proficiency);

			cout << "Enter Proficiency For " << project->getSkill2() << ": ";
			cin >> proficiency;
			
			while (proficiency < 0 || proficiency > 1)
			{
				cout << "Invalid Input" << endl;
				cout << "Enter Proficiency For " << project->getSkill1() << ": ";
				cin >> proficiency;
			}
			
			project->setProficiency2(proficiency);

			cout << "Enter Proficiency For " << project->getSkill3() << ": ";
			cin >> proficiency;
			
			while (proficiency < 0 || proficiency > 1)
			{
				cout << "Invalid Input" << endl;
				cout << "Enter Proficiency For " << project->getSkill1() << ": ";
				cin >> proficiency;
			}

			project->setProficiency3(proficiency);

			project->completionTimeWithProficiency();

			break;
		}
		// End Switch
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
