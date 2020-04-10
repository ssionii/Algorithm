//
// Created by 양시연 on 2020/04/10.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
int N, M, V;
vector<int> graph[1001];

void bfs(){
    bool *visited = new bool[N+1];
    fill_n(visited, N+1, false);
    queue <int> q;

    q.push(V);
    visited[V] = true;

    while(!q.empty()){

        int current = q.front();
        cout << current << " ";
        q.pop();

        for(int i = 0; i < graph[current].size(); i++) {
            int node = graph[current][i];
            if (!visited[node]) {
                q.push(node);
                visited[node] = true;
            }
        }
    }
}

void dfs(){
    bool *visited = new bool[N+1];
    fill_n(visited, N+1, false);
    stack <int> s;

    s.push(V);
    visited[V] = true;
    cout << V << " ";

    while(!s.empty()){

        int current = s.top();
        s.pop();

        for(int i = 0; i < graph[current].size(); i++) {
            int node = graph[current][i];
            if (!visited[node]) {
                cout << node << " ";
                s.push(current);
                s.push(node);
                visited[node] = true;

                break;
            }
        }
    }
}

int main(){

    cin >> N >> M >> V;

    // map 만들기
    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // sorting
    for(int i = 0; i< N; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs();
    cout << endl;
    bfs();




    return 0;
}

