#include <iostream>
#include <stack>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string paren;
    stack<char> s;
    int answer = 0;

    cin >> paren;
    for(int i=0; i<paren.length(); i++){
        if(paren[i]=='('){
            s.push('(');
        }else{
            if(i>0){
                if(paren[i-1] == '('){
                    s.pop();
                    answer += s.size();
                }else{
                    s.pop();
                    answer += 1;
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}