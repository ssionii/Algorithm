#include <iostream>
#include <string>

using namespace std;

int main()
{
	int num;
	cin >> num;
	int temp = num % 100;

	int table[100];

	table[1] = 1; table[2] = -1; table[3] = 1; table[4] = 1;
	
	for (int i = 5; i <= 100; i++) {
		if (table[i - 1] == 1 || table[i - 3] == 1 || table[i-4] == 1)
			table[i] = -1;
		else
			table[i] = 1;
	}

	if (table[temp] == 1)
		cout << "SK";
	else
		cout << "CY";

	return 0;
}