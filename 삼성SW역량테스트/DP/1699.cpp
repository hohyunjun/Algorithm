#include <iostream>
#include <math.h>
using namespace std;

// dp[n] = 어떤 자연수 n을 나타내는데 필요한 제곱수 항의 최소 개수
int dp[100001];

int main(){

    int test = sqrt(100000);

    // 제곱수들의 최소항 체크
    for(int i=0; i<=test; i++){
        int tmp = pow(i,2);
        dp[tmp] = 1;
    }

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        // 아직 최소항을 구하지 않은 숫자일 경우
        if(dp[i] == 0){
            dp[i] = 0x7FFFFFFF;
            int tmp = sqrt(i);
            for(int j=1; j<=tmp; j++){
                int tmp2 = i-pow(j,2);
                dp[i] = min(dp[i], dp[tmp2] + 1);
            }
        }
    }

    cout << dp[n] << '\n';

    return 0;
}