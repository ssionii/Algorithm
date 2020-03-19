#include <iostream>

using namespace std;

class Dice {
	int cell[6] = { 0 };
public:
	int goEast(int number) {
		int temp = cell[2];
		cell[2] = cell[0];
		cell[0] = cell[3];
		cell[3] = cell[5];
		
		if (number != 0) {
			cell[5] = number;
			return -1;
		}
		else
			return temp;
	}

	int goWest(int number) {
		int temp = cell[3];
		cell[3] = cell[0];
		cell[0] = cell[2];
		cell[2] = cell[5];

		if (number != 0) {
			cell[5] = number;
			return -1;
		}
		else
			return temp;
	}

	int goNorth(int number) {
		int temp = cell[1];
		cell[1] = cell[0];
		cell[0] = cell[4];
		cell[4] = cell[5];

		if (number != 0) {
			cell[5] = number;
			return -1;
		}
		else
			return temp;
	}

	int goSouth(int number) {
		int temp = cell[4];
		cell[4] = cell[0];
		cell[0] = cell[1];
		cell[1] = cell[5];

		if (number != 0) {
			cell[5] = number;
			return -1;
		}
		else
			return temp;
	}

	int getTop() {
		return cell[0];
	}
};

int main()
{
	Dice dice;

	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;

	if (!(1 <= n && 20 >= n && 1 <= m && 20 >= m &&
		0 <= x && n - 1 >= x && 0 <= y && m - 1 >= y &&
		1 <= k && k <= 1000)) {
		exit(1);
	}

	int **board = new int*[n];

	for (int i = 0; i < n; i++) {
		board[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] > 9)
				exit(1);
		}
	}

	// 주사위를 놓은 칸의 수는 0
	board[x][y] = 0;

	int *commend = new int[k];
	for (int i = 0; i < k; i++) {
		cin >> commend[i];
	}

	int number, flag;
	for (int i = 0; i < k; i++) {
		flag = 0;
		switch (commend[i])
		{
		case 1:
			// 이 예외처리 간단하게 어떻게 하지
			// 졸려서 머리가 안돌아감
			if (y + 1 == m) {
				flag = -1;
				break;
			}
			number = dice.goEast(board[x][++y]);
			break;
		case 2:
			if (y - 1 == -1) {
				flag = -1;
				break;
			}
			number = dice.goWest(board[x][--y]);
			break;
		case 3:
			if (x - 1 == -1) {
				flag = -1;
				break;
			}
			number = dice.goNorth(board[--x][y]);
			break;
		case 4:
			if (x + 1 == n) {
				flag = -1;
				break;
			}
			number = dice.goSouth(board[++x][y]);
			break;
		}

		if (number != -1 && flag != -1) {
			board[x][y] = number;
			cout << dice.getTop() << endl;
		}
		else if (flag!=-1) {
			board[x][y] = 0;
			cout << dice.getTop() << endl;
		}

	}
	return 0;
}