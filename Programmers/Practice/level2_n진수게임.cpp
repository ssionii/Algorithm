//
// Created by 양시연 on 2020/08/28.
//

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

string transform(int number, int n){
    string result = "";

    int share = number;

    do {
        if (share % n < 10) {
            result += to_string(share % n);
        }else{
            result += char(55 + (share % n));
        }
        share /= n;

    }while(share != 0);

    reverse(result.begin(), result.end());

    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    double count = 0;
    int index = 0;
    while(t * m >= count){
        if(index == 0){
            count += n;
        }else{
            count += (n-1) * pow(n, index);
        }
        index++;
    }

    string str = "";

    for(int i = 0 ; i < count; i++){
        str += transform(i, n);
    }


    for(int i = 0;  i < t; i++){
        answer  += str[(m * i) + p -1];
    }

    return answer;
}

//int main(){
//
//    cout << solution(16, 16, 2, 2);
//}