#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;

    cin >> n;

    vector<int> A(n, 0);
    vector<int> dp(n,0);

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    dp[0] = A[0];

    for(int i=1; i<n; i++){
        int ls = A[i];
        for(int j=0; j<i; j++){
            int tmp = dp[j];
            if(A[j] < A[i]){
                tmp += A[i];
                ls = max(ls, tmp);
            }
        }
        dp[i] = ls;
    }

    int ans = 0;

    for(int i=0; i<n; i++){
       ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}