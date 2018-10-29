#include <iostream>
#include <stack>
using namespace std;

int main(){

    int N;
    stack<int> binary;

    cin >> N;
    if(N==0){
        cout << "0";
    }else{
        while(N){
            int mod = N%(-2);
            N/=(-2);
            if(mod<0){
                mod += 2;
                N+=1;
            }
            binary.push(mod);
        }

        while(!binary.empty()){
            cout << binary.top();
            binary.pop();
        }
    }

    return 0;
}