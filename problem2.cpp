/*Ramsha Bilal
bilal_week4_ps
Problem set 5
problem2.cpp file
PC
*/
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include "problem2.h"

void problem2()
{
	cout << "Running problem 2\n";
	int number, sum = 0;
	string s1 = "12 67 34 777 1 123";
	istringstream s2(s1);
	ostringstream sout;

	while (!s2.eof())
	{
		s2 >> number;
		sum += number;
	}
	cout << "String of numbers to be added: 12 67 34 777 1 123\n";
	sout << "Sum of all numbers in the string: " << sum << endl; 
	cout << sout.str() << endl;
}