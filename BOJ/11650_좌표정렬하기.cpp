//
// Created by 양시연 on 2020/05/31.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first){
        return true;
    }else if(a.first == b.first){
        return a.second < b.second;
    }else{
        return false;
    }
}

int main(){

    vector<pair<int, int>> v;

    int n;
    cin >> n;

    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0 ; i < n; i++){
        cout << v[i].first << " "<< v[i].second << '\n';
    }



    return 0;
}