#include <iostream>
#include <vector>
using namespace std;

int dp[1001];

int f(int n){
    vector<int> A;
    int a;
    A.push_back(0x7FFFFFFF);
    for(int i=0; i<n; i++){
        cin >> a;
        A.push_back(a);
    }
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        int biggest = 0;
        for(int j=1; j<i; j++){
            if(A[j] < A[i]){
                biggest = max(biggest, dp[j]);
            }
        }
        dp[i] = biggest + 1;
    }

    int biggest = 0;
    for(int i=1; i<=n; i++){
        biggest = max(biggest, dp[i]);
    }

    return biggest;

}

int main(){

    int N;

    cin >> N;

    cout << f(N) << endl;

    return 0;
}