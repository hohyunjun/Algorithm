#include <iostream>
#include <math.h>
using namespace std;

int dp[31];

int f(int n){

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    for(int i=3; i<=n; i++){
        dp[i] = 3*dp[i-2];
        for(int j=2; j*2<=i; j++){
            dp[i] += 2*dp[i-2*j];
        }
    }

    return dp[n];
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    cout << f(N) << endl;

    return 0;
}