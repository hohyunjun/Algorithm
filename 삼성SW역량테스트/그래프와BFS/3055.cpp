#include <iostream>
#include <queue>
using namespace std;

char A[51][51];
int dist[51][51];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    int destX, destY;
    int startX, startY;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> A[i][j];
            if(A[i][j] == 'D'){
                destX = i;
                destY = j;
            }
            if(A[i][j] == 'S'){
                startX = i;
                startY = j;
            }
        }
    }

    // 물의 이동 : 물이 찬 dist에는 물이 차는 시간을 채운다. : D가 위치한 곳과 돌이 있는 곳은 갈 수 없다.
    queue<pair<int,int>> water;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j] == '*'){
                water.push(make_pair(i,j));
                dist[i][j] = 1;
            }
        }
    }

    // 고슴도치의 이동 : 물이 차 있는 곳과 돌이 있는 곳은 갈 수 없다
    queue<pair<int,int>> go;    
    go.push(make_pair(startX, startY));
    dist[startX][startY] = 1;

    // 비어있는 곳은 '.' 물이 차있는 곳은 '*' 돌은 'X'
    // 물이 차는 시간 먼저 채운다
    while(!water.empty()){
        int wx = water.front().first;
        int wy = water.front().second;
        water.pop();
        for(int i=0; i<4; i++){
            int nwx = wx + dx[i];
            int nwy = wy + dy[i];
            if(nwx >= 0 && nwy >= 0 && nwx < n && nwy < m){
                if(A[nwx][nwy] != 'D' && A[nwx][nwy] != 'X' && dist[nwx][nwy] == 0){
                    dist[nwx][nwy] = dist[wx][wy] + 1;
                    water.push(make_pair(nwx, nwy));
                }
            }
        }
    }

    // 물이 차는 시간을 고려해서 비버의 이동시간을 채운다.
    while(!go.empty()){
        int gx = go.front().first;
        int gy = go.front().second;
        go.pop();
        for(int i=0; i<4; i++){
            int ngx = gx + dx[i];
            int ngy = gy + dy[i];
            if(ngx >= 0 && ngy >= 0 && ngx < n && ngy < m){
                if(A[ngx][ngy] != 'X' && dist[ngx][ngy] == 0){
                    dist[ngx][ngy] = dist[gx][gy] + 1;
                    go.push(make_pair(ngx, ngy));
                }else if(A[ngx][ngy] != 'X' && dist[ngx][ngy] > dist[gx][gy] + 1){
                    dist[ngx][ngy] = dist[gx][gy] + 1;
                    go.push(make_pair(ngx, ngy));
                }
            }
        }
    }

    if(dist[destX][destY] == -1 || dist[destX][destY] == 0){
        cout << "KAKTUS\n";
    }else{
        cout << dist[destX][destY] - 1 << '\n';
    }

    return 0;
}