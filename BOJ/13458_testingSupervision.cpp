//
// Created by 양시연 on 2020/03/19.
//
#include <iostream>

using namespace std;

int main(){

    int N; // 시험장의 개수
    cin >> N;

    // 학생 수 리스트
    long long* students = new long long[N];
    for(int i= 0 ; i < N; i++){
        cin >> students[i];
    }

    int B, C; // 총감독관과 부감독관이 감시가능한 응시자의 수
    cin >> B >> C;

    int temp = 0;
    long long supervisionNum = 0;
    for(int i = 0; i < N; i++){
        supervisionNum += 1;
        temp = students[i] - B;
        if(temp > 0){
            if(temp % C > 0) supervisionNum += (temp / C) + 1;
            else supervisionNum += (temp / C);
        }
    }
    cout << supervisionNum << endl;

    return 0;
}