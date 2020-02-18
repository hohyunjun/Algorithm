#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;

    cin >> n;

    vector<int> a(n,0);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int ans = 1; // 현재 꽂을 수 있는 플러그 개수

    for(int i=0; i<n; i++){
        ans = (ans-1) + a[i];
    }

    cout << ans << '\n';

    return 0;
}