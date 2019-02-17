#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<pair<string, string>> paths;
    vector<bool> check;
    
    for(int i=0; i<tickets.size(); i++){
        paths.push_back(make_pair(tickets[i][0],tickets[i][1]));
        check.push_back(false);
    }
    
    sort(paths.begin(), paths.end());
    
    // for(auto each:paths){
    //     cout << each.first << " " << each.second << endl;
    // }
    
    stack<string> st;
    st.push("ICN");
    answer.push_back("ICN");
    
    while(!st.empty()){
        string w = st.top();
        st.pop();
        for(int i=0; i<paths.size(); i++){
            if(paths[i].first == w && check[i] == false){
                check[i] = true;
                answer.push_back(paths[i].second);
                st.push(paths[i].second);
                break;
            }
        }
    }
    
    // queue<string> q;
    // q.push("ICN");
    // answer.push_back("ICN");
    
    // //BFS
    // while(!q.empty()){
    //     string w = q.front();
    //     for(int i=0; i<paths.size(); i++){
    //         if(paths[i].first == w && check[i] == false){
    //             check[i] = true;
    //             q.push(paths[i].second);
    //             answer.push_back(paths[i].second);
    //             break;
    //         }
    //     }
    //     q.pop();
    // }
    
    return answer;
}