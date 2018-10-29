#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int main(){

    int T;
    int a, b;

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> a >> b;
        int g = gcd(a,b);
        cout << a*b/g << endl;
    }
    
    return 0;
}