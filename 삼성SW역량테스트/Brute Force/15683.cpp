#include <iostream>
#include <vector>
using namespace std;

/*
    BOJ 15683 감시
    1. N과 M 제한이 매우 작으므로 모든 경우의 수를 다 따져볼 수 있다.
    2. 각 cctv의 위치와 개수를 vector에 저장한다.
    2. 1번부터 5번까지 카메라 각각을 회전시켜 만들수 있는 서로 다른 경우의 수를 저장한다. (4,2,4,2,1)
    3. 즉, 체크해야 하는 모든 경우의 수는 4*2*4*2*1 = 64가지 --> 어떻게 체크해줄 것인지가 관건
    4. 모든 경우의 수에 대해 최소 사각지대를 구한다.

    ============= 접근방법 오류. cctv 번호별로 이동방식을 정하는 것이 아니라, 모든 cctv에 대해 cctv번호 확인하고 이동방식을 정해야 함.

    // DFS로 풀어야 하는 것 같은데, N과 M 풀고나서 다시 와서 풀어보자
*/

int A[8][8]; // 사무실 
int dx[] = {0,-1,0,1}; // 0 왼쪽 1 위 2 오른쪽 3 아래
int dy[] = {-1,0,1,0};
// 1번부터 5번까지 cctv를 0~4번 인덱스에 저장. 1번 cctv개수 : cctv[0].size()
vector<pair<int,int>> cctv[5];
int n, m;

void initialize(int tmp[8][8]){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            tmp[i][j] = A[i][j];
        }
    }
    return;
}

int go(vector<string> search[5], int a1, int a2, int a3, int a4, int a5);


int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> A[i][j];
        }
    }

    int cctvCnt = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j] == 1){
                cctv[0].push_back(make_pair(i,j));
                cctvCnt++;
            }else if(A[i][j] == 2){
                cctv[1].push_back(make_pair(i,j));
                cctvCnt++;
            }else if(A[i][j] == 3){
                cctv[2].push_back(make_pair(i,j));
                cctvCnt++;
            }else if(A[i][j] == 4){
                cctv[3].push_back(make_pair(i,j));
                cctvCnt++;
            }else if(A[i][j] == 5){
                cctv[4].push_back(make_pair(i,j));
                cctvCnt++;
            }
        }
    }

    // 각각의 cctv 별로 탐색가능한 경우의 수를 4자리의 string형태로 표현해 저장한다.
    vector<string> search[5];
    search[0].push_back("1000");
    search[0].push_back("0100");
    search[0].push_back("0010");
    search[0].push_back("0001");
    search[1].push_back("1010");
    search[1].push_back("0101");
    search[2].push_back("0110");
    search[2].push_back("0011");
    search[2].push_back("1001");
    search[2].push_back("1100");
    search[3].push_back("1110");
    search[3].push_back("1011");
    search[4].push_back("1111");

    int ans = 0x7FFFFFFF;

    ans = min(ans, go(search));

    for(int i=0; i<cctvCnt; i++){ // cctv 개수만큼

    }

    // for(int a1=0; a1<4; a1++){
    //     for(int a2=0; a2<2; a2++){
    //         for(int a3=0; a3<4; a3++){
    //             for(int a4=0; a4<2; a4++){
    //                 for(int a5=0; a5<1; a5++){
    //                     ans = min(ans, go(search, a1,a2,a3,a4,a5));
    //                 }
    //             }
    //         }
    //     }
    // }

    cout << ans << '\n';

    return 0;
}

// go 함수는 각 카메라의 탐색방법대로 수행하고, 사각지대의 개수 반환
int go(vector<string> search[5]){
    int tmp[8][8];
    initialize(tmp); // tmp 초기화

    // 첫번째 카메라부터 진행
    for(int i=0; i<cctv[0].size(); i++){
        int x = cctv[0][i].first;
        int y = cctv[0][i].second;
        //for(int a1=0; a1<4; a1++){
            for(int j=0; j<4; j++){
                if(search[0][a1][j] == '1'){ // 방향이 1인경우만
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    while(nx>=0 && ny>=0 && nx<n && ny<m){
                        if(tmp[nx][ny] == 6) break;
                        tmp[nx][ny] = -1;
                        nx += dx[j];
                        ny += dy[j];
                    }
                }
            }
        //}
    }
    
    // 두번째
    for(int i=0; i<cctv[1].size(); i++){
        int x = cctv[1][i].first;
        int y = cctv[1][i].second;
        for(int j=0; j<4; j++){
            if(search[1][a2][j] == '1'){
                int nx = x + dx[j];
                int ny = x + dy[j];
                while(nx>=0 && ny>=0 && nx<n && ny<m){
                    if(tmp[nx][ny] == 6) break;
                    tmp[nx][ny] = -1;
                    nx += dx[j];
                    ny += dy[j];
                }
            }
        }
    }

    // 3
    for(int i=0; i<cctv[2].size(); i++){
        int x = cctv[2][i].first;
        int y = cctv[2][i].second;
        for(int j=0; j<4; j++){
            if(search[2][a3][j] == '1'){
                int nx = x + dx[j];
                int ny = x + dy[j];
                while(nx>=0 && ny>=0 && nx<n && ny<m){
                    if(tmp[nx][ny] == 6) break;
                    tmp[nx][ny] = -1;
                    nx += dx[j];
                    ny += dy[j];
                }
            }
        }
    }

    // 4
    for(int i=0; i<cctv[3].size(); i++){
        int x = cctv[3][i].first;
        int y = cctv[3][i].second;
        for(int j=0; j<4; j++){
            if(search[3][a4][j] == '1'){
                int nx = x + dx[j];
                int ny = x + dy[j];
                while(nx>=0 && ny>=0 && nx<n && ny<m){
                    if(tmp[nx][ny] == 6) break;
                    tmp[nx][ny] = -1;
                    nx += dx[j];
                    ny += dy[j];
                }
            }
        }
    }

    // 5
    for(int i=0; i<cctv[4].size(); i++){
        int x = cctv[4][i].first;
        int y = cctv[4][i].second;
        for(int j=0; j<4; j++){
            if(search[4][a5][j] == '1'){
                int nx = x + dx[j];
                int ny = x + dy[j];
                while(nx>=0 && ny>=0 && nx<n && ny<m){
                    if(tmp[nx][ny] == 6) break;
                    tmp[nx][ny] = -1;
                    nx += dx[j];
                    ny += dy[j];
                }
            }
        }
    }

    int ret = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tmp[i][j] == 0) ret++;
        }
    }

    return ret;
}