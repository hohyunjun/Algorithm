#include <iostream>
using namespace std;

int a[10] = {1,2,3,4,5,6,7,8,9,10};
int ans[10];

void solve(int index, int len, int n, int m){
    if(len == m){
        for(int i=0; i<m; i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    if(index >= n) return;

    ans[len] = a[index];
    solve(index+1, len+1, n, m);
    solve(index+1, len, n, m);
}

int main(){

    int n, m;

    cin >> n >> m;

    solve(0,0,n,m);

    return 0;
}