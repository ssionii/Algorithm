//
// Created by 양시연 on 2020/08/26.
//

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class MusicInfo{
public :
    int playingTime;
    string title;
    string codes;

    MusicInfo(int time, string title, string codes){
        this->playingTime = time;
        this->title = title;
        this->codes = codes;
    }
};

bool cmp(MusicInfo a, MusicInfo b){
    return a.playingTime > b.playingTime;
}

int getPlayingTime(string startTime, string endTime){
    int hour = stoi(endTime.substr(0, 2)) - stoi(startTime.substr(0, 2));
    int minute = stoi(endTime.substr(3, 5)) - stoi(startTime.substr(3, 5));

    return hour * 60 + minute;
}

string changeCode(string inputCodes){
    string resultCode = inputCodes;

    string codes[] = { "C#","D#", "F#", "G#", "A#", "E#","C", "D", "E", "F", "G", "A","B"};
    for(int i = 0 ; i < (sizeof(codes) / sizeof(codes[0])); i++){

        string::size_type n = resultCode.find(codes[i]);

        while(n != string::npos){
            resultCode[n] = i + 97;
            if(codes[i].length() > 1) resultCode.erase(n + 1, 1);
            n = resultCode.find(codes[i]);
        }
    }

    return resultCode;
}

string getCodes(int time, string inputCodes){

    string changedCode = changeCode(inputCodes);

    string result = "";
    int i = 0, index = 0;
    while(i < time) {
        if(index + 1 < changedCode.length() && changedCode[index + 1] == '#'){
            result += changedCode[index] + changedCode[index + 1];
            index++;
            i++;
        }else {
            result += changedCode[index];
        }

        i++;
        index++;
        if(changedCode.length() == index) index = 0;
    }

//    cout << "라디오에서 나온 코드" << result << endl;
    return result;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";

    vector<MusicInfo> musicInfos;
    for(int i = 0; i < musicinfos.size(); i++){

        // split
        vector<string> temp;
        istringstream ss(musicinfos[i]);
        string stringBuffer;
        while (getline(ss, stringBuffer, ','))
        {
            temp.push_back(stringBuffer);
        }


        MusicInfo musicInfo = MusicInfo(getPlayingTime(temp[0], temp[1]), temp[2],
                getCodes(getPlayingTime(temp[0], temp[1]), temp[3]));
        musicInfos.push_back(musicInfo);
    }

    sort(musicInfos.begin(), musicInfos.end(), cmp);

    string userCode = changeCode(m);
//    cout << "사용자가 들은 코드" << userCode << endl;

    bool findMusic = false;
    for(int i = 0 ; i < musicInfos.size(); i++){
        if(musicInfos[i].codes.find(userCode) != string::npos){
            answer = musicInfos[i].title;
            findMusic = true;
            break;
        }
    }

    if(!findMusic){
        answer = "(None)";
    }


    return answer;
}
//
//int main(){
//    cout << solution("ABCD", {"03:00,03:04,FOO,ABCDE#"});
//}
//
