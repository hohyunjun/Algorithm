#include <iostream>
#include <vector>
using namespace std;

vector<int> A[1001];
int check[1001];

void dfs(int x){
    check[x] = 1;
    for(int i=0; i<A[x].size(); i++){
        if(check[A[x][i]] == 0){
            dfs(A[x][i]);
        }
    }
}

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
        if(check[i] == 0){
            cc++;
            dfs(i);
        }
    }

    cout << cc << '\n';

    return 0;
}