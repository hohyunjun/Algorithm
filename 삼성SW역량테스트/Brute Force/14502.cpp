#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int Map[8][8];

int main(){

    int n, m;
    int maxSafe = -0x7FFFFFFF;

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int posId;
            cin >> posId;
            Map[i][j] = posId;
        }
    }

    // 연구소에 벽을 3개 세운다. : 빈 칸의 개수 중에서 3개를 뽑는 brute force
    
    // 빈 칸 좌표 저장
    vector<pair<int,int>> empty;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(Map[i][j] == 0){
                empty.push_back(make_pair(i,j));
            }
        }
    }

    vector<int> p;
    for(int i=0; i<empty.size()-3; i++){
        p.push_back(0);
    }
    for(int i=0; i<3; i++){
        p.push_back(1);
    }

    do{
        int check[8][8];
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                check[i][j] = Map[i][j];
            }
        }
        for(int i=0; i<p.size(); i++){
            if(p[i]==1){
                check[empty[i].first][empty[i].second] = 1;
            }
        }
        
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(check[i][j] == 2){
                    q.push(make_pair(i,j));
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >=0 && nx < n && ny < m){
                    if(check[nx][ny] == 0){
                        q.push(make_pair(nx,ny));
                        check[nx][ny] = 2;
                    }
                }
            }
            q.pop();
        }

        int zeroCount = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(check[i][j] == 0){
                    zeroCount++;
                }
            }
        }

        maxSafe = max(maxSafe, zeroCount);

    }while(next_permutation(p.begin(), p.end()));


    cout << maxSafe << '\n';




    return 0;
}