#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bigger(int a, int b) {
	return a >= b ? a : b;
}

pair<int, int> solution(vector<int> loc, int L, int C) {
	int left = 1;
	int right = L;

	int length;
	pair <int, int> result;

	int now = L;
	while (left <= right) {
		int mid = (left + right) / 2;
		int start = 0, end = L;
		int cut = 0;
		
		for (int i = 0; i < loc.size(); i++) {

			length = bigger(loc.at(i) - start, end - loc.at(i));

			if (length >= mid && length <= now) {
				cut++;
				start = loc.at(i);
				now = length;
				if (cut == 1)
					result.second = start;
				if (cut <= C)
					result.first = length;
			}

		}

		if (cut > C) {
			left = mid + 1;

		}
		else {
			right = mid - 1;
		}
	}

	return result;
}

int main()
{
	int L, K, C;
	cin >> L >> K >> C;

	vector <int> loc;
	int input;
	for (int i = 0; i < K; i++) {
		cin >> input;
		loc.push_back(input);
	}
	
	sort(loc.begin(), loc.end());

	pair <int, int> ans = solution(loc, L, C);

	cout << ans.first << " " << ans.second;

	return 0;
}