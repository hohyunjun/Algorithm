#include <cstdio>
#include <algorithm>
using namespace std;

int A[1001];
int dp[1001]; // dp[i]는 A[i]를 마지막 수로 가지는 가장 긴 증가하는 부분수열

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &A[i]);
    }

    int ans = 0;

    dp[1] = 1;

    for(int i=2; i<=n; i++){
        int tmp = 0;
        for(int j=1; j<i; j++){
            tmp = dp[j];
            if(A[i] > A[j]) {tmp += 1;}
            else if(A[i] <= A[j]){
                tmp = 0;
            }
            dp[i] = max(tmp, dp[i]);
            tmp = 0;
        }
    }

    for(int i=1; i<=n; i++){
        ans = max(ans, dp[i]);
        //printf("%d ", dp[i]);
    }

    printf("%d", ans);

    return 0;
}