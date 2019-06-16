//
//  Chef.hpp
//  Program4OOP
//
//  Created by Nicholas Sullivan on 3/24/18.
//  Copyright © 2018 Nicholas Sullivan. All rights reserved.
//

/* Chef.hpp --------------------------------------------------------------
 Header file for a class Chef derived from Employee that adds
 the attributes unique to Chef.
 Operations are:  A constructor and a virtual output operation.
 -----------------------------------------------------------------------*/

#ifndef Chef_h
#define Chef_h

#include <stdio.h>
#include "Employee.h"

class Chef : public Employee
{
public:
	Chef(long id = 0, std::string last = "", std::string first = "", double salary = 0,
		double monthProf = 0, double percentProfit = 0, double totalSal = 0, std::string cuisine = "");
	/*----------------------------------------------------------------------
	 Chef constructor.
	 Preconditions:  None.
	 Postconditions: Data members myIdNum, myLastName, myFirstName, mySalary, and myMonthProf
	 are initialized by the Employee constructor; myCuisine initialized to empty string, myPercentProfit
	 and myTotalSal initialized to 0.
	 -----------------------------------------------------------------------*/

	virtual void display(std::ostream & out) const;
	/*-----------------------------------------------------------------------
	 Output function member.
	 Precondition:  ostream out is open.
	 Postcondition: A text representation of this Chef
	 object has been output to out.
	 -----------------------------------------------------------------------*/

	virtual double calculateSalary(double profit, double sal);

	// ... Other Chef operations ...

private:
	std::string myCuisine;
	double myPercentProfit,
		myTotalSal;
};

//--- Definition of Chef's Constructor
inline Chef::Chef
(long id, std::string last, std::string first, double salary, double monthProf, double percentProfit, double totalSal, std::string cuisine)
	: Employee(id, last, first, salary, monthProf),
	myCuisine(cuisine), myPercentProfit(percentProfit), myTotalSal(calculateSalary(monthProf, salary))
{ }

//--- Definition of Chef's display()
inline void Chef::display(std::ostream & out) const
{
	Employee::display(out);              //inherited members
	out << "Percent Profit: " << myPercentProfit * 100 << "%" << std::endl // local members
		<< "Total Salary: $" << myTotalSal << std::endl
		<< "Cuisine of Expertise: " << myCuisine << std::endl;
}

//--- Definition of Employee's calculateSalary
inline double Chef::calculateSalary(double profit, double sal)
{
	if (profit < 0)
	{
		std::cout << "Profit is less than zero. Chefs only get base salary." << std::endl;
		return sal;
	}
	else
		return myTotalSal = sal + (profit * myPercentProfit);
}

#endif /* Chef_h */
