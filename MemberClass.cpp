/*Ramsha Bilal
bilal_week4_ps
Problem set 5
MemberClass.cpp file
PC
*/
#include "MemberClass.h"

Member:: Member(): m_firstName(""), m_lastName(""), m_average(0) {};
Member::Member(string f, string l, double avg) : m_firstName(f), m_lastName(l), m_average(avg) {};

void Member::setFirstName(string f) 
{ m_firstName = f; }
void Member::setLastName(string l) 
{ m_lastName = l; }
void Member::setAverage(int a) 
{ m_average = a;}