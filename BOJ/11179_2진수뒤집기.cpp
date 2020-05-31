//
// Created by 양시연 on 2020/05/31.
//

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

    string s ="";
    long long input;

    cin >> input;
    while(input >1){
        if(input % 2 == 1) s+='1';
        else s+='0';
        input /= 2;
    }
    s += '1';

    reverse(s.begin(), s.end());

    long long result = 0;
    for(int i = 0;  i < s.length(); i++){
        if(s[i] == '1') result += pow(2, i);
    }

    cout << result;

    return 0;
}