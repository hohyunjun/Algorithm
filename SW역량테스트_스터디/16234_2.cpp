#include <iostream>
#include <queue>
#include <string.h>
using namespace std;


int n, l, r;
// 방향 이동, 0,2는 가로, 1,3은 세로
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int A[51][51]; // 각 나라의 인구수

// 연합의 개수를 세고, 각 칸이 몇 번 연합에 속하는지 체크한다.
int Union[51][51];


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> r;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A[i][j];
        }
    }

    // 인구 이동 횟수를 센다
    int cnt = 0;

    while(true){

        cnt++;

        int unionCnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(Union[i][j] != 0) continue;
                unionCnt++;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                Union[i][j] = unionCnt;

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    for(int k=0; k<4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx >=0 && ny >=0 && nx<n && ny <n){
                            if(Union[nx][ny] == 0 && abs(A[x][y] - A[nx][ny]) >= l && abs(A[x][y] - A[nx][ny]) <= r){
                                Union[nx][ny] = Union[x][y];
                                q.push(make_pair(nx,ny));
                            }
                        }
                    }
                    q.pop();
                }
            }
        }

        if(unionCnt == n*n){
            cnt -= 1;
            break;
        }

        // union 별로 인구수 총합과 연합을 이루는 칸의 개수를 저장한다.
        // 첫번째 값은 인구수, 두번째 칸은 칸의 개수
        vector<pair<int,int>> unionPop(unionCnt+1, make_pair(0,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                unionPop[Union[i][j]].first += A[i][j];
                unionPop[Union[i][j]].second += 1;
            }
        }

        vector<int> changedPop(unionCnt+1);

        for(int i=1; i<=unionCnt; i++){
            changedPop[i] = unionPop[i].first / unionPop[i].second;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                A[i][j] = changedPop[Union[i][j]];
            }
        }

        memset(Union, 0, sizeof(Union));
   }


    cout << cnt << '\n';


    return 0;
}