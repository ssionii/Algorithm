#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int toIntTime(string str, int i) {
	int hour, minute, time;
	hour = (((int)str[0] - 48) * 10) + ((int)str[1] - 48);
	minute = (((int)str[3] - 48) * 10) + ((int)str[4] - 48) - i;

	time = hour * 60 + minute;

	return time;
}

string toStrTime(int time) {
	string hour, minute;
	if ((time / 60) < 10)
		hour = "0" + to_string(time / 60);
	else
		hour = to_string(time / 60);

	if ((time % 60) < 10)
		minute = "0" + to_string(time % 60);
	else
		minute = to_string(time % 60);

	return hour + ":" + minute;
}

bool compareTime(string str, int n, int t) {

	int time = toIntTime(str, 0);

	if (time <= (9 * 60 + (n*t)))
		return true;
	else
		return false;

}

int main()
{
	int n, t, m;
	vector<string> time_table;
	string temp;

	cin >> n >> t >> m;

	cout << "Time Table : ";
	cin.ignore();
	getline(cin, temp);

	for (int i = 0; i < temp.size() / 5; i++) {
		time_table.push_back(temp.substr(i * 6, 5));
	}

	sort(time_table.begin(), time_table.end());
	
	queue<string> shuttle;
	queue<string> empty;
	string result;
	int last;
	int i = 0, person = 0;
	while (i < n || !shuttle.empty()) {
		if (i != n - 1) {
			for (int j = 0; j < m; j++) {
				// 사람들 태우기
				if (compareTime(time_table.at(person), i, t)) {
					// time_table.clear.erase(time_table.begin() + person);
					shuttle.push(time_table.at(person));
					person++;
				}
			}
		}
		// 마지막 셔틀
		else {
			for (int j = 0; j < m; j++) {
				if (person < time_table.size()) {
					if (compareTime(time_table.at(person), i, t)) {
						shuttle.push(time_table.at(person));
						person++;
						if (j == m - 1) {
							// 셔틀이 꽉 참
							if (shuttle.size() == m) {
								last = toIntTime(shuttle.back(), 1);
								result = toStrTime(last);
							}
							else
								result = toStrTime(9 * 60 + (i*t));
						}
					}
				}
				else {
					result = toStrTime(9 * 60 + (i*t));
				}
			}
		}
		// 사람들 내림
		while (!shuttle.empty()) shuttle.pop();
		i++;	
	}


	cout << result << endl;

	return 0;
}