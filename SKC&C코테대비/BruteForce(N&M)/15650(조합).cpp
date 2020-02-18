#include <iostream>
using namespace std;

int a[8];
bool check[8];

void solve(int index, int start, int n, int m){
    if(index == m){
        for(int i=0; i<m; i++){
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=start; i<=n; i++){
        if(check[i]) continue;
        a[index] = i;
        check[i] = true;
        solve(index+1, i+1, n, m);
        check[i] = false;
    }
}

int main(){

    // 1~n 까지 중에서 m개로 이루어진 순열들을 출력
    int n, m;
    
    cin >> n >> m;

    solve(0, 1, n, m);

    return 0;
}