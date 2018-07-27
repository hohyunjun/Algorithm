#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

long long int dp[5001][27];

long long int f(){

    vector<int> A;
    string a;
    cin >> a;
    int changeda;
    for(int i=0; i<a.length(); i++){
        changeda = a[i] - '0';
        A.push_back(changeda);
    }
    int n = a.length();

    //마지막 값 저장
    int last = A[a.length()-1];
    //dp 값 초기화
    for(int i=0; i<5001; i++){
        memset(dp[i], 0, sizeof(long long int)*27);
    }

    dp[1][A[0]] = 1;
    for(int i=2; i<=n; i++){
        for(int j=1; j<=26; j++){
            dp[i][A[i-1]] += dp[i-1][j]%1000000;
        }
        dp[i][10+A[i-1]] += dp[i-1][1]%1000000;
        if(A[i-1]<=6){
            dp[i][20+A[i-1]] += dp[i-1][2]%1000000;
        }
    }
    
    long long int answer = 0;
    for(int i=1; i<=26; i++){
        answer += dp[n][i]%1000000;
    }

    return answer;
}


int main(){

    cout << f()%1000000 << endl;

    return 0;
}