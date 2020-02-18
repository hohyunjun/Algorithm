#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 방향 0 북, 1 동, 2 남, 3 서
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int n, m;
int ans = -1;
// 보드판
vector<string> board(10);

// 10개의 방향을 담은 배열을 반환한다.
vector<int> getDir(int k){
    vector<int> dir(10);

    for(int i=0; i<10; i++){
        dir[i] = k%4;
        k >>= 2;
    }

    return dir;
}

// 두 가지 경우 제외(같은 방향으로 연속되는 경우, 반대방향으로 연속되는 경우)
bool valid(vector<int> &dir){
    for(int i=0; i+1<dir.size(); i++){
        if(dir[i]==0 && dir[i+1]==2) return false;
        if(dir[i]==2 && dir[i+1]==0) return false;
        if(dir[i]==1 && dir[i+1]==3) return false;
        if(dir[i]==3 && dir[i+1]==1) return false;
        if(dir[i]==dir[i+1]) return false;
    }
    return true;
}

// 한 칸만 이동시키는 함수 : 첫번째 반환값은 공이 움직였는지, 두번째는 공이 구멍에 빠졌는지
pair<bool, bool> simulate(int dir, vector<string> &tmpBoard, int &x, int &y){
    bool moved = false, hole = false;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    // 움직일 수 있을 경우
    if(nx >= 0 && ny >= 0 && nx < n && ny <m){
        if(tmpBoard[nx][ny] == '.'){ // 빈칸일경우
            moved = true;
            tmpBoard[nx][ny] = tmpBoard[x][y];
            tmpBoard[x][y] = '.';
            x = nx;
            y = ny;
            return make_pair(moved, false);
        }
        if(tmpBoard[nx][ny] == 'R' || tmpBoard[nx][ny] == 'B'){ // 구슬일 경우
            return make_pair(false, false);
        }
        if(tmpBoard[nx][ny] == 'O'){ // 구멍일 경우
            tmpBoard[x][y] = '.';
            x = nx;
            y = ny;
            return make_pair(true, true);
        }
        if(tmpBoard[nx][ny] == '#'){ // 벽일 경우
            return make_pair(false, false);
        }
    }
}

// 진짜 기울여 보고, 성공했을 경우 true return;
bool simulate(int curDir, vector<string> &tmpBoard){
    bool success = false;
    int bx, by, rx, ry, hx, hy; // 파란공, 빨간공, 구멍의 좌표 저장
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmpBoard[i][j] == 'B'){
                bx = i;
                by = j;
            }else if(tmpBoard[i][j] == 'R'){
                rx = i;
                ry = j;
            }else if(tmpBoard[i][j] == 'O'){
                hx = i;
                hy = j;
            }
        }
    }

    // 주의! 빨간 공이 구멍에 빠지면 성공, 파란 구슬이 빠지면 실패.
    // 둘 다 구멍에 빠져도 실패!
    bool rMoved = true, bMoved = true; // 빨간공, 파란공이 움직였는지 확인
    bool rHole = false, bHole = false; // 빨간공, 파란공이 구멍에 빠졌는지 확인

    // 빨간공이나 파란공이 하나라도 움직였다면
    while(rMoved || bMoved){
        auto sr = simulate(curDir, tmpBoard, rx, ry);
        auto sb = simulate(curDir, tmpBoard, bx, by);
        rMoved = sr.first;
        bMoved = sb.first;
        rHole = sr.second;
        bHole = sb.second;

        // 빨간 공이 구멍에 빠지고, 파란 공이 빠지지 않을 경우
        if(rHole && !bHole){
            success = true;
        }else if(rHole && bHole){ // 둘다 빠질경우
            success = false;
        }else if(!rHole && bHole){ // 파란공만 빠질경우
            success = false;
        }
    }

    return success;
}

// 방향에 따른 simulate를 호출하고, 성공했을 경우 ans 업데이트
void solve(vector<int> dir){

    // simulate를 위한 임시 보드 저장
    vector<string> tmpBoard(n);
    for(int i=0; i<n; i++){
        tmpBoard[i] = board[i];
    }

    for(int i=0; i<10; i++){
        if(simulate(dir[i], tmpBoard)){ // dir[i] 방향으로 simulate했을 때, 성공한 경우
            if(ans == -1 || ans > i+1) ans = i+1;
            return;
        }
    }
}


int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> board[i];
    }

    // 방향을 전환할 수 있는 모든 경우의 수를 다 수행한다. 최대 가능한 경우의 수는 4^10 = 2^20
    for(int i=0; i <=(1<<20); i++){
        vector<int> dir = getDir(i); // 10개의 방향을 담고있는 배열
        // 같은 방향이 연속되는 경우, 반대방향이 연속되는 경우 제외
        if(!valid(dir)) continue;
        solve(dir);
    }

    cout << ans << '\n';


    return 0;
}