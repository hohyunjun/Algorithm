#include <cstdio>
#include <queue>
using namespace std;

int A[101][101];
int dist[101][101];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};


int main(){

    int m, n;

    scanf("%d%d", &n, &m); // n이 줄, m이 열

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &A[i][j]);
        }
    }

    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    dist[0][0] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(dist[nx][ny] == 0 && A[nx][ny] == 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
        q.pop();
    }

    printf("%d", dist[n-1][m-1]);

    return 0;
}
