//
// Created by 양시연 on 2019/11/14.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    // 체육복을 서로 빌려주지 않았을 때 체육 수업을 들을 수 있는 학생의 수
    int answer = n - lost.size();
    int arr[31] = {0};
    for(int i = 0; i < reserve.size(); i++) arr[reserve[i]]++;

    // 본인 것 분실
    for(int i = 0; i < lost.size(); i++){
        if(arr[lost[i]] > 0) {
            arr[lost[i]]--;
            answer++;
            lost.erase(lost.begin() + i);
            i--;
        }
    }

    for(int i = 0; i < lost.size(); i++){
        if(arr[lost[i]-1] > 0){
            arr[lost[i]-1]--;
            answer++;
        }else if(arr[lost[i]+1] > 0){
            arr[lost[i]+1]--;
            answer++;
        }
    }

    return answer;
}

int main(){

    cout << solution(7,{1,2,3,4,5,6,7}, {1,2,3,4,5,6,7})<<endl;

    return 0;
}