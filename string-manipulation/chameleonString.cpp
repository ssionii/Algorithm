#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getPi(string p) {
	int m = p.size(), j = 0;
	vector<int> pi(m, 0);
                                                                                                                                                              
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}

	return pi;
}

int* kmp(string s, string p) {
	auto pi = getPi(p);
	int n = s.size(), m = p.size(), j = 0;
	int *arr = new int[n];

	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j])
				j++;
		arr[i] = j;
		if (j == m)
			j = pi[j-1];
	}
	return arr;
}

int main()
{
	string str;
	getline(cin, str);

	string stemp;
	int *arr; int max, result = 0;
	for (int i = 1; i < str.size(); i++) {
		stemp = str.substr(0, i);
		
		// 접두사가 접미사인지 확인
		if (stemp.compare(str.substr((str.size() - i), i)) == 0) {
			arr = kmp(str, stemp);
			max = arr[stemp.size() - 1];
			// 접두사와 접미사가 문자열 중간에도  있는지 확인
			for (int j = 0; j < str.size() - 1; j++) {
				if (arr[j] == max && j != max - 1 && result < max) {
					result = max;
				}
			}
		}
	}
	if (result != 0) {
		cout << str.substr(0, result) << endl;
	}
	else
		cout << -1 << endl;

	return 0;
}