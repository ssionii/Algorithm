#include <iostream>
#include <string>

using namespace std;

int goRight(int x, int &y, int num);
int goDown(int &x, int y, int num);
int **board;


int main()
{
	int testcase, line;
	cin >> testcase;

	
	string temp;
	for (int i = 0; i < testcase; i++) {
		cin >> line;

		// 게임판 만들기
		board = new int*[line];
		for (int j = 0; j < line; j++) {
			cin >> temp;
			board[j] = new int[line];
			for (int k = 0; k < line; k++) {
				board[j][k] = temp[k];
			}
		}
		
		int count = 0, x = 0, y = 0;
		int resultr = board[0][0], resultd = board[0][0];
		while (count <= (line * 2 - 2)) {
			resultr = goRight(x, y, resultr);
			resultd = goDown(x, y, resultd);
			if (resultr == 0 || resultd == 0) {
				cout << "YES" << endl;
				break;
			}
			count++;
		}
	}
	return 0;
}

int goRight(int x, int &y, int num) {
	y = y + num;
	return board[x][y];
}

int goDown(int &x, int y, int num) {
	x = x + num;
	return board[x][y];
}