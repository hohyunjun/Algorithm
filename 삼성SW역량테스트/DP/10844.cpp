#include <iostream>
using namespace std;

int modNum = 1000000000;

// dp[i][j] = 길이가 i인 숫자 중 j로 끝나는 계단수의 개수
long long int dp[101][10];


int main(){

    for(int i=1; i<=9; i++){
        dp[1][i] = 1;
    }

    int n;

    cin >> n;

    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            if(j==0){
                dp[i][j] = dp[i-1][j+1] % modNum;
            }else if(j==9){
                dp[i][j] = dp[i-1][j-1] % modNum;
            }else{
                dp[i][j] = (dp[i-1][j-1] % modNum + dp[i-1][j+1]%modNum) % modNum;
            }
        }
    }

    int ans = 0;

    for(int j=0; j<=9; j++){
        ans += dp[n][j] % modNum;
        ans %= modNum;
    }

    cout << ans << '\n';

    return 0;
}