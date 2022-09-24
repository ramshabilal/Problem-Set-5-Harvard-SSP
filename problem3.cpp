/*Ramsha Bilal
bilal_week4_ps
Problem set 5
problem3.cpp file
PC
*/
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <cstdlib>
#include <ctime>
#include "problem3.h"
#include "MemberClass.h"
using namespace std;

void problem3()
{
	cout << "\nPart 1: \n";
	part1();
	cout << "\nPart 2: \n";
	part2();
	cout << "\nPart 3: \n";
	part3();
}

/*Part 1
Create a plain text file in which each line has a full name (i.e., first and last name).
Read each line from the file and display it.
Count the number of lines as you read from the file to show how many names there were. */ 
void part1()
{
	string s, firstName, lastName;
	int count = 0; 
	istringstream sstr;
	//create file
	ofstream ofile1("file1.txt");

	// open for writing
	ofstream fout("file1.txt");                   
	fout << "Al Dentay\nRobin Banks\nPhil Updebole\nAilene Wright\nMike Raffone\n";
	fout.close();
		
	// open for reading
	cout << "File 1 contents: \n";
	ifstream fin("file1.txt"); 
	while (fin >> firstName && fin >> lastName)
	{
		getline(fin, s);
		sstr.clear();
		sstr.str(s);
		sstr >> firstName;
		sstr >> lastName;
		count++;
		cout << firstName << " " << lastName << endl;
	} 
	cout << "Total number of names: " << count << endl; 
}

/*Part 2
After reading through the file one time and getting the line count, create a dynamic array large enough to
store all of the names.
Read through the file a second time- this time read the names and store each name (as a string) in the array.
Sort the names (by first name)
Write the names to a new file.
*/
void part2()
{
	string s, firstName, lastName;
	int count = 0;
	istringstream sstr;
	//create file
	ofstream ofile1("file1.txt");

	// open for writing
	ofstream fout("file1.txt");
	fout << "Al Dentay\nRobin Banks\nPhil Updebole\nMike Raffone\nAilene Wright\n ";
	fout.close();

	// open for reading
	ifstream fin("file1.txt");
	while (fin >> firstName && fin >> lastName)
	{
		getline(fin, s);
		sstr.clear();
		sstr.str(s);
		sstr >> firstName;
		sstr >> lastName;
		cout << firstName << " " << lastName << endl;
		count++;
	}
	cout << "\nTotal number of names: " << count << endl;
	fin.close();
 
	//Part 2 code starts here
	string s2, firstN, lastN, stringToAdd;
	string *dynArray, *startArray;
	dynArray = new string[count];
	if (!dynArray) exit(-1);

	startArray = dynArray;

	istringstream readStr;
	ifstream inFile("file1.txt");
	while ((inFile>> firstN) && (inFile >> lastN))
	{
		getline(inFile, s2);
			readStr.clear();
			readStr.str(s2);
			readStr >> firstN;
			readStr >> lastN;
			stringToAdd = firstN + " " + lastN;
			*dynArray = stringToAdd; 
			dynArray++;
	}
	inFile.close();

	dynArray = startArray;
	cout << "\nDynamically allocated memory looks like this: \n";
	for (int i = 0; i<count; i++)
		cout << *dynArray++ << endl;  
	dynArray = startArray;

	//sorting the array
	string temp;
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count -1; j++)
			if (dynArray[j] > dynArray[j+1])
			{
				temp = dynArray[j];
				dynArray[j] = dynArray[j + 1];
				dynArray[j + 1] = temp; 
			}
	dynArray = startArray;
	cout << "\nAfter sorting, dynamically allocated memory looks like this: \n";
	for (int i = 0; i < count; i++)
		cout << *dynArray++ << endl;

	dynArray = startArray;
	
	//writing names to a new file
	//create file
	ofstream ofile2("file2.txt");
	// open for writing
	ofstream fileOut("file2.txt");
	for (int i = 0; i < count; i++)
		fileOut << *dynArray++ << endl;

	dynArray = startArray; 
	delete[] dynArray;

		fileOut.close();


	//open file to read and test that data is saved correctly
		istringstream writeStr;
		cout << "\nFile 2 contents: \n";
		ifstream fileIn("file2.txt");
		while (fileIn >> firstName && fileIn >> lastName)
		{
			getline(fileIn, s);
			writeStr.clear();
			writeStr.str(s);
			writeStr >> firstName;
			writeStr >> lastName;
			cout << firstName << " " << lastName << endl;
		}
		
		fileIn.close();
}


/*Copy the file to a new file an in this file, change each line to include the name plus several numbers(integers)
after the name. Note – this must work for a different amount of numbers on each line.
Create a class called Member that contains a first and last name and a double which will represent the
average of the numbers.
When you read each line, store the first name, last name and average of the numbers in the Member object.
Store all Member’s in the dynamic array that have allocated.
Extra credit(required for grad students) :
Display all namesand averages from highest to lowest.You will need to sort the Member’s by the average
Possible file :
Al Dentay 34 11 23 799
Robin Banks 123 45
Phil Updebole 73 87 23 83 10
Ailene Wright 300 487 288 19
Mike Raffone 12
*/
void part3()
{

	string s, firstName, lastName;
	int count = 0;
	istringstream sstr;
	//create file
	ofstream ofile1("file1.txt");

	// open for writing
	ofstream fout("file1.txt");
	fout << "Al Dentay\nRobin Banks\nPhil Updebole\nMike Raffone\nAilene Wright\n ";
	fout.close();

	// open for reading
	ifstream fin("file1.txt");
	while (fin >> firstName && fin >> lastName)
	{
		getline(fin, s);
		sstr.clear();
		sstr.str(s);
		sstr >> firstName;
		sstr >> lastName;
		cout << firstName << " " << lastName << endl;
		count++;
	}
	cout << "\nTotal number of names: " << count << endl;
	fin.close();

	//Part 2 code starts here
	string s2, firstN, lastN, stringToAdd;
	string* dynArray, * startArray;
	dynArray = new string[count];
	if (!dynArray) exit(-1);

	startArray = dynArray;

	istringstream readStr;
	ifstream inFile("file1.txt");
	cout << "\n";
	while (inFile >> firstN && inFile >> lastN)
	{
		getline(inFile, s2);
		readStr.clear();
		readStr.str(s2);
		readStr >> firstN;
		readStr >> lastN;
		stringToAdd = firstN + " " + lastN;
		*dynArray = stringToAdd;
		cout << stringToAdd << endl;
		dynArray++;
	}
	inFile.close();

	dynArray = startArray;
	cout << "\nDynamically allocated memory looks like this: \n";
	for (int i = 0; i < count; i++)
		cout << *dynArray++ << endl;
	dynArray = startArray;

	//sorting the array
	string temp;
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count - 1; j++)
			if (dynArray[j] > dynArray[j + 1])
			{
				temp = dynArray[j];
				dynArray[j] = dynArray[j + 1];
				dynArray[j + 1] = temp;
			}
	dynArray = startArray;
	cout << "\nAfter sorting, dynamically allocated memory looks like this: \n";
	for (int i = 0; i < count; i++)
		cout << *dynArray++ << endl;

	dynArray = startArray;

	//writing names to a new file
	//create file
	ofstream ofile2("file2.txt");
	// open for writing
	ofstream fileOut("file2.txt");
	for (int i = 0; i < count; i++)
		fileOut << *dynArray++ << endl;

	dynArray = startArray;
	delete[] dynArray;

	fileOut.close();


	//open file to read and test that data is saved correctly
	istringstream writeStr;
	cout << "\nFile 2 contents: \n";
	ifstream fileIn("file2.txt");
	while (fileIn >> firstName && fileIn >> lastName)
	{
		getline(fileIn, s);
		writeStr.clear();
		writeStr.str(s);
		writeStr >> firstName;
		writeStr >> lastName;
		cout << firstName << " " << lastName << endl;
	}

	fileIn.close();


//Part 3 new code starts here

	//copy each line to new file -
	//first read file contents to a dynamic array and then copy to new file
	string* newArray, * newStart;
	newArray = new string[count];
	newStart = newArray;
	istringstream newstr;
	ifstream fileRead("file2.txt");
	while (fileRead >> firstName && fileRead >> lastName)
	{
		getline(fileRead, s);
		newstr.clear();
		newstr.str(s);
		newstr >> firstName;
		newstr >> lastName;
		*newArray++ = firstName + " " + lastName;
	}
	newArray = newStart;
	fileRead.close();


	string numbers[10] =
	{
		"34 11 23 799",
		"123 45",
		"73 87 23 83 10",
		"300 487 288 19",
		"12",
		"14",
		"15 16 2 12",
		"2",
		"12 122 1222 1222",
		"5 9 0 12"
	};

	int randNum;
	string addString;
		//create new file
	ofstream ofile3("file3.txt");
	// open for writing
	ofstream sout("file3.txt");
	for (int i = 0; i < count; i++)
	{
		randNum = rand() % 10;
		addString = (*newArray++ + " " + numbers[randNum] + "\n");
		cout << addString << endl; //DEBUG
		sout << addString;
		
	} 
	sout.close();
	delete[] newStart;


	istringstream newStr;
	string line, f_Name, l_Name; 
	double integer, average, sum = 0;
	int noOfNums = 0, memNum = 0;

	Member* start; 
	Member *members = new Member[count];
	start = members; 

	ifstream intoFile("file3.txt");
	while (getline(intoFile, line))
	{
		istringstream s(line);
		s >> f_Name;
		s >> l_Name; 
		cout << "Numbers to add: ";  //debug 
		while (s >> integer)
		{
			s >> integer;
			cout << integer << "  ";
			noOfNums++;
			sum += integer;
		}
		
		average = (sum / noOfNums);
		members[memNum].setFirstName(f_Name);
		members[memNum].setLastName(l_Name);
		members[memNum].setAverage(average);
		cout << "Name is " << f_Name << " " << l_Name << " " << "Sum is " << sum << " " << "Average is " << average << endl;
		memNum++;
		sum = 0; 
		average = 0; 
		noOfNums = 0; 
		s.clear();
	}
	cout << endl << endl; 
	members = start; 


	//displaying members 

	for (int i = 0; i < count; i++)
		cout << "Member " << i+1 << " Full Name: "
		<< members[i].getFirstName() << " "
		<< members[i].getLastName()
		<< " Average: " << members[i].getAverage() << endl;
	
	delete[]members; 

}