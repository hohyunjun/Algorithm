#include <iostream>
#include <vector>
using namespace std;

// int grape[10001];
// int dp[10001][3];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int ans = 0;
    cin >> n;

    vector<int> grape(n+1,0);
    vector< vector<int> > dp(n+1, vector<int>(3,0));

    for(int i=1; i<=n; i++){
        cin >> grape[i];
    }

    dp[1][0] = 0;
    dp[1][1] = grape[1];
    dp[1][2] = grape[1];
    
    dp[2][0] = grape[1];
    dp[2][1] = grape[2];
    dp[2][2] = grape[1] + grape[2];

    for(int i=3; i<=n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][0] = max(dp[i][0], dp[i-1][2]);
        dp[i][1] = dp[i-1][0] + grape[i];
        dp[i][2] = dp[i-1][1] + grape[i];
    }

    ans = max(ans, dp[n][0]);
    ans = max(ans, dp[n][1]);
    ans = max(ans, dp[n][2]);

    cout << ans << '\n';


    return 0;
}