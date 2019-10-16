#include "SStack.h"

SStack::SStack(int cap)
{
	this->Capacity = cap;
	this->DynamicStack = new Employee[cap];
	this->used = 0;
}

SStack::SStack(const SStack& s)
{
	this->Capacity = s.Capacity;
	this->DynamicStack = s.DynamicStack;
	this->used = s.used;
}

SStack::~SStack()
{
	delete DynamicStack;
}

void SStack::push(const Employee person)
{
	if (this->used < Capacity)
	{
		this->used++;
		this->DynamicStack[this->used - 1] = person;
	}
	else
	{
		cout << "Error, stack is at capacity, cannot add any more employees." << endl;
	}
}

Employee SStack::pop()
{
	if (!this->IsEmpty())
	{
		Employee temp;
		temp = this->DynamicStack[this->used - 1];
		used--;
	}
	else
	{
		cout << "Error, stack is empty, connot pop from stack." << endl;
		return Employee();
	}
}

Employee SStack::top() const
{
	if (!this->IsEmpty())
	{
		return this->DynamicStack[this->used - 1];
	}
	else
	{
		cout << "This stack is empty, no employees on top of stack.";
		return Employee();
	}
}

bool SStack::IsEmpty() const
{
	return this->used <= 0;
}

void SStack::print() const
{
	if(!this->IsEmpty())
	{
		cout << "Printing every element in the stack, starting from the top, to the bottom..." << endl;
		cout << "Top of Stack" << endl;
		int i = this->used - 1;
		while (i >= 0)
		{
			cout << DynamicStack[i--] << endl;
		}
		cout << "Bottom of Stack" << endl;

	}
	else
	{
		cout << "No elements to print in this stack.";
	}
}

int SStack::size() const
{
	return this->used;
}

int SStack::getCapacity() const
{
	return Capacity;
}

SStack operator+(const SStack& s1, const SStack& s2)
{
	SStack temp = SStack(s1.getCapacity() + s2.getCapacity());
	for (int i = 0; i < s1.used; i++)
	{
		temp.DynamicStack[i] = s1.DynamicStack[i];
	}
	for (int i = 0; i < s2.used; i++)
	{
		temp.DynamicStack[i + s1.used] = s2.DynamicStack[i];
	}
	temp.used = s1.used + s2.used;
	return temp;
}
