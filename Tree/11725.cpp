#include <cstdio>
#include <queue>
using namespace std;

vector<int> A[100001];
bool check[100001];
int parent[100001];


int main(){

    int n;
    scanf("%d", &n);

    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        A[a].push_back(b);
        A[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    check[1] = true;
    parent[1] = 0;
    while(!q.empty()){
        int w = q.front();
        for(int i=0; i<A[w].size(); i++){
            if(check[A[w][i]] == false){ // 아직 방문되지 않은 정점이라면
                q.push(A[w][i]);
                check[A[w][i]] = true;
                parent[A[w][i]] = w;
            }
        }
        q.pop();
    }

    for(int i=2; i<=n; i++){
        printf("%d\n", parent[i]);
    }

    return 0;
}