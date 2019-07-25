#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> queen;
	// 맨 처음에 (0,0)에 넣음

	stack<pair<int,int>> s;
	s.push(make_pair(0, 0));
	
	
	for (int x = 0; x < N; x++) {
		int y = s.top().first + 1;
		if (isLive(s, x, y, N) && hasChild(s, x, N))
			s.push(make_pair(x, y));


	}


	return 0;
}

bool isLive(stack<pair<int, int>> queen, int x, int y, int N) {
	
	int queen_x, queen_y;
	bool result;
	for (int i = 0; i < queen.size(); i++) {
		queen_y = queen.top().first;
		queen_x = queen.top().second;
		if (isAtLeftDiagonol || isAtRightDiagonol || isAtCross)
			return false;
		queen.pop();
	}
	return true;
}

bool isAtLeftDiagonol(int queen_x, int queen_y, int x, int y) {
	while (queen_y != -1) {
		if (queen_x == x &&
			queen_y == y)
			return true;
		queen_x++;
		queen_y--;
	}
	return false;
}

bool isAtRightDiagonol(int queen_x, int queen_y, int x, int y,int N) {
	while (queen_y != N) {
		if (queen_x == x &&
			queen_y == y)
			return true;
		queen_x++;
		queen_y++;
	}
	return false;
}

bool isAtCross(int queen_x, int queen_y, int x, int y) {
	if (queen_x == x || queen_y == y)
		return true;
	return false;
}

bool hasChild(stack <pair<int, int>> queen, int x, int N) {
	for (int i = 0; i < N; i++) {
		if (isLive(queen, x + 1, i, N))
			return true;
	}
	return false;
}