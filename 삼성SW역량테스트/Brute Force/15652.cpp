#include <iostream>
using namespace std;

int a[10];

void solve(int index, int start, int n, int m){
    // 답을 찾은경우
    if(index == m){
        // 출력
        for(int i=0; i<m; i++){
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    for(int i=start; i<=n; i++){
        a[index] = i;
        solve(index+1, i ,n, m);
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    solve(0, 1, n, m);

    return 0;
}