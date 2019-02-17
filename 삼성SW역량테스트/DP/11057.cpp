#include <iostream>
using namespace std;

int modNum = 10007;

long long int dp[1001][10];

int main(){

    for(int i=0; i<10; i++) dp[1][i] = 1;

    int n;

    cin >> n;

    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<=j; k++){
                dp[i][j] += dp[i-1][k] % modNum;
                dp[i][j] %= modNum;
            }
        }
    }

    int ans = 0;

    for(int i=0; i<10; i++){
        ans += dp[n][i];
        ans %= modNum;
    }

    cout << ans % modNum << '\n';

    return 0;
}