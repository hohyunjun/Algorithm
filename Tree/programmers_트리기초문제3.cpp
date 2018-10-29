#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

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

bool solution(string data) {
    bool answer = true;
    vector<int> T;
    vector<int> A;
    T.push_back(-1);
    A = deserialize(data);
    for(int i=0; i<A.size(); i++){
        T.push_back(A[i]);
    }
    
    // for(int i=0; i<T.size(); i++){
    //     cout << T[i] << " ";
    // }
    
    cout << T.size() << '\n';
    
    for(int i=1; i<T.size(); i++){
        int left = 0;
        int right = 0;
        if(T[i] == -1) continue;
        if(T[i] != -1){
            int tmp = i * 2;
            while(tmp < T.size() && T[tmp] != -1){
                left += 1;
                tmp *= 2;
            }
            int tmp2 = i*2 + 1;
            while(tmp2 < T.size() && T[tmp2] != -1){
                right += 1;
                tmp2 = tmp2*2 + 1;
            }
        }
        //cout << T[i] << " : " << left << "," << right << '\n';
        
        if(abs(left-right) > 1){
            answer = false;
            break;
        }
        
    }
    
    
    return answer;
}