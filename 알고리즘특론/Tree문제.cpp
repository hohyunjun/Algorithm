// String으로 Serialize된 트리를 Deserialize해서 배열 형태로 저장하는 코드
// 배열로 표현된 이진트리의 inorder도 확인!
// 해당 문제는 이진탐색트리 검증문제. 트리를 inorder로 돌렸을 때 숫자가 순서대로 나왔는지 확인하는 방식으로 풀었다.

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> sorted;

vector<int> deserialize(string data){
    vector<int> T;
    string tmp="";
    for(int i=0; i<data.length(); i++){
        if(data[i] == ','){
            if(tmp == "null"){
                T.push_back(-1);
            }else{
                T.push_back(stoi(tmp));   
            }
            tmp = "";
            continue;
        }
        tmp += data[i];
    }
    
    if(tmp == "null"){
        T.push_back(-1);
    }else{
        T.push_back(stoi(tmp));
    }
    
    return T;
}

bool isBinTree(vector<int> T){
    
    vector<int> sortedTree;
    for(int i=0; i<T.size(); i++){
        if(T[i] != -1){
            sortedTree.push_back(T[i]);
        }
    }
    sort(sortedTree.begin(), sortedTree.end());
    
    if(sortedTree == sorted){
        return true;
    }
    return false;
    
}

void inorder(int root, vector<int> T){
    if(root < T.size() && T[root] != -1){
        inorder(root*2+1, T);
        sorted.push_back(T[root]);
        inorder(root*2+2, T);   
    }
}

bool solution(string data) {
    bool answer = true;
    vector<int> T;
    T = deserialize(data);
    inorder(0, T); // inorder 돌린 후 sorted 배열에 저장
    
    // for(auto i:sorted){
    //     cout << i << ' ';
    // }
    
    answer = isBinTree(T);
    
    return answer;
}