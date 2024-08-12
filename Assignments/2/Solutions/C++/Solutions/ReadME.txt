1 Purpose of Code

The purpose of code is to manage a project efficiently and get the schedule based on Critical Path Method or based on the availability of resources or based on proficiency of resources. These results play a critical role in managing a project and maintaining factors like cost time and efficiency.

2 Design of Code 

The Code contains following classes:
1.	Skill
2.	Resource
3.	Resource List
4.	Dependency Tasks
5.	Task
6.	Project
The Class Skill contains members of id and proficiency. The Class Resource represents a node containing relevant members like availability, id, a pointer to the next resource. The class Resource List represents a simple linked list to store a list of resources in the class project. The class Task represents a node with its relevant members and the Class Project represents a Doubly linked list. The Class Dependency Tasks is a single linked list of the dependent tasks on each task in project.

3 Usage of Code

A user-friendly menu with all required input validations has been provided. The User can add tasks and resources to the project. Based on the input the user can later view the dependency list of each task. The user can then view the basic schedule of project according to the tasks provided which is calculated according to Critical Path Method (CPM) and view the critical tasks with project completion time. The Class Project being a doubly linked list allows us to forward track the tasks to calculate the Early start and finish and then by Back tracking we calculate the late start and finish. This later assists in calculating the times based on resources and later the basis of their proficiency. While calculating the schedule by resources we follow the given rules of first come first serve and find the appropriate tasks to be assigned the resource first. Similar method is followed in the function for calculating the schedule on proficiency with additional factor of proficiency included and affecting the duration of each task accordingly. 
