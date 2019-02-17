#include <iostream>
#include <vector>
using namespace std;

int check[20001];

void dfs(int x, int prev, vector<int> A[]){
    if(check[prev] == 0 || check[prev] == 2){
        check[x] = 1;
    }else{
        check[x] = 2;
    }
    for(int i=0; i<A[x].size(); i++){
        int y = A[x][i];
        if(check[y] == 0){
            dfs(y, x, A);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;

    cin >> tc;

    while(tc--){
        vector<int> A[20001];
        fill_n(check, 20001, 0);

        int v, e;
        cin >> v >> e;

        for(int i=0; i<e; i++){
            int a, b;
            cin >> a >> b;
            A[a].push_back(b);
            A[b].push_back(a);
        }

        // 모든 정점에 대해 dfs 수행
        for(int i=1; i<=v; i++){
            if(check[i] == 0){
                dfs(i,0,A);
            }
        }

        bool isBipartite = true;

        for(int i=1; i<=v; i++){
            for(int j=0; j<A[i].size(); j++){
                int y = A[i][j];
                if(check[i] == check[y]){
                    isBipartite = false;
                    break;
                }
            }
            if(!isBipartite) break;
        }

        if(isBipartite){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }


    return 0;
}