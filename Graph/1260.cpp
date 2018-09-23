#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

vector<int> A[1001];
bool check[1001] = {false};

void DFS(int v){
    printf("%d ", v); check[v] = true;
    // 인접한 정점 중에서 정점 번호가 가장 작고 아직 방문하지 않은 놈을 찾는다.
    for(int i=0; i<A[v].size(); i++){
        int y = A[v][i];
        if(check[y] == false){
            DFS(y);
        }
    }
}

void BFS(int v){
    memset(check, false, sizeof(check));
    queue<int> q;
    q.push(v); check[v] = true;
    while(!q.empty()){
        int w = q.front();
        for (int i = 0; i < A[w].size(); i++){
            int y = A[w][i];
            if (check[y] == false){
                q.push(y); check[y] = true;
            }
        }
        printf("%d ", w);
        q.pop();
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, v;
    cin >> n >> m >> v;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    for(int i=1; i<n; i++){
        sort(A[i].begin(), A[i].end());
    }

    DFS(v);
    printf("\n");
    BFS(v);

    return 0;
}