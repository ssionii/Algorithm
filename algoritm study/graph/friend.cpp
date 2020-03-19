#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	cin >> n;

	char ** arr = new char*[n];
	int* count = new int[n];

	for (int i = 0; i < n; i++) {
		arr[i] = new char[n];
		count[i] = 0;
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	bool *isFriend = new bool[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'Y') {
				// 1-模备
				if (isFriend[j] == false) {
					count[i]++;
					isFriend[j] = true;
				}

				for (int k = 0; k < n; k++) {
					// 2-模备
					if (k!=i && arr[j][k] == 'Y' && isFriend[k] == false) {
						count[i]++;
						isFriend[k] = true;
					}
				}
			}
		}
		fill_n(isFriend, n, false);
	}

	sort(count, count + n, greater<int>());

	cout << count[0] << endl;

	return 0;
}