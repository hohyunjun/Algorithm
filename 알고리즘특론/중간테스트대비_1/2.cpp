#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(string s1, string s2) {
    bool answer = true;
    bool check[26] = {false};
    string newString = s1;
    
    for(int i=0; i<s1.length(); i++){
        if(s1[i] != s2[i] && check[s1[i] - 'a'] == false){
            check[s1[i] - 'a'] = true; // s1에서 바꾼 char는 체크한다.
            for(int j=i; j<s1.length(); j++){
                if(newString[j] == s1[i]){
                    newString[j] = s2[i];
                }
            }
        }
    }
    
    cout << newString << endl;
    
    if(newString != s2){
        answer = false;
    }
    
    return answer;
}