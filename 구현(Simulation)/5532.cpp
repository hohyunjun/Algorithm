#include <iostream>
using namespace std;

int main(){

    int l,a,b,c,d;
    cin >> l >> a >> b >> c >> d;

    int kookdays, mathdays;

    kookdays = a/c;

    if(a%c != 0){
        kookdays+=1;
    }

    mathdays = b/d;

    if(b%d != 0){
        mathdays+=1;
    }

    int maxdays = max(kookdays, mathdays);

    cout << l - maxdays << '\n';


    return 0;
}