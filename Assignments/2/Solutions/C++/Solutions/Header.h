// Muhammad_Waqas_22i2469_Assignment2
#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>

using namespace std;

class Skill
{
private:
	string skillId;
	double proficiency;

public:
	Skill();

	string getSkillId();
	void setSkillId(string skillId);
	double getProficiency();
	void setProficiency(double proficiency);
};

class Resource
{
public:

	string resourceId;

	bool available;

	string skill;

	double proficiency;

	Resource* resourceNext;

};

class ResourceList
{
private:

	Resource* resourceHead;

public:

	ResourceList();
	~ResourceList();

	Resource* getResourceHead();

	void addResource(string resourceId, bool available, string skill, double proficiency);
	/*void deleteResource(string resourceId);*/

	void setAvailable(string resourceId);
	void setUnavailable(string resourceId);

	bool isAvailable(string resourceId);

	void printResourceList();

};

class Task;

class DependencyTasks
{
public:

	Task* dependencyTask;

	DependencyTasks* dependencyNext;

	DependencyTasks();
	~DependencyTasks();
};

class Task
{
public:

	int taskId;

	double duration;

	double earlyStart;
	double earlyFinish;
	double lateStart;
	double lateFinish;

	double slack;

	string requiredSkill;

	bool criticalTask;

	DependencyTasks* dependents;

	Task* taskNext;
	Task* taskPrev;

	Resource* resourceAssigned;

	int newTaskId;

	bool done;

	Task();
};

class Project
{
private:

	Task* head;
	Task* tail;

	int size;

	string skill1;
	double proficiency1;
	string skill2;
	double proficiency2;
	string skill3;
	double proficiency3;

	ResourceList* resourceList;

	int taskcounter;
	double projectCompletionTime;

public:

	Project();
	~Project();

	void setSkill1(string skill1);
	void setProficiency1(double proficiency1);
	void setSkill2(string skill2);
	void setProficiency2(double proficiency2);
	void setSkill3(string skill3);
	void setProficiency3(double proficiency3);

	string getSkill1();
	double getProficiency1();
	string getSkill2();
	double getProficiency2();
	string getSkill3();
	double getProficiency3();

	int getSize();
	int getTaskCounter();

	ResourceList* getResourceList();

	void addResource();

	void addTask();

	void printAllTasks();

	void setAllTasksDuration();

	void set_nth_TaskDuration(int taskId, double duration);

	void printDependencyList();

	void frontTrack();
	void backTrack();
	void calculateBasicSchedule();

	void printCriticalTasks();

	void completionTimeWithResources();

	void completionTimeWithProficiency();
};
