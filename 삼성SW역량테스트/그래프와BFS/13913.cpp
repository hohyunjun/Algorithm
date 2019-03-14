#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dist[100001]; // 각 점까지의 최소이동시간
int from[100001]; // 각 정점이 어디서부터 이동해왔는지 저장

int main(){

    int n, k;

    cin >> n >> k;

    queue<int> q;
    q.push(n);
    dist[n] = 1;

    while(!q.empty()){
        int x = q.front();
        int y = x-1;
        int z = x+1;
        int w = x*2;
        if(y>=0){
            if(dist[y]==0){ // 아직 방문되지 않은 정점일 경우
                q.push(y);
                dist[y] = dist[x] + 1;
                from[y] = x;
            }else if(dist[y] != 0 && dist[y] > dist[x]+1){ // 이미 방문된 정점이지만 최소이동시간이 아닐 경우
                q.push(y);
                dist[y] = dist[x]+1;
                from[y] = x;
            }
        }
        if(z<=100000){
            if(dist[z] == 0){
                q.push(z);
                dist[z] = dist[x] + 1;
                from[z] = x;
            }else if(dist[z] != 0 && dist[z] > dist[x] + 1){
                q.push(z);
                dist[z] = dist[x] + 1;
                from[z] = x;
            }
        }
        if(w<=100000){
            if(dist[w] == 0){
                q.push(w);
                dist[w] = dist[x] + 1;
                from[w] = x;
            }else if(dist[w] != 0 && dist[w] > dist[x] + 1){
                q.push(w);
                dist[w] = dist[x] + 1;
                from[w] = x;
            }
        }
        q.pop();
    }

    cout << dist[k] - 1 << '\n';

    vector<int> ans;
    int tmp = k;
    ans.push_back(k);
    while(tmp != n){
        ans.push_back(from[tmp]);
        tmp = from[tmp];
    }

    reverse(ans.begin(), ans.end());

    for(auto each : ans){
        cout << each << " ";
    }


    return 0;
}