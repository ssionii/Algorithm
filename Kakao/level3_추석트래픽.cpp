//
// Created by 양시연 on 2020/05/07.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<long long, long long> calculateStartTime(string endTime, string processTime){
    long long time = 0;
    time += stoi(endTime.substr(0, 2)) * 60 * 60 * 1000;
    time += stoi(endTime.substr(3, 2)) * 60 * 1000;
    time += stoi(endTime.substr(6, 2)) * 1000;
    time += stoi(endTime.substr(9, 3));

    double pTime = stod(processTime.substr(0, processTime.length() - 1))*1000;
    long long startTime = time - pTime + 1;

    return make_pair(startTime, time);
}

int solution(vector<string> lines) {
    vector<pair<long long, long long>> timeLine;

    for(int i = 0; i < lines.size(); i++) {
        timeLine.push_back(calculateStartTime(lines[i].substr(11,12), lines[i].substr(24)));
    }

    int max = 0;
    for(int i = 0;  i <timeLine.size(); i++){
        long long start = timeLine[i].first;
        long long startTemp = timeLine[i].first + 1000 - 1;
        long long end = timeLine[i].second;

        int count = 0;
        for(int index = 0; index < timeLine.size(); index++){
            if((timeLine[index].first <= startTemp && timeLine[index].first >= start)
            || (timeLine[index].second <= startTemp && timeLine[index].second >= start)) {
                count++;
            }else if(timeLine[index].first < start && timeLine[index].second > end){
                count++;
            }
        }

        if(max < count){
            max = count;
        }
    }

    for(int i = 0;  i <timeLine.size(); i++){
        long long start = timeLine[i].first;
        long long end = timeLine[i].second;
        long long endTemp = timeLine[i].second + 1000 -1;

        int count = 0;
        for(int index = 0; index < timeLine.size(); index++){
            if((timeLine[index].first <= endTemp && timeLine[index].first >= end)
                     || (timeLine[index].second <= endTemp && timeLine[index].second >= end)){
                count++;
            }else if(timeLine[index].first < start && timeLine[index].second > end){
                count++;
            }
        }

        if(max < count){
            max = count;
        }
    }

    return max;
}

int main(){

    solution({"2016-09-15 20:59:57.421 0.351s",
    "2016-09-15 20:59:58.233 1.181s",
    "2016-09-15 20:59:58.299 0.8s",
    "2016-09-15 20:59:58.688 1.041s",
    "2016-09-15 20:59:59.591 1.412s",
    "2016-09-15 21:00:00.464 1.466s",
    "2016-09-15 21:00:00.741 1.581s",
    "2016-09-15 21:00:00.748 2.31s",
    "2016-09-15 21:00:00.966 0.381s",
    "2016-09-15 21:00:02.066 2.62s"});
    return 0;
}