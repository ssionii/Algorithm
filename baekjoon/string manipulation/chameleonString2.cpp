#include <iostream>
#include <string>

using namespace std;

int* fail(string s) {
	int i = 1, j = 0, m = s.size();
	int *f = new int[m];

	f[0] = -1;

	while (i < m) {
		if (s[j] == s[i]) {
			f[i++] = j++;
		}
		else if (j > 0) { // 패턴의 앞부분이 일치
			j = f[j - 1] + 1;
		}
		else
			f[i++] = -1;
	}
	return f;
}

int main() {
	
	string str;
	getline(cin, str);

	int *f = fail(str);
	int temp = f[str.size() - 1], result = 0;
	if (temp != 0) {
		if ((str.substr(0, temp + 1).compare(str.substr(str.size() - temp-1, temp + 1))) == 0) {
			while (temp > 0) {
				for (int i = 0; i < str.size()-1; i++) {
					if (f[i] == temp) {
						result = temp;
						break;
					}
				}
				if (result != 0)
					break;
				temp = f[temp];
			}
			if (temp > 0)
				cout << str.substr(0, temp + 1) << endl;
			else
				cout << -1 << endl;
		}
		
	}
	else
		cout << -1 << endl;



	return 0;
}