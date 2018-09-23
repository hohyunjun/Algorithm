#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

struct Edge{
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost){

    }
};

vector<Edge> A[100001];
int dist[100001];
bool check[100001];

int main(){

    int v;
    scanf("%d", &v);

    for(int i=1; i<=v; i++){
        int a, b, dv;
        scanf("%d", &a);
        while(1){
            scanf("%d", &b);
            if(b == -1){
                break;
            }else{
                scanf("%d", &dv);
                A[a].push_back(Edge(b, dv));
            }
        }
    }

    // v를 시작점으로
    queue<int> q;
    q.push(v);
    check[v] = true;
    while(!q.empty()){
        int w = q.front();
        for(int i=0; i<A[w].size(); i++){
            if(check[A[w][i].to] == false){ // 아직 방문되지 않은 정점일 경우
                q.push(A[w][i].to);
                check[A[w][i].to] = true;
                dist[A[w][i].to] = dist[w] + A[w][i].cost;
            }
        }
        q.pop();
    }

    int maxdist = dist[1];
    for(int i=2; i<=v; i++){
        if(dist[i] > maxdist){
            maxdist = dist[i];
        }
    }

    int root;
    for(int i=1; i<=v; i++){
        if(dist[i] == maxdist){
            root = i; break;
        }
    }

    // root를 시작점으로 다시 시작
    memset(dist, 0, sizeof(dist));
    memset(check, false, sizeof(check));
    queue<int> q2;
    q2.push(root);
    check[root] = true;
    while(!q2.empty()){
        int w = q2.front();
        for(int i=0; i<A[w].size(); i++){
            if(check[A[w][i].to] == false){
                q2.push(A[w][i].to);
                check[A[w][i].to] = true;
                dist[A[w][i].to] = dist[w] + A[w][i].cost;
            }
        }
        q2.pop();
    }

    int answer = 0;
    for(int i=1; i<=v; i++){
        if(answer < dist[i]) answer = dist[i];
    }

    printf("%d\n", answer);

    return 0;
}