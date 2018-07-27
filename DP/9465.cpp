#include <iostream>
using namespace std;

int dp[100001][3];

int f(int n){
    int score[2][n];
    for(int i=0; i<n; i++){
        cin >> score[0][i];
    }
    for(int i=0; i<n; i++){
        cin >> score[1][i];
    }
    dp[1][0] = 0;
    dp[1][1] = score[0][0];
    dp[1][2] = score[1][0];

    if(n==1){
        return max(dp[n][1],dp[n][2]);
    }
    for(int i=2; i<=n; i++){
        for(int j=0; j<3; j++){
            if(j==0){
                int biggest = 0;
                biggest = max(dp[i - 1][0], biggest);
                biggest = max(dp[i - 1][1], biggest);
                biggest = max(dp[i - 1][2], biggest);
                dp[i][j] = biggest;
            }else if(j==1){
                dp[i][j] = max(dp[i-1][0], dp[i-1][2]) + score[0][i-1];
            }else if(j==2){
                dp[i][j] = max(dp[i-1][0], dp[i-1][1]) + score[1][i-1];
            }
        }
    }
    int answer = 0;
    answer = max(dp[n][0], answer);
    answer = max(dp[n][1], answer);
    answer = max(dp[n][2], answer);
    return answer;
}

int main(){

    int T, n;

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> n;
        cout << f(n) << endl;
    }


    return 0;
}