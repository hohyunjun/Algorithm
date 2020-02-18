#include <iostream>
using namespace std;

int a[10];

void solve(int index, int len, int n, int m){
    if(len == m){
        for(int i=0; i<m; i++){
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    for(int i=1; i<=n; i++){
        a[index] = i;
        solve(index+1, len+1, n, m);
    }
}



int main(){

    int n, m;

    cin >> n >> m;

    solve(0,0,n,m);

    return 0;
}