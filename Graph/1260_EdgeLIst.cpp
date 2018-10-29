#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct Edge{
    int from, to;
};
Edge E[20001];
int cnt[1001];
bool check[1001];
bool cmp(const Edge &u, const Edge &v){
    if(u.from == v.from){
        return u.to < v.to;
    }else{
        return u.from < v.from;
    }
}

void DFS(int v){
    printf("%d ", v); check[v] = true; // 출력찍고 지나갔음을 체크
    //E[cnt[v-1]] 부터 E[cnt[v]-1] 까지가 v로 시작하는 정점들
    for(int i=cnt[v-1]; i<cnt[v]; i++){
        int y = E[i].to;
        if(check[y] == false){
            DFS(y);
        }
    }
}

void BFS(int v){
    queue<int> q;
    q.push(v); check[v] = true;
    while(!q.empty()){
        int w = q.front();
        q.pop();
        printf("%d ", w);
        for(int i=cnt[w-1]; i<cnt[w]; i++){
            int y = E[i].to;
            if(check[y] == false){
                q.push(y); check[y] = true;
            }
        }
    }
}

int main()
{
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);

    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        E[i].from = a;
        E[i].to = b;
        E[i+m].from = b;
        E[i+m].to = a;
    }

    m*= 2;

    sort(E, E+m, cmp);

    for(int i=0; i<m; i++){
        cnt[E[i].from] += 1;
    }

    for(int i=1; i<=n; i++){
        cnt[i] = cnt[i-1] + cnt[i];
    }

    // 이제 cnt에 저장돼 있는 값을 이용해서 특정 정점에서 시작하는 간선의 개수를 알 수 있다.

    DFS(v);
    printf("\n");
    memset(check, false, sizeof(check));
    BFS(v);

    return 0;
}