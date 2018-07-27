#include <iostream>
using namespace std;

long long int dp[101][10];

long long int f(int n){
    if(n==1){
        long long int sum = 0;
        for(int i=0; i<10; i++){
            sum+= dp[n][i];
        }
        return sum;
    }
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            if(j==0){
                dp[i][j] = dp[i-1][1] % 1000000000;
            }else if(j==9){
                dp[i][j] = dp[i-1][8] % 1000000000;
            }else{
                dp[i][j] = dp[i-1][j-1] % 1000000000 + dp[i-1][j+1] % 1000000000;
            }
        }
    }
    long long int sum = 0;
    for(int i=0; i<10; i++){
        sum += dp[n][i] % 1000000000;
    }
    return sum;
}

int main(){

    int N;

    dp[1][0] = 0;
    for(int i=1; i<10; i++){
        dp[1][i] = 1;
    }

    cin >> N;

    cout << f(N) % 1000000000 << endl;

    return 0;
}