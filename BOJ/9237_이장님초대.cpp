//
// Created by 양시연 on 2020/06/02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int N;
    cin >> N;

    vector<int> trees;

    int input;
    for(int i = 0; i < N; i++){
        cin >> input;
        trees.push_back(input);
    }

    sort(trees.begin(), trees.end(), greater<int>());

    int max = 0;
    for(int i = 0 ; i < trees.size(); i++){
        if(max < trees[i] + i + 1) max = trees[i] + i + 1;
    }

    cout << max + 1;

    return 0;
}