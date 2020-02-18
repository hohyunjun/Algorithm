#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;

    cin >> n;

    vector<int> A(n);
    vector<int> B(n);

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    for(int i=0; i<n; i++){
        cin >> B[i];
    }

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());

    int ans = 0;
    for(int i=0; i<n; i++){
        ans += A[i] * B[i];
    }

    cout << ans << '\n';


    return 0;
}