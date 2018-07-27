#include <iostream>
using namespace std;

int dp[1001][10];

int f(int n){
    if(n==1){
        int sum = 0;
        for(int i = 0; i<10; i++){
            sum += dp[1][i];
        }
        return sum;
    }
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            dp[i][j] = 0;
            for(int k=0; k<=j; k++){
                dp[i][j] += dp[i-1][k] % 10007;
            }
        }
    }
    int sum = 0;
    for(int i=0; i<10; i++){
        sum += dp[n][i] % 10007;
    }
    return sum;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int i=0; i<10; i++){
        dp[1][i] = 1;
    }

    cout << f(N) % 10007 << endl;



    return 0;
}