//
// Created by 양시연 on 2019/10/28.
//

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue <int, vector<int>, greater<int>> heap;
    for(int i = 0; i <scoville.size(); i++) heap.push(scoville[i]);

    int count = 0;
    int new_scoville;

    while(!heap.empty() && heap.top() < K) {

        new_scoville = heap.top();
        heap.pop();
        if(!heap.empty()) {
            new_scoville += heap.top() * 2;
            heap.pop();
        }else{
            return -1;
        }

        heap.push(new_scoville);
        count++;
    }

    return count;
}
