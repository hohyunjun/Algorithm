#include <iostream>
using namespace std;

int dp[13];

int main(){

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=12; i++){
        dp[i] = dp[i-1] * i;
    }

    int n;

    cin >> n;

    cout << dp[n] << endl;

    return 0;
}