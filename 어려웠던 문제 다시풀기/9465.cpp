#include <cstdio>
#include <algorithm>
using namespace std;

int A[2][100001];
int dp[3][100001];

int main(){

    int times;
    scanf("%d", &times);

    for(int k = 0; k<times; k++){
        int t;
        scanf("%d", &t);

        for (int i = 0; i < t; i++)
        {
            scanf("%d", &A[0][i]);
        }

        for (int i = 0; i < t; i++)
        {
            scanf("%d", &A[1][i]);
        }

        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[2][0] = 0;

        for (int i = 1; i <= t; i++)
        {
            for (int s = 0; s < 3; s++)
            {
                if (s == 0)
                {
                    dp[s][i] = max(dp[0][i - 1], dp[1][i - 1]);
                    dp[s][i] = max(dp[s][i], dp[2][i - 1]);
                }
                else if (s == 1)
                {
                    dp[s][i] = max(dp[0][i - 1] + A[0][i - 1], dp[2][i - 1] + A[0][i - 1]);
                }
                else
                {
                    dp[s][i] = max(dp[0][i - 1] + A[1][i - 1], dp[1][i - 1] + A[1][i - 1]);
                }
            }
        }

        int ans = 0;
        ans = max(dp[0][t], dp[1][t]);
        ans = max(ans, dp[2][t]);

        printf("%d\n", ans);
    }

    return 0;
}