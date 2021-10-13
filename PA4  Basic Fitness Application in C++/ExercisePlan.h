#pragma once

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ostream;
using std::istream;


class ExercisePlan
{
private:
	int goalSteps;
	string planName;
	string Date;

public:
	//default constructor
	ExercisePlan();
	//contructor w/values
	ExercisePlan(int goal, string name, string date);
	//copy constructor
	ExercisePlan(const ExercisePlan& copy);
	//destructor
	~ExercisePlan();
	/*Setters*/
	void setGoalSteps(int newGoal);
	void setPlanName(string newPlan);
	void setDate(string newDate);

	/*Getters*/
	int getGoalSteps();
	string getPlanName();
	string getDate();

	void editGoalSteps();
};

/*
overloaded stream extraction operator for reading the entirety of a plan from the file
uses a reference to the fstream as the left hand side and a reference to an ExercisePlan object for the right hand side
returns the overloaded left hand side
*/
fstream& operator>>(fstream& lhs, ExercisePlan& rhs);

/*
Overloaded stream insertion operator for printing all of a plan to the console
Uses a reference to the ostream as the left hand side and a reference to an ExercisePlan object for the right hand side
returns the overloaded left hand side
*/
ostream& operator<<(ostream& lhs, ExercisePlan& rhs);

/*
Overloaded stream insertion operator for storing ExercisePlan object to the txt file
Uses a reference to an fstream object for the left hand side, and a reference to an ExercisePlan object for the right
returns the modified left hand side
*/
fstream& operator<<(fstream& lhs, ExercisePlan& rhs);
