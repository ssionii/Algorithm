//
// Created by 양시연 on 2020/06/13.
//

#include <iostream>
#include <string>

using namespace std;

int diff(int a, int b){
    if(a - b >= 0 ) return a - b;
    else return b - a;
}

int main(){

    string word1, word2;
    cin >> word1 >> word2;

    int arr1[27], arr2[27];

    fill_n(arr1, 27, 0);
    fill_n(arr2, 27, 0);

    for(int i = 0 ; i < word1.size(); i++) arr1[word1[i] - 97]++;
    for(int i = 0 ; i < word2.size(); i++) arr2[word2[i] - 97]++;


    int count = 0;
    for(int i = 0; i < 27; i++){
        if(arr1[i] != arr2[i]){
            count += diff(arr1[i], arr2[i]);
        }
    }

    cout << count<<endl;

}
