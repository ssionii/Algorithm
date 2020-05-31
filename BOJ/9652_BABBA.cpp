//
// Created by 양시연 on 2020/05/31.
//

#include <iostream>

using namespace std;

int a[46], b[46];

int main(){

    int k;
    cin >> k;

    a[1] = 0, b[1] = 1;
    a[2] = 1, b[2] = 1;
    a[3] = 1, b[3] = 2;

    for(int i = 4; i<= k; i++){
        a[i] = a[i-1] + a[i-2];
        b[i] = b[i-1] + b[i-2];
    }

    cout << a[k] << " " << b[k];

    return 0;
}