//
// Created by 양시연 on 2020/04/09.
//

#include <iostream>

using namespace std;

int N, M;

int main(){

    cin >> N >> M;
    long long *trees = new long long[N];

    int maxLength = 0;
    for(int i = 0; i < N; i++){
        cin >> trees[i];
        if(trees[i] > maxLength)
            maxLength = trees[i];
    }

    long long left = 1, right = maxLength;
    long long mid, result = 0;

    while(left <= right) {
        mid = (left + right) / 2;
//
//        cout << "left : " << left ;
//        cout << " right : " << right ;
//        cout << " mid : " << mid <<endl;


        for(int i = 0; i < N; i++){
            if(mid < trees[i]) {
                result += trees[i] - mid;
            }
        }
//
//        cout << "result : " << result <<endl;

        if(result < M){
            right = mid - 1;
        }else{
            left = mid + 1;
        }

        result = 0;
    }

    cout << right <<endl;

    return 0;
}