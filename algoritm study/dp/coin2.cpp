#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	
	int *coin = new int[n];
	for (int i = 0; i < n; i++) cin >> coin[i];

	sort(coin, coin + n);

	int *arr = new int[k + 1];

	// base case
	arr[0] = 0;
	for (int i = 0; i < n; i++) arr[coin[i]] = 1;
	
	for (int i = 1; i <= k; i++) {
		arr[i] = k + 1;
		for (int j = 0; j < n; j++) {
			if (i - coin[j] >= 0 && arr[i] > arr[i-coin[j]] + 1) {
				arr[i] = arr[i-coin[j]] + 1;
			}
		}
	}

	if (arr[k] <= k)
		cout << arr[k] << endl;
	else
		cout << "-1" << endl;



	return 0;
}