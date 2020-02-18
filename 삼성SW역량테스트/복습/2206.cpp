#include <cstdio>
#include <queue>
#include <string.h>
#include <tuple>
using namespace std;
 
int A[1001][1001];
int check[1001][1001][2]; // 0은 아직 벽을 깨지 않은 경우, 1은 벽을 깬 경우
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

    // memset(check, -1, sizeof(check));

    queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,0,0));
    check[0][0][0] = 1;

    while(!q.empty()){
        int x, y, d;
        tie(x,y,d) = q.front();
        // int x = get<0>(q.front());
        // int y = get<1>(q.front());
        // int d = get<2>(q.front());
        q.pop();
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = x + dy[k];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(d == 0){ // 현재 좌표까지 벽을 한번도 부수지 않은 경우
                if(A[nx][ny] == 0 && check[nx][ny][d] == 0){ // 길이 있고, 아직 방문되지 않았을 경우
                    check[nx][ny][d] = check[x][y][d] + 1;
                    q.push(make_tuple(nx,ny,d));
                }else if(A[nx][ny] == 1 && check[nx][ny][d+1] == 0){
                    check[nx][ny][d+1] = check[x][y][d] + 1;
                    q.push(make_tuple(nx,ny,d+1));
                }
            }
            if(d == 1){ // 벽을 한번이라도 부순 경우
                if(A[nx][ny] == 0 && check[nx][ny][d] == 0){
                    check[nx][ny][d] = check[x][y][d] + 1;
                    q.push(make_tuple(nx,ny,d));
                }
            }
            
        }
    }

    if(check[n-1][m-1][0] == 0 && check[n-1][m-1][1] == 0){
        printf("%d\n", -1);
    }else{
        int ans = check[n-1][m-1][0];
        int ans2 = check[n-1][m-1][1];
        printf("%d %d", ans, ans2);
        if(ans == 0){
            printf("%d\n", ans2);
        }else if(ans2 == 0){
            printf("%d\n", ans);
        }else{
            printf("%d\n", min(ans, ans2));
        }
    }


    return 0;
}