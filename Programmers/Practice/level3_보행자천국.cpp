//
// Created by 양시연 on 2020/09/06.
//

#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

int r[501][501];
int d[501][501];

int solution(int m, int n, vector<vector<int>> city_map) {

    memset(r, 0, sizeof(r));
    memset(d, 0, sizeof(d));
    r[1][1] = d[1][1] = 1;

    for(int i = 1 ; i <= m; i++){
        for(int j = 1 ; j <= n; j++){
            if(city_map[i-1][j-1] == 0){
                r[i][j] = (r[i][j] + r[i][j-1] + d[i-1][j]) % MOD;
                d[i][j] = (d[i][j] + r[i][j-1] + d[i-1][j]) % MOD;
            }else if(city_map[i-1][j-1] == 1){
                r[i][j] = 0;
                d[i][j] = 0;
            }else{
                r[i][j] = r[i][j-1];
                d[i][j] = d[i-1][j];
            }
        }
    }

    return (r[m][n-1] + d[m-1][n]) % MOD;
}
//
//int main(){
//
//    cout << solution(3, 6, {{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}}) << endl;
//}