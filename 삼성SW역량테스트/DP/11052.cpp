#include <iostream>
using namespace std;

int p[10001];
// dp[n] 은 n개의 카드를 사는 데 지불가능한 금액의 최댓값
int dp[1001];


int main(){

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> p[i];
    }

    dp[1] = p[1];

    for(int i=2; i<=n; i++){
        int tmp = p[i];
        for(int j=1; j<i; j++){
            tmp = max(tmp, dp[i-j] + p[j]);
        }
        dp[i] = tmp;
    }

    cout << dp[n] << '\n';


    return 0;
}