//
// Created by 양시연 on 2020/05/17.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int studentNum, K;
    cin >> studentNum >> K;

    int gender, grade;
    int count = 0;

    int student[13];
    fill_n(student, 13, 0);
    for(int i = 1; i <= studentNum; i++){
        cin >> gender >> grade;
        if(gender == 0) student[(grade) * 2 - 1]++;
        else student[grade * 2]++;
    }

    for(int i = 1 ;  i <= 12; i++){
        if(student[i] % K == 0) count += student[i] / K;
        else count += (student[i] / K) + 1;
    }

    cout << count;

    return 0;
}