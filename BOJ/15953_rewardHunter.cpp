//
// Created by 양시연 on 2020/03/23.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {


    vector<int> firstFestival;
    int firstFestivalReward[6] = {500, 300, 200, 50, 30, 10};

    int level = 1;
    while (level <= 6) {
        for (int j = 0; j < level; j++) {
            firstFestival.push_back(firstFestivalReward[level - 1]);
        }
        level++;
    }

    vector<int> secondFestival;
    int secondFestivalReward[5] = {512, 256, 128, 64, 32};

    level = 1;
    while (level <= 5) {
        for (int j = 0; j < pow(2, level-1); j++) {
            secondFestival.push_back(secondFestivalReward[level-1]);
        }
        level++;
    }


    int N;
    cin >> N;

    int firstExpect, secondExpect;
    vector<int> result;
    int tempResult;
    for(int i = 0; i < N; i++){
        tempResult = 0;
        cin >> firstExpect >> secondExpect;
        if(!firstExpect == 0 && firstExpect <= firstFestival.size()){
            tempResult = firstFestival.at(firstExpect-1);
        }

        if(!secondExpect == 0 && secondExpect <= secondFestival.size()){
            tempResult += secondFestival.at(secondExpect-1);
        }

        result.push_back(tempResult);
    }

    for(int i = 0; i < result.size(); i++)
        cout << result.at(i) * 10000 << endl;
    return 0;
}