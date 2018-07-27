#include <iostream>
#include <string.h>
using namespace std;

long long int dp[201][201];

long long int f(int n, int k){
    // 일단 전체를 0으로 초기화
    for(int i=0; i<201; i++){
        memset(dp[i], 0, sizeof(long long int)*201);
    }
    for(int i=0; i<201; i++){
        dp[0][i] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            // if(j>i){
            //     dp[i][j] = dp[i][j-1] % 1000000000;
            // }
            // else{
                for (int l = 0; l <= i; l++){
                    dp[i][j] += dp[i - l][j - 1] % 1000000000;
                }
            // }
        }
    }

    return dp[n][k] % 1000000000;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;

    cin >> N;
    cin >> K;

    cout << f(N, K) % 1000000000 << endl;    

    return 0;
}