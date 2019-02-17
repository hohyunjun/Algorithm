#include <iostream>
using namespace std;

// dp[n] 은 2*n 크기의 직사각형을 채우는 방법의 수
int dp[1001];

int main(){

    int n;

    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i=4; i<=n; i++){
        dp[i] = (dp[i-1]%10007 + dp[i-2]%10007)%10007;
    }

    cout << dp[n] << '\n';


    return 0;
}