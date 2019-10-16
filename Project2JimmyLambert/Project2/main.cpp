#include <iostream>
#include "SStack.h"

#define PROMPT "menu prompt here\n"

using namespace std;

void pushScript(SStack *stack);
void popScript(SStack* stack);
void topScript(SStack* stack);
void unionScript(SStack* stack);
void printScript(SStack* stack);
void saveScript(SStack* stack);

int main()
{
	int response = 0;
	cout << "What should the maximum capacity of the stack be?";
	cin >> response;
	SStack stack = SStack(response);
	do
	{
		cout << PROMPT;
		cin >> response;

		switch (response)
		{
		case 1:
			pushScript(&stack);
			break;
		case 2:
			popScript(&stack);
			break;
		case 3:
			topScript(&stack);
			break;
		case 4:
			unionScript(&stack);
			break;
		case 5:
			printScript(&stack);
			break;
		case 6:
			saveScript(&stack);
			break;
		case 7:
			response = -1;
			break;
		default:
			response = 0;
			break;
		}
	} while (response != -1);

	return 0;
}

void pushScript(SStack* stack)
{
	cout << "Executing pushScript...";
	cout << "Please enter an employee object in this format:" << endl << "Firstname Lastname ID" << endl;
	Employee e;
	cin >> e;
	stack->push(e);
}

void popScript(SStack* stack)
{
	cout << "Executing popScript...";
	cout << "Please enter a number of employees to pop from the stack (if possible)." << endl;
	int i;
	cin >> i;
	if (i > stack->size())
	{
		cout << "Stack does not contain " << i << " employees, popping " << stack->size() << " instead." << endl;
		for (int j = 0; j < stack->size(); j++)
		{
			Employee e = stack->pop();
			cout << e;
		}
	}
	else
	{
		cout << "Popping these items..." << endl;
		for (int j = 0; j < i; j++)
		{
			Employee e = stack->pop();
			cout << e;
		}
		cout << "Now displaying the remaining stack:" << endl;
		stack->print();
	}
}

void topScript(SStack* stack)
{
	cout << "Executing topScript...";
}

void unionScript(SStack* stack)
{
	cout << "Executing unionScript";
}

void printScript(SStack* stack)
{
	cout << "Executing printScript";
}

void saveScript(SStack* stack)
{
	cout << "Executing saveScript";
}
