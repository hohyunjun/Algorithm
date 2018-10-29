#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isDiffOneChar(string a, string b){
    int diff = 0;
    for(int i=0; i<a.length(); i++){
        if(a[i] != b[i]){
            diff+=1;
        }
        if(diff > 1){
            break;
        }
    }
    if(diff > 1) return false;
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int check[50] = {false};
    bool possible = false;
    for(auto each:words){
        if(each == target){
            possible = true;
            break;
        }
    }
    
    if(!possible){
        answer = 0;
    }else{
        for(int i=0; i<words.size(); i++){
            if(isDiffOneChar(begin, words[i]) && check[i] == false){ // 아직 방문되지 않았고 하나만 차이나는 단어가 존재할 경우
                begin = words[i];
                answer += 1;
                check[i] = true;
                if(isDiffOneChar(begin, target)){
                    answer+=1;
                    begin = target;
                    break;   
                }
                i = 0;
            }
        }   
    }
    
    if(begin != target){
        answer = 0;
    }
    
    return answer;
}