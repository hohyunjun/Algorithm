#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

// 방향 이동, 0,2는 가로, 1,3은 세로
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int A[51][51]; // 각 나라의 인구수
bool garoB[50][50][50]; // 가로로 국경이 open 되었는지 아닌지
bool seroB[50][50][50]; // 세로로 국경이 open 되었는지 아닌지

// 연합의 개수를 세고, 각 칸이 몇 번 연합에 속하는지 체크한다.
int Union[51][51];

// 가로 방향으로 l명 이상 r명 이하인지 파악해서 국경선을 연다.
// l명 이상 r명 이하인 경우가 없을 경우는 false를 반환한다.
bool garoDiff(int n, int l, int r){

    bool opened = false;

    // dy[2] 수행 ( 오른쪽 )
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int ny = j + dy[2];
            if(ny >= 0 && ny < n){ // y 값이 범위 내일 경우만
                if(abs(A[i][j] - A[i][ny]) >= l && abs(A[i][j] - A[i][ny]) <= r){ // 두 나라의 인구 차이가 l명 이상 r명 이하라면
                    opened = true; // 인구 이동이 일어났다.
                    garoB[i][j][ny] = true; // 국경이 열렸다
                }
            }
        }
    }

    return opened;
}

bool seroDiff(int n, int l, int r){
    
    bool opened = false;

    // dx[3] 수행 ( 세로 )
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int nx = i + dx[3];
            if(nx >= 0 && nx < n){ // x 값이 범위 내일 경우만
                if(abs(A[i][j] - A[nx][j]) >= l && abs(A[i][j] - A[nx][j]) <= r){ // 두 나라의 인구 차이가 l명 이상 r명 이하라면
                    opened = true; // 인구 이동이 일어났다.
                    seroB[j][i][nx] = true; // 국경이 열렸다
                }
            }
        }
    }

    return opened;
}

// (i,j) 로부터 시작해서 bfs 돌린 후 연합 체크
void bfs(int i, int j, int uc, int n){

    Union[i][j] = uc;

    queue<pair<int,int>> q;

    q.push(make_pair(i,j));

    while(!q.empty()){ // 방향 이동, 0,2는 가로, 1,3은 세로
        int x = q.front().first;
        int y = q.front().second;
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = x + dy[k];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue; // 범위 체크
            if(k == 0 || k == 2){ // 가로 확인
                if(garoB[y][ny]){ // 국경선이 열려있다면
                    Union[nx][ny] = uc;
                    q.push(make_pair(nx, ny));
                }
            }else{
                if(seroB[x][nx]){
                    Union[nx][ny] = uc;
                    q.push(make_pair(nx,ny));
                }
            }
        }
        q.pop();
    }

    return;
}


int main(){

    int n, l, r;

    cin >> n >> l >> r;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A[i][j];
        }
    }

    // 인구 이동 횟수를 센다
    int cnt = 0;

    // 가로, 세로 둘 중 하나라도 이동이 일어날 경우에 계속 수행
    while(garoDiff(n,l,r) || seroDiff(n,l,r)){

        cnt++;

        // 국경선 체크가 완료된 상태이므로, 연합을 이루고 있는 국가들의 인구수를 계산해 update하면 된다.
        int unionCnt = 1;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(Union[i][j] != 0) continue;
                unionCnt++;
                bfs(i,j,unionCnt,n);
            }
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

        // 국경선 초기화(모든 국경선을 닫는다)
        memset(garoB, sizeof(garoB), false);
        memset(seroB, sizeof(seroB), false);
    }

    cout << cnt << '\n';


    garoDiff(n,l,r);
    seroDiff(n,l,r);

    int unionCnt = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(Union[i][j] != 0) continue;
            unionCnt++;
            bfs(i,j,unionCnt,n);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << Union[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}