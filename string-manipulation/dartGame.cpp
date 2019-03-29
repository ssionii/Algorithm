/*
	string manipulation
	3. 다트게임
	2019.03.17
	by. siyeon
*/

#include <iostream>
#include <string>

using namespace std;

void main() {

	string input;
	cin >> input;

	int score[3] = { 0 };

	int index = -1;
	for (int i = 0; i < input.size(); i++) {

		// 점수
		if (input[i] >= 48 && input[i] <= 57) {
			index++;
			if (input[i] == 49 && input[i + 1] == 48) { // 점수 10
				score[index] = 10;
			}
			else {
				score[index] = input[i] - 48;
			}
		}

		// 보너스
		else if (input[i] == 83) {}
		else if (input[i] == 68) {
			score[index] = pow(score[index], 2);
		}
		else if (input[i] == 84) {
			score[index] = pow(score[index], 3);
		}

		// 옵션
		else if (input[i] == 35) {
			score[index] = -score[index];
		}
		else if (input[i] == 42) {
			if (index == 0) {
				score[index] *= 2;
			}
			else {
				score[index - 1] *= 2;
				score[index] *= 2;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 3; i++) {
		result += score[i];
	}
	cout <<endl << result;
}