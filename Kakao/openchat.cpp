//
// Created by 양시연 on 2019/11/08.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class User{
public:
    string id;
    string name;

    User(string _id, string _name){
        id = _id;
        name = _name;
    }

};

vector<string> solution2(vector<string> record) {
    vector<string> answer;

    int idLength;
    string name, id;

    // user id, name mapping
    map <string, string> users;
    for(int i = 0; i < record.size(); i++){
        // enter
        if(record[i][0] == 'E'){
            // id의 position은 6부터
            idLength = record[i].find(" ", 6) - 6;
            id = record[i].substr(6, idLength);
            name = record[i].substr(7+idLength);
            if(users.count(id) == 0)
                users.insert(make_pair(id, name));
            else
                users[id] = name;
        }else if(record[i][0] == 'C'){
            // id의 position은 7부터
            idLength = record[i].find(" ", 7) - 7;
            id = record[i].substr(7, idLength);
            name = record[i].substr(8+idLength);
            users[id] = name;
        }
    }

    for(int i = 0; i <record.size(); i++){
        if(record[i][0] == 'E'){
            idLength = record[i].find(" ", 6) - 6;
            id = record[i].substr(6, idLength);

            answer.push_back(users[id] + "님이 들어왔습니다.");
        }else if(record[i][0] == 'L'){
            idLength = record[i].find(" ", 6) - 6;
            id = record[i].substr(6, idLength);
            answer.push_back(users[id] + "님이 나갔습니다.");
       }
    }
    return answer;
}

int main(){

    vector<string> answer = solution2({"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"});

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i];
    }
}