#include <iostream>

#define PROMPT "menu prompt here\n"

using namespace std;

int main()
{
	int response = 0;
	do
	{
		cout << PROMPT;
		cin >> response;

	} while (response != -1);

	return 0;
}