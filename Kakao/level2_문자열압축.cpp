//
// Created by 양시연 on 2020/05/05.
//

#include <iostream>
#include <string>

using namespace std;

int solution(string s) {

    string result = s;

    for(int l = 1; l <= s.size() / 2; l++){
        int index = 0;
        string temp = "";
        while(index < s.size()) {
            int count = 1;

            string compStr = s.substr(index, l);
            if(compStr.size() < l){
                temp += compStr;
                break;
            }

            index += l;

            while (compStr == s.substr(index, l)) {
                count++;
                index += l;
            }

            if(count != 1) temp += to_string(count) + compStr;
            else temp += compStr;
        }
        if(result.size() > temp.size())
            result = temp;
    }

    return result.size();
}

int main(){

    cout << solution("xababcdcdababcdcd")<<endl;

    return 0;
}