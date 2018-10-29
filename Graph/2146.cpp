#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int map[100][100];
int dist[100][100];
int group[100][100];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int main(){

    int N;
    scanf("%d", &N);

    // 지도 초기화
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &map[i][j]);
        }
    }

    // 각 섬을 구분하기 위해 cnt를 붙인다. group 배열에 저장.
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == 1 && group[i][j] == 0){ // 육지이고 아직 방문되지 않았을 경우에
                cnt+=1;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                group[i][j] = cnt;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    for(int k=0; k<4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx>=0 && nx<N && ny>=0 && ny<N){
                            if(map[nx][ny] == 1 && group[nx][ny] == 0 ){
                                q.push(make_pair(nx,ny));
                                group[nx][ny] = cnt;
                            }
                        }
                    }
                    q.pop();
                }
            }
        }
    }

    int ans = 999;
    // 한 섬을 시작좌표로 잡고 다른 섬으로 이동하는 거리 구하기
    for(int i=1; i<=cnt; i++){
        queue<pair<int,int>> q;
        // 시작 섬인 i 섬을 dist 배열에 체크
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if(group[j][k] == i && dist[j][k] == 0){
                    q.push(make_pair(j,k));
                    dist[j][k] = 1;
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            for(int k=0; k<4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx>=0 && nx<N && ny>=0 && ny<N){
                    if(map[nx][ny] == 0 && dist[nx][ny] == 0){
                        q.push(make_pair(nx,ny));
                        dist[nx][ny] = dist[x][y] + 1;
                    }
                }
            }
            q.pop();
        }

        // 시작섬이 아닌 도착섬의 좌표를 큐에 넣는다.
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if(dist[j][k] == 0){
                    q.push(make_pair(j,k));
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            for(int k=0; k<4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx>=0 && nx<N && ny>=0 && ny<N){
                    if(dist[nx][ny] < ans && dist[nx][ny] != 0){
                        ans = dist[nx][ny];
                    }
                }
            }
            q.pop();
        }

        // printf("=========dist map start from group %d =========\n", i);

        // for(int j=0; j<N; j++){
        //     for(int k=0; k<N; k++){
        //         printf("%d ", dist[j][k]);
        //     }
        //     printf("\n");
        // }

        for(int j=0; j<N; j++){
            memset(dist[j], 0, sizeof(int)*N);
        }
    }

    printf("%d\n", ans-1);

    return 0;
}