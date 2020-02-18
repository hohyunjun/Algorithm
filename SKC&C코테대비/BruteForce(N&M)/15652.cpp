#include <iostream>
using namespace std;

int a[10];

void solve(int index, int start, int n, int m){
    if(index == m ){
        for(int i=0; i<m; i++){
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=start; i<=n; i++){
        a[index] = i;
        solve(index+1, i, n, m);
    }
}

int main(){

    int n, m;

    cin >> n >> m;

    solve(0,1,n,m);

    return 0;
}