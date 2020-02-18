#include <iostream>
#include <vector>
using namespace std;

int A[501][501];

int main(){

    int n, m;

    int ans = 0;

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> A[i][j];
        }
    }

    // 가능한 19가지 경우수에 대해서 모든 좌표 저장
    vector<pair<int,int>> Tetromino[19];

    // ㅡ
    Tetromino[0].push_back(make_pair(0,0)); Tetromino[0].push_back(make_pair(0,1)); Tetromino[0].push_back(make_pair(0,2)); Tetromino[0].push_back(make_pair(0,3));
    Tetromino[1].push_back(make_pair(0,0)); Tetromino[1].push_back(make_pair(1,0)); Tetromino[1].push_back(make_pair(2,0)); Tetromino[1].push_back(make_pair(3,0));

    // ㅁ
    Tetromino[2].push_back(make_pair(0,0)); Tetromino[2].push_back(make_pair(0,1)); Tetromino[2].push_back(make_pair(1,0)); Tetromino[2].push_back(make_pair(1,1));

    // L
    Tetromino[3].push_back(make_pair(0,0)); Tetromino[3].push_back(make_pair(1,0)); Tetromino[3].push_back(make_pair(2,0)); Tetromino[3].push_back(make_pair(2,1));
    Tetromino[4].push_back(make_pair(0,0)); Tetromino[4].push_back(make_pair(1,0)); Tetromino[4].push_back(make_pair(0,1)); Tetromino[4].push_back(make_pair(0,2));
    Tetromino[5].push_back(make_pair(0,0)); Tetromino[5].push_back(make_pair(0,1)); Tetromino[5].push_back(make_pair(1,1)); Tetromino[5].push_back(make_pair(2,1));
    Tetromino[6].push_back(make_pair(0,0)); Tetromino[6].push_back(make_pair(0,1)); Tetromino[6].push_back(make_pair(0,2)); Tetromino[6].push_back(make_pair(-1,2));
    Tetromino[7].push_back(make_pair(0,0)); Tetromino[7].push_back(make_pair(0,1)); Tetromino[7].push_back(make_pair(-1,1)); Tetromino[7].push_back(make_pair(-2,1));
    Tetromino[8].push_back(make_pair(0,0)); Tetromino[8].push_back(make_pair(-1,0)); Tetromino[8].push_back(make_pair(0,1)); Tetromino[8].push_back(make_pair(0,2));
    Tetromino[9].push_back(make_pair(0,0)); Tetromino[9].push_back(make_pair(0,1)); Tetromino[9].push_back(make_pair(1,0)); Tetromino[9].push_back(make_pair(2,0));
    Tetromino[10].push_back(make_pair(0,0)); Tetromino[10].push_back(make_pair(0,1)); Tetromino[10].push_back(make_pair(0,2)); Tetromino[10].push_back(make_pair(1,2));

    //
    Tetromino[11].push_back(make_pair(0,0)); Tetromino[11].push_back(make_pair(1,0)); Tetromino[11].push_back(make_pair(1,1)); Tetromino[11].push_back(make_pair(2,1));
    Tetromino[12].push_back(make_pair(0,0)); Tetromino[12].push_back(make_pair(0,1)); Tetromino[12].push_back(make_pair(-1,1)); Tetromino[12].push_back(make_pair(-1,2));
    Tetromino[13].push_back(make_pair(0,0)); Tetromino[13].push_back(make_pair(-1,0)); Tetromino[13].push_back(make_pair(-1,1)); Tetromino[13].push_back(make_pair(-2,1));
    Tetromino[14].push_back(make_pair(0,0)); Tetromino[14].push_back(make_pair(0,1)); Tetromino[14].push_back(make_pair(1,1)); Tetromino[14].push_back(make_pair(1,2));

    // ㅗ
    Tetromino[15].push_back(make_pair(0,0)); Tetromino[15].push_back(make_pair(0,1)); Tetromino[15].push_back(make_pair(0,2)); Tetromino[15].push_back(make_pair(1,1));
    Tetromino[16].push_back(make_pair(0,0)); Tetromino[16].push_back(make_pair(0,1)); Tetromino[16].push_back(make_pair(-1,1)); Tetromino[16].push_back(make_pair(1,1));
    Tetromino[17].push_back(make_pair(0,0)); Tetromino[17].push_back(make_pair(0,1)); Tetromino[17].push_back(make_pair(0,2)); Tetromino[17].push_back(make_pair(-1,1));
    Tetromino[18].push_back(make_pair(0,0)); Tetromino[18].push_back(make_pair(1,0)); Tetromino[18].push_back(make_pair(1,1)); Tetromino[18].push_back(make_pair(2,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<19; k++){
                int tmp = 0;
                // 범위를 벗어날 경우 continue;
                if(i + Tetromino[k][1].first < 0 || i+Tetromino[k][2].first < 0 || i+Tetromino[k][3].first < 0){
                    continue;
                }
                if(i + Tetromino[k][1].first >= n || i+Tetromino[k][2].first >= n || i+Tetromino[k][3].first >= n){
                    continue;
                }
                if(j + Tetromino[k][1].second < 0 || j+Tetromino[k][2].second < 0 || j+Tetromino[k][3].second < 0){
                    continue;
                }
                if(j + Tetromino[k][1].second >= m || j+Tetromino[k][2].second >= m || j+Tetromino[k][3].second >= m){
                    continue;
                }

                tmp += A[i + Tetromino[k][0].first][j + Tetromino[k][0].second];
                tmp += A[i + Tetromino[k][1].first][j + Tetromino[k][1].second];
                tmp += A[i + Tetromino[k][2].first][j + Tetromino[k][2].second];
                tmp += A[i + Tetromino[k][3].first][j + Tetromino[k][3].second];
                ans = max(ans, tmp);
            }
        }
    }

    cout << ans << '\n';


    return 0;
}