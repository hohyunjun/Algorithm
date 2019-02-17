#include <iostream>
using namespace std;

int dp[1001][10];
int modNum = 10007;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    int N;
    cin >> N;

    for(int i=0; i<=9; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=N; i++){
        for(int j=0; j<=9; j++){
            for(int k=0; k<=j; k++){
                dp[i][j] += dp[i-1][k] % modNum;
            }
        }
    }

    for(int i=0; i<=9; i++){
        ans += dp[N][i] % modNum;
        ans %= modNum;
    }

    cout << ans << '\n';

    return 0;
}