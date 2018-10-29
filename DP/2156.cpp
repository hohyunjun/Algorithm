#include <iostream>
using namespace std;

long long int dp[10001][3];

long long int f(int n){
    int grape[n];
    for(int i=0; i<n; i++){
        cin >> grape[i];
    }
    dp[1][0] = 0;
    dp[1][1] = grape[0];
    dp[1][2] = grape[0];
    dp[2][0] = grape[0];
    dp[2][1] = grape[1];
    dp[2][2] = grape[0] + grape[1];
    if(n<=2){
        long long int biggest = 0;
        biggest = max(dp[n][0], biggest);
        biggest = max(dp[n][1], biggest);
        biggest = max(dp[n][2], biggest);
        return biggest;
    }
    for(int i=3; i<=n; i++){
        for(int j=0; j<3; j++){
            if(j==0){
                long long int biggest = 0;
                biggest = max(dp[i-1][0], biggest);
                biggest = max(dp[i-1][1], biggest);
                biggest = max(dp[i-1][2], biggest);
                dp[i][j] = biggest;
            }
            if(j==1){
                dp[i][j] = dp[i-1][0] + grape[i-1];
            }
            if(j==2){
                dp[i][j] = dp[i-2][0] + grape[i-2] + grape[i-1];
            }
        }
    }
    long long int biggest = 0;
    biggest = max(dp[n][0], dp[n][1]);
    biggest = max(biggest, dp[n][2]);
    return biggest;
}

int main(){

    int n;

    cin >> n;

    cout << f(n) << endl;

    return  0;
}