#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Number
{
public:
	int first_num;
	int second_num;
	int third_num;
	int strike;
	int ball;

	Number() {}

	Number(int n, int s, int b) {
		first_num = n / 100;
		second_num = (n - first_num * 100) / 10;
		third_num = n - (first_num * 100) - (second_num * 10);
		strike = s;
		ball = b;
	}
};

int main()
{

	int question_num;
	cin >> question_num;

	vector<Number> v;

	int n, s, b;
	for (int i = 0; i < question_num; i++) {
		cin >> n >> s >> b;
		v.push_back(Number(n, s, b));
	}


	int result = 0;

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (i == j) continue;
			for (int k = 1; k < 10; k++) {
				if (k == i || k == j) continue;

				int l = 0;
				bool candidate = true;
				while (candidate != false && l < question_num) {
					int strike = 0, ball = 0;
					// ù��° �ڸ� ��
					if (i == v.at(l).first_num) // ������ ù��° ����
						strike++;				// Ž���Ϸ��� ���� ù��° ���� ������ strike++
					else if (i == v.at(l).second_num || i == v.at(l).third_num)
						ball++;					// ������ ��,����° ���� ������ ball++

					// �ι�° �ڸ� ��
					if (j == v.at(l).second_num)
						strike++;
					else if (j == v.at(l).first_num || j == v.at(l).third_num)
						ball++;

					// ����° �ڸ� ��
					if (k == v.at(l).third_num)
						strike++;
					else if (k == v.at(l).first_num || k == v.at(l).second_num)
						ball++;

					if (v.at(l).strike != strike ||
						v.at(l).ball != ball) {
						candidate = false;
						break;
					}

					l++;
				}
				if (candidate) result++;
			}

		}
	}

	cout << result;
}

	
