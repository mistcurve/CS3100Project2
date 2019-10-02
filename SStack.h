//FILE: SStack.h
//CREATED BY: Meilin Liu

//CONTENTS: Declaries Class SStack, with data members, contructors and member function prototypes
//If you want, you can make minor changes to this header file

#ifndef _StackClass_
#define  _StackClass_

#include <cstdlib>
#include "Employee.h"
#include <iostream>

using namespace std;

class SStack
{
public:
	// Constructor
	SStack(int cap);
	// Copy Constructor
	SStack(const SStack& s);
	~SStack(); //destructor

// The member function push: Precondition:  the stack is not full.
	void push(const Employee person);

	// The member function pop: Precondition:  the stack is not empty.
	Employee pop();

	// The member function top: Precondition:  the stack is not empty.
	Employee top() const;

	bool IsEmpty() const;

	//printing all the elements in the stack
	void print() const;

	int size() const;
	int getCapacity() const;


private:
	int Capacity; // Capacity is the maximum number of items that a stack can hold
	Employee* DynamicStack;
	int used; // How many items are stored in the stack
};


// NONMEMBER FUNCTIONS for the stack class
// Postcondition: The stack returned is the union of s1 and s2.
SStack operator +(const SStack& s1, const SStack& s2);


#endif
