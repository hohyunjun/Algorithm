#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A[1001];
int check[1001];
int check2[1001];

void dfs(int x){
    check[x] = 1;
    cout << x << " ";
    for(int i=0; i<A[x].size(); i++){
        int y = A[x][i];
        // 아직 방문되지 않은 정점이라면
        if(check[y] == 0){
            dfs(y);
        }
    }
}

int main(){

    int v, e, start;

    cin >> v >> e >> start;

    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    for(int i=1; i<=v; i++){
        sort(A[i].begin(), A[i].end());
    }

    dfs(start);
    cout << '\n';

    queue<int> q;
    q.push(start);
    check2[start] = 1;

    while(!q.empty()){
        int x = q.front();
        cout << x << " ";
        for(int i=0; i<A[x].size(); i++){
            if(check2[A[x][i]] == 0){
                q.push(A[x][i]);
                check2[A[x][i]] = 1;
            }
        }
        q.pop();
    }

    return 0;
}