#include <iostream>
#include <vector>
using namespace std;

int dp[100001];

int f(int n){
    vector<int> A;
    int a;
    A.push_back(0);
    for(int i=0; i<n; i++){
        cin >> a;
        A.push_back(a);
    }
    int largest, tmp;
    tmp = A[1];
    largest = A[1];
    dp[1] = largest;
    for(int i=2; i<=n; i++){
        if(A[i-1]>0 && A[i]>0){ // 양수 양수
            tmp += A[i];
            largest = max(largest, tmp);
        }else if(A[i-1] < 0 && A[i] < 0){ // 음수 음수
            tmp = 0;
            tmp += A[i];
            largest = max(largest, tmp);
        }else{
            if(tmp<0){
                tmp = 0;
                tmp += A[i];
                largest = max(largest, tmp);
            }else{
                tmp += A[i];
                largest = max(largest, tmp);
            }
        }
        dp[i] = largest;
    }

    return dp[n];
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << f(n) << endl;

    return 0;
}