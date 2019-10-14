// CS3100 Data Structures and Algorithms
// Created By James Brien Lambert
// Professor Meilin Liu
// 9/14/2019
// Programming Assignment #1

#define _Employee_

#include <cstdlib>
#include <iostream>
#include <string>

class Employee{

public:
	Employee();
	Employee(int IdNum, std::string last, std::string first);
	Employee(const Employee &person);
	~Employee();
	void setFirstName(std::string first);
	void setLastName(std::string last);
	void setID(int IdNum);
	int getID() const;
	bool isEmpty() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	friend std::ostream& operator<<(std::ostream &outs, Employee &person);
	friend std::istream& operator>>(std::istream &ins, Employee &person);
private:
	int ID;
	std::string lastname;
	std::string firstname;

};

bool operator==(const Employee& p1, const Employee& p2); // test if two employees are the same. aka, first = first, last = last, ID = ID
