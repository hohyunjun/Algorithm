#include <iostream>
using namespace std;

int cnt = 0;
bool A[15][15];
int n;

bool check(int row, int col){
    // |
    for(int i=0; i<n; i++){
        if(i == row) continue;
        if(A[i][col]){
            return false;
        }
    }

    // / 오른쪽 위
    int x = row - 1;
    int y = col + 1;
    while(x >= 0 && y < n){
        if(A[x][y]) return false;
        x -= 1;
        y += 1;
    }

    // \ 왼쪽 위
    int nx = row - 1;
    int ny = col - 1;
    while(nx >= 0 && ny >= 0){
        if(A[nx][ny]) return false;
        nx -= 1;
        ny -= 1;
    }

    return true;
}

void calc(int row){
    if(row == n){
        cnt += 1;
    }
    for(int col=0; col<n; col++){
        A[row][col] = true;
        if(check(row, col)){
            calc(row+1);
        }
        A[row][col] = false;
    }
}

int main(){

    cin >> n;

    calc(0);

    cout << cnt << '\n';

    return 0;
}