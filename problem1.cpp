/*Ramsha Bilal
bilal_week4_ps
Problem set 5
problem1.cpp file
PC
*/
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include "moneyclass.h"
#include "problem1.h"
using namespace std;

void problem1()
{

	const int DOLLARS = 10, CENTS = 145;   //Test constants to check if addMoney works

	Money wallet1;                         //creating test object using constructor
	wallet1.showMoney();                   //testing showMoney method 
										   //showing that cents and dollars are initialised to 0

	wallet1.addMoney(CENTS, DOLLARS);      //testing addMoney
	Money wallet2 = wallet1;               //creating copy of wallet1 using copy constructor 
	wallet2.showMoney();                   //testing that wallet2 is properly constructed
	wallet2.addMoney(CENTS, DOLLARS);      //adding money in wallet2
	cout << "In wallet 1: \n";
	wallet1.showMoney();

	cout << "In wallet 2: \n";
	wallet2.showMoney();

}

/*int answer;
	cout << "Running problem 1. \n"
		<< "Do you want the debug version? Press 1 for yes or press 0 for no. " << endl;
	cin >> answer;
	if (answer == 1)
		debug = true;
		*/
