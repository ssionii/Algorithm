//
// Created by 양시연 on 2020/06/07.
//

#include <iostream>
#include <vector>

using namespace std;

vector <int> cards;
int N, M, maxSum = 0;

void combination(int r, int temp[], int current, int start) {
    if (r == current) {
        int sum = temp[0] + temp[1] + temp[2];
        if(sum <= M && maxSum < sum){
            maxSum = sum;
        }
    } else {
        for (int i = start; i < cards.size(); i++) {
            temp[current] = cards[i];
            combination(r, temp, current + 1, i + 1);
        }
    }
}

int main(){

    cin >> N >> M;

    int input;
    for(int i = 0 ; i < N; i++){
        cin >> input;
        cards.push_back(input);
    }

    int temp[4];
    combination(3, temp, 0, 0);


    cout << maxSum;

    return 0;
}
