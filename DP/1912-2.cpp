#include <iostream>
#include <vector>
using namespace std;

int dp[100001];

int f(int n)
{
    vector<int> A;
    int a;
    A.push_back(0);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        A.push_back(a);
    }

    dp[1] = A[1];
    for(int i=2; i<=n; i++){
        int largest = 0;
        largest = max(dp[i-1] + A[i], A[i]);
        dp[i] = largest;
    }

    int answer = -9999;
    for(int i=1; i<=n; i++){
        answer = max(answer, dp[i]);
    }

    return answer;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << f(n) << endl;

    return 0;
}