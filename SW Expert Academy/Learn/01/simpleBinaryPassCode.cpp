#include <iostream>
#include <fstream>

using namespace std;

int findPassCode(int n, int m, int **arr) {
	
	for (int i = 0; i <n ; i++) {
		for (int j = 0 ; j <m; j++) {
			cout << arr[i][j] << endl;
			if (arr[i][j] == 1) {
				return i * n + j;
			}
		}
	}

	/**
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			cout << arr[i][j] << endl;
			if (arr[i][j] == 1) {
				return i * n + j;
			}
		}
	}
	*/
}

int getInfo(int *passcode) {

	int info[] = { 13, 25, 19, 61, 35, 49, 47, 59, 55, 11 };
	
	bool flag;

	for (int index = 0; index < 10; index++) {
		flag = true;
		for (int i = 6; info[index] > 0; i--) {
			// 둘이 다르면
			if ((info[index] % 2) & passcode[i] != passcode[i]) {
				flag = false;
				break;
			}
			else
				info[index] = info[index] / 2;
		}
		if (flag)
			return index;
	}
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int test_case;
	//cin >> test_case;
	in >> test_case;

	for (int case_num = 0; case_num < test_case; case_num++) {
		int n, m;
		//cin >> n >> m;
		in >> n >> m;


		// byte여야 함!!!! 난 바보다
		int **arr = new int*[n];

		for (int i = 0; i < n; i++) {
			arr[i] = new int[m];
			for (int j = 0; j < m; j++) {
				in >> arr[i][j];
				// cin >> arr[i][j];
			}
		}

		int passcode[8][7];
		int index = findPassCode(n, m, arr);

		int vericode[8];

		int y = index / n;
		int x = index % m;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 7; j++) {
				passcode[i][j] = arr[y][(x++) - 55];
			}
			vericode[i] = getInfo(passcode[i]);
		}

		int sum = 0;
		for (int i = 0; i < 8; i++) {
			if (i % 2 == 0 && i != 7)
				sum += vericode[i] * 3;
			else
				sum += vericode[i];
		}

		if (sum % 10 != 0)
			sum = 0;
		
		cout << "#" << case_num << " " << sum << endl;

		
	}
}