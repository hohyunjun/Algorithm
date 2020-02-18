#include <iostream>
#include <string>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
int r, c;
string A[20];
int ans = 0;
bool alpha[26];

void solve(int x, int y, int cnt){
    if(ans < cnt) ans = cnt;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || ny<0 || nx>=r || ny>=c){
            continue;
        }
        if(!alpha[A[nx][ny] - 'A']){ // 사용된 적이 없다면
            alpha[A[nx][ny] - 'A'] = true;
            solve(nx, ny, cnt+1);
            alpha[A[nx][ny] - 'A'] = false;
        }
    }
}

int main(){

    cin >> r >> c;

    for(int i=0; i<r; i++){
        cin >> A[i];
    }

    alpha[A[0][0] - 'A'] = true;

    solve(0,0,1);

    cout << ans << '\n';

    return 0;
}