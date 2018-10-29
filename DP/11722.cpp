#include <iostream>
#include <vector>
using namespace std;

int dp[1001];

int f(int n){
    int a;
    vector<int> A;
    A.push_back(-1);
    for(int i=0; i<n; i++){
        cin >> a;
        A.push_back(a);
    }
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        int longgest = 0;
        for(int j=1; j<i; j++){
            if(A[j] > A[i]){
                longgest = max(longgest, dp[j]);
            }
        }
        dp[i] = longgest + 1;
    }

    int longgest = 0;
    for(int i=1; i<=n; i++){
        longgest = max(longgest, dp[i]);
    }

    return longgest;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    cout << f(N) << endl;

    return 0;
}