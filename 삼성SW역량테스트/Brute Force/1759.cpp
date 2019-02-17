#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void solve(int n, vector<char> alpha, string password, int i){
    // 답을 찾은 경우
    if(password.length() == n){
        // 모음 1개 이상, 자음 2개 이상인지 체크
        int moumCnt = 0;
        int jaumCnt = 0;
        for(int j=0; j<password.length(); j++){
            if(password[j] == 'a' || password[j] == 'e' || password[j] == 'i' || password[j] == 'o' || password[j] == 'u'){
                moumCnt++;
            }else{
                jaumCnt++;
            }
        }
        if(moumCnt >= 1 && jaumCnt >=2){
            cout << password << '\n';
        }
        return;
    }
    // 불가능한 경우
    if(password.length() > n) return;
    if(i >= alpha.size()) return;
    solve(n, alpha, password+alpha[i], i+1);
    solve(n, alpha, password, i+1);
}

int main(){

    int l, c;

    cin >> l >> c;

    vector<char> alpha(c);

    for(int i=0; i<c; i++){
        cin >> alpha[i];
    }

    sort(alpha.begin(), alpha.end());

    string password = "";
    solve(l, alpha, password, 0);
    // 최소 한 개의 모음과 두 개의 자음
    // 암호는 정렬된 상태


    return 0;
}