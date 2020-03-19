#include <iostream>
#include <vector>

using namespace std;

int w = 1, h = 1;

void dfs(int x, int y, int**map, int**visited, int &count, int f_x, int f_y) {

	visited[y][x] = 1;

	int dx[8] = {-1, 0, +1, +1, +1, 0, -1, -1 };
	int dy[8] = {-1, -1, -1, 0, +1, +1, +1, 0};

	for (int i = 0; i < 8; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx >= 0 && tx < w && ty >= 0 && ty < h) {
			if (map[ty][tx] == 1 && visited[ty][tx] == 0) {
				dfs(tx, ty, map, visited, count, f_x, f_y);
			}
		}
	}
	if (f_x == x && f_y == y) {
		count++;
	}
}

int main()

{
	vector <int> ans;

	while (w != 0 || h != 0) {

		cin >> w >> h;

		int **map = new int	*[h];
		int **visited = new int*[h];

		for (int i = 0; i < h; i++) {
			map[i] = new int[w];
			visited[i] = new int[w];
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				visited[i][j] = 0;
			}
		}

		int count = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					dfs(j, i, map, visited, count, j, i);
				}
			}
		}
		ans.push_back(count);
	}

	for (int i = 0; i < ans.size() - 1; i++) {
		cout << ans.at(i) << endl;
	}


	return 0;
}