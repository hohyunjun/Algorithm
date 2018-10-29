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

int solution(string tree, int k) {
    int answer = 0;
    
    vector<int> T = deserialize(tree);
    
    for(int i=0; i<T.size(); i++){
        int sum = 0;
        if(isLeafNode(T, i) && T[i] != -1){
            int parent = i;
            sum += T[parent];
            while( parent >= 0){
                if(parent - 1 < 0){
                    break;
                }
                parent = (parent -1) / 2;
                sum += T[parent];
            }
            if(sum == k){
                answer += 1;
            }
        }
    }
    
    return answer;
}