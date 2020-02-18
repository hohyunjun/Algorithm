#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
    BOJ 9935. 폭발 문자열
    stack에 문자열의 각 char를 넣으면서, explosive의 마지막 char가 들어올 경우 stack 내부를 확인한다.
*/

int main(){

    string str;
    string explosive;

    cin >> str;
    cin >> explosive;

    int l = explosive.length();
    char lastChar = explosive[l-1];
    stack<char> s;

    for(int i=0; i<str.length(); i++){
        if(str[i] == lastChar){
            if(l==1){
                continue;
            }else{
                bool found = true;
                stack<char> tmp;

                if(s.size() < explosive.length()-1){
                    s.push(str[i]);
                    continue;
                }

                for(int j=l-2; j>=0; j--){ // 폭발 문자열의 마지막부터 차례로 stack 에 들어있는지 확인
                    if(s.top() == explosive[j]){
                        tmp.push(s.top());
                        s.pop();
                    }else{ // 폭발 문자열과 일치하지 않을 경우
                        found = false;
                        break;
                    }
                }
                if(!found){
                    while(!tmp.empty()){
                        s.push(tmp.top());
                        tmp.pop();
                    }
                    s.push(str[i]);
                }
            }
        }else{
            s.push(str[i]);
        }
    }

    if(s.empty()){
        cout << "FRULA" << '\n';
    }else{
        stack<char> ans;

        while(!s.empty()){
            ans.push(s.top());
            s.pop();
        }

        while(!ans.empty()){
            cout << ans.top();
            ans.pop();
        }
    }

    return 0;
}