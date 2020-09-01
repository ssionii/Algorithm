//
// Created by 양시연 on 2020/08/24.
//

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    vector<int> v1(26*26, 0);
    vector<int> v2(26*26, 0);

    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    for(int i = 0; i < str1.length() - 1; i++){
        string temp = str1.substr(i, 2);
        if(isalpha(temp[0]) && isalpha(temp[1])){
            v1[(temp[0] - 65)*26 + (temp[1] - 65)]++;
        }
    }

    for(int i = 0; i < str2.length() - 1; i++){
        string temp = str2.substr(i, 2);
        if(isalpha(temp[0]) && isalpha(temp[1])){
            v2[(temp[0] - 65)*26 + (temp[1] - 65)]++;
        }
    }

    double unionCount = 0;
    double intersectionCount = 0;

    for(int i = 0; i < 26 * 26; i++){
        unionCount += max(v1[i], v2[i]);
        intersectionCount += min(v1[i], v2[i]);
    }

    if(unionCount == 0)
        answer = 65536;
    else
        answer = intersectionCount / unionCount * 65536;

    return answer;
}


//int main(){
//
//    cout << solution("aa1+aa2", "AAAA12");
//}