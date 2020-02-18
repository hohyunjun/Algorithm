#include <iostream>
using namespace std;

int a[8];
bool check[8];

// index 번째 숫자를 정해주는 함수
void solve(int index, int n, int m){
    if(index == m){
        for(int i=0; i<m; i++){
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++){
        if(check[i]) continue;
        a[index] = i;
        check[i] = true;
        solve(index+1, n, m);
        check[i] = false;
    }
}

int main(){

    int n, m;

    cin >> n >> m;

    solve(0,n,m);


    return 0;
}