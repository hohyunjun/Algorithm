#include <iostream>
using namespace std;

int A[100001];
int dp[100001];
int dpr[100001];
int dpa[100001];

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    dp[0] = A[0];

    for(int i=1; i<n; i++){
        dp[i] = max(A[i], dp[i-1] + A[i]);
    }

    dpr[n-1] = A[n-1];
    for(int i=n-1; i>=0; i--){
        dpr[i] = max(A[i], dpr[i+1] + A[i]);
    }

    int ans = -0x7FFFFFFF;
    for(int i=1; i<n; i++){
        ans = max(ans, dp[i]);
    }

    dpa[0] = ans;

    ans = -0x7FFFFFFF;
    for(int i=0; i<n-1; i++){
        ans = max(ans, dp[i]);
    }

    dpa[n-1] = ans;

    for(int i=1; i<n-1; i++){
        dpa[i] = dp[i-1] + dpr[i+1];
    }

    int rans = -0x7FFFFFFF;

    for(int i=0; i<n; i++){
        rans = max(rans, dpa[i]);
    }

    cout << rans << '\n';

    return 0;
}