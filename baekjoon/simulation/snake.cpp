#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Snake {
	pair<int, int> head;
	vector<pair<int, int>> body;
	int length;
	char direc;
public:
	Snake() {
		head.first = 0; head.second = 0;
		length = 1;
		direc = 'e';
		body.push_back(make_pair(0, 0));
	}
	
	void eatApple() {
		length++;
	}

	bool go(int size) {
		switch (direc)
		{
		case 'e':
			head.second++;
			break;
		case 'w':
			head.second--;
			break;
		case 'n':
			head.first--;
			break;
		case 's':
			head.first++;
			break;
		}
		body.push_back(make_pair(head.first, head.second));
		for (int i = 0; i < body.size() - length; i++) {
			body.erase(body.begin() + i);
		}

		for (int i = 1; i < body.size(); i++) {
			if (head.first == body.at(i).first &&
				head.second == body.at(i).second)
				return false;
		}
		if (head.first == (size+1) || head.second == (size+1)
			|| head.first == -1 || head.second == -1)
			return false;
		else
			return true;
	}

	void transDirec(int trans) {
		if ((direc == 'e' && trans == 68) ||
			direc == 'w' && trans == 76)
			direc = 's';
		else if ((direc == 's' && trans == 68) ||
			direc == 'n' && trans == 76)
			direc = 'w';
		else if ((direc == 'w' && trans == 68) ||
			direc == 'e' && trans == 76)
			direc = 'n';
		else
			direc = 'e';
	}

	pair<int, int> getHead() {
		return head;
	}

};

int main()
{
	int board_size, apple_num;
	cin >> board_size;
	cin >> apple_num;

	vector<pair<int, int>> apple_loc(apple_num);

	int x, y;
	for (int i = 0; i < apple_num; i++) {
		cin >> x >> y;
		apple_loc[i].first = x;
		apple_loc[i].second = y;
	}
	
	int direc_num;
	cin >> direc_num;

	vector<pair<int, int>> direc(direc_num);
	int sec;
	char trans;
	for (int i = 0; i < direc_num; i++) {
		cin >> sec >> trans;
		direc[i].first = sec;
		direc[i].second = (int)trans;
	}

	sort(direc.begin(), direc.end());

	Snake snake;

	int clock = 1, index = 0;
	while (1) {
		if (!direc.empty() && index < direc_num) {
			if (clock == direc.at(index).first+1) {
				snake.transDirec(direc.at(index).second);
				index++;
			}
		}
		
		if (!apple_loc.empty()) {
			for (int i = 0; i < apple_loc.size(); i++) {
				if (snake.getHead().first == apple_loc.at(i).first &&
					snake.getHead().second == apple_loc.at(i).second)
					snake.eatApple();
			}
		}
		
		// °¥ ±æÀ» °¨
		if (snake.go(board_size))
			clock++;
		else{ // º®¿¡ ºÎµúÈ÷°Å³ª ÀÚ½ÅÀÇ ¸ö°ú ºÎµúÈû
			cout << clock << endl;
			break;
		}
			
	}
	
	return 0;
}