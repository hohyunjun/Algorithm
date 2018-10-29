#include <cstdio>
using namespace std;

long long int dp[1001];

int main(){

    dp[1] = 1;
    dp[2] = 2;

    int n;
    scanf("%d", &n);

    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    printf("%d", dp[n]%10007);



    return 0;
}