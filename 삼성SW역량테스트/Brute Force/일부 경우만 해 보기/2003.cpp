#include <iostream>
using namespace std;

int main(){

    int n, m;
    int A[10001];

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum+=A[j];
            if(sum == m){
                ans++;
            }else if(sum > m){
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}