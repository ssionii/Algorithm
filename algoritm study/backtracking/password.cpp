#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int L, C;
vector <char> input;

void dfs(int index, int count, int vowel, int consonant, string s) {
	if (count == L) {
		if (vowel >= 1 && consonant >= 2)
			cout << s << endl;
		return;
	}
	if (index == C)
		return;

	if (input[index] == 'a' || input[index] == 'e' || input[index] == 'i' ||
		input[index] == 'o' || input[index] == 'u')
		dfs(index + 1, count + 1, vowel + 1, consonant, s + input[index]);
	else
		dfs(index + 1, count + 1, vowel, consonant + 1, s + input[index]);
	dfs(index + 1, count, vowel, consonant, s);

}

int main()
{
	// ют╥б
	cin >> L >> C;

	char temp;
	for (int i = 0; i < C; i++) {
		cin >> temp;
		input.push_back(temp);
	}

	sort(input.begin(), input.end());

	dfs(0, 0, 0, 0, "");

	return 0;
}
