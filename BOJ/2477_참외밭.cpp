//
// Created by 양시연 on 2020/05/17.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int k;
    cin >> k;

    int count[5] = {0, 0, 0, 0, 0};

    int dir, len;
    vector<pair<int, int>> v;
    for(int i = 0; i < 6; i++){
        cin >> dir >> len;
        v.push_back(make_pair(dir, len));
        count[dir]++;
    }

    pair<int, int> longLength = make_pair(0, 0);
    for(int i = 1; i <= 4; i++){
        if(count[i] == 1){
            if(longLength.first == 0) longLength.first = i;
            else longLength.second = i;
        }
    }

    int size;
    int a, b;
    for(int i = 0 ;  i < 6; i++){
        if(v[i].first == longLength.first) a = v[i].second;
        if(v[i].first == longLength.second) b = v[i].second;
    }

    size = a * b;


    for(int i = 0 ; i <= 6; i++){
        if(longLength.first == 2 && longLength.second == 4){
            if(v[i].first == 1 && v[i+1].first == 3){
                size -= v[i].second * v[i+1].second;
                break;
            }
        }else if(longLength.first == 1 && longLength.second == 4){
            if(v[i].first == 3 && v[i+1].first == 2){
                size -= v[i].second * v[i+1].second;
                break;
            }
        }else if(longLength.first == 2 && longLength.second == 3){
            if(v[i].first == 4 && v[i+1].first == 1){
                size -= v[i].second * v[i+1].second;
                break;
            }
        }else if(longLength.first == 1 && longLength.second == 3){
            if(v[i].first == 2 && v[i+1].first == 4){
                size -= v[i].second * v[i+1].second;
                break;
            }
        }

        if(i == 6){
            size -= v[i-1].second * v[0].second;
        }
    }

    cout << size * k;


    return 0;
}