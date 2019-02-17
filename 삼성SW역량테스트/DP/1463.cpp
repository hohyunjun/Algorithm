#include <iostream>
using namespace std;

int dp[1000001]; // dp[n]은 n에서 1을 만드는 데 쓰이는 연산의 최소 횟수

int main(){

    int n;

    cin >> n;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i=4; i<=n; i++){
        if(i%3 == 0 && i%2 == 0){
            dp[i] = dp[i-1];
            dp[i] = min(dp[i], dp[i/2]);
            dp[i] = min(dp[i], dp[i/3]);
            dp[i] += 1;
        }else if(i%3 == 0){
            dp[i] = dp[i-1];
            dp[i] = min(dp[i], dp[i/3]);
            dp[i] += 1;
        }else if(i%2 == 0){
            dp[i] = dp[i-1];
            dp[i] = min(dp[i], dp[i/2]);
            dp[i] += 1;
        }else{
            dp[i] = dp[i-1];
            dp[i] += 1;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}