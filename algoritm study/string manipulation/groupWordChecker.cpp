/*
	string manipulation
	1. 그룹 단어 체커
	2019.03.16
	by. siyeon
*/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {

	int count = 0;

	cin >> count;
	string *word = new string[count];

	int **alpha = new int*[count];
	for (int i = 0; i < count; i++) {
		alpha[i] = new int[27];
		memset(alpha[i], 0, sizeof(int) * 27);	// 2차원 배열 0으로 초기화

	}

	for (int i = 0; i < count; i++) {
		cin >> word[i];
	}

	// 그룹 단어인지 체크
	for (int j = 0; j < count; j++) {
		for (int i = 0; i < word[j].size(); i++) {
			if (word[j][i] != word[j][i + 1]) {      // 바로 앞 뒤의 글자가 다르면
				alpha[j][word[j][i] - 96]++;         // 체크
				if (alpha[j][word[j][i] - 96] > 1) { // 두번 이상 체크되면
					alpha[j][0] = 1;                 // 그룹단어가 X
					break;
				}
			}
		}
	}

	// 결과 체크
	int result = 0;
	for (int j = 0; j < count; j++) {
		if (alpha[j][0] == 0)
			result++;
	}

	cout << result << endl;


}