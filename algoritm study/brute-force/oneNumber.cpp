#include <iostream>

using namespace std;

int getFirstNum(int num) {
	return num / 100;
}

int getSecondNum(int num) {
	return (num - getFirstNum(num) * 100) / 10;
}

int getThirdNum(int num) {
	return num - (getFirstNum(num) * 100) - (getSecondNum(num) * 10);
}

int main()
{
	int input;
	cin >> input;

	int count = 99;

	// input�� 100���� ������ ������ �Ѽ�
	if (input < 100) {
		cout << input;
		return 0;
	}
	else if (input <1000) {
		
		int index = 100;
		while (index <= input) {
			if (getFirstNum(index) - getSecondNum(index)
				== getSecondNum(index) - getThirdNum(index))
				count++;
			index++;
		}

		cout << count;
	}
	else
		cout << 144;

	


	return 0;
}

/*  �̷��� �ϵ� �ڵ� ó�� ���� �ʰ� �������� �Ϸ���,
	input�� string���� �޾Ƽ� ���̿� ����
	�� �ڸ����� ã�Ƴ��� ���� ��ͷ� ������ ó��! */