#include <iostream>
using namespace std;


int main(){

    int n;
    
    cin >> n;

    int p[n+1];

    for(int i=1; i<n+1; i++){
        cin >> p[i];
    }

    int dp[1001] = {};
    dp[0] = 0;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], p[j] + dp[i-j]);
        }
    }

    cout << dp[n] << endl;


    return 0;
}