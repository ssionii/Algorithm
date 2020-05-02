//
// Created by 양시연 on 2020/05/02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, K;
int arr[100][100];
int numCount[101];

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int calculateR(int r, int c){
    for(int i = 1; i <= 100; i++){
        numCount[i] = 0;
    }

    int max = 0;
    for(int i = 0 ; i < c; i++){
        numCount[arr[r][i]]++;
        if(max < arr[r][i])
            max = arr[r][i];
    }

    vector<pair<int, int>> v;
    for(int i = 1; i <= max; i++){
        v.push_back(make_pair(i, numCount[i]));
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < 100; i++){
        arr[r][i] = 0;
    }

    int index = 0;
    for(int i = 0 ; i < v.size(); i++){
        if(v[i].second != 0){
            arr[r][index++] = v[i].first;
            arr[r][index++] = v[i].second;
        }
    }

    return index;

}

int calculateC(int c, int r){
    for(int i = 1; i <= 100; i++){
        numCount[i] = 0;
    }

    int max = 0;
    for(int i = 0 ; i < r; i++){
        numCount[arr[i][c]]++;
        if(max < arr[i][c])
            max = arr[i][c];
    }

    vector<pair<int, int>> v;
    for(int i = 1; i <= max; i++){
        v.push_back(make_pair(i, numCount[i]));
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < 100; i++){
        arr[i][c] = 0;
    }

    int index = 0;
    for(int i = 0 ; i < v.size(); i++){
        if(v[i].second != 0){
            arr[index++][c] = v[i].first;
            arr[index++][c] = v[i].second;
        }
    }

    return index;

}

int main(){

    cin >> R >> C >> K;
    for(int r = 0 ; r < 3; r++){
        for(int c = 0; c < 3; c++){
            cin >> arr[r][c];
        }
    }

    int time = 0;
    int colLength = 3, rowLength = 3, tempLength;
    while(arr[R-1][C-1] != K && time <= 100){
        time++;
       if(colLength <= rowLength){
           for(int i = 0; i < rowLength; i++){
               tempLength = calculateR(i, colLength);
               if(colLength < tempLength){
                   colLength = tempLength;
               }
           }
       }else{
           for(int i = 0; i < colLength; i++){
               tempLength = calculateC(i, rowLength);
               if(rowLength < tempLength){
                   rowLength = tempLength;
               }
           }
       }

//        for(int r = 0; r< rowLength; r++){
//            for(int c= 0; c < colLength; c++){
//                cout << arr[r][c] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
    }

    if(time <= 100)
        cout << time;
    else
        cout << -1;


    return 0;
}