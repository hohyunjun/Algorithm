#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int check[200] = {false};
    vector<int> A[200];
    
    for(int i=0; i<computers.size(); i++){
        for(int j=0; j<computers[i].size(); j++){
            if(computers[i][j] == 1 && i != j){
                A[i].push_back(j);
            }
        }
    }
    
    for(int i=0; i<n; i++){
        if(check[i] == false){
            answer+=1;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int w = q.front();
                for(int i=0; i<A[w].size(); i++){
                    if(check[A[w][i]] == false){
                        check[A[w][i]] = true;
                        q.push(A[w][i]);
                    }
                }
                q.pop();
            }
        }
    }
    
    
    return answer;
}