#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int A[26][26];
int check[26][26];

int main(){

    int n; 

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &A[i][j]);
        }
    }

    int cc = 0;
    // 모든 좌표에 대해 집이고 아직 방문되지 않았을 경우
    for(int i=0; i<n; i++){ // x
        for(int j=0; j<n; j++){ // y
            if(A[i][j] == 1 && check[i][j] == 0){
                cc++;
                queue<pair<int, int>> q;
                q.push(make_pair(i,j));
                check[i][j] = cc;

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    for(int k=0; k<4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx >= 0 && ny >= 0 && nx < n && ny < n){
                            if(A[nx][ny] == 1 && check[nx][ny] == 0){
                                check[nx][ny] = cc;
                                q.push(make_pair(nx,ny));
                            }
                        }
                    }
                    q.pop();
                }
            }
        }
    }

    vector<int> answers;

    for(int k=1; k<=cc; k++){
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(check[i][j] == k) cnt++;
            }
        }
        answers.push_back(cnt);
    }

    sort(answers.begin(), answers.end());

    printf("%d\n", cc);

    for(auto each:answers){
        printf("%d\n", each);
    }
    


    return 0;
}