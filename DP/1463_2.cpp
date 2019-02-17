#include <iostream>
using namespace std;

int dp[1000000];

int main(){

    int N;

    cin >> N;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    if(N <= 3){
        cout << dp[N] << '\n';
    }else{
        for(int i=4; i<=N; i++){
            if(i%2==0 && i%3==0){
                int ans = 0xFFFFFFF;
                ans = min(ans, dp[i/2]);
                ans = min(ans, dp[i/3]);
                ans = min(ans, dp[i-1]);
                dp[i] = ans + 1;
            }else if(i%2 ==0){
                int ans = 0xFFFFFFF;
                ans = min(ans, dp[i/2]);
                ans = min(ans, dp[i-1]);
                dp[i] = ans + 1;
            }else if(i%3 ==0){
                int ans = 0xFFFFFFF;
                ans = min(ans, dp[i/3]);
                ans = min(ans, dp[i-1]);
                dp[i] = ans + 1;
            }else{
                dp[i] = dp[i-1] + 1;
            }
        }
        cout << dp[N] << '\n';
    }


    return 0;
}