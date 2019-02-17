#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;

    cin >> n;

    vector<int> A(n, 0);
    vector<int> dp(n, 0);
    vector<int> dpf(n, 0);
    vector<int> dpb(n, 0);

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    // 맨 앞에서부터 LIS 찾기
    dpf[0] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(A[j] < A[i]){
                dpf[i] = max(dpf[i], dpf[j]);
            }
        }
        dpf[i] += 1;
    }

    // 맨 뒤에서부터 LIS 찾기
    dpb[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(A[i] > A[j]){
                dpb[i] = max(dpb[i], dpb[j]);
            }
        }
        dpb[i] += 1;
    }

    for(int i=0; i<n; i++){
        dp[i] = dpf[i] + dpb[i];
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]);
    }

    cout << ans-1 << '\n';

    return 0;
}