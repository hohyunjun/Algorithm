#include <iostream>
using namespace std;

int dp[10001];
int A[101];

int main(){

    fill_n(dp, 10001, 0x7FFFFFF);
    int n, k;

    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    dp[0] = 0;

    for(int i=0; i<n; i++){
        if(A[i] < 10001){
            dp[A[i]] = 1;
        }
    }

    for(int i=1; i<=k; i++){
        if(dp[i] == 0x7FFFFFF){
            int v = 0x7FFFFFF;
            for(auto each:A){
                if(each <= i){
                    v = min(v, dp[i-each]);
                }
            }
            dp[i] = v+1;
        }
    }

    if(dp[k] == 0x7FFFFFF + 1){
        dp[k] = -1;
    }
    cout << dp[k] << '\n';


    return 0;
}