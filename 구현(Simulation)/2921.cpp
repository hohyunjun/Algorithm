#include <iostream>
using namespace std;

int main(){

    int n;

    cin >> n;

    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<=n; j++){
            ans += i + j;
        }
    }

    for(int i=0; i<=n; i++){
        ans += i*2;
    }
    
    cout << ans << '\n';
    
    return 0;
}