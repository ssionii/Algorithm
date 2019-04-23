#include <iostream>
#include <string>
#include <map>

using namespace std;

class Security {
	string *first_key;
	string *second_key;
	string *cryptogram;
	//string *plain;
	int *rule;
	int num;

public:
	Security(){}

	Security(int n, string *f, string *s, string *c){
		first_key = f;
		second_key = s;
		cryptogram = c;
		num = n;
		//plain = new string[num];
	}

	// ±ÔÄ¢
	void setRule() {
		rule = new int[num];
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				if (first_key[i] == second_key[j]) {
					rule[i] = j;
					break;
				}
			}
		}


	}

	string getPlainText(int i) {
		return cryptogram[rule[i]];
	}

	int getNum() {
		return num;
	}
};

int main()
{
	int test_case;
	cin >> test_case;

	Security *security = new Security[test_case];

	for (int i = 0; i < test_case; i++) {
		Security temp;
		int word_num;
		cin >> word_num;

		string *first_key = new string[word_num];
		string *second_key = new string[word_num];
		string *cryptogram = new string[word_num];
		for (int j = 0; j < word_num; j++)
			cin >> first_key[j];
		for (int j = 0; j < word_num; j++)
			cin >> second_key[j];
		for (int j = 0; j < word_num; j++)
			cin >> cryptogram[j];

		temp = Security(word_num, first_key, second_key, cryptogram);
		
		security[i] = temp;
		security[i].setRule();
	}

	for (int i = 0; i < test_case; i++) {
		for(int j = 0; j <security[i].getNum(); j++)
			cout << security[i].getPlainText(j) << " ";
		cout << endl;
	}

	return 0;
}