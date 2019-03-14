#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int main(){

    int t;

    cin >> t;

    while(t--){
        int h, w;

        cin >> h >> w;

        // 임의로 바깥의 빈칸 '.' 을 추가하여 그래프를 나타낸다.
        vector<string> A(h+2);
        string tmp = "";
        for(int i=0; i<w+2; i++){
            tmp += ".";
        }
        A[0] = tmp;
        for(int i=1; i<h+1; i++){
            string tmp2 = ".";
            string tmp3 = "";

            cin >> tmp3;
            tmp2 += tmp3;
            tmp2 += ".";
            A[i] = tmp2;
        }
        A[h+1] = tmp;

        // BFS를 시작할 죄수들의 위치 저장
        vector<pair<int,int>> prisoner;
        for(int i=0; i<h+2; i++){
            for(int j=0; j<w+2; j++){
                if(A[i][j] == '$'){
                    prisoner.push_back(make_pair(i,j));
                }
            }
        }

        // 각 BFS의 결과값을 저장할 배열
        int check[h+2][w+2];
        int check1[h+2][w+2];
        int check2[h+2][w+2];
        int check3[h+2][w+2];
        
        memset(check, -1, sizeof(check));
        memset(check1, -1, sizeof(check1));
        memset(check2, -1, sizeof(check2));
        memset(check3, -1, sizeof(check3));

        prisoner.push_back(make_pair(0,0));

        // 각각의 시작점에서 BFS 수행
        for(int i=0; i<3; i++){
            deque<pair<int,int>> q;
            q.push_back(make_pair(prisoner[i].first, prisoner[i].second));
            check[prisoner[i].first][prisoner[i].second] = 0;
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop_front();
                for(int j=0; j<4; j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(nx>=0 && ny>=0 && nx<h+2 && ny<w+2){
                        if(A[nx][ny] == '*') continue;
                        if(check[nx][ny] != -1) continue;
                        if(A[nx][ny] == '#'){
                            check[nx][ny] = check[x][y] + 1;
                            q.push_back(make_pair(nx,ny));
                        }else{
                            check[nx][ny] = check[x][y];
                            q.push_front(make_pair(nx,ny));
                        }
                    }
                }
                
            }
            if(i==0){
                for(int a1=0; a1<h+2; a1++){
                    for(int a2=0; a2<w+2; a2++){
                        check1[a1][a2] = check[a1][a2];
                    }
                }
            }else if(i==1){
                for(int a1=0; a1<h+2; a1++){
                    for(int a2=0; a2<w+2; a2++){
                        check2[a1][a2] = check[a1][a2];
                    }
                }
            }else{
                for(int a1=0; a1<h+2; a1++){
                    for(int a2=0; a2<w+2; a2++){
                        check3[a1][a2] = check[a1][a2];
                    }
                }
            }
            memset(check, -1, sizeof(check));
        }

        int ans = 0x7FFFFFFF;
        for(int i=0; i<h+2; i++){
            for(int j=0; j<w+2; j++){
                if(A[i][j] == '*') continue;
                int cur = check1[i][j] + check2[i][j] + check3[i][j];
                if(A[i][j] == '#'){
                    cur -= 2;
                }
                ans = min(ans, cur);
            }
        }

        cout << ans << '\n';

    }


    return 0;
}