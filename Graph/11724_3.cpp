#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check[1001];

int main(){

    int N, M;
    int cc = 0;
    cin >> N >> M;

    vector<int> A[N+1];

    // 그래프 초기화
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    for(int i=1; i<=N; i++){
        if(check[i] == false){ // 아직 방문되지 않은 정점인 경우
            cc++;
            queue<int> q;
            q.push(i);
            check[i] = true;
            while(!q.empty()){
                int w = q.front();
                for(int i=0; i<A[w].size(); i++){
                    if(check[A[w][i]] == false){
                        q.push(A[w][i]);
                        check[A[w][i]] = true;
                    }
                }
                q.pop();
            }
        }
    }

    cout << cc << "\n";

    return 0;
}