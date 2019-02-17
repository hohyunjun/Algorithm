#include <iostream>
using namespace std;

int dp[12];

int main(){

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    int t;

    cin >> t;

    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        if(dp[n] > 0){
            cout << dp[n] << '\n';
        }else{
            for(int j=4; j<=n; j++){
                dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
            }
            cout << dp[n] << '\n';
        }
    }


    return 0;
}