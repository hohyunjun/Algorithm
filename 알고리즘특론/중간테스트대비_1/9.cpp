#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int check[100][100];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int solution(vector<vector<int>> grid) {
    int answer = 0;
    
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            if(grid[i][j] == 1 && check[i][j] == false){ // 아직 방문하지 않은 땅일경우
                answer += 1; // 섬 하나 추가요
                queue<pair<int, int>> q;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    for(int i=0; i<4; i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if(nx >= 0 && nx < grid.size() && ny>=0 && ny < grid[i].size()){ // 범위를 넘어가지 않을 경우에
                            if(grid[nx][ny] == 1 && check[nx][ny] == false){ // 아직 방문되지 않은 땅일경우
                                q.push(make_pair(nx, ny));
                                check[nx][ny] = true;
                            }
                        }
                    }
                    q.pop();
                }
            }
        }
    }
    
    return answer;
}