#include <iostream>
#include <math.h>
using namespace std;

int dp[100001];

int f(int n){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        int least = 0x7FFFFFFF;
        for(int j=1; ( pow(j,2) ) <=i; j++){
            int tmp = pow(j,2);
            least = min( dp[ i - tmp ] + 1, least);
        }
        dp[i] = least;
    }

    return dp[n];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    cout << f(N) << endl;


    return 0;
}