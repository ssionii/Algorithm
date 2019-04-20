#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMaxInterval(vector<int> v, int router_num) {

	int min_interval = 1;
	int max_interval = v.at(v.size() - 1);

	int d, install = 2;

	while (min_interval <= max_interval) {

		int interval = (min_interval + max_interval) / 2;
		int start = v.at(0);

		for (int i = 1; i < v.size() - 2; i++) {
			d = v.at(i) - start;
			if (d >= interval) {
				install++;
				start = v.at(i);
			}
		}

		if (install > router_num) {
			 // 공유기 수 줄이기
		}
		else if (install < router_num) {
			// 공유기 수 늘리기
		}
	}

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


	return 0;
}