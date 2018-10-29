#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isPalindrome(string s, int start, int last){
    if(start >= last){
        return true;
    }
    if(s[start] == s[last]){
        return isPalindrome(s, start+1, last-1);
    }else{
        return false;
    }
}

int solution(string s) {
    int answer = 0;
    vector<string> substrings;
    
    for(int i=0; i<s.length(); i++){
        string substring;
        for(int j=1; j<=s.length()-i; j++){
            substring = s.substr(i, j);
            substrings.push_back(substring);
        }
    }
    
    for(auto each:substrings){
        if(isPalindrome(each, 0, each.length()-1)){
            answer += 1;
        }
    }
    
    return answer;
}