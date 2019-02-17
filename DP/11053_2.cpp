#include <iostream>
using namespace std;

int dp[1001]; // A[i]를 마지막 요소로 가지는 LIS를 저장한다.
int A[1001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    dp[0] = 1;

    for(int i=1; i<n; i++){
        int ll = 1;
        for(int j=0; j<i; j++){
            if(A[j] <= A[i]){
                ll = max(ll, dp[j] + 1);
            }
        }
        dp[i] = ll;
    }
    
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}