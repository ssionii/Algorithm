#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int test_case, personnel;
	cin >> test_case;

	int *result = new int[test_case];

	for (int i = 0; i < test_case; i++) {
		cin >> personnel;
		vector <int> r_rating;
		vector <int> k_rating;

		int temp;
		for (int j = 0; j < personnel; j++) {
			cin >> temp;
			r_rating.push_back(temp);	// 바로 넣을 수 있는 방법은 없나?
		}
		for (int j = 0; j < personnel; j++) {
			cin >> temp;
			k_rating.push_back(temp);
		}

		// 알고리즘 시작
		int win = 0;

		// 오름차순으로 정렬
		sort(r_rating.begin(), r_rating.end());
		sort(k_rating.begin(), k_rating.end());

		int index = 0;
		for (int r = 0; r < personnel; r++) {
			while (index < k_rating.size()) {
				if (r_rating.at(r) <= k_rating.at(index)) {
					k_rating.erase(k_rating.begin() + index);
					win++;
					break;
				}
				index++;
			}
		}

		result[i] = win;

	}

	for (int i = 0; i < test_case; i++)
		cout << result[i] << endl;

	return 0;
}