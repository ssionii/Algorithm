//
// Created by 양시연 on 2020/03/19.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

int N;
int** map;

// 상어의 정보
pair <int, int> sharkPosition; // 상어의 위치
int sharkSize = 2; // 상어의 크기
int sharkEat = 0; // 상어가 먹은 물고기의 수

bool compareFishLocation(const pair<int, int>& a, const pair<int, int>& b){

    if((abs(sharkPosition.first - a.first) + abs(sharkPosition.second - a.second)) == (abs(sharkPosition.first - b.first) + abs(sharkPosition.second - b.second))){
        if(a.first == b.first){
            return a.second <= b.second;
        }
        return a.first <= b.first;
    }

    if((abs(sharkPosition.first - a.first)+abs(sharkPosition.second - a.second))
       == (abs(sharkPosition.first - b.first)+abs(sharkPosition.second - b.second))){
        if(a.first <= b.first)
            return true;
        else
            return false;
    }else{
        return((abs(sharkPosition.first - a.first)+abs(sharkPosition.second - a.second))
               <= (abs(sharkPosition.first - b.first)+abs(sharkPosition.second - b.second)));
    }

}

vector<pair<int, int>> canEatFishLocationList(int size){

    vector<pair<int, int>> result;

    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            if(map[y][x] != 0 && map[y][x] < size)
                result.push_back(make_pair(y, x));
        }
    }

    // sorting
    sort(result.begin(), result.end(), compareFishLocation);

    return result;
}


int goToFish(pair<int, int> shark, pair<int, int> fish, int sharkSize) {

    queue<pair<int, int>> q;

    int **visited = new int *[N];
    for (int i = 0; i < N; i++) {
        visited[i] = new int[N];
        fill_n(visited[i], N, 0);
    }

    int **time = new int *[N];
    for (int i = 0; i < N; i++) {
        time[i] = new int[N];
        fill_n(time[i], N, 0);
    }

    q.push(make_pair(shark.first, shark.second));
    visited[shark.first][shark.second] = 1;

    int y[4] = {-1, 0, 0, 1};
    int x[4] = {0, -1, 1, 0};
    int nextYposi, nextXposi;
    while (!q.empty()) {

        pair<int, int> pos = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            nextYposi = pos.first + y[i];
            nextXposi = pos.second + x[i];

            // 물고기가 있는 자리에 도착 하면 시간 return
            if(make_pair(nextYposi, nextXposi) == fish){
                time[nextYposi][nextXposi] = time[pos.first][pos.second] + 1;
                map[nextYposi][nextXposi] = 0;

                return time[nextYposi][nextXposi];
            }

            if (nextYposi < N && nextYposi >= 0 && nextXposi < N && nextXposi >= 0) {
                if (visited[nextYposi][nextXposi] == 0 && map[nextYposi][nextXposi] <= sharkSize) {
                    q.push(make_pair(nextYposi, nextXposi));
                    visited[nextYposi][nextXposi] = 1;
                    time[nextYposi][nextXposi] = time[pos.first][pos.second] + 1;

                }
            }
        }
    }

    return 0;
}

int main(){

    // map의 크기
    cin >> N;

    // map 생성
    map = new int*[N];
    for(int i = 0; i < N; i++){
        map[i] = new int[N];
    }

    // map 초기화
    for(int y = 0; y < N ;y++){
        for(int x = 0; x < N; x++){
            cin >> map[y][x];

            // 상어 첫 위치 찾기
            if(map[y][x] == 9) {
                sharkPosition = make_pair(y, x);
                map[y][x] = 0;
            }
        }
    }

    // 상어가 먹을 수 있는 물고기들의 위치
    vector<pair<int, int>> fishLocation;
    fishLocation = canEatFishLocationList(sharkSize);

    int time = 0;
    while(!fishLocation.empty()) {

        // 상어가 이동한다.
        // return 값이 0이 아니면 물고기를 먹은 것이므로
        time += goToFish(sharkPosition, fishLocation[0], sharkSize);
        if (time != 0) {
            sharkEat++;
            sharkPosition = fishLocation[0];
            fishLocation.erase(fishLocation.begin());

            if (sharkEat == sharkSize) {
                sharkEat = 0;

                sharkSize++;
            }
            fishLocation = canEatFishLocationList(sharkSize);

        }
    }

    cout << time <<endl;

    return 0;
}
