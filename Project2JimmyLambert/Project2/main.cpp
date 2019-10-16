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
	cout << "Executing topScript..." << endl;
	cout << "Displaying the top item of the stack:" << endl;
	Employee e = stack->pop();
	cout << e;
}

void unionScript(SStack* stack)
{
	cout << "Executing unionScript";
	Employee e = Employee(0101, "James", "Lambert");
	Stack s0 = Stack(5);
	s0.push(e);
	e = Employee(1020, "Saber", "Davidson");
	s0.push(e);
	e = Employee(3829, "John", "Cena");
	s0.push(e);
	Stack s1 = Stack(5);
	e = Employee(3304, "Big", "Mac");
	s1.push(e);
	e = Employee(8362, "David", "Tennant");
	s1.push(e);
	e = Employee(1123, "Micheal", "Sheen");
	s1.push(e);
	e = Employee(1173, "Neil", "Gaiman");
	s1.push(e);
	cout << "Combining the two following stacks into one stack..." << endl;
	cout << "Stack1:" << endl << s0 << endl;
	cout << "Stack2:" << endl << s1 << endl;
	Stack s2 = s0 + s1;
	cout << "Stack3, Union of Stack1 and Stack2:" << endl << s2;
}

void printScript(SStack* stack)
{
	cout << "Executing printScript";
	cout << "Now printing the current stack:" << endl;
	stack->print();
}

void saveScript(SStack* stack)
{
	cout << "Executing saveScript";
	ofstream outfile;
	outfile.open("out_jameslambert.txt", ios::out);
	cout << "Outputting the contents of the current stack to out_jameslambert.txt" << endl;
	while(stack->size > 0)
	{
		Employee e = stack->pop();
		outfile << e;
	}
	outfile.close();

}
