#include <iostream>

#define PROMPT "menu prompt here\n"

using namespace std;

void pushScript();
void popScript();
void topScript();
void unionScript();
void printScript();
void saveScript();

int main()
{
	int response = 0;
	do
	{
		cout << PROMPT;
		cin >> response;

		switch (response)
		{
		case 1:
			pushScript();
			break;
		case 2:
			popScript();
			break;
		case 3:
			topScript();
			break;
		case 4:
			unionScript();
			break;
		case 5:
			printScript();
			break;
		case 6:
			saveScript();
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

void pushScript()
{
	cout << "Executing pushScript...";
}

void popScript()
{
	cout << "Executing popScript...";
}

void topScript()
{
	cout << "Executing topScript...";
}

void unionScript()
{
	cout << "Executing unionScript";
}

void printScript()
{
	cout << "Executing printScript";
}

void saveScript()
{
	cout << "Executing saveScript";
}
