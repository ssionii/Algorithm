//
// Created by 양시연 on 2020/08/28.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> dictionary;

vector<int> solution(string msg) {
    vector<int> answer;
    string alpha = "A";

    // 사전 초기화
    for(int i = 1 ;  i <= 26; i++){
        dictionary.push_back(alpha);
        alpha[0]++;
    }

    string temp;
    int i;
    auto index = 0;
    for(i = 0 ; i < msg.length(); i++) {
        auto it = std::find(dictionary.begin(), dictionary.end(),msg.substr(0, i + 1));
        if(it != dictionary.end()){
            temp = msg.substr(0, i + 1);
            index = std::distance(dictionary.begin(), it);

        }else{
            answer.push_back(index + 1);
            dictionary.push_back(msg.substr(0, i + 1));

            msg.erase(0, i);
            i = -1;
        }
    }

    answer.push_back(index + 1);

    return answer;
}
//
//int main(){
//
//
//    vector<int> answer = solution("TOBEORNOTTOBEORTOBEORNOT");
//    for(int i = 0 ; i < answer.size(); i++){
//        cout << answer[i] << " ";
//    }
//
//    return 0;
//}