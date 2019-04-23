#include <iostream>
#include <vector>
#include <stack>

#define MAX 300

using namespace std;

stack<iceBerg> s;

class iceBerg {
public:
	int x;
	int y;
	int height;

	iceBerg(int x, int y, int h) {
		this->x = x;
		this->y = y;
		this->height = h;
	}

	void melting(int **board ) {
		int dx[4] = { +1, -1, 0, 0 };
		int dy[4] = { 0, 0, +1, -1 };

		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];

			if (tx < MAX && tx >= 0 && ty < MAX && ty >= 0 &&
				board[tx][ty] == 0)
				height--;
		}
	}

};

void dfs(int x, int y, int height, vector<iceBerg> v) {
	
	int dx[4] = { +1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, +1 };

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];

		if (tx < MAX && tx >= 0 && ty < MAX && ty >= 0 &&
			height != 0){ 
			s.push(v.at(index));
	}
}


int main()
{
	int x, y;
	cin >> x >> y;

	int **board = new int*[x];
	vector<iceBerg> v;

	for (int i = 0; i < x; i++) {
		board[x] = new int[y];
		for (int j = 0; j < y; j++) {
			cin >> board[x][y];
			if (board[x][y] > 0) {
				iceBerg temp(x, y, board[x][y]);
				v.push_back(temp);
			}
		}
	}

	int time = 0;
	int index = 0;
	while (v.size() != 0) {
			v.at(index).melting(board);
			if (v.at(index).height== 0)
				v.erase(v.begin() + index);
			else
				index++;
	}



	return 0;
}