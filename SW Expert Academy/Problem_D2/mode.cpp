#include <iostream>
using namespace std;

int main()
{
		int T; // test case
		cin >> T;

		int number, score;
		int score_table[101] = { 0 };

		for (int i = 0; i < T; i++) {
			cin >> number;
			for (int j = 0; j < 1000; j++) {
				cin >> score;
				score_table[score]++;
			}

			int max = 0, result;
			for (int j = 0; j <= 100; j++) {
				if (max <= score_table[j]) {
					max = score_table[j];
					result = j;
				}
			}
			
			cout << "#" << number << " " << result << endl;

			fill_n(score_table, 101, 0);
		}
	return 0;
}