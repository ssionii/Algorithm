//
// Created by 양시연 on 2020/05/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct user{
    int age;
    string name;
    int order;
};

bool compare(user a,user b){
    if(a.age > b.age){
        return false;
    }else if(a.age == b.age){
        return a.order < b.order;
    } else
        return true;
}

int main(){

    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<user> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        user user;
        cin >> user.age >> user.name;
        user.order = i;
        v.push_back(user);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0 ; i <n; i++){
        cout << v[i].age << " "<< v[i].name <<'\n';
    }
    return 0;
}