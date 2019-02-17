#include <iostream>
using namespace std;

long long int dp[5001][5001];
int mn = 1000000000;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    for(int i=0; i<=k; i++){
        dp[0][i] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            dp[i][j] = dp[i-1][j]%mn + dp[i][j-1]%mn;
            dp[i][j] %= mn;
        }
    }

    cout << dp[n][k] % mn << '\n';

    return 0;
}