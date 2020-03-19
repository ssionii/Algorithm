#include <iostream>
#include <algorithm>

using namespace std;

long p[10001];
long dp[10001];

int N;

int main() {
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> p[i];
    }

    dp[1] = p[1];
    if(N > 0)
        dp[2] = p[2] + p[1];

    for(int i = 3; i <= N; i++){
        dp[i] = max(dp[i-1], max(dp[i-2]+p[i], dp[i-3] + p[i-1] + p[i]));
    }

    cout << dp[N];

    return 0;
}
