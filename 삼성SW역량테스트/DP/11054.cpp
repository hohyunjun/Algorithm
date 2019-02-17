#include <iostream>
using namespace std;

// dpd[n] = A[n]으로 시작하는 가장 긴 감소하는 부분수열의 길이
int dpd[1001];
// dpi[n] = A[n]으로 끝나는 가장 긴 증가하는 부분수열의 길이
int dpi[1001];
int A[1001];

int main(){

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    dpi[0] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(A[j] < A[i]){
                dpi[i] = max(dpi[i], dpi[j]);
            }
        }
        dpi[i]+=1;
    }

    dpd[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(A[j] < A[i]){
                dpd[i] = max(dpd[i], dpd[j]);
            }
        }
        dpd[i] += 1;
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        ans = max(ans, dpi[i] + dpd[i] - 1);
    }

    cout << ans << '\n';

    return 0;
}