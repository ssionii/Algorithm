#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int k, n;
	cin >> k >> n;

	int *lan = new int[k];
	for (int i = 0; i < k; i++) {
		cin >> lan[i];
	}

	sort(lan, lan + k);

	int min = 0;
	int max = lan[0] * 2;
	int result;

	while (min <= max) {
		long long mid = (min + max) / 2;
		int count = 0;
		for (int i = 0; i < k; i++) {
			// 랜선 자르기
			int temp = lan[i];
			while (temp-mid >= 0) {
				count++;
				temp -= mid;
			}
		}

		if (count >= n) {
			result = mid;
			min = mid+1;
		}
		else
			max = mid-1;

	}

	cout << result << endl;


	return 0;

}