#include <iostream>
#include <string>
using namespace std;

int main(){

    int a, b, c, d;
    long long int aPlusB;
    long long int cPlusD;
    string ab;
    string cd;

    cin >> a >> b >> c >> d;

    ab = to_string(a) + to_string(b);
    cd = to_string(c) + to_string(d);
    
    aPlusB = stoll(ab);
    cPlusD = stoll(cd);

    cout << aPlusB + cPlusD << endl;

    return 0;
}