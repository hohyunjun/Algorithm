#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int S[20][20];
int ans = 0x7FFFFFFF;
int n;

// go 함수는 index번째 사람을 start 또는 link팀에 할당한다.
void go(int index, vector<int> &start, vector<int> &link){
    // 불가능한 조건
    if(start.size() > n/2) return;
    if(link.size() > n/2) return;
    // 종료조건
    // 모든 팀으로의 할당이 끝난 경우 차이값 계산
    if(index == n){
        int startCapa = 0;
        int linkCapa = 0;
        for(int i=0; i<n/2-1; i++){
            for(int j=i+1; j<n/2; j++){
                startCapa += S[start[i]][start[j]] + S[start[j]][start[i]];
                linkCapa += S[link[i]][link[j]] + S[link[j]][link[i]];
            }
        }
        ans = min(ans, abs(startCapa-linkCapa));
        return;
    }
    // 진행조건(index 번째 사람이 start팀에 들어갔을 경우, link 팀에 들어갔을 경우)
    start.push_back(index);
    go(index+1, start, link);
    start.pop_back();
    link.push_back(index);
    go(index+1, start, link);
    link.pop_back();

}


int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> S[i][j];
        }
    }

    vector<int> start;
    vector<int> link;
    go(0, start, link);

    cout << ans << '\n';

    return 0;
}