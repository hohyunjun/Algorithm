#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int dist[101][101];
int A[101][101];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int main(){

    memset(dist, -1, sizeof(dist));

    int n, m;

    scanf("%d%d", &m, &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &A[i][j]);
        }
    }

    deque<pair<int, int>> dq;
    dq.push_front(make_pair(0,0));
    dist[0][0] = 0;

    while(!dq.empty()){
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                if(dist[nx][ny] == -1 && A[nx][ny] == 0){
                    dq.push_front(make_pair(nx, ny));
                    dist[nx][ny] = dist[x][y];
                }else if(dist[nx][ny] == -1 && A[nx][ny] == 1){
                    dq.push_back(make_pair(nx, ny));
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }

    printf("%d\n", dist[n-1][m-1]);

    return 0;
}