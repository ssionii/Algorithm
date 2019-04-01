#include <iostream>
#include <queue>

#define MAX 100001

using namespace std;


int main()
{
	int n, k;
	cin >> n >> k;

	queue<int> q;
	bool visit[MAX] = { false };
	q.push(n);

	int time = 0;

	while (q.front() != k) {
		
		int size = q.size();
		for (int i = 0; i < size; i++) {
			if (q.front() == k)
				goto meet;

			if (q.front() > 0 &&visit[q.front() - 1] == false) {
				q.push(q.front() - 1);
				visit[q.front() - 1] = true;
			}
			if (q.front() < 100000 && visit[q.front() + 1] == false) {
				q.push(q.front() + 1);
				visit[q.front() + 1] = true;
			}
			if (q.front() *2 <= 100000 && visit[q.front() * 2] == false) {
				q.push(q.front() * 2);
				visit[q.front() * 2] = true;
			}
			q.pop();
		}
		time++;
	}

	meet:
	cout << time << endl;
}