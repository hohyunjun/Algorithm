#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int,int>> dist(100001); // 첫번째 값은 최소 dist, 두번째  값은 가장 빠른 시간으로 찾는 방법의 수

int main(){

    int n,k;

    cin >> n >> k;

    queue<int> q;
    q.push(n);
    dist[n] = make_pair(1,1);

    while(!q.empty()){
        int x = q.front();

        int a = x+1;
        int b = x-1;
        int c = x*2;

        if(a<=100000){
            if(dist[a].first == 0){ // 방문되지 않은 정점이라면
                dist[a].first = dist[x].first + 1;
                dist[a].second += 1;
                q.push(a);
            }else if(dist[a].first !=0 && dist[a].first > dist[x].first + 1){
                dist[a].first = dist[x].first + 1;
                dist[a].second = 1;
                q.push(a);
            }else if(dist[a].first !=0 && dist[a].first == dist[x].first + 1){
                dist[a].second += 1;
                q.push(a);
            }
        }

        if(b >= 0){
            if(dist[b].first == 0){ // 방문되지 않은 정점이라면
                dist[b].first = dist[x].first + 1;
                dist[b].second += 1;
                q.push(b);
            }else if(dist[b].first !=0 && dist[b].first > dist[x].first + 1){
                dist[b].first = dist[x].first + 1;
                dist[b].second = 1;
                q.push(b);
            }else if(dist[b].first !=0 && dist[b].first == dist[x].first + 1){
                dist[b].second += 1;
                q.push(b);
            }
        }

        if(c <= 100000){
            if(dist[c].first == 0){ // 방문되지 않은 정점이라면
                dist[c].first = dist[x].first + 1;
                dist[c].second += 1;
                q.push(c);
            }else if(dist[c].first !=0 && dist[c].first > dist[x].first + 1){
                dist[c].first = dist[x].first + 1;
                dist[c].second = 1;
                q.push(c);
            }else if(dist[c].first !=0 && dist[c].first == dist[x].first + 1){
                dist[c].second += 1;
                q.push(c);
            }
        }
        q.pop();
    }

    cout << dist[k].first - 1 << '\n' << dist[k].second << '\n';

    return 0;
}