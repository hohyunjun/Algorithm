#include <iostream>
#include <stack>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;

    for(int i=0; i<T; i++){
        stack<char> s;
        string paren;
        bool no = false;

        cin >> paren;

        for(int j=0; j<paren.length(); j++){
            if(paren[j]=='('){
                s.push('(');
            }else if(paren[j] == ')' && s.size() != 0){
                s.pop();
            }else if(paren[j] == ')' && s.size() == 0){
                no = true;
                break;
            }
        }

        if(no || s.size()>0){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }



    return 0;
}