//
// Created by 양시연 on 2020/09/02.
//

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    vector<int> score;

    int numIdx = 0;
    for(int i = 0; i < dartResult.size(); i++){
        if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T'){
            int tempScore = stoi(dartResult.substr(numIdx , i - numIdx));
            switch (dartResult[i]){
                case 'D':
                    tempScore = pow(tempScore, 2);
                    break;
                case 'T':
                    tempScore = pow(tempScore, 3);
                    break;
            }

            score.push_back(tempScore);
            numIdx = i + 1;
        }

        if(dartResult[i] == '*'){
            score[score.size() - 1] *= 2;
            if(score.size() - 2 >= 0) score[score.size() - 2] *= 2;

            numIdx = i + 1;
        }

        if(dartResult[i] == '#'){
            score[score.size() - 1] *= -1;
            numIdx = i + 1;
        }
    }

    for(int i = 0; i < score.size(); i++){
        answer += score[i];
    }

    return answer;
}

int main(){

    cout << solution("1D2S3T*") << endl;
}