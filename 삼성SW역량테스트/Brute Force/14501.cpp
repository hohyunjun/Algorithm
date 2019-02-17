#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans = 0;

// solve 함수는 day 일까지 얻은 수익을 반환하고, day일에 상담을 할지 말지를 결정한다.
// 첫번째 인자 : 몇일인지
// 두번째, 세번째 인자 : 상담에 걸리는 기간, 받을 수 있는 금액
// 네번째 인자 : 최대 수익
// 다섯번째 인자 : 현재 일 수
void solve(int n, vector<int> t, vector<int> p, int profit, int day){
    // 불가능한 경우
    if(day > n) return;
    // 정답을 찾은 경우
    if(day == n){
        if(ans < profit){
            ans = profit;
        }
        return;
    }

    solve(n,t,p, profit+p[day], day+t[day]);
    solve(n,t,p, profit, day+1);
}

int main(){

    int n;
    cin >> n;

    vector<int> t(n);
    vector<int> p(n);

    for(int i=0; i<n; i++){
        cin >> t[i] >> p[i];
    }

    solve(n,t,p,0,0);

    cout << ans << '\n';

    return 0;
}