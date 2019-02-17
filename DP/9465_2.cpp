#include <iostream>
#include <vector>
using namespace std;

int main(){

    int T;

    cin >> T;

    for(int i=0; i<T; i++){
        int n;
        int ans;
        cin >> n;
        vector<vector<int>> s(2, vector<int>(n+1,0)); // 2차원 벡터 생성
        vector<vector<int>> dp(2, vector<int>(n+1,0));
        for(int j=1; j<=n; j++){
            cin >> s[0][j];
        }
        for(int j=1; j<=n; j++){
            cin >> s[1][j];
        }

        dp[0][1] = s[0][1];
        dp[1][1] = s[1][1];

        for(int j=2; j<=n; j++){
            dp[0][j] = max(dp[1][j-1] + s[0][j], dp[0][j-1]);
            dp[1][j] = max(dp[0][j-1] + s[1][j], dp[1][j-1]);
        }

        ans = max(dp[0][n], dp[1][n]);

        cout << ans << '\n';
    }    


    return 0;
}