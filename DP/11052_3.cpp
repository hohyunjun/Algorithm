#include <iostream>
#include <vector>
using namespace std;

int dp[1001];

int main(){

    int n;
    cin >> n;
    vector<int> price(n+1);
    for(int i=1; i<=n; i++){
        cin >> price[i];
    }

    dp[1] = price[1];

    if(dp[n] > 0){
        cout << dp[n] << '\n';
    }else{
        for(int i=2; i<=n; i++){
            int ans = 0;
            for(int j=1; j<=i; j++){
                ans = max(dp[i-j] + price[j], ans);
            }
            dp[i] = ans;
        }
        cout << dp[n] << '\n';
    }

    return 0;
}