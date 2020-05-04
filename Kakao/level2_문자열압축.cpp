//
// Created by 양시연 on 2020/05/05.
//

#include <iostream>
#include <string>

using namespace std;

int solution(string s) {

    int catNum = s.size() / 2;
    int index = 0, count = 1;
    string compStr;
    string temp = "", result = s;
    for(int l = 1; l <= catNum; l++){
        while(index < s.size()) {
            compStr = s.substr(index, l);
            if(compStr.size() < l){
                temp += compStr;
                break;
            }
            index += l;

            while (compStr == s.substr(index, l)) {
                count++;
                index += l;
            }

            if(count != 1){
                temp += to_string(count) + compStr;
            }else{
                temp += compStr;
            }

            count = 1;
        }
        if(result.size() > temp.size())
            result = temp;

        index = 0;
        temp = "";

    }

    return result.size();
}

int main(){

    cout << solution("xababcdcdababcdcd")<<endl;

    return 0;
}