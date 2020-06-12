//
// Created by 양시연 on 2020/06/07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person{
public:
    int num;
    vector<int> friends;

    Person(){}
};

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second <= b.second;
    }
    return a.first <= b.first;
}

int main(){

    int N, M;
    vector<Person> friendList;
    Person p;
    p.num = 1;
    friendList.push_back(p);

    cin >> N >> M;

    vector<pair<int, int>> v;
    int first, second;

    for(int i = 0 ; i < M; i++){
        cin >> first >> second;
        v.push_back(make_pair(first, second));
        v.push_back(make_pair(second, first));
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0 ; i < v.size(); i++){
        first = v[i].first;
        second = v[i].second;

        bool hasList = false;
        for(int j =0; j< friendList.size(); j++){
            if(friendList[j].num == first){

                friendList[j].friends.push_back(second);

                hasList = true;
                break;
            }
        }

        if(!hasList){
            Person p;
            p.num = first;
            p.friends.push_back(second);
            friendList.push_back(p);

        }
    }


    vector<int> invite;

    for(int i = 0 ; i < friendList[0].friends.size(); i++){
        invite.push_back(friendList[0].friends[i]);
    }

    int count = 0;
    for(int i = 0 ; i < invite.size(); i++){
        for(int j = 0; j < friendList.size(); j++){
            // 찾기
            if(friendList[j].num == invite[i]){
                vector<int> f = friendList[j].friends;
                for(int j = 0 ; j < f.size(); j++){
                    if(find(invite.begin(), invite.end(), f[j]) == invite.end()
                    && f[i] != 1){
                        count ++;
                    }
                }
            }
        }
    }

    cout << invite.size() + count -1 <<endl;

    return 0;

}

