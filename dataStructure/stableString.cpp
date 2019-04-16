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

	// 맨 왼쪽이 }이거나 맨 오른쪽이 {일 때
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

	// 짝꿍을 찾음
	bool checkPair() {
		int index = 0;
		string temp1, temp2;
		bool firstClose = true;

		// 가장 안쪽에 있는 '{'을 찾음
		while (data[index] == '{') {
			index++;
			firstClose = false;
		}
		
		// {의 위치를 index로
		if (index != 0 && index != data.size())
			index--;
		// 처음부터 }
		else if (index == 0 && firstClose == true);

		if (data.size() == 2) {
			if (firstClose == false)
				isStable = true;
			return false;
		}

		// {가 없음
		if (index == data.size())
			return false;
		// 첨부터 {}
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