#include "DietPlan.h"


//default constructor
DietPlan::DietPlan()
{
	goalCalories = 0;
	planName = ""; //setting it to a blank string
	Date = "";
}

//constructor that accepts values
DietPlan::DietPlan(int goal, string name, string date)
{
	goalCalories = goal;
	planName = name;
	Date = date;
}

//copy constructor
DietPlan::DietPlan(const DietPlan& copy)
{
	goalCalories = copy.goalCalories;
	planName = copy.planName;
	Date = copy.Date;
}

//destructor
DietPlan::~DietPlan()
{
	//left empty because implicit
}

/*setters*/
void DietPlan::setGoalCalories(int newGoal)
{
	if (newGoal < 0) //checking for invalid values
	{
		goalCalories = 0; //setting it to 0 if an invalid value is entered
	}
	else
	{
		goalCalories = newGoal;
	}
}

void DietPlan::setPlanName(string newName)
{
	planName = newName;
}

void DietPlan::setDate(string newDate)
{
	Date = newDate;
}

/*Getters*/
int DietPlan::getGoalCalories()
{
	return goalCalories;
}

string DietPlan::getPlanName()
{
	return planName;
}

string DietPlan::getDate()
{
	return Date;
}

void DietPlan::editGoalCalories()
{
	int userGoal = 0;
	cout << "Enter a new calorie goal for " << getPlanName() << endl;
	cin >> userGoal;
	while (userGoal < 0)
	{
		cout << "No food in existence has negative calories, try again" << endl;
		cin >> userGoal;
	}
	setGoalCalories(userGoal);
	cout << "Goal Edited Successfully!" << endl;

}

/*
Overloaded stream extraction operator for reading in one whole daily plan to a DietPlan Object
Uses a reference to the fstream object(infile) for the left hand side, and a reference to a diet plan object for the right
returns the modified left hand side
*/
fstream& operator>>(fstream& lhs, DietPlan& rhs)
{
	string name, date, goalString, newLine;
	int goal;
	getline(lhs, name); //reads in plan name
	getline(lhs, goalString); //reads in the goal calories as a string
	goal = stoi(goalString); //and then converts it to an integer
	getline(lhs, date);
	getline(lhs, newLine); //reads in the new line to ignore
	rhs.setPlanName(name); //sets the values gathered from reading to the data members
	rhs.setGoalCalories(goal);
	rhs.setDate(date);

	return lhs;
}

/*
Overloaded stream insertion operator for printing diet plan to the screen
Takes a reference to an ostream object for the left hand side and a reference to the diet plan object as the right
Returns the modified left hand side
*/
ostream& operator<<(ostream& lhs, DietPlan& rhs)
{
	cout << "Today we're making  " << rhs.getPlanName() << " on " << rhs.getDate() << " with a goal of " << rhs.getGoalCalories() << " calories " << endl;
	return lhs;
}

/*
Overloaded stream insertion operator for storing diet plan info to the file
Takes a reference to an fstream object for the left hand side and a reference to the diet plan object
Returns modified left hand side
*/
fstream& operator<<(fstream& lhs, DietPlan& rhs)
{
	lhs << rhs.getPlanName() << endl;
	lhs << rhs.getGoalCalories() << endl;
	lhs << rhs.getDate() << endl;
	lhs << "\n";

	return lhs;
}