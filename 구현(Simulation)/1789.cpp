#include <iostream>
using namespace std;

long long int dp[1000001];

int main(){

    long long int a;

    cin >> a;

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=1000000; i++){
        dp[i] = dp[i-1] + i;
    }

    for(int i=0; i<=1000000; i++){
        if(dp[i] > a){
            cout << i-1 << endl;
            break;
        }
        if(dp[i] == a){
            cout << i << endl;
            break;
        }
    }

    return 0;
}