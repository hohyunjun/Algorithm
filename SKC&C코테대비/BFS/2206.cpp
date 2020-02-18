#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

int A[1001][1001];
int dist[1001][1001][2];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int main(){

    int n, m;

    scanf("%d%d", &n, &m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &A[i][j]);
        }
    }

    tuple<int,int,int> start = make_tuple(0,0,0);
    queue<tuple<int,int,int>> q;
    q.push(start);
    dist[0][0][0] = 1;
    
    while(!q.empty()){
        int x, y, c;
        tie(x,y,c) = q.front();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;

            if(c==0){ // 아직 벽을 부수지 않은 경우
                if(A[nx][ny] == 1 && dist[nx][ny][c+1] == 0){
                    dist[nx][ny][c+1] = dist[x][y][c] + 1;
                    q.push(make_tuple(nx,ny,c+1));
                }else if(A[nx][ny] == 0 && dist[nx][ny][c] == 0){
                    dist[nx][ny][c] = dist[x][y][c] + 1;
                    q.push(make_tuple(nx,ny,c));
                }
            }

            if(c==1){ // 이미 벽을 부순 경우
                if(A[nx][ny] == 0 && dist[nx][ny][c] == 0){
                    dist[nx][ny][c] = dist[x][y][c] + 1;
                    q.push(make_tuple(nx,ny,c));
                }
            }
        }
        q.pop();
    }

    int ans1 = dist[n-1][m-1][0];
    int ans2 = dist[n-1][m-1][1];

    if(ans1 == 0 && ans2==0){
        printf("-1\n");
    }else if(ans1==0 && ans2!=0){
        printf("%d\n", ans2);
    }else if(ans1!=0 && ans2==0){
        printf("%d\n", ans1);
    }else{
        printf("%d\n", min(ans1,ans2));
    }



    return 0;
}