#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
	return a > b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue <pair<int, bool>> printer;
    vector <int> num_list;
    
    for(int i = 0; i < priorities.size(); i++){
    	
    	if(i != location) printer.push(make_pair(priorities[i], false));
    	else printer.push(make_pair(priorities[i],true));
    	
    	num_list.push_back(priorities[i]);
    }  
    
    sort(num_list.begin(), num_list.end(), compare);
    
    int index = 0;
    while(!printer.empty()){
    	if(printer.front().first != num_list[index]){
    		printer.push(printer.front());
    		printer.pop();
    	}else{
    		index++;
    		if(printer.front().second){
    			answer = index;
    			return answer;
    		}
    		printer.pop();
    	}
    }
    
    return answer;
}
