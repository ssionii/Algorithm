#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> map[100001];
vector<int> length;
bool visited[100001];
int N, K, M;

void bfs() {

	queue <int> q;
	q.push(1);
	visited[1] = true;
	int tlength = 0;

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front();
			length.push_back(tlength);
			q.pop();
			for (int j = 0; j < map[x].size(); j++) {
				if (visited[map[x].at(j)] == false) {
					q.push(map[x].at(j));
					visited[map[x].at(j)] = true;
					if (map[x].at(j) == N)
						return;
				}
			}
		}
		tlength++;
	}
}


int main() {

	cin >> N >> K >> M;
	
	int *station = new int[K];

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> station[j];
		}

		// map √ ±‚»≠
		for (int j = 0; j < K; j++) {
			if (j == 0)
				map[station[j]].push_back(station[j + 1]);
			else if (j == K - 1)
				map[station[j]].push_back(station[j - 1]);
			else {
				map[station[j]].push_back(station[j - 1]);
				map[station[j]].push_back(station[j + 1]);
			}
		}
	}


	bfs();

	sort(length.begin(), length.end(), greater<int>());

	if (length.at(0) == 0)
		length.at(0) = -1;

	cout << length.at(0) << endl;


	return 0;
}