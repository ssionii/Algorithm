#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string, int> closet;
    vector <string> type;
    
    for(int i = 0; i < clothes.size(); i++){
        if(!closet.count(clothes[i][1])){
            closet.insert(make_pair(clothes[i][1], 2));
            type.push_back(clothes[i][1]);
        }else
            closet[clothes[i][1]]++;
    }
    
    answer = closet[type[0]];
    for(int i = 1; i < type.size(); i++){
    	answer *= closet[type[i]];
    }
    
    return answer - 1;
}
