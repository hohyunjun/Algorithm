#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int A[25][25];
int check[25][25];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

int main(){

    int N;

    scanf("%d", &N);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &A[i][j]);
        }
    }

    queue<pair<int,int>> q;

    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(A[i][j] == 1 && check[i][j] == 0){
                cnt += 1;
                q.push(make_pair(i,j));
                check[i][j] = cnt;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    for(int k=0; k<4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx>=0 && nx<N && ny>=0 && ny<N){
                            if(A[nx][ny] == 1 && check[nx][ny]==0){
                                check[nx][ny] = cnt;
                                q.push(make_pair(nx,ny));
                            }
                        }
                    }
                    q.pop();
                }
            }
        }
    }


    vector<int> groupcnt;

    for(int i=1; i<=cnt; i++){
        int gc = 0;
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if(check[j][k] == i) gc+=1;
            }
        }
        groupcnt.push_back(gc);
    }

    sort(groupcnt.begin(), groupcnt.end());

    printf("%d\n", cnt);

    for(int i=0; i<groupcnt.size(); i++){
        printf("%d\n", groupcnt[i]);
    }


    return 0;
}