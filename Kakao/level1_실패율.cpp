//
// Created by 양시연 on 2020/05/05.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check[501];

bool compare(pair<int, double> a, pair<int, double> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;

}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> failure;

    fill_n(check, 501, false);
    sort(stages.begin(), stages.end());

    double sum = 1;

    for(int i = 0 ;  i < stages.size(); i++){
        int level = stages[i];
        if(stages[i] != stages[i+1] && level <= N) {
            failure.push_back(make_pair(level, sum / (stages.size() - ( i +1 ) + sum)));
            sum = 1;

            check[level] = true;
        }else{
            sum++;
        }
    }

    for(int i = 1 ; i <= N; i++){
        if(!check[i])
            failure.push_back(make_pair(i, 0));
    }

    sort(failure.begin(), failure.end(), compare);

    for(int i = 0 ; i < failure.size(); i++){
        answer.push_back(failure[i].first);
    }

    return answer;
}

int main(){
    int N = 4;
    vector<int> answer = solution(N, {4, 4, 4, 4, 4} );

    for(int i = 0; i < N; i++){
        cout << answer[i] << " ";
    }

    return 0;
}