/************************************************************************************************************************
Name: Eric Hinds                             Z#: Z23134823
Course: Data Structures (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  1/30/2016                    Due Time: 11:59 p.m.
Total Points: 25
Assignment 2: date.h

Description: Runs various checks to see if the date entered is accurate. Test driver runs the default constructor as well
as explicit-value constructor and lists whether the year, month, or day is inaccurate, else it will print the date using display function.
Also overloads the extraction operator to print dates and checks if a year is a leap year or not.

The program is split into 3 files: A header file, a cpp file for the functions of call_class, and the test driver.
*************************************************************************************************************************/

#include "date.h"

int main()
{
	Date myDate;
	Date yourDate(12,31, 1957);
	Date test1Date(15, 1, 1962); //should generate error message that bad month
	Date test2Date(2, 29, 1956); //ok, should say leep year
	Date test3Date(2, 30, 1956); //should generate error message that bad day
	Date test4Date(12,31,0000); //should generate error message that bad year
	Date test5Date(80,40,0000); //should generate error message that bad month, day and year
	yourDate.display();
	cout<<yourDate.getMonth()<<endl;
	cout<<yourDate.getDay()<<endl;
	cout<<yourDate.getYear()<<endl;
	myDate.setMonth(11);
	myDate.setDay(12);
	myDate.setYear(2015);
	cout << "myDate: "<< myDate << " test2Date: " << test2Date << " yourDate: "<< yourDate << endl;
	return 0;
}