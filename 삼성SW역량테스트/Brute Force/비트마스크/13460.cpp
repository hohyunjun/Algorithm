#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ans = 11;
// 왼쪽, 위, 오른쪽, 아래 순으로 0,1,2,3
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

vector<int> gen(int k){
    vector<int> dir(10);
    for(int i=0; i<10; i++){
        dir[i] = (k&3); // k%3과 같은 비트연산
        k >>= 2; // 계산한 k값 두칸 밀어준다.
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

pair<bool,bool> simulate(vector<string> &A, int dir, int &x, int &y){
    int moved = false;
    int holeIn = false;
    int n = A.size(); // 세로길이
    int m = A[0].length(); // 가로길이
    int nx, ny;
    nx = x + dx[dir];
    ny = y + dy[dir];

    // 이동불가
    if(nx<=0 || ny<=0 || nx >= n || ny >= m){
        return make_pair(false, false);
    }

    if(A[nx][ny] == '#'){
        return make_pair(moved, holeIn);
    }
    if(A[nx][ny] == 'O'){
        A[x][y] = '.';
        x = nx; y = ny;
        moved = true;
        holeIn = true;
        return make_pair(moved, holeIn);
    }
    if(A[nx][ny] == '.'){
        swap(A[x][y], A[nx][ny]); // .과 공의 위치를 바꿈
        x = nx; y = ny;
        moved = true;
        return make_pair(moved, holeIn);
    }
    if(A[nx][ny] == 'R' || A[nx][ny] == 'B'){
        return make_pair(moved, holeIn);
    }
}


// 10번의 시도 방향이 나왔을 때 실제 simulate 해보는 함수
int check(vector<int> &dir, vector<string> A){
    int cnt = 0;
    // 구멍 위치, 파란구슬, 빨간구슬 위치 체크
    int hx, hy, rx, ry, bx, by;
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<A[i].length(); j++){
            if(A[i][j] == '#') continue;
            if(A[i][j] == '.') continue;
            if(A[i][j] == 'B'){
                bx = i;
                by = j;
            }else if(A[i][j] == 'R'){
                rx = i;
                ry = j;
            }else if(A[i][j] == 'O'){
                hx = i;
                hy = j;
            }
        }
    }

    for(int k : dir){
        cnt+=1;
        bool rhole = false, bhole = false;
        while(true){
            auto p1 = simulate(A,k,rx,ry);
            auto p2 = simulate(A,k,bx,by);
            // 빨간공과 파란공이 둘 다 이동하지 않았다면 break;
            if(p1.first == false && p2.first == false){
                break;
            }
            if(p1.second) rhole = true;
            if(p2.second) bhole = true;
        }
        if(bhole) return 11;
        if(rhole) return cnt;
    }
    return 11;
}

int main(){

    int n, m; // n이 세로, m이 가로

    cin >> n >> m;

    vector<string> A(n);

    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    // 비트마스크를 이용해서 2의 20승 가지 경우를 모두 해 본다.
    for(int i=0; i< (1<<20); i++){
        // 비트마스크 i를 4진수로 변환한다.(4가지 방향 형태로 바꾸어야 한다.)
        vector<int> direction = gen(i);
        // 연속해서 같은방향, 바로 반대방향 가는 경우 제외
        if(!valid(direction)) continue;
        // 구해진 10회의 방향으로 simulation해서 최소 횟수를 구한다.
        int localAns = check(direction, A);
        ans = min(localAns, ans);
    }

    if(ans == 11){
        ans = -1;
    }

    cout << ans << '\n';

    return 0;
}