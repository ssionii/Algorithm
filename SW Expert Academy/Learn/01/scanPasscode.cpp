#include <iostream>
#include <string>

using namespace std;

// 10진수를 2진수로
string convert(int deci) {

	string result = "";
	char temp[4];
	for (int i = 3; i >= 0; i--) {
		temp[i] = (char)(deci % 2 + 48);
		deci /= 2;
	}

	for (int i = 0; i < 4; i++)	result += temp[i];

	return result;
}

// 16진수를 10진수로
string hexToBinary(string hex) {

	string temp_s, result = "";

	for (int i = 0; i <= 1; i++) {
		int temp = (int)hex[i];

		if (temp >= 65 && temp <= 70) {
			temp -= 55;
			temp_s = convert(temp);
		}
		else if (temp >= 48 && temp <= 57) {
			temp -= 48;
			temp_s = convert(temp);
		}
		result += temp_s;
	}
	return result;
}

int getInfo(string passcode) {

	string info[] = { "3211", "2221", "2122", "1411", "1132",
					"1231", "1114", "1312", "1213", "3112" };
	
	string ratio;
	char cur = passcode[0];
	int count = 0;
	for (int i = 0; i <= passcode.length(); i++) {
		if (cur == passcode[i])
			count++;
		else {
			ratio += (char)(count+48);
			cur = passcode[i];
			count = 1;
		}
	}

	bool possible = true;

	while (possible == true) {
		for (int i = 0; i < 4; i++) {
			if (ratio[i] % 2 != 0) {
				possible = false;
				break;
			}
		}
		if (possible == true) {
			for (int i = 0; i < 4; i++) {
				ratio[i] = (((int)ratio[i] - 48) / 2 + 48);
			}
		}
	}

	for (int index = 0; index < 10; index++) {
		if (ratio.compare(info[index]) == 0)
			return index;
	}
	return -1;
}

int main() {

	int test_case;
	cin >> test_case;
	for (int case_num = 0; case_num < test_case; case_num++) {
		
		int N, M;
		cin >> N >> M;

		string *arr = new string[N];
		bool flag = false;
		int result = 0;

		for (int i = 0; i < N; i++) {
			cin >> arr[i];

			for (int z = M - 1; z >= 0; z--) {
				if (arr[i][z] != '0' && flag == false) {
					// flag를 true로 바꿔서 test case 한개 당 한 줄만 받을 수 있도록
					flag = true;

					// 2진수 암호스트링으로 변환
					string passcode;
					for (int t = 0; t < M; t += 2) {
						passcode += hexToBinary(arr[i].substr(t, 2));
					}

					// 암호스트링 뽑아내기
					int start;
					for (int j = passcode.length() - 1; j >= 0; j--) {
						if (passcode[j] != '0') {
							start = j - 55;

							// vericode의 길이가 14일 때는 start를 다르게 해줘야 함,,, 

							// 암호코드 변환
							int vericode[8];
							fill_n(vericode, 8, -1);
							int length = 7;
							for (int l = 0; l < 8; l++) {
								while (vericode[l] == -1) {
									vericode[l] = getInfo(passcode.substr(start, length));
									if(vericode[l] == -1)
										length += 7;
								}
								cout << endl;
								cout << l << " : " << vericode[l] << endl;
								start += length;
								
							}

							int sum = 0, tresult = 0;
							for (int k = 0; k < 8; k++) {
								if (k % 2 == 0 && k != 7)
									sum += vericode[k] * 3;
								else
									sum += vericode[k];
								tresult += vericode[k];
							}

							if (sum % 10 == 0)
								result = tresult;

							j -= 57;
						}
					}
				}
			}
		}
		cout << "#" << case_num + 1 << " " << result << endl;
	}

	return 0;
}