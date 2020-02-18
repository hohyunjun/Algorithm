#include <iostream>
#include <vector>
#define MAX 8
using namespace std;

/*
    4번.
     최대 8자리의 숫자 배열이 주어지고, K라는 값이 주어진다. 
     숫자 배열의 각 원소를 1대 1로 swap하여 최소 횟수의 swap으로 모든 인접 원소 간 차이값이 K이하가 되도록 할 때,
     최소 횟수 answer를 구하라.
     K이하로 만드는 것이 불가능할 경우, answer는 -1을 반환한다.
*/

// 입력값
int k, n;
vector<int> input(MAX);

// 정답
int ans = -1;

// visit 체크
bool visit[MAX][MAX];

// 모든 인접 원소 간 차이값이 K 이하인지 확인하는 함수
bool check(){
    for(int i=0; i<n-1; i++){
        if(abs(input[i] - input[i+1]) > k) return false;
    }
    return true;
}

//int checking = 0;

void dfs(int cnt, int start){

    // 조건을 만족할 경우
    if(check()){
        if(ans == -1){
            ans = cnt;
        }else{
            ans = min(ans, cnt);
        }
        return;
    }

    for(int i=start; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(visit[i][j] || visit[j][i]) continue; // 바꾼 것을 또 바꾸는 경우 제외
            swap(input[i], input[j]);
            visit[i][j] = true;
            visit[j][i] = true;
            // checking++;
            // for(int a=0; a<n; a++){
            //     cout << input[a] << " ";
            // }
            // cout << '\n';
            dfs(cnt+1, start+1);
            swap(input[i], input[j]);
            visit[i][j] = false;
            visit[j][i] = false;
        }
    }

}

int main(){

    cin >> k >> n;

    for(int i=0; i<n; i++){
        cin >> input[i];
    }

    dfs(0, 0);

    cout << ans << '\n';
//    cout << checking << '\n';

    return 0;
}