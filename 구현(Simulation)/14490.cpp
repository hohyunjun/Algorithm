#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    int r = a%b;
    a = b;
    b = r;
    return gcd(a,b);
}

int main(){

    string tmp;

    cin >> tmp;

    stringstream ss(tmp);

    string strA, strB;

    getline(ss, strA, ':');
    getline(ss, strB);

    int a = stoi(strA);
    int b = stoi(strB);

    int d = gcd(a,b);

    string ans = "";

    ans += to_string(a/d);
    ans += ":";
    ans += to_string(b/d);

    cout << ans << '\n';

    return 0;
}