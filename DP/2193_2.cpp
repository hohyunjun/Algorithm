#include <iostream>
using namespace std;

long long int dp[91][2];

int main(){

    int N;

    cin >> N;

    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int i=2; i<=N; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    long long int ans = 0;
    ans = dp[N][0] + dp[N][1];

    cout << ans << '\n';

    return 0;
}