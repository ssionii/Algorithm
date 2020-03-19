#include <iostream>
#include <vector>

using namespace std;

int print(int M, vector<pair<int, int>> queue, int *priority) {
	int index = 0, order = 0, pointer;
	while (!queue.empty()) {
		pointer = queue.at(index).second;

		bool canPrint = true;
		for (int j = pointer + 1; j < 10; j++) {
			if (priority[j] != 0) {
				canPrint = false;
				break;
			}
		}

		if (canPrint) {
			if (queue.at(index).first == M) {
				return order + 1;
			}
			priority[queue.at(index).second]--;
			queue.erase(queue.begin() + index);
			order++;
			index--;
		}
		// 순환되게
		if (index + 1 == queue.size()) {
			index = 0;
		}
		else
			index++;
	}
}

int main()
{
	int test_case;
	cin >> test_case;

	int M, N;
	int *result = new int[test_case];
	for (int i = 0; i < test_case; i++) {
		cin >> N >> M;

		vector<pair<int, int>> queue;
		int priority[10];
		fill_n(priority, 10, 0);

		int input;
		for (int j = 0; j < N; j++) {
			cin >> input;
			queue.push_back(make_pair(j, input));
			priority[input]++;
		}

		result[i] = print(M, queue, priority);
	}

	for (int i = 0; i < test_case; i++) {
		cout << result[i] << endl;
	}

	return 0;
}