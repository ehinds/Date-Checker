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

//*************************************************************************************
//Name: Date
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to 01/01/0001
//Description: This is the default constructor which will be called automatically when
//an object is declared. It will initialize the state of the class
//*************************************************************************************
Date::Date()
{
	cout << "Default constructor has been called.\n";
	myDay = myMonth = myYear = 1;
	display();
}

//*************************************************************************************
//Name: Date
//Precondition: The state of the object (private data) has not been initialized to today's date
//Postcondition: The state has been initialized to today's date.
//Description: This is the explicit value constructor which initializes the date to 
// today's date.
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	cout << "Explicit-value constructor has been called.\n";
	myMonth = m;
	myDay = d;
	myYear = y;
	display();	
}
//*************************************************************************************
//Name: Display
//Precondition: The contents have not been printed to the screen
//Postcondition: The contents have been printed to the screen
//Description: Prints the date if valid or specificies whether the month, day, or year is invalid
// Also prints whether or not it is a leap year.
//*************************************************************************************
void Date::display()
{
	if (getMonth() == -1 || getDay() == -1 || getYear() == -1)
	{
		if (getMonth() == -1)
		{
			cout << "Month = " << setfill('0') << setw(2) << myMonth << " is incorrect.\n";
		}
		if (getDay() == -1)
		{
			cout << "Day = " << setfill('0') << setw(2) << myDay << " is incorrect.\n";
		}
		if (getYear() == -1)
		{
			cout << "Year = " << setfill('0') << setw(4) << myYear << " is incorrect.\n";
		}
		cout << endl << endl;
	}
	else if (getMonth() == myMonth && getDay() == myDay && getYear() == myYear)
	{
		cout << setfill('0') << setw(2) << myMonth << "/";
		cout << setfill('0') << setw(2) << myDay << "/";
		cout << setfill('0') << setw(4) << myYear << endl;
		if (getLeapYear() == 1)
		{
			cout << "This is a leap year.\n";
		}
		cout << endl << endl;
	}
}

//*************************************************************************************
//Name: getMonth
//Precondition: Has not checked to see if the month is valid or not
//Postcondition: Has checked to see if the month is valid
//Description: If the month is valid returns the month, else it returns -1
//*************************************************************************************
int Date::getMonth()
{
	if (myMonth > 0 && myMonth < 13)
	{
		return myMonth;
	}
	else
		return -1;
}

//*************************************************************************************
//Name: getDay
//Precondition: Day has not been checked for validity.
//Postcondition: The day has been checked for validity.
//Description: Checks the day to see if it is a valid date and returns myDate if valid and -1 if not.
//*************************************************************************************
int Date::getDay()
{
	if (myDay < 1)
	{
		return -1;
	}
	else if ((myMonth == 1 || myMonth == 3 || myMonth == 5 || myMonth == 7 || myMonth == 8 || myMonth == 10 || myMonth == 12
) && myDay < 32)
	{
		return myDay;
	}
	else if (myMonth == 2 && myDay < 29 && getLeapYear() == -1)
	{
		return myDay;
	}
	else if (myMonth == 2 && myDay < 30 && getLeapYear() == 1)
	{
		return myDay;
	}
	else if ((myMonth == 4 || myMonth == 6 || myMonth == 9 || myMonth == 11) && myDay < 31)
	{
		return myDay;
	}
	else if (getMonth() == -1 && myDay < 32)
	{
		//month is incorrect but day COULD be correct so return day
		return myDay;
	}
	else
	{
		return -1;
	}
}

//*************************************************************************************
//Name: getYear
//Precondition: Year has not been checked for validity.
//Postcondition: Year has been checked for validity.
//Description: Checks the year to see if it is greater than 0. If not returns -1;
//*************************************************************************************
int Date::getYear()
{
	if (myYear > 0)
	{
		return myYear;
	}
	else
	{
		return -1;
	}
}

//*************************************************************************************
//Name: getLeapYear
//Precondition: Year has not been checked to see if it is a leap year.
//Postcondition: Year has been checked to for leap year status.
//Description: If the year is a leap year this will return 1, otherwise -1.
//*************************************************************************************
int Date::getLeapYear()
{
	if (myYear % 4 == 0)
	{
		if (myYear % 100 == 0)
		{
			if (myYear % 400 == 0)
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
		return 1;
	}
	return -1;
}

//*************************************************************************************
//Name: setMonth
//Precondition: The user has not set the value of the month
//Postcondition: Month has been set to the value the user has given
//Description: Takes an input month from the user and sets the month to that value if valid
//*************************************************************************************
void Date::setMonth(unsigned m)
{
	myMonth = m;

}

//*************************************************************************************
//Name: setDay
//Precondition: The user has not set the value of the day
//Postcondition: day has been set to the value the user has given
//Description: Takes an input day from the user and sets the day to that value if valid
//*************************************************************************************
void Date::setDay(unsigned d)
{
	myDay = d;
}

//*************************************************************************************
//Name: setYear
//Precondition: The user has not set the value of the year
//Postcondition: year has been set to the value the user has given
//Description: Takes an input year from the user and sets the year to that value if valid
//*************************************************************************************
void Date::setYear(unsigned y)
{
	myYear = y;
}

/****************************************************************************************************************************/
//Name: operator<<
//Precondition: Extraction operator has not been overloaded
//Postcondition: Extraction operator has been ovreloaded
//Decription: Friend function that overloads the extraction operator to print the date.
/***************************************************************************************************************************/
ostream & operator<<(ostream & out, const Date & dateObj)
{	
		out << setfill('0') << setw(2) << dateObj.myMonth << "/";
		out << setfill('0') << setw(2) << dateObj.myDay << "/";
		out << setfill('0') << setw(4) << dateObj.myYear;
	
	return out;
}

