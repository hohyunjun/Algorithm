#include <iostream>
#include <stack>
#include <string>
using namespace std;

int pr(char ch){
    if(ch == '(') return 0;
    else if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
}


int main(){

    string str;

    cin >> str;

    stack<char> op;

    // - 'A' < 0 이면 operator

    for(int i=0; i<str.length(); i++){
        if(str[i] - 'A' >= 0){ // 알파벳인 경우
            cout << str[i];
        }else if(str[i] == '('){ // 괄호시작인 경우
            op.push(str[i]);
        }else if(str[i] == ')'){ // 괄호끝인 경우
            while(op.top() != '('){
                cout << op.top();
                op.pop();
            }
            op.pop();
        }else{ // 연산자인 경우
            while(!op.empty() && pr(op.top()) >= pr(str[i])){
                cout << op.top();
                op.pop();
            }
            op.push(str[i]);
        }
    }

    while(!op.empty()){
        cout << op.top();
        op.pop();
    }


    return 0;
}