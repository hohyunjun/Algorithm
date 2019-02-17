#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {-1,-1,0,1,1,1,0,-1};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        int A[51][51];
        int check[51][51];

        // check 배열 0으로 초기화
        for(int i=0; i<51; i++){
            memset(check[i], 0, sizeof(int)*51);
        }
        
        int w, h;
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> A[i][j];
            }
        }

        int cc = 0;
        // 모든 섬에 대해서 연결 요소 체크
        for(int i=0; i<h; i++){ // x
            for(int j=0; j<w; j++){ // y
                if(A[i][j] == 1 && check[i][j] == 0){
                    cc++;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    check[i][j] = cc;
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        for(int k=0; k<8; k++){
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if(nx >= 0 && ny >=0 && nx < h && ny < w){
                                if(A[nx][ny] == 1 && check[nx][ny] == 0){
                                    q.push(make_pair(nx, ny));
                                    check[nx][ny] = cc;
                                }
                            }
                        }
                        q.pop();
                    }
                }
            }
        }

        cout << cc << '\n';
    }


    return 0;
}