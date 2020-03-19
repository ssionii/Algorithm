/*
	string manipulation
	1. �׷� �ܾ� üĿ
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
		memset(alpha[i], 0, sizeof(int) * 27);	// 2���� �迭 0���� �ʱ�ȭ

	}

	for (int i = 0; i < count; i++) {
		cin >> word[i];
	}

	// �׷� �ܾ����� üũ
	for (int j = 0; j < count; j++) {
		for (int i = 0; i < word[j].size(); i++) {
			if (word[j][i] != word[j][i + 1]) {      // �ٷ� �� ���� ���ڰ� �ٸ���
				alpha[j][word[j][i] - 96]++;         // üũ
				if (alpha[j][word[j][i] - 96] > 1) { // �ι� �̻� üũ�Ǹ�
					alpha[j][0] = 1;                 // �׷�ܾ X
					break;
				}
			}
		}
	}

	// ��� üũ
	int result = 0;
	for (int j = 0; j < count; j++) {
		if (alpha[j][0] == 0)
			result++;
	}

	cout << result << endl;


}