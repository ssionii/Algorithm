//
// Created by 양시연 on 07/10/2019.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector <string> participant, vector<string> completion){

    string answer ="";
    unordered_map<string, int> hash_map;

    // hash_map 만들기
    for(int i = 0 ; i < completion.size(); i++) {
        if (!hash_map.count(completion.at(i)))
            hash_map.insert(make_pair(completion.at(i), 1));
        else
            hash_map[completion.at(i)]++;

    }

    for(int i = 0 ; i < participant.size(); i++) {
        if (hash_map.count(participant.at(i)) && hash_map[participant.at(i)] > 0 )
            hash_map[participant.at(i)]--;
        else {
            answer = participant.at(i);
            break;
        }
    }
    return answer;
}

/*
int main(){

    vector <string> participant;
    vector <string> completion;

    int participant_num;
    cout << "마라톤 경기에 참여한 선수의 수:";
    cin >> participant_num;

    string temp;
    for(int i = 0; i < participant_num; i++){
        cin >> temp;
        participant.push_back(temp);
    }

    int completion_num;
    cout << "마라톤 경기를 완주한 선수의 수:";
    cin >> completion_num;

    for(int i = 0; i < completion_num; i++){
        cin >> temp;
        completion.push_back(temp);
    }

    cout << solution(participant, completion) <<endl;

    return 0;
}*/