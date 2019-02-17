#include <iostream>
#include <map>
using namespace std;

int r, c;
char A[21][21];
// 나온 알파벳들 체크
map<char, bool> m;
int ans = 0;
int dy[] = {-1,0,1,0};
int dx[] = {0,-1,0,1};

bool check(int row, int col){
    if(m[A[row][col]]) return false;
    return true;
}

void go(int row, int col, int depth){
    ans = max(ans, depth);
    for(int i=0; i<4; i++){
        int nx = row + dx[i];
        int ny = col + dy[i];
        if(nx>=0 && ny>=0 && nx<r && ny<c){
            if(check(nx, ny)){
                m[A[nx][ny]] = true;
                go(nx, ny, depth+1);
                m[A[nx][ny]] = false;
            }
        }
    }
}

int main(){

    cin >> r >> c;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> A[i][j];
        }
    }

    m[A[0][0]] = true;
    go(0,0,1);

    cout << ans << '\n';

    // if(check(1,0)) cout << "true!!" << '\n';
    // if(check(0,1)) cout << "true!!" << '\n';

    return 0;
}