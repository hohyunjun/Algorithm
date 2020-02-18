#include <iostream>
using namespace std;


// 장소상태 : 0은 빈칸, 1은 벽, 2는 이미 청소한 공간
int A[51][51];
int n, m;

// 방향 0 북, 1 동, 2 남, 3 서
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


// 네 방향 모두가 불가능할 때 true 반환
bool check4(int x, int y){

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >=0 && ny >= 0 && nx < n && ny < m && A[nx][ny] == 0) return false;
    }

    return true;
}

int main(){

    cin >> n >> m;

    int robotX, robotY, dir;

    cin >> robotX >> robotY >> dir;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> A[i][j];
        }
    }

    int cnt = 0;

    // 탐색 시작
    while(true){
        
        // 현재 위치를 청소한다.
        if(A[robotX][robotY] == 0){
            A[robotX][robotY] = 2;
            cnt++;
        }

        // 네 방향 모두가 불가능할 경우 : 방향유지하고 후진
        if(check4(robotX, robotY)){
            int nx = robotX - dx[dir];
            int ny = robotY - dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) break; // 후진도 불가능할 경우
            if(A[nx][ny] == 1) break; // 후진도 불가능할 경우
            robotX = nx;
            robotY = ny;
            continue;
        }

        // 현재 방향을 기준으로 왼쪽부터 탐색을 시작한다.
        // 왼쪽 방향이 청소하지 않은 공간인지 확인
        int leftDir = dir - 1;
        if(leftDir == -1) leftDir = 3;

        // 왼쪽 방향에 청소하지 않은 공간이 존재한다면
        if(robotX + dx[leftDir] >=0 && robotX + dx[leftDir] < n && robotY + dy[leftDir] >=0 && robotY + dy[leftDir] < m){ // 좌표가 범위 내이고
            if(A[robotX + dx[leftDir]][robotY + dy[leftDir]] == 0){ 
                dir = leftDir;
                robotX = robotX + dx[dir];
                robotY = robotY + dy[dir];
                continue;
            }
        }

        // 청소할 공간이 없다면
        dir = leftDir;
        continue;

    }

    cout << cnt << '\n';


    return 0;
}