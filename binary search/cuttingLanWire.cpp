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

	long long min = 0;
	long long max = 2147483647;
	int result;

	while (min <= max) {
		long long mid = (min + max) / 2;
		int count = 0;
		for (int i = 0; i < k; i++) {
			// 랜선 자르기
			count += lan[i] / mid;
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


/*
	hidden test case
	1 1
	2147483647 (2^31-1) -> long long의 최대 값
*/