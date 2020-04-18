//
// Created by 양시연 on 2020/04/19.
//

#include <iostream>
#include <queue>

using namespace std;

int INF = 10001;
int M, N;
string map[101];

bool check[10001];

class Room{
public:
    int r;
    int c;
    int number;
    int isWall;
    int smash;

    Room(){}

    Room(int r, int c, int w){
        this->r = r;
        this->c = c;
        number = M * r + c;
        isWall = w;
        if(r == 0 && c == 0) {
            smash = 0;
        }else{
            smash = INF;

        }
    }
};

struct cmp{
    bool operator()(Room a, Room b){
        return a.smash > b.smash;
    }
};

int main(){
    cin >> M >> N;
    for(int i = 0 ;  i < N; i++){
        cin >> map[i];
    }

    Room *D= new Room[N * M];
    fill_n(check, N * M, false);
    priority_queue <Room, vector<Room>, cmp> pq;


    for(int r = 0 ;  r < N ; r++){
        for(int c = 0; c < M; c++){
            Room room = Room(r, c , map[r][c] - 48);
            D[M*r + c] = room;

            pq.push(D[M*r + c]);
        }
    }

    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};

    while(!pq.empty()){

        Room cur = pq.top();
        pq.pop();

//        cout << "현재 위치 : " << cur.r << "," << cur.c <<endl;

        for(int i = 0 ; i < 4; i++){
            pair<int, int> nextPosi = make_pair(cur.r + dy[i], cur.c + dx[i]);
            if(nextPosi.first >= 0 && nextPosi.second >= 0
                && nextPosi.first < N && nextPosi.second < M){
                Room next = D[M * nextPosi.first + nextPosi.second];

//                cout << "갈 수 있는 위치 : " << next.r << "," << next.c <<endl;

                if(!check[next.number] && (next.smash > cur.smash + next.isWall)){
//                    cout << next.smash << " > "  << cur.smash << " + " << next.isWall <<endl;
                    next.smash = cur.smash + next.isWall;
//                    cout << "변한 값 : " << next.smash <<endl;

                    D[M * nextPosi.first + nextPosi.second].smash = next.smash;

                    pq.push(next);

                }
            }
        }

        check[cur.number] = true;
    }

    cout << D[M*N -1].smash << endl;


    return 0;
}