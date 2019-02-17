#include <iostream>
using namespace std;

int dp[1001];
int A[1001];

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    dp[0] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(A[j] < A[i]){
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i]+= 1;
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        ans = max(dp[i], ans);
    }

    cout << ans << '\n';

    return 0;
}