#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
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

vector<int> inorderedTree;

void Inorder(vector<int> T, int node){
    if(T[node] != -1 && node < T.size()){
            Inorder(T, node*2 + 1);
            inorderedTree.push_back(T[node]);
            Inorder(T, node*2 + 2);   
    }
}


bool solution(string data) {
    bool answer = false;
    
    vector<int> T = deserialize(data);
    Inorder(T, 0);
    
    
    vector<int> sortedTree(inorderedTree);
    
    sort(sortedTree.begin(), sortedTree.end());
    
    if(sortedTree == inorderedTree){
        answer = true;
    }
    
    return answer;
}