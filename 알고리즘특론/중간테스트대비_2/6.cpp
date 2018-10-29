#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    vector<pair<string, string>> flight;
    vector<bool> check;
    
    for(int i=0; i<tickets.size(); i++){
        flight.push_back(make_pair(tickets[i][0], tickets[i][1]));
        check.push_back(false);
    }
    
    sort(flight.begin(), flight.end());
    answer.push_back("ICN");
    
    // for(auto each:flight){
    //     cout << each.first << " " << each.second << '\n';
    // }
    
    string departure = "ICN";
    //cout << check.size() << '\n';
    
    for(int i=0; i<flight.size(); i++){
        if(flight[i].first == departure && check[i] == false){
            answer.push_back(flight[i].second);
            departure = flight[i].second;
            check[i] = true;
            i = -1;
        }
    }
    
    return answer;
}