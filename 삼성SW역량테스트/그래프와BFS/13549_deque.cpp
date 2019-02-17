#include <iostream>
#include <queue>
using namespace std;

int dist[100001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill_n(dist, 100001, -1);

    int n, k;

    cin >> n >> k;


    deque<int> dq;
    dq.push_front(n);
    dist[n] = 0;

    while(!dq.empty()){
        int x = dq.front();
        dq.pop_front();

        // 2*x
        if(2*x <= 100000 && dist[2*x] == -1){
            dq.push_front(2*x);
            dist[2*x] = dist[x];
        }

        // x+1
        if(x+1 <= 100000 && dist[x+1] == -1){
            dq.push_back(x+1);
            dist[x+1] = dist[x] + 1;
        }

        // x-1
        if(x-1 >= 0 && dist[x-1] == -1){
            dq.push_back(x-1);
            dist[x-1] = dist[x] + 1;
        }
    }

    cout << dist[k] << '\n';

    return 0;
}