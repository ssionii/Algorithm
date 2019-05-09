#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bigger(int a, int b) {
	return a >= b ? a : b;
}


pair<long long, long long> solution(vector<int> loc, long long L, int C) {
	long long left = 1;
	long long right = L;

	long long length;
	pair <long long, long long> result;
	vector <long long> piece;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long start = 0, end = L;
		int cut = 0;

		for (int i = 0; i < loc.size(); i++) {

			length = bigger(loc.at(i) - start, end - loc.at(i));

			if (length <= mid) {
				cut++;
				start = loc.at(i);

				if (cut == 1) {
					result.second = start;
					piece.clear();
					piece.push_back(0);
				}
				piece.push_back(loc.at(i));

				if (cut == C)
					break;
			}

		}

		if (cut < C) {
			left = mid + 1;

		}
		else {
			right = mid - 1;
		}

		
	}


	result.first = 0;
	piece.push_back(L);
	long long temp;
	for (int i = piece.size()-1; i > 0; i--) {
		temp = piece.at(i) - piece.at(i - 1);
		if (result.first < temp)
			result.first = temp;
	}
	
	return result;
}

int main()
{
	long long L;
	int K, C;
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