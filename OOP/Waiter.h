//
//  Waiter.hpp
//  Program4OOP
//
//  Created by Nicholas Sullivan on 3/24/18.
//  Copyright © 2018 Nicholas Sullivan. All rights reserved.
//

/* Waiter.hpp --------------------------------------------------------------
 Header file for a class Waiter derived from Employee that adds
 the attributes unique to Waiters.
 Operations are:  A constructor and a virtual output operation.
 -----------------------------------------------------------------------*/

#ifndef Waiter_h
#define Waiter_h

#include <stdio.h>
#include "Employee.h"

class Waiter : public Employee
{
public:
	Waiter(long id = 0, string last = "", string first = "", double salary = 0,
		double monthProf = 0, double tips = 0, double totalSal = 0, double yearsService = 0);
	/*----------------------------------------------------------------------
	 Waiter constructor.
	 Preconditions:  None.
	 Postconditions: Data members myIdNum, myLastName, myFirstName, mySalary, myMonthProf
	 are initialized by the Employee constructor; myTips, myTotalSal, and myYearsService initialized to 0.
	 -----------------------------------------------------------------------*/

	virtual void display(ostream & out) const;
	/*-----------------------------------------------------------------------
	 Output function member.
	 Precondition:  ostream out is open.
	 Postcondition: A text representation of this Waiter
	 object has been output to out.
	 -----------------------------------------------------------------------*/

	virtual double calculateSalary(double salary, double profit);

	// ... Other Waiter operations ...

private:
	double myTips,
		myYearsService,
		mytotalSal;
};

//--- Definition of Waiter's Constructor
inline Waiter::Waiter
(long id, string last, string first, double salary, double monthProf, double tips, double totalSal, double yearsService)
	: Employee(id, last, first, salary, monthProf),
	myTips(tips), myYearsService(yearsService), mytotalSal(calculateSalary(salary, monthProf))
{ }

//--- Definition of Waiter's display()
inline void Waiter::display(std::ostream & out) const
{
	Employee::display(out);              //inherited members
	out << "Tips: $" << myTips << std::endl << "Total Salary: $" << mytotalSal << std::endl // local members
		<< "Years of Service: " << myYearsService << std::endl;
}

//--- Definition of Employee's calculateSalary
inline double Waiter::calculateSalary(double salary, double profit)
{
	if (profit < 0)
		std::cout << "Profit is less than zero. Waiters are uneffected." << std::endl;
	return mytotalSal = salary + myTips;
}

#endif /* Waiter_h */
