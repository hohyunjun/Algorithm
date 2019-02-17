#include <iostream>
using namespace std;

int check[10];
int a[10];

void solve(int index, int n, int m){
    // 종료조건
    if(index == m){
        //출력(오름차순 체크 후)
        int print = true;
        for(int i=0; i<m-1; i++){
            if(a[i] > a[i+1]){
                print = false;
                break;
            }
        }
        if(print){
            for(int i=0; i<m; i++){
                cout << a[i] << " ";
            }
            cout << '\n';
        }
        return;
    }

    for(int i=1; i<=n; i++){
        if(check[i]) continue;
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