/************************************************************************************************************************
Name: Eric Hinds                             Z#: Z23134823
Course: Data Structures (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  1/30/2016                    Due Time: 11:59 p.m.
Total Points: 25
Assignment 2: date.h

Description:  Runs various checks to see if the date entered is accurate. Test driver runs the default constructor as well
as explicit-value constructor and lists whether the year, month, or day is inaccurate, else it will print the date using display function.
Also overloads the extraction operator to print dates and checks if a year is a leap year or not.

The program is split into 3 files: A header file, a cpp file for the functions of call_class, and the test driver.
*************************************************************************************************************************/

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
public:
	Date(); //default constructor; sets m=01, d=01, y =0001
	Date(unsigned m, unsigned d, unsigned y); //explicit-value constructor to set date equal to today's
	//date. Use 2-digits for month (m) and day (d), and 4-digits for year (y); this function should //print a message if a leap year.
	void display();//output Date object to the screen
	int getMonth();//accessor to output the month
	int getDay();//accessor to output the day
	int getYear();//accessor to output the year
	int getLeapYear(); //Checks if a year is a leap year
	void setMonth(unsigned m);//mutator to change the month
	void setDay(unsigned d);//mutator to change the day
	void setYear(unsigned y);//mutation to change the year
	friend ostream & operator<<(ostream & out, const Date & dateObj);//overloaded operator<< as a friend function with chaining
	//you may add other functions if necessary
private:
	int myMonth, myDay, myYear; //month, day, and year of a Date obj respectively
};
#endif