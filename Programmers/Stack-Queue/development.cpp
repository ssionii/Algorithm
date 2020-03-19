//
// Created by 양시연 on 2019/10/17.
//

#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue <int> q;
    for(int i = 0; i < progresses.size(); i++) q.push(progresses[i]);

    double time, temp;
    int index = 0;
    int count = 0;

    time = (100.0 - q.front()) / speeds[index];
    if(time - int(time/1) > 0) time = int(time/1) + 1;

    while(index < progresses.size()) {

        temp = (100.0 - progresses[index]) - (speeds[index] * time);
        if (temp <= 0) {
            count++;
            q.pop();
        } else {
            time = (100.0 - progresses[index]) / speeds[index];
            if (time - int(time / 1) > 0) time = int(time / 1) + 1;

            answer.push_back(count);
            count = 1;
        }
        index++;
    }

    answer.push_back(count);
    return answer;
}