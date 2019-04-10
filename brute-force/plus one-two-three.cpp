#include <iostream>

using namespace std;

int main()
{
	int testcase;
	cin >> testcase;

	int arr[12];
	arr[0] = 0, arr[1] = 1, arr[2] = 2, arr[3] = 4;

	int n;
	int *result = new int[testcase];

	for (int j = 0; j < testcase; j++) {
		cin >> n;
		for (int i = 4; i <= n; i++) {
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		}
		result[j] = arr[n];
	}

	for (int i = 0; i < testcase; i++) {
		cout << result[i] << endl;
	}

}