//
// Created by 양시연 on 2019/11/27.
//

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;

    sort(routes.begin(), routes.end());

    int camera = routes[0][1];
    for(int i = 0;  i <routes.size()-1; i++){
        if(camera > routes[i][1])
            camera = routes[i][1];
        if(camera < routes[i+1][0]) {
            answer++;
            camera = routes[i+1][1];
        }
    }


    return answer;
}

int main(){

    cout << solution({{-20,15}, {-14,-5}, {-18,-13}, {-5,-3}});
}