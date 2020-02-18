#include <iostream>
using namespace std;

int A[10][10];

// 각 대각선이 이미 존재하는지 체크
bool dig1[20]; // 우상향
bool dig2[20]; // 우하향
int n;
int ans = 0;

bool check(int row, int col){
    if(A[row][col] == 0) return false;
    if(dig1[row+col]) return false;
    if(dig2[row-col+n-1]) return false;

    return true;
}


// 비숍개수, 열, 행
void solve(int cnt, int row, int col){
    // 종료조건
    if(row == n){
        if(ans < cnt) ans = cnt;
        return;
    }

    // 행이 범위를 넘어가면
    if(col == n){
        solve(cnt, row+1, 0);
        return;
    }

    if(A[row][col] == 0){
        solve(cnt, row, col+1);
        return;
    }

    if(check(row,col)){ // 놓을 수 있다면 놓는 경우
        dig1[row+col] = true;
        dig2[row-col+n-1] = true;
        solve(cnt+1, row, col+1);
        dig1[row+col] = false;
        dig2[row-col+n-1] = false;
    }

    // 안놓고 넘어가는경우
    solve(cnt, row, col+1);
}


int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A[i][j];
        }
    }

    solve(0,0,0);

    cout << ans << '\n';

    return 0;
}