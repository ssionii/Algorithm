//
// Created by 양시연 on 2020/05/31.
//

#include <iostream>

using namespace std;

double score[1001];

int main(){

    int n;
    cin >> n;

    double max = 0;
    for(int i = 0 ;  i < n ; i++){
        cin >> score[i];

        if(max < score[i])
            max = score[i];
    }

    double sum = 0;
    for(int i = 0 ; i < n ; i ++){
        score[i] = score[i] / max * 100.0;
        sum += score[i];
    }

    cout << sum / n;

    return 0;
}