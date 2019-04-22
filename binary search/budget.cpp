#include <iostream>
#include <algorithm>

using namespace std;



int main()
{
	int city_num;
	cin >> city_num;

	int *request = new int[city_num];
	for (int i = 0; i < city_num; i++) cin >> request[i];

	int budget;
	cin >> budget;

	sort(request, request + city_num);
	
	int min = budget / city_num;
	int max = request[city_num - 1];
	int result;

	
	while (min <= max) {
		int mid = (min + max) / 2;
		int temp = 0;
		for (int i = 0; i < city_num; i++) {
 			if (request[i] > mid)
				temp += mid;
			else
				temp += request[i];
		}

		if (temp <= budget) {
			result = mid;
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}

	cout << result;

	return 0;
}