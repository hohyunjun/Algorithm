#include <iostream>
using namespace std;

long long int dp[201][201];
int mn = 1000000000;

int main(){

    int n, k;

    cin >> n >> k;

    for(int i=0; i<=k; i++){
        dp[0][i] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            for(int l=0; l<=i; l++){
                dp[i][j] += dp[i-l][j-1] % mn;
                dp[i][j] %= mn;
            }
        }
    }

    cout << dp[n][k] % mn << '\n';

    return 0;
}