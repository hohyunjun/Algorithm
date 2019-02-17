#include <iostream>
using namespace std;

// dp[n] 은 n을 1,2,3의 합으로 나타내는 방법의 수
long long int dp[1000001];
int mod = 1000000009;

int main(){

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;


    for(int i=4; i<=1000000; i++){
        dp[i] = (dp[i-1]%mod + dp[i-2]%mod + dp[i-3]%mod)%mod;
    }


    int t;

    cin >> t;

    while(t--){
        int n;
       cin >> n;
       cout << dp[n] << '\n';
    }


    return 0;
}