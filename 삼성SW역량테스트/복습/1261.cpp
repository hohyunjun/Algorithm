#include <cstdio>
#include <deque>
#include <string.h>
using namespace std;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int main(){

    int m, n;

    scanf("%d%d", &m, &n);

    int A[101][101];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &A[i][j]);
        }
    }

    int check[101][101];
    memset(check, -1, sizeof(check));

    deque<pair<int,int>> q;
    q.push_front(make_pair(0,0));

    check[0][0] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(check[nx][ny] != -1) continue;
            if(A[nx][ny] == 0){
                check[nx][ny] = check[x][y];
                q.push_front(make_pair(nx,ny));
            }else{
                check[nx][ny] = check[x][y] + 1;
                q.push_back(make_pair(nx,ny));
            }
        }
    }

    printf("%d\n", check[n-1][m-1]);

    return 0;
}