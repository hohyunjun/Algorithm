#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> sorted;

void inorder(vector<int> tree, int start){
    if(start >= tree.size()){
        return;
    }
    if(tree[start] == -1){
        return;
    }
    inorder(tree, start*2); // left
    sorted.push_back(tree[start]); // root
    inorder(tree, start*2+1); // right
}

vector<int> deserialize(string data){
    vector<int> A;
    string str = "";
    for(int i=0; i<data.length(); i++){
        if(data[i] != ','){
            str += data[i];
        }else{
            if(str == "null"){
                A.push_back(-1);
                str = "";
            }else{
                A.push_back(stoi(str));
                str = "";   
            }
        }
    }
    
    if(str == "null"){
        A.push_back(-1);
        str = "";
    }else{
        A.push_back(stoi(str));
        str = "";   
    }
    
    return A;
}



int solution(string data, int k) {
    int answer = 0;
    vector<int> tree;
    vector<int> A;
    tree.push_back(-1);
    A = deserialize(data);
    for(int i=0; i<A.size(); i++){
        tree.push_back(A[i]);
        cout << A[i] << " ";
    } // tree에 노드 값을 인덱스 1부터 저장
    cout << '\n';
    inorder(tree, 1);
    
    for(int i=0; i<sorted.size(); i++){
        cout << sorted[i] << " ";
    }
    
    answer = sorted[k-1];
    
    return answer;
}