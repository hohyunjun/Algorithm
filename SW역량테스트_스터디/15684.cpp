#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

/*
    사다리 조작
    1. 사다리 타는 것 시뮬레이션 구현
      - 저장해야 할 값 : 세로선1, 세로선2, 가로선 
      - 세로선을 타고 내려가면서 각 H 마다 가로선이 존재하는지 체크한다. 존재한다면 사다리 옮기기
    2. 가능한 모든 사다리 선 집합에 대해서 탐색 진행 ( 1번째 -> 2번째 -> 3번째)
      - 가능한 사다리 선의 집합을 찾는다 : possible함수 사용
    3. 3번째까지 했는데 불가능할 경우, -1 출력
*/

bool simulation(int n, int h);
void solve(int cnt, int n, int h, int x, int y);
int ans = -1;

int A[32][12]; // i열 j행에 존재하는 라인의 종류를 넣는다. 0이면 없음, 1이면 오른쪽으로 진행, 2면 왼쪽으로 진행

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, h;

    cin >> n >> m >> h;

    for(int i=0; i<m; i++){
        int a, b;

        cin >> a >> b;

        A[a][b] = 1;
        A[a][b+1] = 2;
    }

    solve(0, n, h, 1, 1);

    cout << ans << '\n';

    return 0;
}

// 실제 사다리 타보고 i로 시작해서 i로 끝나지 않는 경우는 false 반환.
bool simulation(int n, int h){

    bool complete = true;

    for(int i=1; i<=n; i++){ // 가로
        int start = i;
        for(int j=1; j<=h; j++){ // 세로
            if(A[j][start] == 1){
                start += 1;
            }else if(A[j][start] == 2){
                start -= 1;
            }
        }
        if( start != i){
            complete = false;
            break;
        }
    }

    return complete;
}

void solve(int cnt, int n, int h, int x, int y){
    if(y > n){
        if(simulation(n,h)){
            if(cnt < ans || ans == -1) ans = cnt;
        }
        return;
    }

    if(x > h){
        solve(cnt, n, h, 1, y+1);
        return;
    }

    if(A[x][y] == 0 && A[x][y+1] == 0 && cnt <3){
        A[x][y] = 1;
        A[x][y+1] = 2;
        solve(cnt+1, n, h, x+1, y);
        A[x][y] = 0;
        A[x][y+1] = 0;
    }

    solve(cnt, n, h, x+1, y);

}