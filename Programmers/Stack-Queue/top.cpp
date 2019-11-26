//
// Created by 양시연 on 2019/10/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;

    // stack에 건물의 높이와 위치 저장
    stack <pair<int, int>> s;
    for(int i = 0; i < heights.size(); i++) s.push(make_pair(heights[i], i+1));

    pair<int, bool> temp[100];
    fill_n(temp, heights.size()+1 ,make_pair(101, true));

    while(!s.empty()) {
        temp[s.top().second].first = s.top().first;
        s.pop();

        for (int i = heights.size(); i > 0; i--) {
            if (!s.empty() && temp[i].second && // empty를 여기서 한번 더 검사하지 않는 방법은 없나?
                temp[i].first < s.top().first) {
                temp[i] = make_pair(s.top().second, false);
            }
        }
    }

    for(int i = 1; i <= heights.size(); i++){
        if(!temp[i].second) answer.push_back(temp[i].first);
        else answer.push_back(0);
    }
    return answer;
}

int main(){

    vector <int> heights = {6,9,5,7,4};
    vector <int> answer =  solution(heights);

    for(int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";

    return 0;
}