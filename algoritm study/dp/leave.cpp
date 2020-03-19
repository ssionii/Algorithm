#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main()
{
	int N;
	cin >> N;

	vector <pair<int, int>> consulting;
	consulting.push_back(make_pair(0, 0));

	int t, p;
	for (int i = 0; i < N; i++) {
		cin >> t >> p;
		consulting.push_back(make_pair(t,p));
	}

	int *dp = new int[N+5];
	fill_n(dp, N + 5, 0);
	
	int next;
	for (int i = N; i > 0; i--) {
		next = i + consulting.at(i).first;
		if (next > N + 1) {
			dp[i] = dp[i + 1];
		}
		else {
			/*
				dp[i+1] 상담 채택 X
				consulting.at(i).second + dp[next] 상담 채택
			*/

			dp[i] = max(dp[i + 1], consulting.at(i).second + dp[next]);
		}
	}

	cout << dp[1] << endl;

	return 0;
}