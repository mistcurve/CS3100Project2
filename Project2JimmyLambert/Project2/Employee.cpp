// CS3100 Data Structures and Algorithms
// Created By James Brien Lambert
// Professor Meilin Liu
// 9/14/2019
// Programming Assignment #1

#include "Employee.h"

#define INVALID_ID "\t\t**Invalid employee ID, this employee will be reported as empty.**\n"

Employee::Employee()
{
	this->ID = -1;
	this->firstname = "no first name";
	this->lastname = "no last name";
}

Employee::Employee(int IdNum, std::string last, std::string first)
{
	this->ID = IdNum;;
	this->lastname = last;
	this->firstname = first;
	if (this->ID < 0 || this->ID > 9999999)
	{
		std::cout << INVALID_ID;
	}
}

Employee::Employee(const Employee& person)
{
	this->ID = person.ID;
	this->lastname = person.lastname;
	this->firstname = person.firstname;
	if (this->ID < 0 || this->ID > 9999999)
	{
		std::cout << INVALID_ID;
	}
}

Employee::~Employee()
{
	//No code needed for the destructor because no dynamic allocation.

	std::cout << "\t\t**Employee Destructor Called.**\n";
}

void Employee::setFirstName(std::string first)
{
	this->firstname = first;
}

void Employee::setLastName(std::string last)
{
	this->lastname = last;
}

void Employee::setID(int IdNum)
{
	if (IdNum >= 0 && IdNum < 9999999)
		this->ID = IdNum;
	else
		std::cout << "\t\t**Not setting IdNum, invalid ID**\n";
}

int Employee::getID() const
{
	return this->ID;
}

bool Employee::isEmpty() const
{
	return this->firstname == "no first name" || this->lastname == "no last name" || this->ID < 0 || this->ID > 9999999;
}

std::string Employee::getFirstName() const
{
	return this->firstname;
}

std::string Employee::getLastName()const
{
	return this->lastname;
}

std::ostream& operator<<(std::ostream& outs, Employee& person)
{
	outs << person.getFirstName() << " " << person.getLastName() << " " << person.getID() << "\n";
	return outs;
}

std::istream& operator>>(std::istream& ins, Employee& person)
{
	ins >> person.firstname >> person.lastname >> person.ID;
	if (person.ID < 0 || person.ID > 9999999)
	{
		std::cout << INVALID_ID;
	}
	return ins;
}

bool operator==(const Employee& p1, const Employee& p2)
{
	return p1.getFirstName() == p2.getFirstName() &&
		p1.getLastName() == p2.getLastName() &&
		p1.getID() == p2.getID();
}
