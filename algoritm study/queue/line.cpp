#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> map[32001];
	int *count = new int[N + 1];
	fill_n(count, N + 1, 0);

	int input1, input2;
	for (int i = 0; i < M; i++) {
		cin >> input1 >> input2;
		map[input2].push_back(input1);
		count[input1]++;
	}
	
	queue <int> q;

	// 자신을 향하는 간선이 없는 애를 찾음
	for (int i = 1; i <= N; i++) {
		if (count[i] == 0) {
			q.push(i);
			count[i] = -1;
		}
	}
	
	vector<int> order;

	while (!q.empty()) {
		int front = q.front();
		order.push_back(front);
		q.pop();

		for (int i = 0; i < map[front].size(); i++) {
			count[map[front].at(i)]--;
			if (count[map[front].at(i)] == 0)
				q.push(map[front].at(i));

		}
		
	}
	
	for (int i = order.size() - 1; i >= 0; i--) {
		cout << order.at(i) << " ";
	}

	return 0;
}