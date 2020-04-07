//
// Created by 양시연 on 2020/04/08.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int **map;
int space_size;
vector<pair<int, int>> virus;
int answer = 0;

void spreadVirus(int **tmap){
    queue<pair<int, int>> q;

     int dy[] = {1, 0, -1, 0};
     int dx[] = {0, 1, 0, -1};

     int tx, ty;

    pair<int, int> front;
     for(int i = 0; i < virus.size(); i++){
         q.push(virus[i]);

         while(!q.empty()){
             front = q.front();
             q.pop();
             for(int d = 0; d < 4; d++){
                 ty = front.first + dy[d];
                 tx = front.second + dx[d];

                 if(tx >= 0 && tx < M && ty >= 0 && ty < N
                 && tmap[ty][tx] == 0 ){
                     q.push(make_pair(ty, tx));
                     tmap[ty][tx] = 2;

                 }
             }

         }

     }

     int safe = 0;

     for(int c = 0; c < N; c++){
         for(int r = 0; r < M; r++){
             if(tmap[c][r] == 0) {
                 safe++;
             }
         }
     }

     if(safe > answer) {
         answer = safe;
//         for(int r = 0; r < N; r++){
//             for(int c = 0; c < M; c++){
//                 cout << tmap[r][c] << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
     }



}


void buildWalls(pair<int, int> *temp, pair<int, int> *space, int current, int start){

    if(current == 3){
        // 벽 세우기
        int **tmap = new int*[N];
        for(int i = 0; i < N; i++){
            tmap[i] = new int[M];
        }

        for(int r = 0; r < N; r++){
            for(int c = 0; c < M; c++){
              tmap[r][c] = map[r][c];
            }
        }

        for(int i = 0 ; i < 3; i++){
            tmap[temp[i].first][temp[i].second] = 1;
        }

        // 바이러스 퍼뜨리기
        spreadVirus(tmap);
        return;
    }else{
        for(int i = start; i <space_size; i++){
            temp[current] = space[i];
            buildWalls(temp, space, current+1, i+1);
        }
    }

}

int main(){

    cin >> N >> M;

    pair<int, int> space[N*M];
    space_size = 0;

    //map 생성
    map = new int*[N];
    for(int i = 0; i < N; i++){
        map[i] = new int[M];
    }

    // map 초기화
    int input;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < M; c++){
            cin >> map[r][c];
            if(map[r][c] == 0){
                space[space_size].first = r;
                space[space_size++].second = c;
            }else if(map[r][c] == 2){
                virus.push_back(make_pair(r, c));
            }
        }
    }


    pair<int, int> temp[N*M];
    buildWalls(temp, space, 0, 0);

    cout << answer << endl;


    return 0;
}