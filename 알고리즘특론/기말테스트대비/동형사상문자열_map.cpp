// 하나의 문자에 두 개 이상의 문자가 대응될 경우 false

#include <string>
#include <vector>
#include <map>
using namespace std;

bool solution(string s1, string s2) {
    bool answer = true;
    map<char, int> m;
    
    for(int i=0; i<s1.length(); i++){
        if(m.find(s1[i]) != m.end()){
            if(m[s1[i]] != s2[i]){
                answer = false;
                break;   
            }
        }else{
            m[s1[i]] = s2[i];   
        }
    }
    
    return answer;
}