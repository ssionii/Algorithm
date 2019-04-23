#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector <pair<int, int>> info_v;

class Opinion {
	int x, y;
	int x_precipitation = 0, y_precipitation = 0;

	string result;
public:
	Opinion(int x, int y) {
		this->x = x; this->y = y;
		
		// X년도와 Y년도의 강수량 초기화
		for (int i = 0; i < info_v.size(); i++) {
			if (info_v.at(i).first == y)
				y_precipitation = info_v.at(i).second;
			else if (info_v.at(i).first == x) {
				x_precipitation = info_v.at(i).second;
				break;
			}
		}
	}

	void printResult() {

		result = "true";

		// Y년도의 강수량과 X년도의 강수량 비교
		if (y_precipitation == 0 || x_precipitation == 0)
			result = "maybe";

		for (int i = 0; i < info_v.size(); i++) {
			// Z년도의 강수량 존재 X
			if (info_v.at(i).second == 0)
				result = "maybe";
			// Y년도 이후 X년도 전까지의 강수량 비교
			if (info_v.at(i).first > y && info_v.at(i).first <x) {
				if (info_v.at(i).second >= x_precipitation
					&& x_precipitation != 0) {
					result = "false";
					break;
				}
			}
		}
		cout << result << endl;

	}
};

int main()
{
	int n;
	cin >> n;

	int year, precipitation, last_year;
	for (int i = 0; i < n; i++) {
		cin >> year >> precipitation;
		
		if (i == 0) {
			last_year = year;
			info_v.push_back(pair<int, int>(year, precipitation));
		}
		else {
			// 년도가 연속되는 경우
			if (year == last_year)
				info_v.push_back(pair<int, int>(year, precipitation));
			else {
				info_v.push_back(pair<int, int>(last_year++, 0));
				info_v.push_back(pair<int, int>(year, precipitation));
			}
		}
		last_year++;
	}

	int m;
	cin >> m;

	vector <Opinion> op_v;
	for (int i = 0; i < m; i++) {
		int y, x;
		cin >> y >> x;
		
		Opinion temp(x, y);
		op_v.push_back(temp);
	}
	for (int i = 0; i < m; i++) {
		op_v.at(i).printResult();
	}



	return 0;
}