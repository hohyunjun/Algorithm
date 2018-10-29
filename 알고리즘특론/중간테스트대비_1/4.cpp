#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> deserialize(string tree){
    
    vector<int> T;
    string node = "";
    for(int i=0; i<tree.length(); i++){
        if(tree[i] == ','){
            if(node == "null"){
                T.push_back(-1);
            }else{
                T.push_back(stoi(node));   
            }
            node = "";
        }else{
            node+=tree[i];   
        }
    }
    if(node == "null"){
        T.push_back(-1);
    }else{
        T.push_back(stoi(node));
    }
    
    return T;
}

pair<int,bool> checkHeight(vector<int> T, int node){
    if(node < T.size() && T[node] != -1){
        int left = checkHeight(T, node*2 + 1).first;
        int right = checkHeight(T, node*2 + 2).first;
        int height = max(left, right) + 1;
        if(abs(left - right) > 1){
            return make_pair(height, false);
        }else{
            return make_pair(height, true);   
        }
    }else{
        return make_pair(0, true);
    }
}

bool solution(string data) {
    bool answer = true;
    
    vector<int> T = deserialize(data);
    vector<pair<int, bool>> Height(T.size());
    for(int i=0; i<T.size(); i++){
        Height[i] = checkHeight(T, i);
    }
    
    for(int i=0; i<Height.size(); i++){
        if(Height[i].second == false){
            answer = false;
            break;
        }
    }
    
    return answer;
}