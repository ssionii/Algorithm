#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, m;
vector <int> graph[20001];
vector <pair<int, int>> length;
bool visited[20001];

bool compare(pair<int, int> a, pair<int, int>b) {
	if (a.second > b.second)
		return true;
	else if (a.second == b.second)
		return a.first < b.first;
	else
		return false;
}

void bfs() {
	
	queue <int> q;
	q.push(1);
	visited[1] = true;
	int tlength = 0;
	
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front();
			length.push_back({ x, tlength });
			q.pop();
			for (int j = 0; j < graph[x].size(); j++) {
				if(visited[graph[x].at(j)] == false){
					q.push(graph[x].at(j));
					visited[graph[x].at(j)] = true;
				}
			}
		}
		tlength++;
	}



}

int main()
{	
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs();

	sort(length.begin(), length.end(), compare);

	int max = length.at(0).second;
	int count = 0;
	for (int i = 0; i < length.size(); i++) {
		if (max == length.at(i).second)
			count++;
	}

	cout << length.at(0).first << " " << max << " " << count << endl;

	return 0;
}
