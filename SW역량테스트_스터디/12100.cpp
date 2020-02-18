#include <iostream>
#include <vector>
using namespace std;

/*
    BOJ 12100 2048(Easy)

    가능한 모든 경우의 수는 2^10(5번의 시행, 가능한 방향 4개)

*/

// 0 왼쪽, 1 위쪽, 2 오른쪽, 3 아래쪽
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int n;

vector<int> gen(int num){
    vector<int> dir(5);

    for(int i=0; i<5; i++){
        dir[i] = num%4;
        num >>= 2;
    }

    return dir;
}

// Board를 실제로 특정 방향으로 이동시키는 함수
int simulate(vector<vector<pair<int,bool>>> &Board, int dir){

    int localAns = 0; // 한 번의 시행 후에 최댓값

    // dir 방향으로 벽을 만나거나 숫자를 만날 때까지 이동한다.
    // 같은 숫자를 만나면 *2를 한다.
    // 한 번의 이동에서 이미 합쳐진 블록은 또 합쳐질 수 없다. 

    // 왼쪽
    if(dir == 0){
        for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                if(Board[i][j].first == 0) continue; // 0인경우 넘어가고
                int curx = i;
                int cury = j;
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                while(nx >=0 && ny >= 0 && nx < n && ny < n && (Board[nx][ny].first == 0 || Board[nx][ny].first == Board[curx][cury].first) ){
                    if(Board[nx][ny].first == Board[curx][cury].first){
                        if(Board[nx][ny].second == false && Board[curx][cury].second == false){
                            Board[nx][ny].first = Board[nx][ny].first * 2;
                            Board[curx][cury].first = 0;
                            Board[nx][ny].second = true;
                        }else{ // 이미 합쳐진 놈이라면
                            break;
                        }
                    }else{
                        Board[nx][ny].first = Board[curx][cury].first; // 이동하고
                        Board[curx][cury].first = 0; // 비워주고
                        curx = nx;
                        cury = ny;
                        nx = curx + dx[dir];
                        ny = cury + dy[dir];
                    }
                }
            }
        }
    }else if(dir == 1){ // 위
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(Board[i][j].first == 0) continue; // 0인경우 넘어가고
                int curx = i;
                int cury = j;
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                while(nx >=0 && ny >= 0 && nx < n && ny < n && (Board[nx][ny].first == 0 || Board[nx][ny].first == Board[curx][cury].first) ){
                    if(Board[nx][ny].first == Board[curx][cury].first){
                        if(Board[nx][ny].second == false && Board[curx][cury].second == false){
                            Board[nx][ny].first = Board[nx][ny].first * 2;
                            Board[curx][cury].first = 0;
                            Board[nx][ny].second = true;
                        }else{ // 이미 합쳐진 놈이라면
                            break;
                        }
                    }else{
                        Board[nx][ny].first = Board[curx][cury].first; // 이동하고
                        Board[curx][cury].first = 0; // 비워주고
                        curx = nx;
                        cury = ny;
                        nx = curx + dx[dir];
                        ny = cury + dy[dir];
                    }
                }
            }
        }
    }else if(dir == 2){ // 오른쪽

        for(int j=n-1; j>=0; j--){
            for(int i=0; i<n; i++){
                if(Board[i][j].first == 0) continue; // 0인경우 넘어가고
                int curx = i;
                int cury = j;
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                while(nx >=0 && ny >= 0 && nx < n && ny < n && (Board[nx][ny].first == 0 || Board[nx][ny].first == Board[curx][cury].first) ){
                    if(Board[nx][ny].first == Board[curx][cury].first){
                        if(Board[nx][ny].second == false && Board[curx][cury].second == false){
                            Board[nx][ny].first = Board[nx][ny].first * 2;
                            Board[curx][cury].first = 0;
                            Board[nx][ny].second = true;
                        }else{ // 이미 합쳐진 놈이라면
                            break;
                        }
                    }else{
                        Board[nx][ny].first = Board[curx][cury].first; // 이동하고
                        Board[curx][cury].first = 0; // 비워주고
                        curx = nx;
                        cury = ny;
                        nx = curx + dx[dir];
                        ny = cury + dy[dir];
                    }
                }
            }
        }

    }else{ // 아래

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                if(Board[i][j].first == 0) continue; // 0인경우 넘어가고
                int curx = i;
                int cury = j;
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                while(nx >=0 && ny >= 0 && nx < n && ny < n && (Board[nx][ny].first == 0 || Board[nx][ny].first == Board[curx][cury].first) ){
                    if(Board[nx][ny].first == Board[curx][cury].first){
                        if(Board[nx][ny].second == false && Board[curx][cury].second == false){
                            Board[nx][ny].first = Board[nx][ny].first * 2;
                            Board[curx][cury].first = 0;
                            Board[nx][ny].second = true;
                        }else{ // 이미 합쳐진 놈이라면
                            break;
                        }
                    }else{
                        Board[nx][ny].first = Board[curx][cury].first; // 이동하고
                        Board[curx][cury].first = 0; // 비워주고
                        curx = nx;
                        cury = ny;
                        nx = curx + dx[dir];
                        ny = cury + dy[dir];
                    }
                }
            }
        }

    }

    // 시행 후 false로 초기화, local Ans 구한다.
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(Board[i][j].first == 0) continue;
            Board[i][j].second = false;
            if(localAns < Board[i][j].first) localAns = Board[i][j].first;
        }
    }

    return localAns;
}

int main(){


    int ans = 0;

    cin >> n;

    // Board의 숫자와 이미 합쳐졌는지 체크할 bool 변수 pair로 저장
    vector<vector<pair<int,bool>>> Board(n, vector< pair<int,bool> >(n,make_pair(0,false)));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> Board[i][j].first;
        }
    }

    // 2^10 가지 경우의 수
    for(int i=0; i <(1<<10); i++){
        vector<vector<pair<int,bool>>> tmpBoard(Board);
        vector<int> dir = gen(i);
        for(int i=0; i<5; i++){
            ans = max(ans, simulate(tmpBoard, dir[i]));
        }
    }

    cout << ans << '\n';


    return 0;
}