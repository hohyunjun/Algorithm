#include <iostream>
using namespace std;

int A[100001];
int dp[100001];

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    dp[0] = A[0];

    for(int i=1; i<n; i++){
        dp[i] = A[i];
        dp[i] = max(dp[i], dp[i-1] + A[i]);
    }

    int ans = -0x7FFFFFFF;

    for(int i=0; i<n; i++){
        ans = max(dp[i], ans);
    }

    cout << ans << '\n';

    return 0;
}