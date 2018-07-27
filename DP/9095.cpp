#include <iostream>
using namespace std;

int dp[12];

int f(int n){

    if(n==1){
        dp[n] = 1;
        return dp[n];
    }
    if(n==2){
        dp[n] = 2;
        return dp[n];
    }
    if(n==3){
        dp[n] = 4;
        return dp[n];
    }
    if(n>3){
        if(dp[n] > 0){
            return dp[n];
        }else{
            dp[n] = f(n-1) + f(n-2) + f(n-3);
            return dp[n];
        }
    }

}

int main(){

    int T, N;

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N;
        cout << f(N) << endl;
    }
    return 0;
}