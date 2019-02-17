#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> A[1001];
int check[1001];

int main(){

    int v, e;

    cin >> v >> e;

    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    int cc = 0;

    for(int i=1; i<=v; i++){
        // 방문되지 않은 정점일 경우 연결요소 증가, bfs
        if(check[i] == 0){
            cc++;
            queue<int> q;
            q.push(i);
            check[i] = 1;
            while(!q.empty()){
                int w = q.front();
                for(int j=0; j<A[w].size(); j++){
                    int x = A[w][j];
                    if(check[x] == 0){
                        check[x] = 1;
                        q.push(x);
                    }
                }
                q.pop();
            }
        }
    }

    cout << cc <<'\n';

    return 0;
}