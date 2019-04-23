#include <iostream>

using namespace std;

int r, c, ans = 0;
bool visited[26] = { false };

void dfs(int x, int y, char **board, int count) {

	if (ans < count)
		ans = count;

	int dx[4] = { +1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, +1 };

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx >= 0 && tx < r &&ty >= 0 && ty < c &&
			visited[board[tx][ty] - 65] == false) {
			visited[board[tx][ty] - 65] = true;
			dfs(tx, ty, board, count + 1);
			visited[board[tx][ty] - 65] = false;
		}

	}
}

int main()
{
	cin >> r >> c;

	char **board = new char*[r];

	for (int i = 0; i < r; i++) {
		board[i] = new char[c];
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}

	visited[board[0][0] - 65] = true;
	dfs(0, 0, board, 1);

	cout << ans << endl;

	return 0;
}