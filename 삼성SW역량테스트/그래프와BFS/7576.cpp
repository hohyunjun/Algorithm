#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int A[1001][1001];
int dist[1001][1001];

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;

    cin >> m >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> A[i][j];
        }
    }

    queue<pair<int,int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j] == 1){
                q.push(make_pair(i,j));
                dist[i][j] = 1;
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny >= 0 && nx < n && ny < m){
                if(A[nx][ny] == 0 && dist[nx][ny] == 0){
                    q.push(make_pair(nx,ny));
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
        q.pop();
    }

    int days = 0;
    bool complete = true;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dist[i][j] == 0 && A[i][j] != -1){
                complete = false;
                break;
            }
            days = max(days, dist[i][j]);
        }
        if(!complete) break;
    }

    cout << days -1 << '\n';

    return 0;
}