//
// Created by 양시연 on 2019/10/22.
//

#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    queue <int> q;
    int weight_sum = truck_weights[0];
    int time = 1;
    int index = 1;
    q.push(truck_weights[0]);

    while(index < truck_weights.size()){
        if(weight_sum + truck_weights[index] <= weight
            && q.size() < bridge_length){
            q.push(truck_weights[index]);
            weight_sum += truck_weights[index++];
        }
        else
            q.push(0);

        if(q.size() == bridge_length) {
            weight_sum -= q.front();
            q.pop();
        }
        time++;
    }

    return time+bridge_length;
}
