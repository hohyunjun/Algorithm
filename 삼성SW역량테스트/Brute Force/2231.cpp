#include <iostream>
#include <string>
using namespace std;

int solve(int x){
    int divPlus = 0;
    divPlus += x;
    string tmp = to_string(x);
    for(int i=0; i<tmp.length(); i++){
        divPlus += tmp[i] - '0';
    }

    return divPlus;
}

int main(){

    int n;
    cin >> n;

    int ans = 0;

    for(int i=0; i<=n; i++){
        int tmp = solve(i);
        if(tmp == n){
            ans = i;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}