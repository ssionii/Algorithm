//
// Created by 양시연 on 2019/10/17.
//

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compareGenres(const pair<string, int> &p1, const pair<string, int> &p2){
    return p1.second > p2.second;
}

bool comparePlays(const pair<int, int> &p1, const pair <int, int> &p2){
   if(p1.second == p2.second)
        return p1.first < p2.first;

   return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map <string, vector<pair<int, int>>> hash_map;
    unordered_map <string, int> sum;

    // hash_map 만들기
    for(int i = 0 ; i < genres.size(); i++) {
        hash_map[genres[i]].push_back(make_pair(i, plays[i]));
        sum[genres[i]] += plays[i];
    }

    // 재생된 횟수로 장르 정렬
    vector<pair<string,int>> sorted_genres;
    for(auto iter = sum.begin(); iter != sum.end(); iter++){
        sorted_genres.push_back(make_pair(iter->first, iter->second));
    }
    sort(sorted_genres.begin(), sorted_genres.end(), compareGenres);

    for(auto iter = sorted_genres.begin(); iter != sorted_genres.end(); iter++){
        sort(hash_map[iter->first].begin(), hash_map[iter->first].end(), comparePlays);
        for(int i = 0; i < hash_map[iter->first].size(); i++){
            answer.push_back(hash_map[iter->first].at(i).first);

            if(i == 1)
                break;
        }
    }

    return answer;
}
