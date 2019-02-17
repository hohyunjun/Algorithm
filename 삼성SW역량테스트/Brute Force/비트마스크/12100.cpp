#include <iostream>
#include <vector>
using namespace std;

// 왼쪽 : 0 , 위 : 1, 오른쪽 : 2, 아래 : 3
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int n;

// 2진수를 4진수 형태로 바꿔주는 함수
vector<int> getDir(int k){
    vector<int> dir(5);
    for(int i=0; i<5; i++){
        dir[i] = (k&3);
        k >>= 2;
    }
    return dir;
}

// 실제 simulate 함수
int simulate(int direction, vector<vector<pair<int,bool>>> &pa){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << pa[i][j].first << " ";
        }
        cout << '\n';
    }

}

// 최대값 체크해서 반환하는 함수
int check(vector<int> dir, vector<vector<int>> A){

    vector<vector<pair<int,bool>>> pa(n,vector<pair<int,bool>>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            pa[i][j].first = A[i][j];
        }
    }

    // dir에 저장되어 있는 5가지 방향 모두 수행
    for(int i=0; i<5; i++){
        simulate(dir[i], pa);
    }

    // 최대값 구한다
    int tmp = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tmp = max(tmp, pa[i][j].first);
        }
    }

    return tmp;
}

int main(){

    int ans = 0;

    cin >> n;

    vector<vector<int>> A(n, vector<int>(n,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A[i][j];
        }
    }

    // // 비트마스크를 활용해 모든 경우의 수를 만든다.
    // for(int i=0; i< (1<<10); i++){
    //     // 2진수를 4진수 형태로 바꾸어 방향을 나타내도록 한다.
    //     vector<int> dir = getDir(i);
    //     // simulate
    //     ans = max(ans, check(dir, A));
    // }

    vector<int> dir = getDir(0);
    cout << check(dir,A);


    return 0;
}