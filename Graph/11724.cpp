#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

bool check[1001] = {false};
vector<int> A[1001];

int main(){

    int N, M, cc=0, start=1;

    scanf("%d %d", &N, &M);

    // 그래프 간선을 인접 리스트 형태로 저장
    for(int i=0; i<M; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        A[u].push_back(v);
        A[v].push_back(u);
    }

    // BFS
    queue<int> q;
    for(int j=1; j<=N; j++){ // j는 모든 정점
        if(check[j]!=true){
            q.push(j);
            check[j] = true;
            while(!q.empty()){
                int w = q.front();
                for(int i=0; i<A[w].size(); i++){
                    int y = A[w][i];
                    if(check[y]==false){
                        q.push(y);
                        check[y] = true;
                    }
                }
                q.pop();
            }
            cc++;
        }
    }

    printf("%d", cc);

    return 0;
}