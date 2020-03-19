//
// Created by 양시연 on 08/10/2019.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {

    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for(int i = 0; i <phone_book.size()-1; i++){
        if(phone_book.at(i+1).substr(0, phone_book.at(i).length()) == phone_book.at(i)) {
            answer = false;
            break;
        }
    }
    return answer;
}

int main(){

    vector<string> phone_book;

    int pb_num;
    cout << "전화번호부의 길이를 입력해주세요"<<endl;
    cin >> pb_num;

    string temp;
    for(int i = 0; i< pb_num; i++) {
        cin >> temp;
        phone_book.push_back(temp);
    }

    cout << (bool)solution(phone_book) <<endl;
    return 0;
}