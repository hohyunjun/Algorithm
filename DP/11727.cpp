#include <iostream>
using namespace std;

int dp[1001] = {};

int f(int n)
{
    if(n==1){
        dp[n] = 1;
        return dp[n];
    }
    if (n == 2)
    {
        dp[n] = 3;
        return dp[n];
    }
    else
    {
        if (dp[n] > 0)
        {
            return dp[n];
        }
        else
        {
            dp[n] = (f(n - 1) % 10007) + (f(n - 2) % 10007) * 2;
            return dp[n];
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << f(n) % 10007 << endl;

    return 0;
}