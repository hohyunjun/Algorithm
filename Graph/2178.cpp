#include <cstdio>
#include <queue>
using namespace std;

int a[100][100];
int dist[100][100];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int main(){

    int N, M;
    scanf("%d %d", &N, &M);

    // 미로 초기화
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &a[i][j]);
        }
    }

    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    dist[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx>=0 && nx<N && ny>=0 && ny<M){
                if(a[nx][ny] == 1 && dist[nx][ny] == 0){
                    q.push(make_pair(nx,ny));
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
        q.pop();
    }

    printf("%d\n", dist[N-1][M-1]);

    return 0;
}