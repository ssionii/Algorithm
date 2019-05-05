#include <iostream>
#include <vector>

using namespace std;

int m, n, **map, **way;

int canGo(int y, int x) {

	// memoization
	if (way[y][x] != -1) return way[y][x];
	// base case
	if (y == m - 1 && x == n - 1)
		return 1;

	way[y][x] = 0;

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	
	for (int i = 0; i < 4; i++ ) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < n && ty < m && tx >= 0 && ty >= 0) {
			if (map[y][x] > map[ty][tx]) {
				way[y][x] += canGo(ty, tx);
			}
		}
	}

	return way[y][x];
}

int main()
{
	cin >> m >> n;
	map = new int*[m];
	way = new int*[m];

	for (int i = 0; i < m; i++) {
		map[i] = new int[n];
		way[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			way[i][j] = -1;
		}
	}

	canGo(0, 0);

	cout << way[0][0] << endl;

	return 0;
}