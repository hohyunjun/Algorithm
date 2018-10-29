#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int main(){

    int a[50][50];
    int group[50][50];
    int dx[] = {0,1,1,1,0,-1,-1,-1};
    int dy[] = {-1,-1,0,1,1,1,0,-1};

    while(true){
        int w, h;
        scanf("%d%d", &w, &h);
        if(w==0 && h==0){
            break;
        }
        // 먼저, 배열을 초기화한다.
        for(int i=0; i<50; i++){
            memset(a[i], 0, sizeof(int)*50);
            memset(group[i], 0, sizeof(int) * 50);
        }

        // a에 주어진 값을 넣는다.
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                scanf("%d", &a[i][j]);
            }
        }

        int cnt= 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(a[i][j] == 1 && group[i][j] == 0){ // 땅이 존재하고 아직 방문되지 않았을 경우
                    cnt+=1;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    group[i][j] = cnt;
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        for(int k=0; k<8; k++){
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if(nx>=0 && nx<h && ny>=0 && ny<w){ // 정해진 a의 범위를 넘어가지 않을 경우에만
                                if(a[nx][ny] == 1 && group[nx][ny] == 0){
                                    q.push(make_pair(nx, ny));
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

    }


    return 0;
}
