#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DataSet {
	string data;
	int count;
	bool isStable;
public:

	DataSet(){}

	DataSet(string data) {
		this->data = data;
		count = 0;
		isStable = false;
	}

	// �� ������ }�̰ų� �� �������� {�� ��
	void checkEdge() {
		if (data[0] == '}') {
			count++;
			data[0] = '{';
		}
		
		if (data[data.size() - 1] == '{') {
			count++;
			data[data.size() - 1] = '}';
		}
	}

	// ¦���� ã��
	bool checkPair() {
		int index = 0;
		string temp1, temp2;
		bool firstClose = true;

		// ���� ���ʿ� �ִ� '{'�� ã��
		while (data[index] == '{') {
			index++;
			firstClose = false;
		}
		
		// {�� ��ġ�� index��
		if (index != 0 && index != data.size())
			index--;
		// ó������ }
		else if (index == 0 && firstClose == true);

		if (data.size() == 2) {
			if (firstClose == false)
				isStable = true;
			return false;
		}

		// {�� ����
		if (index == data.size())
			return false;
		// ÷���� {}
		else if (index == 0) {
			if (firstClose == false) {
				data = data.substr(index + 2, data.size() - index);
				return true;
			}
			else
				return false;
		}


		temp1 = data.substr(0,index);
		temp2 = data.substr(index + 2, data.size() - index);
		data = temp1 + temp2;


		return true;
	}

	int getCount() {

		while (!isStable) {
			if (checkPair() == false) {
				checkEdge();
			}
		}
		return count;
	}
};


int main()
{
	string input = "";
	int index = 0;

	vector<DataSet> v;

	while (input.find("-", 0) == string::npos) {
		cin >> input;
		v.push_back(DataSet(input));
	}

	for (int i = 0; i < v.size()-1; i++) {
		cout << i+1 << ". " << v.at(i).getCount();
		cout << endl;
	}

	return 0;
}