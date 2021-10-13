#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//this is so I don't have to type "std::" before everything
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::istream;
using std::ostream;

//copy and paste the following before each function prototype delete before submission
/* * * * * * * * * * * * * * *
Function Name:
Date Created:
Date Last Modfied:
Description of Function:
Input parameters:
Returns:
Preconditions:
Postconditions:
* * * * * * * * * * * * * * */
class DietPlan
{
private:
	int goalCalories;
	std::string planName;
	std::string Date;
	

public:
	/*Constructors*/
	//default constructor for the diet plan
	DietPlan();
	//constructor w/values
	DietPlan(int goal, string name, string date);
	//copy constructor
	DietPlan(const DietPlan& copy);
	//destructor
	~DietPlan();
	
	/*Setters*/
	//set goal calories
	void setGoalCalories(int newGoal);
	//set the name of the plan
	void setPlanName(string newName);
	//set the date
	void setDate(string newDate);

	/*Getters*/
	//get the goal calories
	int getGoalCalories();
	//get the plan name
	string getPlanName();
	//get the date
	string getDate();

	/*Operators*/
	

	/*Member functions*/
/* * * * * * * * * * * * * * *
Function Name: editGoalCalories
Date Created: 10.3
Date Last Modfied: 10.4
Description of Function: prompts the user for a new value for goal calories and changes the value
Input parameters: none
Returns: none
Preconditions:
Postconditions:
* * * * * * * * * * * * * * */
	void editGoalCalories();


};

/*
Overloaded stream extraction operator for reading in one whole daily plan to a DietPlan Object
Uses a reference to the fstream object(infile) for the left hand side, and a reference to a diet plan object for the right
returns the modified left hand side
*/
fstream& operator>>(fstream& lhs, DietPlan& rhs);

/*
Overloaded stream insertion operator for printing diet plan to the screen
Takes a reference to an ostream object for the left hand side and a reference to the diet plan object as the right
Returns the modified left hand side
*/
ostream& operator<<(ostream& lhs, DietPlan& rhs);

/*
Overloaded stream insertion operator for storing diet plan info to the file
Takes a reference to an fstream object for the left hand side and a reference to the diet plan object
Returns modified left hand side
*/
fstream& operator<<(fstream& lhs, DietPlan& rhs);