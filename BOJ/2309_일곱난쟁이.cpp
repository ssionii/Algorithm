//
// Created by 양시연 on 2020/06/01.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int input[10];

int main(){

    int temp, sum =0;
    for(int i = 0; i < 9; i++){
        cin >> input[i];
        sum += input[i];
    }

    sum = sum - 100;

    bool isDone = false;

    for(int i = 0; i < 8; i++){
        if(isDone) break;
        for(int j = i+1; j < 9; j++){
            if(input[i] + input[j] == sum){
                input[i] = 0;
                input[j] = 0;
                isDone = true;
            }
        }
    }

    vector<int> v;
    for(int i = 0;  i < 9; i++){
        if(input[i] != 0){
            v.push_back(input[i]);
        }
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < 7; i++){
        cout << v[i] << endl;
    }

    return 0;
}