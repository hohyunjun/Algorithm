#include <iostream>
#include <stack>
using namespace std;

int dp[1001];
int A[1001];
int V[1001];

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    dp[0] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(A[j] < A[i]){
                if(dp[i] < dp[j]){
                    dp[i] = dp[j];
                    V[i] = j;
                }
            }
        }
        dp[i]+= 1;
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        ans = max(dp[i], ans);
    }

    cout << ans << '\n';
    
    int startIdx;

    for(int i=0; i<n; i++){
        if(dp[i] == ans){
            startIdx = i;
            break;
        }
    }

    stack<int> s;

    while(true){
        s.push(A[startIdx]);
        if(dp[startIdx] == 1) break;
        startIdx = V[startIdx];
    }

    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}