#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int *arr = new int[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int max = -1000;
	int* dp = new int[n+1];
	fill_n(dp, n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (dp[i-1] >=0 && dp[i - 1] + arr[i] > 0) {
			dp[i] = dp[i - 1] + arr[i];
		}
		else
			dp[i] = arr[i];

		if (max < dp[i])
			max = dp[i];	
	}

	cout << max << endl;

	return 0;
}