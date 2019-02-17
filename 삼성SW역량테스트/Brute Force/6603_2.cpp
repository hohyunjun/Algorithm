#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 첫번째 인자는 뽑아야 하는 개수
// 두번째 인자는 S[k], 뽑을 수 있는 숫자의 배열
// 세번째 인자는 뽑은 lotto
// 네번째 인자는 배열에서 뽑는 인덱스
void solve(int n, vector<int> S, vector<int> lotto, int idx){
    // 정답을 찾은 경우
    if(lotto.size() == n){
        for(auto each:lotto){
            cout << each << " ";
        }
        cout << '\n';
        return;
    }
    // 불가능한 경우
    if(idx >= S.size()) return;

    vector<int> lotto_2(lotto);
    lotto_2.push_back(S[idx]);
    solve(n, S, lotto_2, idx+1);
    solve(n, S, lotto, idx+1);
}

int main(){

    while(true){
        int k;
        cin >> k;
        if(k==0) break;
        vector<int> S(k);
        for(int i=0; i<k; i++){
            cin >> S[i];
        }
        vector<int> lotto;
        solve(6, S, lotto, 0);
        cout << '\n';
    }



    return 0;
}