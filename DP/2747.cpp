#include <iostream>
using namespace std;

long long int dp[91] = {};

int fibonacci(int n){
    if(n<=1){
        dp[n] = n;
        return dp[n];
    }else{
        if(dp[n] > 0 ){
            return dp[n];
        }else{
            dp[n] = fibonacci(n-1) + fibonacci(n-2);
            return dp[n];
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << fibonacci(n) << endl;

    return 0;
}