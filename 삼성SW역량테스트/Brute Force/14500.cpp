#include <iostream>
#include <vector>
using namespace std;

int main(){

    int m, n; // n이 세로크기, m이 가로크기

    cin >> n >> m;

    vector<int> A[n];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int tmp;
            cin >> tmp;
            A[i].push_back(tmp);
        }
    }

    int maxSum = 0;
    int sum = 0;

    vector<pair<int, int>> Tetromino[19];

    Tetromino[0].push_back(make_pair(0,0)); Tetromino[0].push_back(make_pair(0,1)); Tetromino[0].push_back(make_pair(0,2)); Tetromino[0].push_back(make_pair(0,3));
    Tetromino[1].push_back(make_pair(0,0)); Tetromino[1].push_back(make_pair(1,0)); Tetromino[1].push_back(make_pair(2,0)); Tetromino[1].push_back(make_pair(3,0));
    Tetromino[2].push_back(make_pair(0,0)); Tetromino[2].push_back(make_pair(0,1)); Tetromino[2].push_back(make_pair(1,0)); Tetromino[2].push_back(make_pair(1,1));
    Tetromino[3].push_back(make_pair(0,0)); Tetromino[3].push_back(make_pair(1,0)); Tetromino[3].push_back(make_pair(2,0)); Tetromino[3].push_back(make_pair(2,1));
    Tetromino[4].push_back(make_pair(0,0)); Tetromino[4].push_back(make_pair(1,0)); Tetromino[4].push_back(make_pair(0,1)); Tetromino[4].push_back(make_pair(0,2));
    Tetromino[5].push_back(make_pair(0,0)); Tetromino[5].push_back(make_pair(0,1)); Tetromino[5].push_back(make_pair(1,1)); Tetromino[5].push_back(make_pair(2,1));
    Tetromino[6].push_back(make_pair(0,0)); Tetromino[6].push_back(make_pair(1,0)); Tetromino[6].push_back(make_pair(1,-1)); Tetromino[6].push_back(make_pair(1,-2));
    Tetromino[7].push_back(make_pair(0,0)); Tetromino[7].push_back(make_pair(1,0)); Tetromino[7].push_back(make_pair(2,0)); Tetromino[7].push_back(make_pair(2,-1));
    Tetromino[8].push_back(make_pair(0,0)); Tetromino[8].push_back(make_pair(1,0)); Tetromino[8].push_back(make_pair(1,1)); Tetromino[8].push_back(make_pair(1,2));
    Tetromino[9].push_back(make_pair(0,0)); Tetromino[9].push_back(make_pair(0,1)); Tetromino[9].push_back(make_pair(1,0)); Tetromino[9].push_back(make_pair(2,0));
    Tetromino[10].push_back(make_pair(0,0)); Tetromino[10].push_back(make_pair(0,1)); Tetromino[10].push_back(make_pair(0,2)); Tetromino[10].push_back(make_pair(1,2));
    Tetromino[11].push_back(make_pair(0,0)); Tetromino[11].push_back(make_pair(1,0)); Tetromino[11].push_back(make_pair(1,1)); Tetromino[11].push_back(make_pair(2,1));
    Tetromino[12].push_back(make_pair(0,0)); Tetromino[12].push_back(make_pair(0,1)); Tetromino[12].push_back(make_pair(1,0)); Tetromino[12].push_back(make_pair(1,-1));
    Tetromino[13].push_back(make_pair(0,0)); Tetromino[13].push_back(make_pair(1,0)); Tetromino[13].push_back(make_pair(1,-1)); Tetromino[13].push_back(make_pair(2,-1));
    Tetromino[14].push_back(make_pair(0,0)); Tetromino[14].push_back(make_pair(0,1)); Tetromino[14].push_back(make_pair(1,1)); Tetromino[14].push_back(make_pair(1,2));
    Tetromino[15].push_back(make_pair(0,0)); Tetromino[15].push_back(make_pair(0,1)); Tetromino[15].push_back(make_pair(0,2)); Tetromino[15].push_back(make_pair(1,1));
    Tetromino[16].push_back(make_pair(0,0)); Tetromino[16].push_back(make_pair(0,1)); Tetromino[16].push_back(make_pair(-1,1)); Tetromino[16].push_back(make_pair(1,1));
    Tetromino[17].push_back(make_pair(0,0)); Tetromino[17].push_back(make_pair(1,-1)); Tetromino[17].push_back(make_pair(1,0)); Tetromino[17].push_back(make_pair(1,1));
    Tetromino[18].push_back(make_pair(0,0)); Tetromino[18].push_back(make_pair(1,0)); Tetromino[18].push_back(make_pair(1,1)); Tetromino[18].push_back(make_pair(2,0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<19; k++){
                // 범위를 벗어나는 경우
                if(i+Tetromino[k][1].first < 0 || i+Tetromino[k][1].first >= n || j+Tetromino[k][1].second < 0 || j+Tetromino[k][1].second >=m){
                    continue;
                }
                if(i+Tetromino[k][2].first < 0 || i+Tetromino[k][2].first >= n || j+Tetromino[k][2].second < 0 || j+Tetromino[k][2].second >=m){
                    continue;
                }
                if(i+Tetromino[k][3].first < 0 || i+Tetromino[k][3].first >= n || j+Tetromino[k][3].second < 0 || j+Tetromino[k][3].second >=m){
                    continue;
                }
                sum += A[i+Tetromino[k][0].first][j+Tetromino[k][0].second];
                sum += A[i+Tetromino[k][1].first][j+Tetromino[k][1].second];
                sum += A[i+Tetromino[k][2].first][j+Tetromino[k][2].second];
                sum += A[i+Tetromino[k][3].first][j+Tetromino[k][3].second];
                if(maxSum < sum){
                    maxSum = sum;
                }
                sum = 0;
            }
        }
    }

    cout << maxSum << endl;

    return 0;
}