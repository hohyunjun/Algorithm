#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> A[100001];
int check[100001];
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
    check[1] = 1;
    parent[1] = 0;
    while(!q.empty()){
        int w = q.front();
        for(int i=0; i<A[w].size(); i++){
            if(check[A[w][i]] == 0){
                check[A[w][i]] = 1;
                q.push(A[w][i]);
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