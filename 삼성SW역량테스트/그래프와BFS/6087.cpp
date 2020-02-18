#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int main(){

    int w, h;

    cin >> w >> h;

    vector<string> a(h);

    for(int i=0; i<h; i++){
        cin >> a[i];
    }

    // 두 지점 사이의 직선개수 -1 이 설치해야 하는 거울의 개수이다.
    // BFS 수행 시 인접한 정점만이 아닌 4방향의 모든 정점을 넣어서 돌린다.

    // 두 지점의 좌표 저장
    vector<pair<int,int>> tp;

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(a[i][j] == 'C'){
                tp.push_back(make_pair(i,j));
            }
        }
    }

    int check[101][101];
    memset(check, -1, sizeof(check));

    queue<pair<int,int>> q;
    int sx = tp[0].first;
    int sy = tp[0].second;
    q.push(make_pair(sx,sy));
    check[sx][sy] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            while(nx>=0 && ny>=0 && nx<h && ny<w){ // 지도를 벗어나지 않을 경우

                if(a[nx][ny] == '*') break;
                if(check[nx][ny] == -1){ // 방문되지 않은 정점일 경우만
                    check[nx][ny] = check[x][y] + 1;
                    q.push(make_pair(nx,ny));
                }
                nx = nx + dx[k];
                ny = ny + dy[k];
            }
        }
        q.pop();
    }

    int ansx = tp[1].first;
    int ansy = tp[1].second;

    cout << check[ansx][ansy] - 1 << '\n';


    return 0;
}