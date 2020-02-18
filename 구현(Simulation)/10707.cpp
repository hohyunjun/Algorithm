#include <iostream>
using namespace std;

int main(){

    int a,b,c,d,p;

    cin >> a >> b >> c >> d >> p;

    int priceA, priceB;

    priceA = a * p;

    if(p <= c){
        priceB = b;
    }else{
        priceB = b + (p-c)*d;
    }

    if(priceA <= priceB){
        cout << priceA << '\n';
    }else{
        cout << priceB << '\n';
    }


    return 0;
}