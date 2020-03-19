#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int *time = new int[n];
	for (int i = 0; i < n; i++)
		cin >> time[i];
	
	sort(time, time + n);

	long long min = 1;
	long long max = 1000000000000000000;
	long long result = 0;

	while (min <= max) {
		long long person_num = 0;
		long long mid = (min + max) / 2;
		for (int i = 0; i < n; i++) {
			person_num += mid / time[i];
		}

		if (person_num >= m) {
			result = mid;
			max = mid - 1;
		}
		else
			min = mid + 1;

	}

	cout << result;

	return 0;
}
