#include <iostream>
#include <algorithm>

using namespace std;

long wine[10001];
long sum[10001];
bool isFull[10001] = {false};

int N;

int main() {

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> wine[i];
    }

    sum[0] = wine[0]; isFull[0] = false;

    for(int i = 1; i < N; i++) {
        if (isFull[i - 1] && i - 3 >= 0) {
            if(wine[i] + wine[i - 1] + sum[i - 3] >= wine[i] + sum[i - 2]){
                sum[i]+=wine[i] + wine[i - 1] + sum[i - 3];
                isFull[i] = true;
            }else{
                sum[i]+= wine[i] + sum[i - 2];
            }
        }else if(isFull[i-1] && i - 3 < 0){
            sum[i] = max(wine[i]+wine[i-1],wine[i]+sum[i-2]);
            isFull[i] = true;
        }else if (!isFull[i - 1]) {
            sum[i] = wine[i] + sum[i - 1];
            isFull[i] = true;
        }

    }

    for(int i = 0; i < N-1; i++)
        cout << sum[i] << " ";

    if(N > 1) {
        cout << max(sum[N - 1], sum[N - 2]) << endl;
    }else
        cout <<sum[0]<<endl;
    return 0;
}
