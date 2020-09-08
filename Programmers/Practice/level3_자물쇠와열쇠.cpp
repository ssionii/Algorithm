//
// Created by 양시연 on 2020/09/08.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int keySize, lockSize, boardSize;

void rotateKey(vector<vector<int>> &key){

    vector<vector<int>> temp(keySize, vector<int>(keySize));

    for(int i = 0; i < keySize; i++){
        for(int j = 0; j < keySize; j++){
            temp[j][i] = key[keySize-i-1][j];
        }
    }

    key = temp;
}

bool moveKey(int y, int x, vector<vector<int>> key, vector<vector<int>> board){

    for(int i = y; i < y + keySize; i++){
        for(int j = x; j < x + keySize; j++){
            board[i][j] += key[i - y][j - x];
        }
    }


    for(int i = keySize - 1; i <= boardSize - keySize; i++){
        for(int j = keySize - 1; j <= boardSize - keySize; j++){
            if(board[i][j] == 1) continue;

            return false;
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    keySize = key.size();
    lockSize = lock.size();
    boardSize = (keySize - 1) * 2 + lockSize;

    vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));
    for(int i = keySize - 1; i <= boardSize - keySize; i++){
        for(int j = keySize - 1; j <= boardSize - keySize; j++){
            board[i][j] = lock[i - keySize + 1][j - keySize + 1];
        }
    }

    for(int r = 0; r < 4; r++){

        for(int i = 0; i <= boardSize - keySize; i++){
            for(int j = 0 ; j <= boardSize - keySize; j++){
                if(moveKey(i, j, key, board)){
                    answer = true;
                    return answer;
                }
            }
        }

        rotateKey(key);
    }

    return answer;
}
