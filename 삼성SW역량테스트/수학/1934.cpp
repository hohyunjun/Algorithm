#include <iostream>
using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(){

    int t, a, b;

    cin >> t;

    for(int i=0; i<t; i++){
        cin >> a >> b;
        cout << a*b / gcd(a,b) << endl;
    }

    return 0;
}