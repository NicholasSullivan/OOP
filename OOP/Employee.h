//
//  Employee.hpp
//  Program4OOP
//
//  Created by Nicholas Sullivan on 3/24/18.
//  Copyright © 2018 Nicholas Sullivan. All rights reserved.
//

/* Employee.hpp --------------------------------------------------------------
 Header file for a class Employee that encapsulates the attributes common
 to all employees.
 Operations are:  A constructor and an output operation.
 -----------------------------------------------------------------------*/

#ifndef Employee_h
#define Employee_h

#include <stdio.h>
#include <iostream>
#include <string>

 //typedef int StaqueElement; // define StaqueElement as an integer

class Employee
{
public:
	Employee(long id = 0, std::string last = "", std::string first = "", double salary = 0, double monthProf = 0);
	/*-----------------------------------------------------------------------
	 Employee constructor.
	 Preconditions:  None.
	 Postconditions: myIdNum is initialized to id (default 0), myLastName
	 to last (default empty string), myFirstName to first (default
	 empty string), mySalary to salary (default 0) and myMonthProf to monthProf (default 0).
	 ----------------------------------------------------------------------*/

	virtual void display(std::ostream & out) const;
	/*-----------------------------------------------------------------------
	 Output function member.
	 Precondition:  ostream out is open.
	 Postcondition: A text representation of this Employee object has
	 been output to out.
	 ------------------------------------------------------------------------*/

	 // ... Other employee operations ...

private:
	long myIdNum;             // Employee's id number
	std::string myLastName,        //     "      last name
		myFirstName;       //     "      first name
	double mySalary;           //     "      salary
	double myMonthProf;        //    "    month profit
	// ... other attributes common to all employees
};


//--- Definition of Employee's Constructor
inline Employee::Employee(long id, std::string last, std::string first, double salary, double monthProf)
	: myIdNum(id), myLastName(last), myFirstName(first), mySalary(salary), myMonthProf(monthProf)
{ }

//--- Definition of Employee's display()
inline void Employee::display(std::ostream & out) const
{
	out << "Name: " << myLastName << ", " << myFirstName << ". ID# " << myIdNum << std::endl << "Base Salary: $" <<
		mySalary << std::endl;
}

//--- Definition of output operator <<
inline std::ostream & operator<<(std::ostream & out, const Employee & emp)
{
	emp.display(out);
	return out;
};

#endif /* Employee_h */
