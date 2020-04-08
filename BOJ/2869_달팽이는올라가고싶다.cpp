//
// Created by 양시연 on 2020/04/09.
//

#include <iostream>

using namespace std;

long A, B, V;

int main(){

    cin >> A >> B >> V;

    long lastDay = (V - A) % (A - B);
    long oneDay = (V - A) / (A - B);
    if(lastDay != 0){
        cout << oneDay + 2 <<endl;
    }else{
        cout << oneDay + 1<<endl;
    }

    return 0;
}