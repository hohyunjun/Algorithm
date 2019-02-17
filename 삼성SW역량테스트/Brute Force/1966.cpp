#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){
        int n, m;

        cin >> n >> m;

        // 지워졌는지 안지워졌는지 체크
        vector<bool> removed(n, false);
        // 우선순위 값들을 배열 형태로 저장
        vector<int> pv(n);
        // (숫자, 원래 위치) 형태로 큐에 저장
        queue<pair<int,int>> q;
        // 지워진 순서를 저장
        // key = 원위치, value = 지워진 순서
        map<int, int> removedm;
        int cnt = 1;

        for(int i=0; i<n; i++){
            int priority;
            cin >> priority;
            q.push(make_pair(priority, i));
            pv[i] = priority;
        }

        while(!q.empty()){
            int fp = q.front().first; // 맨 앞 문서의 중요도
            int fposition = q.front().second; // 맨 앞 문서의 원래 위치
            bool print = true;
            for(int i=0; i<n; i++){
                if(i==fposition) continue;
                // 현재 문서보다 중요도가 높고 지워지지 않은 문서가 있을 경우
                if(pv[i] > fp && removed[i] == false){
                    print = false;
                    break;
                }
            }
            if(!print){
                q.pop();
                q.push(make_pair(fp, fposition));
            }
            if(print){
                removed[fposition] = true;
                removedm[fposition] = cnt;
                cnt+=1;
                q.pop();
            }
        }

        cout << removedm[m] << '\n';   
    }


    return 0;
}