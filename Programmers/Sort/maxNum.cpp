//
// Created by 양시연 on 2019/11/05.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &s1, const string &s2){

    int digit1 = s1.length();
    int digit2 = s2.length();

    // 자리수가 같은 경우
    if(digit1 == digit2){
        return s1 > s2;
    }
    // 자리수가 다른 경우
    int big, small;
    if(digit1 > digit2){
        big = digit1;
        small = digit2;
    }else{
        big = digit2;
        small = digit1;
    }

    // 각 자리의 수 비교

    int i;
    for(i = 0; i < small; i++){
        // 맨앞자리 다르면 바로 return
        if(s1[i] != s2[i]) {
            return s1[i] > s2[i];
        }
    }
    for(int j = i; j < big; j++) {
        if (digit1 > digit2) {
            if (s1[j] != s2[j-i]) {
                return s1[j] > s2[j-i];
            }
        }else{
            if (s2[j-i] != s1[j]) {
                return s2[j-i] > s1[j];
            }
        }
    }


    return true;
}

string solution2(vector<int> numbers) {
    string answer = "";
    vector <string> v;

    bool allZero = true;

    // int를 string으로 변환
    for(int i = 0; i <numbers.size(); i++){
        v.push_back(to_string(numbers[i]));
        if(allZero && numbers[i] != 0){
            allZero = false;
        }

    }

    if(allZero) return"0";

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < v.size(); i++){
        answer+=v.at(i);
    }

    return answer;
}

int main(){

    cout << solution2({5435,543552});

}