//
// Created by 양시연 on 2020/05/10.
//

#include <iostream>

using namespace std;

int main(){

    int time;
    cin >> time;

    int num[] = {300, 60, 10 };
    int result[] = {0 ,0, 0};

    for(int i = 0 ;  i < 3; i++){
        result[i] = time / num[i];
        time %= num[i];
    }

    if(time == 0){
        for(int i = 0; i <3; i++){
            cout << result[i] <<" ";
        }
    }else{
        cout << -1;
    }

    return 0;
}