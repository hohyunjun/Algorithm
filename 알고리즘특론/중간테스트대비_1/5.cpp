#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

bool solution(string ransomNote, string magazine) {
    bool answer = true;
    map<char, int> _map;
    
    for(int i=0; i<magazine.length(); i++){ // map에 char 별로 존재할 경우 1씩 추가
        _map[magazine[i]] += 1;
    }
    
    for(int i=0; i<ransomNote.length(); i++){
        _map[ransomNote[i]] -= 1;
    }
    
    for(auto each:_map){
        if(each.second < 0){
            answer = false;
            break;
        }
    }
    
    
    return answer;
}