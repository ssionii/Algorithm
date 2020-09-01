//
// Created by 양시연 on 2020/08/30.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int makeToMinTime(string time){
    return stoi(time.substr(0, 2)) *  60 + stoi(time.substr(3, 2));
}

bool cmp(string a, string b){
    return makeToMinTime(a) < makeToMinTime(b);
}


string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    vector<string> shuttleTimeTable;
    shuttleTimeTable.push_back("09:00");

    // 셔틀버스 시간표
    for(int i = 1; i < n; i++){

        int hour = stoi(shuttleTimeTable[i-1].substr(0, 2));
        int min = stoi(shuttleTimeTable[i-1].substr(3, 2));

        if(min + t >= 60){
            hour++;
            min += t - 60;
        }else{
            min += t;
        }

        string time = "";
        if(hour < 10) time += "0" + to_string(hour);
        else time += to_string(hour);
        if(min < 10) time += ":0" + to_string(min);
        else time += ":" + to_string(min);

        shuttleTimeTable.push_back(time);
    }

    sort(timetable.begin(), timetable.end(), cmp);

    for(int i = 0 ; i < shuttleTimeTable.size(); i++){
        int count = 0;

        while(i != shuttleTimeTable.size() - 1 && count < m && timetable.size() != 0 &&
              makeToMinTime(shuttleTimeTable[i]) >= makeToMinTime(timetable[0])){
            count++;
            timetable.erase(timetable.begin());
        }

        if(i == shuttleTimeTable.size() - 1){

            vector<string> lastPeople;

            while(count < m && timetable.size() != 0 &&
                  makeToMinTime(shuttleTimeTable[i]) >= makeToMinTime(timetable[0])){
                count++;
                lastPeople.push_back(timetable[0]);
                timetable.erase(timetable.begin());
            }

            if(lastPeople.size() < m){
                answer = shuttleTimeTable[i];

                break;
            }else {

                int hour = stoi(lastPeople[lastPeople.size() -1].substr(0, 2));
                int min = stoi(lastPeople[lastPeople.size() -1].substr(3, 2));

                if(min - 1 < 0){
                    hour -= 1;
                    min = 59;
                }else{
                    min--;
                }

                if(hour < 10) answer += "0" + to_string(hour);
                else answer += to_string(hour);
                if(min < 10) answer += ":0" + to_string(min);
                else answer += ":" + to_string(min);

                break;
            }
        }

    }


    return answer;
}

int main(){

    cout << "정답 : " << solution(2, 1, 3, {"09:00", "09:00", "09:00", "09:00"});

}