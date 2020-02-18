#include <iostream>
using namespace std;

/*
    1. dp[i] = A[i]로 끝나는 가장 긴 증가하는 부분수열이라고 정의한다.
    2. dp[0] = 1; 이라고 초기화하고,
       dp[1] 부터 시작해서 자기자신보다 작은 인덱스의 숫자가 더 작을 경우에, dp[i]의 최댓값을 구한다.
       dp[i] = 위에서 구한 최댓값 + 1 이다
    3. 구해진 dp[i]들 중에서 최댓값을 구한다.

*/


int n;
int A[1001];
int dp[1001];
int ans = 0;

int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    dp[0] = 1;

    // dp[i] = A[i]로 끝나는 가장 긴 증가하는 부분수열
    for(int i=1; i<n; i++){
        int biggest = 0;
        for(int j=0; j<i; j++){
            if(A[j] < A[i]){   
                biggest = max(biggest, dp[j]);
            }
        }
        dp[i] = biggest + 1;
    }

    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';


    return 0;
}