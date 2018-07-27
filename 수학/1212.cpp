#include <iostream>
#include <stack>
using namespace std;

int main(){

    string oct;
    stack<int> mod;

    cin >> oct;

    for(int i=0; i<oct.length(); i++){
        int tmp = oct[i]-'0';
        while(tmp){
            mod.push(tmp%2);
            tmp = tmp/2;
        }
        if(i!=0){
            while(mod.size()!=3){
                mod.push(0);
            }
        }
        while(!mod.empty()){
            cout << mod.top();
            mod.pop();
        }
    }

    if(oct=="0\0"){
        cout << '0';
    }


    return 0;
}