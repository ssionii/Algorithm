#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int getInfo(string passcode) {

	string info[] = { "0001101", "0011001", "0010011", "0111101", "0100011",
					"0110001", "0101111", "0111011", "0110111", "0001011" };
	
	for (int index = 0; index < 10; index++) {
		if(passcode.compare(info[index]) == 0)
			return index;
	}
}

int main()
{
	int test_case;
	cin >> test_case;

	for (int case_num = 0; case_num < test_case; case_num++) {
		int n, m;
		cin >> n >> m;

		string *arr = new string[n];
		bool flag = false;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		
			if (arr[i].find("1", 0) != string::npos && flag == false) {
				flag = true;
				string temp;
				for (int j = m - 1; j >= 0; j--) {
					if (arr[i][j] == '1') {
						temp = arr[i].substr(j - 55, 56);
						break;
					}
				}

				string passcode[8];
				int vericode[8];
				int start = 0;
				for (int k = 0; k < 8; k++) {
					passcode[k] = temp.substr(start, 7);
					vericode[k] = getInfo(passcode[k]);
					start += 7;
				}


				int sum = 0, result = 0;
				for (int k = 0; k < 8; k++) {
					if (k % 2 == 0 && k != 7)
						sum += vericode[k] * 3;
					else
						sum += vericode[k];
					result += vericode[k];
				}

				if (sum % 10 != 0)
					result = 0;
			
				cout << "#" << case_num+1 << " " << result << endl;
			}
			
		}

		
	}
}