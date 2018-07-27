#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;

    cin >> a >> b;

    int tmp = max(a,b);
    int tmp2 = min(a,b);

    a = tmp;
    b = tmp2;

    int tmp3;
    while(b){
        tmp3 = a%b;
        a = b;
        b = tmp3;
    }

    int gcd = a;
    int lcm;

    lcm = tmp*tmp2/gcd;

    cout << gcd << endl;
    cout << lcm << endl;

    return 0;
}