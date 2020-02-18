#include <iostream>
using namespace std;

int ans = 0;
int n;

bool col[15]; // |
bool dig1[31]; // /
bool dig2[31]; // \

bool check(int r, int c){
    if(col[c]) return false;
    if(dig1[r+c]) return false;
    if(dig2[n-1+r-c]) return false;
    return true;
}

void solve(int row){
    // 맨 끝줄까지 다 놓았을 때
    if(row == n){
        ans += 1;
    }

    // 열 검사
    for(int i=0; i<n; i++){
        if(check(row, i)){ // (row,i) 에 놓을 수 있다면
            col[i] = true;
            dig1[row + i] = true;
            dig2[n - 1 + row -i] = true;
            solve(row+1);
            col[i] = false;
            dig1[row + i] = false;
            dig2[n - 1 + row - i] = false;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    solve(0);

    cout << ans << '\n';

    return 0;
}