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

	// input이 100보다 작으면 무조건 한수
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

/*  이렇게 하드 코딩 처럼 하지 않고 동적으로 하려면,
	input을 string으로 받아서 길이에 따라
	각 자리수를 찾아내는 것을 재귀로 돌려서 처리! */