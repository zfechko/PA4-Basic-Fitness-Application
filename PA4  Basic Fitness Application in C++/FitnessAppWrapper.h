#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>

#include "DietPlan.h"
#include "ExercisePlan.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::fstream;

class FitnessAppWrapper
{
private:
	vector<DietPlan> diet;
	vector<ExercisePlan> exercise;

public:
	FitnessAppWrapper();
	~FitnessAppWrapper();

	void runApp();

	//overloaded loadDailyPlan functions
	//precondition, file is already open
	void loadDailyPlan(fstream& infile, DietPlan& plan);
	void loadDailyPlan(fstream& infile, ExercisePlan& plan);

	//overloaded loadWeeklyPlan functions
	//has to call loadDailyPlan in the function
	//precondition: the file has to be open
	void loadWeeklyPlan(fstream& infile, vector<DietPlan>& d);
	void loadWeeklyPlan(fstream& infile, vector<ExercisePlan>& e);

	//overloaded displayDailyPlan functions
	//precondition: vectors must be populated with values
	void displayDailyPlan(vector<DietPlan>& d, int position);
	void displayDailyPlan(vector<ExercisePlan>& e, int position);

	//overloaded displayWeeklyPlan functions
	//precondition: vectors must be populated with data
	void displayWeeklyPlan(vector<DietPlan>& d);
	void displayWeeklyPlan(vector<ExercisePlan>& e);
	
	void displayMenu();

	int getIntChoice();

	//overloaded storeDailyPlan functions
	//precondition: outfile must be open and vectors must have data
	void storeDailyPlan(fstream& outfile, vector<DietPlan>& d, int position);
	void storeDailyPlan(fstream& outfile, vector<ExercisePlan>& e, int position);
	

	//overloaded storeWeeklyPlan functions
	//precondition: outfile must be open
	void storeWeeklyPlan(fstream& outfile, vector<DietPlan>& d);
	void storeWeeklyPlan(fstream& outfile, vector<ExercisePlan>& e);

	//overloaded functions for choosing a day from the weekly plan
	//precondition: vectors must have data
	int chooseDailyPlan(vector<DietPlan>& d);
	int chooseDailyPlan(vector<ExercisePlan>& e);

};

