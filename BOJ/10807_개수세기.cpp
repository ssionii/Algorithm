//
// Created by 양시연 on 2020/05/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int nums;
    cin >> nums;

    vector<int> v;
    int temp;
    for(int i = 0; i < nums; i++){
        cin >> temp;
        v.push_back(temp);
    }

    int look;
    cin >> look;
    sort(v.begin(), v.end());

    int count = 0;
    for(int i = 0 ;  i <nums; i++){
        if(v[i] == look){
            count++;
        }else if(v[i] > look){
            break;
        }
    }

    cout << count;


    return 0;
}