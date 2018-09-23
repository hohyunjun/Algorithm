#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;

    for(int i=0; i<T; i++){
        vector<int> A(100001); // 그래프 간선 저장
        vector<int> check(100001); // 그래프의 각 정점이 몇 번째 시도만에 방문되었는가
        vector<int> S(100001); // 각 단계에서 정점이 방문된 순서를 저장한다.
        int n;
        cin >> n;
        for(int j=1; j<=n; j++){
            int a;
            cin >> a;
            A[j] = a;
        }

        int cycle = 0;
        int step = 0;
        for(int j=1; j<=n; j++){
            if(check[j] == 0){ // j 정점이 방문되지 않았을 경우에만
                int cnt = 1;
                step += 1; // step 증가
                queue<int> q;
                q.push(j);
                check[j] = step;
                S[j] += cnt++; // S배열에 step에 속하는 정점 추가
                while(!q.empty()){
                    int w = q.front();
                    if(check[A[w]] == 0){ // w와 접하는 정점이 방문되지 않았다면
                        int y = A[w];
                        q.push(y);
                        check[y] = step;
                        S[y] += cnt++;
                    }else{ // 이미 방문된 정점일 경우
                        int y = A[w];
                        if(check[y] == step){ // 현재 bfs에서 방문한 정점일 경우
                            if(y == A[y]){ // 자기 자신으로 가는 사이클일 경우
                                cycle += 1;
                            }else{ // 자기 자신이 아닌 다른 정점으로 가는 사이클일 경우
                                cycle += cnt-S[y];
                            }
                        }
                    }
                    q.pop();
                }
            }
        }

        cout << n - cycle << "\n";
    }

    return 0;
}