#include <iostream>
using namespace std;

int dp[1000001] = {};
int f(int n){
    if(n==1){
        dp[n] = 0;
        return dp[n];
    }else{
        if(dp[n] > 0){
            return dp[n];
        }else{
            dp[n] = f(n-1) + 1;
            if (n % 2 == 0){
                int tmp = f(n/2) + 1;
                dp[n] = (tmp < dp[n]) ? tmp : dp[n];
            }
            if (n % 3 == 0){
                int tmp = f(n/3) + 1;
                dp[n] = (tmp < dp[n]) ? tmp : dp[n];
            }
            return dp[n];
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    cout << f(N) << endl;


    return 0;
}