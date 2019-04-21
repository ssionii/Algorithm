#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getInterval(vector<int> v, int router_num) {

	int min_interval = 1;
	int max_interval = v.at(v.size() - 1);

	int d, result;


	while (min_interval <= max_interval) {

		int interval = (min_interval + max_interval) / 2;
		int start = v.at(0);
		int install = 1;

		for (int i = 1; i < v.size(); i++) {
			d = v.at(i) - start;
			if (d >= interval) {
				install++;
				start = v.at(i);
			}
		}

		if (install >= router_num) {
			 // 공유기 수 줄이기
			result = interval;
			min_interval = interval + 1;
		}
		else{
			// 공유기 수 늘리기
			max_interval = interval - 1;
		}
	}

	cout << result << endl;

}

int main()
{
	int house_num, router_num;
	vector <int> house_pos;

	cin >> house_num >> router_num;
	
	int pos;
	for (int i = 0; i < house_num; i++) {
		cin >> pos;
		house_pos.push_back(pos);
	}

	sort(house_pos.begin(), house_pos.end());

	getInterval(house_pos, router_num);

	return 0;
}