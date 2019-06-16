//
//  Owner.hpp
//  Program4OOP
//
//  Created by Nicholas Sullivan on 3/24/18.
//  Copyright © 2018 Nicholas Sullivan. All rights reserved.
//

/* Owner.hpp -------------------------------------------------------
 Header file for a class Owner derived from Employee that
 adds the attributes unique to Owner.
 Operations are:  A constructor and a virtual output operation.
 -----------------------------------------------------------------------*/

#ifndef Owner_h
#define Owner_h

#include <stdio.h>
#include "Employee.h"

class Owner : public Employee
{
public:
	Owner(long id = 0, std::string last = "", std::string first = "", double salary = 0,
		double monthProf = 0, double percentProfit = 0, double totalSal = 0, int numEmps = 0);
	/*----------------------------------------------------------------------
	 Owner constructor.
	 Preconditions:  None.
	 Postconditions: Data members myIdNum, myLastName, myFirstName, mySalary, and myMonthProf
	 are initialized by the Employee constructor; myNumEmps, myTotalSal and myPercentProfit are initialized to 0.
	 -----------------------------------------------------------------------*/

	virtual void display(std::ostream & out) const;
	/*-----------------------------------------------------------------------
	 Output function member.
	 Precondition:  ostream out is open.
	 Postcondition: A text representation of this Owner
	 object has been output to out.
	 -----------------------------------------------------------------------*/

	virtual double calculateSalary(double profit, double sal);

	// ... Other Owner operations ...

private:
	int myNumEmps;
	double myPercentProfit,
		myTotalSal;
};

//--- Definition of Owner's Constructor
inline Owner::Owner
(long id, std::string last, std::string first, double salary, double monthProf, double percentProfit, double totalSal, int numEmps)
	: Employee(id, last, first, salary, monthProf),
	myNumEmps(numEmps), myPercentProfit(percentProfit), myTotalSal(calculateSalary(monthProf, salary))
{ }

//--- Definition of Owner's display()
inline void Owner::display(std::ostream & out) const
{
	Employee::display(out);              //inherited members
	out << "Percent of Profit: " << myPercentProfit * 100 << "%" << std::endl // local members
		<< "Total Salary: $" << myTotalSal << std::endl << "Number of Employees: "
		<< myNumEmps << std::endl;
}

//--- Definition of Employee's calculateSalary
inline double Owner::calculateSalary(double profit, double sal)
{
	if (profit < 0)
	{
		std::cout << "Profit is less than zero. Taking difference from owner's Salary." << std::endl;
		return myTotalSal = sal + profit;
	}
	else
		return myTotalSal = sal + (profit * myPercentProfit);
}

#endif /* Owner_h */
