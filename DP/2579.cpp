#include <iostream>
#include <vector>
using namespace std;

long long int dp[301][3];

long long int f(int n){
    vector<int> stairs;
    int a;
    stairs.push_back(0);
    for(int i=0; i<n; i++){
        cin >> a;
        stairs.push_back(a);
    }

    dp[1][1] = stairs[1];
    dp[2][1] = stairs[2];
    dp[2][2] = stairs[1] + stairs[2];
    dp[3][1] = stairs[1] + stairs[3];
    dp[3][2] = stairs[2] + stairs[3];

    for(int i=4; i<=n; i++){
        long long int largest = 0;
        for(int j=1; j<=2; j++){
            if(j==1){
                largest = max(dp[i - 2][1], dp[i - 2][2]);
                dp[i][j] = largest + stairs[i];
            }else{
                dp[i][j] = dp[i-1][1] + stairs[i];
            }
        }
    }

    long long int answer = 0;
    answer = max(dp[n][1], dp[n][2]);
    return answer;
}

int main(){

    int n;

    cin >> n;

    cout << f(n) << endl;

    return 0;
}