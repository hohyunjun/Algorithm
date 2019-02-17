#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    
    cin >> n;

    vector<int> A(n, 0);
    vector<int> dp(n, 0); // dp[i] = A[i]를 마지막 요소로 가지는 가장 긴 감소하는 부분수열

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    dp[0] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(A[j] > A[i]){
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i]+=1;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}