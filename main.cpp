/*
Ramsha Bilal
Problem Set 5
main.cpp 
bilal_week5_ps.cpp
PC
*/

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include "moneyclass.h"
#include "problem1.h"
#include "problem2.h"
#include "problem3.h"
using namespace std; 


int main()
{
	srand(static_cast<unsigned int> (time(0)));

	cout << "Running problem 1: \n";
	problem1();
	cout << endl << endl;

	cout << "Running problem 2: \n";
	problem2(); 
	cout << endl << endl;

	cout << "Running problem 3: \n";
	problem3();
	

	return 0; 
}