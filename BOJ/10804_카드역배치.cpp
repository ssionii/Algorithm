//
// Created by 양시연 on 2020/05/24.
//

#include <iostream>

using namespace std;

int main(){

    int cards[21];
    for(int i = 1 ;  i <= 20; i++) cards[i] = i;

    for(int i = 0; i < 10; i++){
        int start, end;
        cin >> start >> end;
        int temp[21];
        int index = end;

        for(int j = start; j <= end; j++) temp[index--] = cards[j];
        for(int j = start; j <= end; j++) cards[j] = temp[j];
    }

    for(int i = 1; i <= 20; i++) cout << cards[i] << " ";


    return 0;
}