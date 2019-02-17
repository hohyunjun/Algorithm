#include <iostream>
using namespace std;

int check[10];
int a[10];

void solve(int index, int n, int m){
    if(index == m){
        // 출력
        for(int i=0; i<m; i++){
            cout << a[i] << " ";
        }
        cout << '\n'; 
        return;
    }
    for(int i=1; i<=n; i++){
        if(check[i]) continue;
        // 사용했으면 체크
        check[i] = true;
        a[index] = i;
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