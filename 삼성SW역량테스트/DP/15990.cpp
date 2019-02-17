#include <iostream>
using namespace std;

int modNum = 1000000009;
// dp[n] = n을 1,2,3 의 합으로 나타내는 방법의 수(같은 수가 연속되지 않음)
long long int dp[100001][4];

int main(){

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for(int i=4; i<=100000; i++){
        for(int j=1; j<=3; j++){
            if(j==1){
                dp[i][j] = (dp[i-j][2]%modNum + dp[i-j][3]%modNum)%modNum;
            }else if(j==2){
                dp[i][j] = (dp[i-j][1]%modNum + dp[i-j][3]%modNum)%modNum;
            }else if(j==3){
                dp[i][j] = (dp[i-j][1]%modNum + dp[i-j][2]%modNum)%modNum;
            }
        }
    }


    int t;

    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << (dp[n][1]%modNum + dp[n][2]%modNum + dp[n][3]%modNum)%modNum << '\n';
    }


    return 0;
}