#include <cstdio>
#include <queue>
using namespace std;

int a[1000][1000];
int rot[1000][1000];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int main(){

    int M, N; // N이 행, M이 열
    scanf("%d%d", &M, &N);

    // 토마토 박스 초기화
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &a[i][j]);
        }
    }

    // 익은 토마토가 있는 좌표를 큐에 넣는다.
    queue<pair<int, int>> q;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(a[i][j] == 1){
                q.push(make_pair(i,j));
                rot[i][j] = 1;
            }
        }
    }

    // BFS 알고리즘 적용
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx>=0 && nx<N && ny>=0 && ny<M){
                if(a[nx][ny] == 0 && rot[nx][ny] == 0){ // 다음 좌표가 아직 익지 않은 토마토이고 아직 방문되지 않았을 경우에
                    q.push(make_pair(nx,ny));
                    rot[nx][ny] = rot[x][y] + 1;
                }
            }
        }
        q.pop();
    }

    int ans = 0;
    // 다 익었는지 체크. 안익은게 하나라도 있을 경우 ans = -1
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(rot[i][j] == 0 && a[i][j] == 0){
                ans = -1;
                break;
            }
        }
    }

    // 다 익었을 경우
    if(ans != -1){
        ans = rot[0][0];
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(rot[i][j] > ans){
                    ans = rot[i][j];
                }
            }
        }
    }

    if(ans == -1){
        printf("%d\n", ans);
    }else{
        printf("%d\n", ans-1);
    }


    return 0;
}