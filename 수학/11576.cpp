#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

int main(){

    int A, B;
    int m;
    stack<int> A_baseNumber;
    int decimal = 0;
    stack<int> B_baseNumber;

    cin >> A >> B >> m;

    int tmp;
    for(int i=0; i<m; i++){
        cin >> tmp;
        A_baseNumber.push(tmp);
    }

    while(!A_baseNumber.empty()){
        decimal += A_baseNumber.top() * pow(A, m - A_baseNumber.size());
        A_baseNumber.pop();
    }

    if(decimal==0){
        B_baseNumber.push(0);
    }else{
        while(decimal){
            int tmp2 = decimal%B;
            B_baseNumber.push(tmp2);
            decimal/=B;
        }
    }

    while(!B_baseNumber.empty()){
        cout << B_baseNumber.top() << " ";
        B_baseNumber.pop();
    }

    return 0;
}