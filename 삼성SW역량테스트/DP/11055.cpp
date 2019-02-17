#include <iostream>
using namespace std;

// dp[n] = A[n]을 마지막 숫자로 가지는 증가부분수열의 합
int dp[1001];
int A[1001];

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    dp[0] = A[0];

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(A[j] < A[i]){
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += A[i];
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}