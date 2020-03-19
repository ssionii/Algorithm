/*
	string manipulation
	2. 파일명 정렬
	2019.03.18
	by. siyeon
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class File {
	string name;
	string head = "\0";
	string number = "\0";
	int number_length = 0;
	string tail = "\0";

public:
	File() {}

	File(string input) {
		int i = 0;
		while (input[i] != '\0') {
			if (!((input[i] >= 48 && input[i] <= 57) || // 숫자
				(input[i] >= 65 && input[i] <= 90) ||   // 대문자
				(input[i] >= 97 && input[i] <= 122) ||  // 소문자
				input[i] == ' ' || input[i] == '.' || input[i] == '-' // 예외 처리
				|| input[i] == ',')) {
				cout << "영문 대소문자, 숫자, 공백, 마침표, 빼기 부호를 제외한 다른 문자가 들어갔습니다." << endl;
				exit(1);
			}
			i++;
			
		}
		int index = setHead(input);
		index = setNumber(input, index);
		setTail(input, index);

		this->name = head + number + tail;
	}

	// head setter
	int setHead(string input) {
		int count = 0;
		while (!(input[count] >= 48 && input[count] <= 57))
			count++;

		head = input.substr(0,count);

		return count;
	}

	// number setter
	int setNumber(string input, int index) {
		int count = 0;
		while ((input[index + count] >= 48 && input[index + count] <= 57)
			&& count <= 5)
			count++;

		if (count == 0) {
			cout << "NUMBER에 숫자가 하나 이상 필요합니다." << endl;
			exit(1);
		}

		number = input.substr(index, count);
		number_length = count;

		return index + count;
	}

	// tail setter
	void setTail(string input, int index) {
		int count = 0;
		while (input[index + count] != NULL) {
			count++;
		}

		tail = input.substr(index, count);
	}

	string getName() {
		return name;
	}

	string getHead() {
		transform(head.begin(), head.end(), head.begin(), tolower);
		return head;
	}

	int getNumber() {
		int temp = 0;
		for (int i = 0; i < number_length; i++) {
			temp += (number[number_length - i - 1] - 48)*pow(10, i);
		}
		return temp;
	}
};

bool compare(File &a, File &b) {
	if (a.getHead() == b.getHead())
		return a.getNumber() < b.getNumber();
	else
		return a.getHead() < b.getHead();
}

void main()
{
	string files;
	getline(cin, files);

	File * file = new File[1000];

	vector<File> v;

	int i = 0, index = 0, length = 0;
	while (1) {
		if (files[i] == ',') {
			file[index] = File((files.substr(i - length, length)));
			v.push_back(file[index]);
			index++;
			length = 0;
		}
		else if (files[i] == '\0') {
			file[index] = File((files.substr(i - length, length)));
			v.push_back(file[index]);
			index++;
			break;
		}
		else
			length++;

		i++;

		// 예외 처리
		if (length > 100) {
			cout << "파일명은 100글자 이내" << endl;
			exit(1);
		}
	}
	
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < index; i++) {
		cout << v[i].getName() << endl;
	}
}

