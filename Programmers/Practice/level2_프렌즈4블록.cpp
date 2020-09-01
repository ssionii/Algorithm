//
// Created by 양시연 on 2020/08/25.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> board;

bool dropBlock(int m, int n){

    bool isDrop = false;

    for(int i = m - 1; i > 0 ; i--){
        for(int j = 0; j < n; j++){
            if(board[i][j] == ' '){
                for(int k = i - 1; k >= 0; k--){
                    if(board[k][j] != ' '){
                        board[i][j] = board[k][j];
                        board[k][j] = ' ';
                        isDrop = true;
                        break;
                    }
                }
            }
        }
    }

    return isDrop;
}

int burstBlock(int m, int n){

    vector<pair<int, int>> temp;
    char blockType = ' ';

    for(int i = 0 ; i < m - 1; i++){
        for(int j = 0; j < n - 1; j++){
            blockType = board[i][j];
            if(blockType != ' ' && blockType == board[i+1][j] && blockType == board[i][j+1] && blockType == board[i+1][j+1]){
                temp.push_back(make_pair(i+1, j));
                temp.push_back(make_pair(i, j));
                temp.push_back(make_pair(i, j+1));
                temp.push_back(make_pair(i+1, j+1));
            }
        }
    }

    // 중복 제거
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for(int i = 0 ; i < temp.size(); i++){
        board[temp[i].first][temp[i].second] = ' ';
    }

    return temp.size();

}

int solution(int m, int n, vector<string> inputBoard) {
    int answer = 0;
    board = inputBoard;

    do{
        answer += burstBlock(m, n);
    }while(dropBlock(m, n));

    return answer;
}
//
//int main(){
//
//    cout << solution(6, 6, {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"}) << endl;
//}