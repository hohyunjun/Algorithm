#include <cstdio>
#include <algorithm>
using namespace std;

int p[1001];
int dp[1001];

int main(){

    int n;
    scanf("%d", &n);

    for(int i=1; i<n+1; i++){
        scanf("%d", &p[i]);
    }    

    dp[0] = 0;
    dp[1] = p[1];

    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], p[j] + dp[i-j]);
        }
    }    

    printf("%d\n", dp[n]);

    return 0;
}