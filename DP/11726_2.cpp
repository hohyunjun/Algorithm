#include <iostream>
using namespace std;

int dp[1001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    if(dp[n] > 0){
        cout << dp[n] << '\n';
    }else{
        for(int i=4; i<=n; i++){
            dp[i] = ((dp[i-1] % 10007) + (dp[i-2] % 10007)) % 10007;
        }
        cout << dp[n] << '\n';
    }


}