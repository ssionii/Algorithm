//
// Created by 양시연 on 2020/05/22.
//

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    if(n == 1){
        answer.push_back(0);
        return answer;
    }


    int length = 0;
    for(int i = 0 ;  i < n; i++) length += pow(2, i);
    int *arr = new int[length];
    fill_n(arr, length, -1);

    vector<pair<int, int>> temp;
    for(int i = 0 ;  i < length; i += 4){
        if(i % 2 == 0){
            arr[i] = 0;
            arr[i + 2] = 1;
            temp.push_back(make_pair(i, i+2));

        }
    }

    vector<pair<int, int>> newTemp;

    while(1) {
        int left, right;
        for (int i = 0; i < temp.size(); i+=2) {
            left = (temp[i].first + temp[i].second) / 2;
            arr[left] = 0;
            right = (temp[i + 1].first + temp[i + 1].second) / 2;
            arr[right] = 1;
            newTemp.push_back(make_pair(temp[i].first, temp[i+1].second));
        }
        temp = newTemp;
        newTemp.clear();

        if(arr[length/2] != -1)
            break;
    }

    for(int i = 0 ;  i < length; i++){
        answer.push_back(arr[i]);
        cout << arr[i]<<" ";
    }

    return answer;
}
//
//int main(){
//
//    solution(3);
//
//
//    return 0;
//}