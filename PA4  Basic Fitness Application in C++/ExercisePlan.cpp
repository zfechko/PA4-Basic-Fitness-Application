#include "ExercisePlan.h"

/*Constructors*/
//default constructor
ExercisePlan::ExercisePlan()
{
	goalSteps = 0;
	planName = ""; //set to a blank string
	Date = "";
}

//constructors with parameters
ExercisePlan::ExercisePlan(int goal, string name, string date)
{
	goalSteps = goal;
	planName = name;
	Date = date;
}

ExercisePlan::ExercisePlan(const ExercisePlan& copy)
{
	goalSteps = copy.goalSteps;
	planName = copy.planName;
	Date = copy.Date;
}

//destructor
ExercisePlan::~ExercisePlan()
{
	//destroys when object leaves scope
}

/*Setters*/
void ExercisePlan::setGoalSteps(int newGoal)
{
	if (newGoal < 0)
	{
		goalSteps = 0;
	}
	else
	{
		goalSteps = newGoal;
	}
}

void ExercisePlan::setPlanName(string newPlan)
{
	planName = newPlan;
}

void ExercisePlan::setDate(string newDate)
{
	Date = newDate;
}

/*Getters*/
int ExercisePlan::getGoalSteps()
{
	return goalSteps;
}

string ExercisePlan::getPlanName()
{
	return planName;
}

string ExercisePlan::getDate()
{
	return Date;
}

/*
overloaded stream extraction operator for reading the entirety of a plan from the file
uses a reference to the fstream as the left hand side and a reference to an ExercisePlan object for the right hand side
returns the overloaded left hand side
*/
fstream& operator>>(fstream& lhs, ExercisePlan& rhs)
{
	string name, stepsStr, date, newLine;
	int steps = 0;
	getline(lhs, name); //reads the name
	getline(lhs, stepsStr); //reads the steps as a string
	steps = stoi(stepsStr);//and then converts it to an integer
	getline(lhs, date); //reads the date string and stores it
	getline(lhs, newLine); //this is for ignoring the blank line
	rhs.setGoalSteps(steps);
	rhs.setPlanName(name);
	rhs.setDate(date);

	return lhs;
}

/*
Overloaded stream insertion operator for printing all of a plan to the console
Uses a reference to the ostream as the left hand side and a reference to an ExercisePlan object for the right hand side
returns the overloaded left hand side
*/
ostream& operator<<(ostream& lhs, ExercisePlan& rhs)
{
	lhs << "We're doing " << rhs.getPlanName() << " on " << rhs.getDate() << " with a goal of " << rhs.getGoalSteps() << " steps " << endl;
	return lhs;
}

/*
Overloaded stream insertion operator for storing ExercisePlan object to the txt file
Uses a reference to an fstream object for the left hand side, and a reference to an ExercisePlan object for the right
returns the modified left hand side
*/
fstream& operator<<(fstream& lhs, ExercisePlan& rhs)
{
	lhs << rhs.getPlanName() << endl;
	lhs << rhs.getGoalSteps() << endl;
	lhs << rhs.getDate() << endl;
	lhs << "\n";
	return lhs;
}

void ExercisePlan::editGoalSteps()
{
	int userGoal = 0;
	cout << "Enter a new step goal for " << getPlanName() << endl;
	cin >> userGoal;
	while (userGoal < 0)
	{
		cout << "It's physically impossible for you to walk this much, try again" << endl;
		cin >> userGoal;
	}
	setGoalSteps(userGoal);
}