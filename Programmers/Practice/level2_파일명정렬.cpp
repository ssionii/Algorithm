//
// Created by 양시연 on 2020/08/26.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class File{
public:
    string head;
    string number;
    string tail;
    File(){
        head = "";
        number = "";
        tail = "";
    }
};

bool cmp(File a, File b){
    string aHead = a.head;
    string bHead = b.head;
    std::transform(aHead.begin(),aHead.end(), aHead.begin(), ::tolower);
    std::transform(bHead.begin(),bHead.end(), bHead.begin(), ::tolower);

    if(aHead < bHead){
        return true;
    }else if(aHead == bHead){
        if(stoi(a.number) < stoi(b.number)){
            return true;
        }
    }
    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> fileVector;

    // head, number, tail 분리하기
    for(int i = 0 ; i < files.size(); i++){

        int flag = 0;
        int start = 0;
        File file = File();
        for(int j = 0 ; j < files[i].length(); j++){

            if(flag == 0 && (files[i][j] >= 48 && files[i][j] <= 57)){
                file.head = files[i].substr(0, j);
                start = j;
                flag = 1;
            }

            if(flag == 1 && !(files[i][j] >= 48 && files[i][j] <= 57)){
                file.number = files[i].substr(start, j - start);
                start = j;
                flag = 2;
            }
            if(flag == 2) {
                file.tail = files[i].substr(start);
                break;
            }

        }

        if(file.number == ""){
            file.number = files[i].substr(start);
        }

        fileVector.push_back(file);
    }

    stable_sort(fileVector.begin(), fileVector.end(), cmp);
    for(int i = 0 ;  i < fileVector.size(); i++){
        answer.push_back(fileVector[i].head + fileVector[i].number + fileVector[i].tail);
    }

    return answer;
}

//int main(){
//
//    vector<string> answer = solution({"img01b01.png","img10.png", "img0010", "img02.png", "img1.png", "IMG0001.GIF", "img2.JPG"});
//    for(int i = 0; i < answer.size(); i++){
//        cout << answer[i] << endl;
//    }
//}