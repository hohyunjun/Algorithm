#include <iostream>
using namespace std;

int dp[1000001];
int A[1000001];

int main(){

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    dp[0] = 1;

    for(int i=1; i<n; i++){
        int ll = 1;
        for(int j=0; j<i; j++){
            if(A[j] < A[i]){
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