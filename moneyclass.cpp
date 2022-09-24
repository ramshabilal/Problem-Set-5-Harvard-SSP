/*Ramsha Bilal
bilal_week4_ps
Problem set 5
moneyclass.cpp file
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

/*constructor*/
Money::Money(): m_cents(0), m_dollars(0)
{
	cout << "\nInside the constructor.\n";
}

/*copy constructor*/
Money::Money(const Money& moneyObject)
{
	m_cents = moneyObject.m_cents;
	m_dollars = moneyObject.m_dollars;

	cout << "\nInside copy constructor.\n";
}

/*takes cents and dollars as parameter and adds them to 
the existing cents and dollars respectively. If new total cents exceed 99,
 converts the excess to dollars and saves in dollars*/
void Money::addMoney(int cents, int dollars)
{
	m_dollars += dollars;
	m_cents += cents;

	if (m_cents >= MAX_CENTS)
	{
		int noOfDollars;
		noOfDollars = (m_cents / 100);     //to check how many dollars to be added:
		m_cents -= (noOfDollars * MAX_CENTS);     //for example, in case that number of cents is greater than 200,
		m_dollars += noOfDollars;                // 2 dollars should be added.

		{cout << "Inside addMoney()\n" 
			<< "No of dollars to add: " 
			<< noOfDollars 
			<< endl;  //DEBUG VERSION
		}
	}
	{
		cout << "dollars: " << m_dollars << endl;   //testing
		cout << "cents: " << m_cents << endl;       //testing
	}
}

/*shows the total money in a money object.
converts cents to dollars if cents exceeds 99*/
void Money::showMoney()
{
	cout << "\nInside showMoney()\n";

	double centToDollars, totalDollars;
	centToDollars = (static_cast<double>(m_cents) / MAX_CENTS);
	
	cout << centToDollars << " dollars are converted from cents." << endl; //testing

	totalDollars = static_cast<double>(m_dollars) + centToDollars;
	cout << "\nTotal money: $" << totalDollars << endl;
}

//to access money i.e cents or dollars which are otherwise private
int Money::getCents()
{
	return m_cents;
}
int Money::getDollars()
{
	return m_dollars;
}