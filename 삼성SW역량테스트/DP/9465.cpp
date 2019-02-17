#include <iostream>
using namespace std;

int dp[100001][3];
int sticker[2][100001];

int main(){

    int t;

    cin >> t;

    while(t--){
        int n;
        cin >> n;
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                cin >> sticker[i][j];
            }
        }

        dp[0][0] = sticker[0][0];
        dp[0][1] = sticker[1][0];
        dp[0][2] = 0;

        for(int i=1; i<n; i++){
            dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + sticker[0][i];
            dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + sticker[1][i];
            dp[i][2] = max(dp[i-1][1],dp[i-1][0]);
            dp[i][2] = max(dp[i][2], dp[i-1][2]);
        }

        cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]) << '\n';
    }


    return 0;
}