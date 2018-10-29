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

bool isLeafNode(vector<int> T, int node){
    int leftChild = node * 2 + 1;
    int rightChild = leftChild + 1;
    bool lc = true;
    bool rc = true;
    if(leftChild >= T.size()){
        lc = false;
    }
    if(rightChild >= T.size()){
        rc = false;
    }
    if(T[leftChild] == -1){
        lc = false;
    }
    if(T[rightChild] == -1){
        rc = false;
    }
    if(lc == false && rc == false){
        return true;
    }
    return false;
}

bool solution(string data, int sum) {
    bool answer = false;
    vector<int> T = deserialize(data);
    
    for(int i=0; i<T.size(); i++){
        int target = 0;
        if(isLeafNode(T, i) && T[i] != -1){
            int parent = i;
            target += T[parent];
            while(parent >= 0 ){
                if(parent - 1 < 0) break;
                parent = (parent - 1) / 2;
                target += T[parent];
            }
            if(target == sum){
                answer = true;
                break;
            }
        }
    }
    
    return answer;
}