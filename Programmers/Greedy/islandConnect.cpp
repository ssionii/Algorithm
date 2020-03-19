//
// Created by 양시연 on 2019/11/26.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int find(int x, int *root){
    if(root[x] == x){
        return x;
    }else{
        return root[x] = find(root[x], root);
    }
}

bool union_(int x_, int y_, int *root){
    int x = find(x_, root);
    int y = find(y_, root);

    if(x == y)
        return false;

    root[y] = x;
    return true;
}

bool cmp(const vector<int> &v1,const vector<int> &v2){
    return v1[2] < v2[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    // 오름차순으로 정렬
    sort(costs.begin(), costs.end(), cmp);

    // Disjoint Set 생성
    int root[n];
    for(int i = 0; i < n; i++) root[i] = i;

    for(int i = 0; i < costs.size(); i++){
        // 사이클이 있는지 체크
        if(union_(costs[i][0], costs[i][1], root)){
            answer+= costs[i][2];
        }
    }
    return answer;
}

int main(){
    cout << solution(6, {{0,1,5},{0,3,2},{0,4,3},{1,4,1},{3,4,10}, {1,2,2}, {2,5,3}, {4,5,4}});
}