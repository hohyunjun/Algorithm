#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> l;
    stack<char> r;
    int T;
    char Pchar;
    char op;
    string initStr;

    cin >> initStr;

    for(int i=0; i<initStr.length(); i++){
        l.push(initStr[i]);
    }

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> op;
        switch(op){
            case 'P': {
                cin >> Pchar;
                l.push(Pchar);
                break;
            }
            case 'L':{
                if(l.size() != 0){
                    char tmp = l.top();
                    l.pop();
                    r.push(tmp);
                }
                break;
            }
            case 'D':{
                if(r.size() != 0){
                    char tmp = r.top();
                    r.pop();
                    l.push(tmp);
                }
                break;
            }
            case 'B':{
                if(l.size() != 0){
                    l.pop();
                }
                break;
            }
        }
    }

    vector<char> left, right;
    while(l.size()!=0){
        left.push_back(l.top());
        l.pop();
    }
    while(r.size()!=0){
        right.push_back(r.top());
        r.pop();
    }

    for(int i=left.size()-1; i>=0; i--){
        cout << left[i];
    }
    for(int i=0; i<right.size(); i++){
        cout << right[i];
    }

    return 0;
}