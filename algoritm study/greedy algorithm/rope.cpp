#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int rope_num;
	cin >> rope_num;
	vector <int> ropes;

	int temp;
	for (int i = 0; i < rope_num; i++){
		cin >> temp;
		ropes.push_back(temp);
	}

	sort(ropes.begin(), ropes.end(), greater<int>());

	int max = ropes.at(0);
	int num = 2;

	while (num <= rope_num) {
		if (max < (ropes.at(num - 1) *num)) {
			max = ropes.at(num - 1)*num;
		}
		num++;
	}

	cout << max << endl;


	return 0;
}