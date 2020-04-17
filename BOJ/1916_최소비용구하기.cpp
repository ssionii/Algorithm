//
// Created by 양시연 on 2020/04/14.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int INF = 1000000000;

class Bus{
public:
    int v;
    int money;

    Bus(){}

    Bus(int v, int m){
        this -> v = v;
        this->money = m;
    }

};

struct cmp{
    bool operator()(Bus a, Bus b){
        return a.money > b.money;
    }
};

int main(){

    cin >> N >> M;

    vector<Bus> busList[1001];

    int s, f, m;
    for(int i = 0 ; i < M; i++){
        cin >> s >> f >>m;
        Bus bus = Bus(f, m);
        busList[s].push_back(bus);
    }

    int start, finish;
    cin >> start >> finish;

    if(start == finish){
        cout << 0 <<endl;
        return 0;
    }

    priority_queue<Bus, vector<Bus>, cmp> pq;
    Bus *D = new Bus[N+1];
    bool *check = new bool[N+1];
    for(int i = 1 ; i <= N; i++){
        if(i == start){
            D[i] = Bus(i, 0);
        }else{
            D[i] = Bus(i, INF);
        }
        check[i] = false;
        pq.push(D[i]);
    }


    while(!pq.empty()){
        Bus cur = pq.top();
        pq.pop();

        for(Bus next : busList[cur.v]){
                if(!check[next.v] && (D[next.v].money > D[cur.v].money + next.money)){
                D[next.v].money = D[cur.v].money + next.money;
                pq.push(D[next.v]);
            }
        }
        check[cur.v] = true;
    }

    cout << D[finish].money << endl;



    return 0;
}