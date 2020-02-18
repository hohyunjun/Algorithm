#include <iostream>
#include <algorithm>
using namespace std;

int a[10];
int ans[10];

void solve(int index, int start, int n, int m){
    if(index == m){
        for(int i=0; i<m; i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=start; i<n; i++){
        ans[index] = a[i];
        solve(index+1, i, n, m);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    solve(0,0,n,m);

    return 0;
}