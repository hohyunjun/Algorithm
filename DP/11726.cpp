#include <iostream>
using namespace std;

int dp[1001] = {};

int f(int n){
    if(n<=2){
        dp[n] = n;
        return dp[n];
    }else{
        if(dp[n]>0){
            return dp[n];
        }else{
            dp[n] = (f(n-1)+f(n-2)) % 10007;
            return dp[n];
        }
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << f(n)<< endl;

    return 0;
}