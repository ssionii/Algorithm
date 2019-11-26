//
// Created by 양시연 on 2019/10/24.
//

#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int temp[100001];

    stack<pair<int,int>> s;

    int index = 0;
    while(index < prices.size()){
        if(!s.empty() && prices[index] < s.top().first ){
            temp[s.top().second] = index - s.top().second;
            s.pop();

        } else {
            s.push(make_pair(prices[index], index));
            index++;
        }
    }

    while(!s.empty()) {
        temp[s.top().second] = prices.size() - s.top().second - 1;
        s.pop();
    }

    for(int i = 0; i < prices.size(); i++)
        answer.push_back(temp[i]);


    return answer;
}
