#include <iostream>
using namespace std;

int modNum = 1000000000;

int dp[101][101];

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    for(int i=1; i<=9; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=N; i++){
        for(int j=0; j<=9; j++){
            if(j==0){
                dp[i][j] = dp[i-1][j+1] % modNum;
            }else if(j==9){
                dp[i][j] = dp[i-1][j-1] % modNum;
            }else{
                dp[i][j] = dp[i-1][j-1] % modNum + dp[i-1][j+1] % modNum;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=9; i++){
        ans += dp[N][i] % modNum;
        ans %= modNum;
    }

    cout << ans << '\n';

    return 0;
}