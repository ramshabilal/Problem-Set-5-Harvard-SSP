/*Ramsha Bilal
bilal_week4_ps
Problem set 5
MemberClass.h file
PC
*/
#ifndef MEMBER_H
#define MEMBER_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
class Member
{
private:
	string m_firstName;
	string m_lastName;
	double m_average;

public:
	Member(); //default constructor;
	Member(string f, string l, double avg);
	void setFirstName(string f);
	void setLastName(string l);
	void setAverage(int a); 

	string getFirstName() 
	{ 
		return m_firstName;
	}
	string getLastName()
	{
		return m_lastName;
	}
	double getAverage()
	{
		return m_average;
	}
};
#endif

