#include "FitnessAppWrapper.h"
#include "DietPlan.h"
#include "ExercisePlan.h"

FitnessAppWrapper::FitnessAppWrapper()
{
	diet.clear();
	exercise.clear();
}

FitnessAppWrapper::~FitnessAppWrapper()
{
	//left empty because implicit destructor
}

void FitnessAppWrapper::runApp()
{
	
	bool isAppRunning = true; //bool value for a while loop encapsulating the actual app
	

	fstream exerciseTxt;
	fstream dietTxt;

	while (isAppRunning) //while isAppRunning is true
	{
		system("cls");
		displayMenu();
		int choice = getIntChoice();
		switch (choice)
		{
		case 1: 
			//load weekly diet plan
			system("cls");
			dietTxt.open("DietPlan.txt", std::ios::in); //open the dietplan text file
			if (dietTxt.is_open()) //if the text file is open
			{
				cout << "Loading diet plan..." << endl;
				Sleep(2000);
				loadWeeklyPlan(dietTxt, diet);
				cout << "Diet plan has been successfully loaded. Press enter to go back to menu" << endl;
				dietTxt.close();
			}
			else
			{
				cout << "Something went wrong opening this text file, check your code dumbass" << endl; //if this causes me to lose points I'm sorry haha
			}
			system("pause");
			break;

		case 2:
			//load weekly exercise plan
			system("cls");
			exerciseTxt.open("ExercisePlan.txt", std::ios::in); //open the text file for mode read
			if (exerciseTxt.is_open())
			{
				cout << "Loading exercise plan..." << endl;
				Sleep(2000);
				loadWeeklyPlan(exerciseTxt, exercise);
				cout << "Exercise plan has been successfully loaded. Press enter to go back to menu" << endl;
				exerciseTxt.close();
				
			}
			else
			{
				cout << "Something went wrong with opening the text file, check your code dumbass" << endl;
			}
			system("pause");
			break;

		case 3:
			//store diet plan
			system("cls");
			if (diet.empty())
			{
				cout << "I see you testing my stuff bud, gotta load the plan first" << endl;
			}
			else
			{
				dietTxt.open("DietPlan.txt", std::ios::out);
				cout << "Storing to file..." << endl;
				storeWeeklyPlan(dietTxt, diet);
				Sleep(2000);
				cout << "Diet plan successfully stored to file!" << endl;
			}
			system("pause");
			break;

		case 4:
			//store exercise plan
			system("cls");
			if (diet.empty())
			{
				cout << "I see you trying to store an empty plan, try loading it first" << endl;
			}
			else
			{
				exerciseTxt.open("ExercisePlan.txt", std::ios::out); //open the file for mode write
				cout << "Storing to file..." << endl; //print a message
				storeWeeklyPlan(exerciseTxt, exercise); //store the plan
				Sleep(2000); //wait 2 seconds
				cout << "Exercise plan stored successfully!" << endl; //print a success statement
				exerciseTxt.close(); //close the outfile
			}
			system("pause");
			break;

		case 5:
			//display weekly diet plan
			system("cls");
			if (diet.empty())
			{
				cout << "You haven't loaded in your plan yet so I can't display anything" << endl;
			}
			else
			{
				displayWeeklyPlan(diet);
			}
			system("pause");
			break;

		case 6:
			//display weekly exercise plan
			system("cls");
			if (exercise.empty())
			{
				cout << "I see what you're doing, there's nothing to display so load your plan first" << endl;
			}
			else
			{
				displayWeeklyPlan(exercise);
			}
			system("pause");
			break;

		case 7:
			//edit the goal in a day in the diet plan
			system("cls");
			if (diet.empty())
			{
				cout << "I see you trying to test me bud, gotta load the plan first" << endl;
			}
			else
			{
				int dayChoice = 0;
				dayChoice = chooseDailyPlan(diet);
				diet.at(dayChoice - 1).editGoalCalories();
			}
			system("pause");
			break;

		case 8:
			//edit the goal in a day in the fitness plan
			system("cls");
			if (exercise.empty())
			{
				cout << "You probably forgot to load in your exercise plan, try again" << endl;
			}
			else
			{
				int dayChoice = 0;
				dayChoice = chooseDailyPlan(exercise);
				exercise.at(dayChoice - 1).editGoalSteps();
			}
			system("pause");
			break;

		case 9:
			/*
			Exit function:
			-call both store functions
			-print a goodbye message
			-set isAppRunning to false to end the loop
			*/
			system("cls");

			if (!exercise.empty()) //if the vector has content, we need to save it
			{
				exerciseTxt.open("ExercisePlan.txt", std::ios::out);
				storeWeeklyPlan(exerciseTxt, exercise); //we save the plan
				cout << "Exercise plan has been saved" << endl;
				exerciseTxt.close();
			}

			if (!diet.empty()) //if the vector has content, we need to save
			{
				dietTxt.open("DietPlan.txt", std::ios::out);
				storeWeeklyPlan(dietTxt, diet); //we save the plan
				cout << "Diet plan has been saved" << endl;
				dietTxt.close();
			}
			cout << "See you next time!" << endl;
			isAppRunning = false; //set isAppRunning to false to break the loop
			break;

		default:
			system("cls");
			cout << "invalid choice, please try again" << endl;
			system("pause");
		}
	}

}

/* * * * * * * * * * * * * * *
Function Name: loadDailyPlan
Date Created: 10.3
Date Last Modfied: 10.12
Description of Function: This function reads in a day's worth of plan info and pushes it into a vector
Input parameters: A reference to an infile(fstream), and a reference to a plan object (like a vector)
Returns: nothing it's void
Preconditions: file has to be open
Postconditions: vector will be populated with one day's worth of plans
* * * * * * * * * * * * * * */
void FitnessAppWrapper::loadDailyPlan(fstream& infile, DietPlan& plan)
{
	infile >> plan; //read in one day's information to that object
	diet.push_back(plan); //pushes that day's information to the back of the vector
}

void FitnessAppWrapper::loadDailyPlan(fstream& infile, ExercisePlan& plan)
{
	infile >> plan;
	exercise.push_back(plan);
}

/* * * * * * * * * * * * * * *
Function Name: loadWeeklyPlan
Date Created: 10.3
Date Last Modfied: 10.8
Description of Function: This function uses the loadDailyPlan in a loop to populate one week's worth
of plan data to a vector
Input parameters: reference to an infile, and the vector
Returns: nothing it's void
Preconditions: infile has to be open
Postconditions:
* * * * * * * * * * * * * * */
void FitnessAppWrapper::loadWeeklyPlan(fstream& infile, vector<DietPlan>& d)
{
	for (int i = 0; i < 7; ++i) //repeats exactly 7 times
	{
		DietPlan day;
		loadDailyPlan(infile, day);
	}
}

void FitnessAppWrapper::loadWeeklyPlan(fstream& infile, vector<ExercisePlan>& e)
{
	for (int i = 0; i < 7; ++i) //repeats exactly 7 times
	{
		ExercisePlan day;
		loadDailyPlan(infile, day);
	}
}

/* * * * * * * * * * * * * * *
Function Name: displayDailyPlan
Date Created: 10.4
Date Last Modfied: 10.8
Description of Function: This overloaded function displays one day's plan to the screen
this will not be used by the user, only as a helper fuction to displayWeeklyPlan
Input parameters: a reference to a vector of plan objects, and an integer for position
Returns: nothing, it's void
Preconditions: vectors have to be populated with data
Postconditions:
* * * * * * * * * * * * * * */
void FitnessAppWrapper::displayDailyPlan(vector<DietPlan>& d, int position)
{
	cout << d.at(position) << endl;
}

void FitnessAppWrapper::displayDailyPlan(vector<ExercisePlan>& e, int position)
{
	cout << e.at(position) << endl;
}
/* * * * * * * * * * * * * * *
Function Name: displayWeeklyPlan
Date Created: 10.4
Date Last Modfied: 10.8
Description of Function: This overloaded function prints the week's plans to the screen
Input parameters: either a diet plan or exercise plan vector
Returns: nothing it's void
Preconditions: vectors must have data
Postconditions:
* * * * * * * * * * * * * * */
void FitnessAppWrapper::displayWeeklyPlan(vector<DietPlan>& d)
{
	for (int i = 0; i < 7; ++i) 
	{
		displayDailyPlan(d, i);
	}
}

void FitnessAppWrapper::displayWeeklyPlan(vector<ExercisePlan>& e)
{
	for (int i = 0; i < 7; i++)
	{
		displayDailyPlan(e, i);
	}
}

/* * * * * * * * * * * * * * *
Function Name: displayMenu
Date Created: 10.8
Date Last Modfied: 10.8
Description of Function: This function simply prints the menu options
Input parameters: nothing, it's void
Returns: nothing, it's void
Preconditions: none
Postconditions: none
* * * * * * * * * * * * * * */
void FitnessAppWrapper::displayMenu()
{
	cout << "Welcome to this scuffed fitness and diet tracker made by a pretty clueless college sophomore" << endl;
	cout << "Please select an option by typing a number" << endl;
	cout << "1. Load in a weekly diet plan from a file" << endl;
	cout << "2. Load in a weekly exercise plan from a file" << endl;
	cout << "3. Store a diet plan to a file" << endl;
	cout << "4. Store an exercise plan to a file" << endl;
	cout << "5. Display weekly diet plan information" << endl;
	cout << "6. Display weekly fitness plan information" << endl;
	cout << "7. Edit a day in your diet plan" << endl;
	cout << "8. Edit a day in your fitness plan" << endl;
	cout << "9. Exit" << endl;
}

/* * * * * * * * * * * * * * *
Function Name: getIntChoice
Date Created: 10.8
Date Last Modfied: 10.8
Description of Function: This function simply receives user input and then passes that input along
to other functions
Input parameters: nothing
Returns: An integer representing the user's choice
Preconditions: nothing, it's void
Postconditions: functions execute with the given choice
* * * * * * * * * * * * * * */
int FitnessAppWrapper::getIntChoice()
{
	int choice = 0;
	cin >> choice;
	return choice;
}

/* * * * * * * * * * * * * * *
Function Name: storeDailyPlan
Date Created: 10.9
Date Last Modfied: 10.11
Description of Function: These overloaded functions store a day's worth of plan to the file they were read from
Input parameters: A reference to an outfile, reference to the vector, and an int to represent position
Returns: nothing, it's void
Preconditions: outfile already has to be open
Postconditions: helper for storeWeeklyPlan
* * * * * * * * * * * * * * */
void FitnessAppWrapper::storeDailyPlan(fstream& outfile, vector<DietPlan>& d, int position)
{
	outfile << d.at(position);
}

void FitnessAppWrapper::storeDailyPlan(fstream& outfile, vector<ExercisePlan>& e, int position)
{
	outfile << e.at(position);
}

/* * * * * * * * * * * * * * *
Function Name: storeWeeklyPlan
Date Created: 10.9
Date Last Modfied: 10.11
Description of Function: These overloaded functions write a weekly plan to the same file
they were written in
Input parameters: reference to an outfile, reference to either a Diet
Returns: nothing, it's void
Preconditions: outfile has to be open for mode write
Postconditions: the file is now edited
* * * * * * * * * * * * * * */
void FitnessAppWrapper::storeWeeklyPlan(fstream& outfile, vector<DietPlan>& d)
{
	for (int i = 0; i < 7; ++i)
	{
		storeDailyPlan(outfile, d, i);
	}
}

void FitnessAppWrapper::storeWeeklyPlan(fstream& outfile, vector<ExercisePlan>& e)
{
	for (int i = 0; i < 7; ++i)
	{
		storeDailyPlan(outfile, e, i);
	}
}

/* * * * * * * * * * * * * * *
Function Name: chooseDailyPlan
Date Created: 10.11
Date Last Modfied: 10.11
Description of Function: These overloaded functions print the names of the daily plans and then prompt the user
to choose one
Input parameters: a reference to a diet plan or exercise vector
Returns: an integer for the user's choice
Preconditions: vectors have to be populated with data
Postconditions:
* * * * * * * * * * * * * * */
int FitnessAppWrapper::chooseDailyPlan(vector<DietPlan>& d)
{
	int choice = 0, i = 0;
	cout << "Which day would you like to edit?" << endl;
	for (i = 0; i < 7; ++i)
	{
		cout << i + 1 << ". " << d.at(i).getPlanName() << endl;
	}
	cin >> choice;
	while (choice < 0 || choice > 8) //if the choice is less than 0 or greater than 8 (invalid value)
	{
		cout << "gotta pick a valid number buddy" << endl;
		cin >> choice;
	}
	return choice; //returning choice - 1 for using in vector index
}

int FitnessAppWrapper::chooseDailyPlan(vector<ExercisePlan>& e)
{
	int choice = 0, i = 0;
	cout << "which day would you like to edit?" << endl;
	for (i = 0; i < 7; ++i)
	{
		cout << i + 1 << ". " << e.at(i).getPlanName() << endl;
	}
	cin >> choice;
	while (choice < 0 || choice > 8)
	{
		cout << "gotta pick a valid number buddy" << endl;
		cin >> choice;
	}
	return choice;
}

