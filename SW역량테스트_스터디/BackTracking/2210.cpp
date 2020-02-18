#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int A[5][5];
vector<string> ans;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

void solve(int x, int y, int cnt, string tmp){
    if(x < 0 || y < 0 || x >= 5 || y >= 5) return;
    if(cnt == 6){
        ans.push_back(tmp);
        return;
    }
    for(int i=0; i<4; i++){
        solve(x+dx[i], y+dy[i], cnt+1, tmp+to_string(A[x+dx[i]][y+dy[i]]));
    }
}

int main(){

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> A[i][j];
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            solve(i,j,1,"" + to_string(A[i][j]));
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << '\n';

    return 0;
}