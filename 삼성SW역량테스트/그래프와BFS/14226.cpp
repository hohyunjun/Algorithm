#include <iostream>
#include <queue>
using namespace std;

// check[s][c], s는 이모티콘 개수 c는 클립보드에 저장된 이모티콘 개수
int check[1001][1001];

int main(){

    int s;

    cin >> s;

    queue<pair<int,int>> q;
    q.push(make_pair(1,0));
    check[1][0] = 1;

    while(!q.empty()){
        int emo = q.front().first;
        int cb = q.front().second;

        // op1 : 복사
        int emo1 = emo;
        int cb1 = emo1;
        if(check[emo1][cb1] == 0){
            check[emo1][cb1] = check[emo][cb] + 1;
            q.push(make_pair(emo1, cb1));
        }

        // op2 : 붙여넣기
        if(cb != 0 && emo + cb <= 1000){
            int emo2 = emo + cb;
            int cb2 = cb;
            if(check[emo2][cb2] == 0){
                check[emo2][cb2] = check[emo][cb] + 1;
                q.push(make_pair(emo2, cb2));
            }
        }

        // op3 : 삭제
        if(emo >= 1){
            int emo3 = emo - 1;
            int cb3 = cb;
            if(check[emo3][cb3] == 0){
                check[emo3][cb3] = check[emo][cb] + 1;
                q.push(make_pair(emo3, cb3));
            }
        }
        q.pop();
    }

    int ans = 0x7FFFFFFF;
    for(int i=0; i<1001; i++){
        if(check[s][i] != 0){
            ans = min(ans, check[s][i] - 1);
        }
    }

    cout << ans << '\n';

    return 0;
}