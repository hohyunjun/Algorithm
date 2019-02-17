#include <iostream>
using namespace std;

int dp[10001][3];
int drink[10001];

int main(){

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> drink[i];
    }

    dp[0][0] = 0;
    dp[0][1] = drink[0];
    dp[0][2] = 0;

    for(int i=1; i<n; i++){
        dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        dp[i][1] = dp[i-1][0] + drink[i];
        dp[i][2] = dp[i-1][1] + drink[i];
    }

    cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])) << '\n';

    return 0;
}