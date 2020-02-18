#include <iostream>
#include <string>
using namespace std;

int main(){

    string a;
    string b;
    char op;

    cin >> a >> op >> b;

    if(op == '*'){
        for(int i=0; i<b.length()-1; i++){
            a+='0';
        }
        cout << a << '\n';
    }else{
        if(a.length() == b.length()){
            string answer = "2";
            for(int i=0; i<a.length()-1; i++){
                answer+='0';
            }
            cout << answer << '\n';
        }else if(a.length() > b.length()){
            string answer = a.substr(0,a.length()-b.length());
            answer += '1';
            for(int i=0; i<b.length()-1; i++){
                answer += '0';
            }
            cout << answer << '\n';
        }else{
            string answer = b.substr(0, b.length() - a.length());
            answer += '1';
            for (int i = 0; i < a.length() - 1; i++)
            {
                answer += '0';
            }
            cout << answer << '\n';
        }
    }


    return 0;
}