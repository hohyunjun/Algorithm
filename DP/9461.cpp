#include <iostream>
using namespace std;

long long int dp[101];

long long int p(int n){
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    dp[7] = 4;
    dp[8] = 5;
    for(int i=9; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-5];
    }
    return dp[n];
}

int main(){

    int T, N;

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N;
        cout << p(N) << endl;
    }

    return 0;
}