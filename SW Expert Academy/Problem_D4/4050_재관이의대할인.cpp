//
// Created by 양시연 on 2020/05/03.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int testNum = 0;
    cin >> testNum;

    for(int index = 1; index <= testNum; index++){
        int n;
        cin >> n;

        vector<int> clothes;
        for(int i = 0;  i < n; i++){
            int temp;
            cin >> temp;
            clothes.push_back(temp);
        }

        sort(clothes.begin(), clothes.end(), greater<int>());
        int sum = 0;
        for(int i = 0 ; i < clothes.size(); i++){
            if(i % 3 != 2){
                sum += clothes[i];
            }
        }

        cout << "#" << index << " "<< sum<<endl;
    }

    return 0;
}