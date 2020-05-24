//
// Created by 양시연 on 2020/05/24.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    int ySum = 0;
    int mSum = 0;
    for(int i = 0; i < v.size(); i++){
        ySum += ((v[i] / 30 ) + 1) * 10;
        mSum += ((v[i] / 60 ) + 1) * 15;

    }

    if(ySum < mSum) cout << "Y " << ySum;
    else if(ySum > mSum) cout << "M " << mSum;
    else cout << "Y M " << mSum;


    return 0;
}
