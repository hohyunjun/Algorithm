#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int w, h;

// BFS 수행 후 시작점에서부터의 거리가 적힌 배열을 반환하는 함수
vector< vector<int> > bfs(vector<string> &A, int startx, int starty){

    vector< vector<int> > check(h, vector<int>(w, 0));

    queue< pair<int,int> > q;
    q.push(make_pair(startx,starty));
    check[startx][starty] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(A[nx][ny] == 'x') continue; // 벽
            if(check[nx][ny] != 0) continue; // 이미 방문
            if(A[nx][ny] == '.'){ // 빈공간
                check[nx][ny] = check[x][y] + 1;
                q.push(make_pair(nx,ny));
            }else{ // dirt일 경우
                check[nx][ny] = check[x][y] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }

    return check;
}

int main(){

    // 처음 풀 때 틀렸던 풀이(이 방식이 항상 최소이동거리를 보장해주지 않는다)
    // 로봇 청소기의 위치로부터 BFS 시작해서, 최초로 더러운 곳을 찾을 때까지 진행
    // 더러운 위치까지 이동한 거리 저장
    // 더러운 위치에서 다시 시작하여 다른 더러운 위치를 찾는 것 반복.
    // 더러운 위치는 깨끗한 위치로 바꿔야 한다.

    // 해설보고 풀어본 풀이
    // 모든 *의 위치를 저장한다.
    // 각 *로부터 BFS를 돌린 배열을 저장한다.
    // *의 순서를 순열로 permutation 돌려서 해당 순서대로 방문했을 때의 거리를 구해 최소값을 갱신해준다.

    while(true){

        cin >> w >> h;

        if(w==0 && h==0) break;

        vector<string> A(h);

        for(int i=0; i<h; i++){
            cin >> A[i];
        }

        vector< pair<int,int> > dirt(1); // dirt[0] 에는 로봇청소기, 1부터는 dirt 들이 저장
        int dirtyCnt = 0;
        int ans = 0x7FFFFFF;

        // 최초 로봇청소기의 시작위치를 찾아주고, 더러운 위치의 개수를 세 준다.
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(A[i][j] == 'o'){
                    dirt[0] = make_pair(i,j);
                    A[i][j] = '0';
                }else if(A[i][j] == '*'){
                    dirtyCnt++;
                    A[i][j] = dirtyCnt + '0';
                    dirt.push_back(make_pair(i,j));
                }
            }
        }

        int d[21][21]; // 특정 dirt로부터 다른 dirt로의 최소이동거리를 저장할 배열
        
        memset(d, -1, sizeof(d));

        int l = dirt.size();
        // dirt 내부에 있는 모든 좌표에서부터 시작한 거리 배열을 얻어낸다.
        for(int i=0; i<l; i++){
            auto dist = bfs(A,dirt[i].first, dirt[i].second); // dist는 dirt[i] 좌표에서부터 시작했을 때의 거리를 체크한 배열
            for(int j=0; j<l; j++){
                d[i][j] = dist[dirt[j].first][dirt[j].second] - 1; // d에다 최소이동거리 저장
            }
        }

        bool possible = true;

        for(int i=1; i<l; i++){
            if(d[0][i] == -1){
                possible = false;
                break;
            }
        }

        if(possible){
            // 0부터 dirt 개수만큼 order 배열 지정
            vector<int> order(l-1);
            for(int i=0; i<l-1; i++){
                order[i] = i+1;
            }

            do{
                int sum = d[0][order[0]];
                for(int i=0; i<l-2; i++){
                    sum += d[order[i]][order[i+1]];
                }
                ans = min(ans,sum);
            }while(next_permutation(order.begin(),order.end()));
        }else{
            ans = -1;
        }

        cout << ans << '\n';

    }




    return 0;
}