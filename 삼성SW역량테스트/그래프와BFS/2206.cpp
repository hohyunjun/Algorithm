#include <cstdio>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int A[1001][1001];
// [][][0] 은 벽을 아직 부수지 않은 경우, [][][1] 은 벽을 부순 경우
int dist[1001][1001][2];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int main(){

    int n, m;

    scanf("%d%d", &n, &m);

    // tuple<int, int, int> tp = make_tuple(2,3,4);

    // cout << get<0>(tp) << '\n';
    // cout << get<1>(tp) << '\n';
    // cout << get<2>(tp) << '\n';

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &A[i][j]);
        }
    }

    queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,0,0));
    dist[0][0][0] = 1;

    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int c = get<2>(q.front());
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            // 벽을 부수지 않은 경우
            if(c == 0){
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    if(dist[nx][ny][c] == 0 && A[nx][ny] == 0){
                        q.push(make_tuple(nx,ny,c));
                        dist[nx][ny][c] = dist[x][y][c] + 1;
                    }else if(dist[nx][ny][c+1] == 0 && A[nx][ny] == 1){
                        q.push(make_tuple(nx,ny,c+1));
                        dist[nx][ny][c+1] = dist[x][y][c] + 1;
                    }
                }
            }
            // 벽을 이미 부순 경우
            if(c == 1){
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    if(dist[nx][ny][c] == 0 && A[nx][ny] == 0){
                        q.push(make_tuple(nx,ny,c));
                        dist[nx][ny][c] = dist[x][y][c] + 1;
                    }
                }
            }
        }
        q.pop();
    }

    if(dist[n-1][m-1][0] == 0 && dist[n-1][m-1][1] == 0){
        printf("%d\n", -1);
    }else{
        int ans = dist[n-1][m-1][0];
        int ans2 = dist[n-1][m-1][1];
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