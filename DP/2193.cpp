#include <iostream>
using namespace std;

long long int dp[91] = {};

long long int f(int n){
    if(n<=2){
        dp[n] = 1;
        return dp[n];
    }
    else{
        if(dp[n]>0){
            return dp[n];
        }else{
            dp[n] = f(n-1) + f(n-2);
            return dp[n];
        }
    }
}

int main(){

    int N;

    cin >> N;

    cout << f(N) << endl;


    return 0;
}