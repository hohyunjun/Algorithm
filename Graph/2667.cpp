#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int A[25][25];
int group[25][25];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
int ans[25*25];

int main(){

    int N;
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &A[i][j]);
        }
    }

    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(A[i][j] == 1 && group[i][j] == 0){ // 아파트가 존재하고 아직 방문되지 않았을 경우에만
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
                        if(nx>=0 && nx<N && ny>=0 && ny<N){ // nx, ny가 A의 범위를 넘어가지 않을 때만
                            if(A[nx][ny] == 1 && group[nx][ny] == 0){
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

    printf("%d\n", cnt);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ans[group[i][j]] += 1;
        }
    }

    //cnt 값은 무조건 1이상이다.
    sort(ans+1, ans+cnt+1);

    for(int i=1; i<=cnt; i++){
        printf("%d\n", ans[i]);
    }


    return 0;
}