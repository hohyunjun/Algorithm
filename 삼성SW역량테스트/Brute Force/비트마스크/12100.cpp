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

// 실제 simulate 함수 : pa 값을 실제로 변경해주어야 하므로 call by reference 
void simulate(int direction, vector<vector< pair<int,bool> > > &pa){
    // 방향에 따라 적용 순서가 달라져야 한다.
    if(direction == 0){
        // 1회 시행
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                int x = i;
                int y = j;
                if(pa[x][y].first == 0) continue;
                while(true){
                    int nx = x + dx[direction];
                    int ny = y + dy[direction];
                    // 판을 벗어나는 경우
                    if(nx<0 || ny<0 || nx >= n || ny >= n) break;
                    // 합쳐질 수 없는 경우
                    if(pa[nx][ny].first != 0 && pa[nx][ny].first != pa[x][y].first) break;
                    if(pa[nx][ny].first == pa[x][y].first && (pa[x][y].second || pa[nx][ny].second)) break;
                    // 합쳐지는 경우
                    if(pa[x][y].first == pa[nx][ny].first && pa[x][y].second == false && pa[nx][ny].second == false){
                        pa[nx][ny].first = (pa[nx][ny].first << 1); // 이동할 블럭을 제곱수로 바꿔주고
                        pa[nx][ny].second = true; // 합쳐졌으므로 true로 바꿔준다.
                        pa[x][y].first = 0; // 원래 있던 자리의 블럭은 빈 자리로
                        break;
                    }
                    // 빈 자리로 이동하는 경우
                    if(pa[nx][ny].first == 0){
                        pa[nx][ny].first = pa[x][y].first;
                        pa[x][y].first = 0;
                        x = nx;
                        y = ny;
                    }
                }
            }
        }
    }else if(direction == 1){
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int x = i;
                int y = j;
                if(pa[x][y].first == 0) continue;
                while(true){
                    int nx = x + dx[direction];
                    int ny = y + dy[direction];
                    // 판을 벗어나는 경우
                    if(nx<0 || ny<0 || nx >= n || ny >= n) break;
                    // 합쳐질 수 없는 경우
                    if(pa[nx][ny].first != 0 && pa[nx][ny].first != pa[x][y].first) break;
                    if(pa[nx][ny].first == pa[x][y].first && (pa[x][y].second || pa[nx][ny].second)) break;
                    // 합쳐지는 경우
                    if(pa[x][y].first == pa[nx][ny].first && pa[x][y].second == false && pa[nx][ny].second == false){
                        pa[nx][ny].first = (pa[nx][ny].first << 1); // 이동할 블럭을 제곱수로 바꿔주고
                        pa[nx][ny].second = true; // 합쳐졌으므로 true로 바꿔준다.
                        pa[x][y].first = 0; // 원래 있던 자리의 블럭은 빈 자리로
                        break;
                    }
                    // 빈 자리로 이동하는 경우
                    if(pa[nx][ny].first == 0){
                        pa[nx][ny].first = pa[x][y].first;
                        pa[x][y].first = 0;
                        x = nx;
                        y = ny;
                    }
                }
            }
        }
    }else if(direction == 2){
        for(int i=0; i<n; i++){
            for(int j=n-2; j>=0; j--){
                int x = i;
                int y = j;
                if(pa[x][y].first == 0) continue;
                while(true){
                    int nx = x + dx[direction];
                    int ny = y + dy[direction];
                    // 판을 벗어나는 경우
                    if(nx<0 || ny<0 || nx >= n || ny >= n) break;
                    // 합쳐질 수 없는 경우
                    if(pa[nx][ny].first != 0 && pa[nx][ny].first != pa[x][y].first) break;
                    if(pa[nx][ny].first == pa[x][y].first && (pa[x][y].second || pa[nx][ny].second)) break;
                    // 합쳐지는 경우
                    if(pa[x][y].first == pa[nx][ny].first && pa[x][y].second == false && pa[nx][ny].second == false){
                        pa[nx][ny].first = (pa[nx][ny].first << 1); // 이동할 블럭을 제곱수로 바꿔주고
                        pa[nx][ny].second = true; // 합쳐졌으므로 true로 바꿔준다.
                        pa[x][y].first = 0; // 원래 있던 자리의 블럭은 빈 자리로
                        break;
                    }
                    // 빈 자리로 이동하는 경우
                    if(pa[nx][ny].first == 0){
                        pa[nx][ny].first = pa[x][y].first;
                        pa[x][y].first = 0;
                        x = nx;
                        y = ny;
                    }
                }
            }
        }
    }else{
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int x = i;
                int y = j;
                if(pa[x][y].first == 0) continue;
                while(true){
                    int nx = x + dx[direction];
                    int ny = y + dy[direction];
                    // 판을 벗어나는 경우
                    if(nx<0 || ny<0 || nx >= n || ny >= n) break;
                    // 합쳐질 수 없는 경우
                    if(pa[nx][ny].first != 0 && pa[nx][ny].first != pa[x][y].first) break;
                    if(pa[nx][ny].first == pa[x][y].first && (pa[x][y].second || pa[nx][ny].second)) break;
                    // 합쳐지는 경우
                    if(pa[x][y].first == pa[nx][ny].first && pa[x][y].second == false && pa[nx][ny].second == false){
                        pa[nx][ny].first = (pa[nx][ny].first << 1); // 이동할 블럭을 제곱수로 바꿔주고
                        pa[nx][ny].second = true; // 합쳐졌으므로 true로 바꿔준다.
                        pa[x][y].first = 0; // 원래 있던 자리의 블럭은 빈 자리로
                        break;
                    }
                    // 빈 자리로 이동하는 경우
                    if(pa[nx][ny].first == 0){
                        pa[nx][ny].first = pa[x][y].first;
                        pa[x][y].first = 0;
                        x = nx;
                        y = ny;
                    }
                }
            }
        }
    }
    // 시행 후 모든 bool 값을 false로
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            pa[i][j].second = false;
            //cout << pa[i][j].first << " ";
        }
        //cout << '\n';
    }

    return;
}

// 최대값 체크해서 반환하는 함수
int check(vector<int> dir, vector< vector<int> > A){

    // pa 는 기존의 A에 있는 숫자와 함께 한 번의 시행에서 이미 합쳐진 것인지를 체크하는 bool을 함께 저장하는 2차원 벡터
    vector<vector< pair<int,bool> > > pa(n,vector< pair<int,bool> >(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            pa[i][j].first = A[i][j];
        }
    }

    // dir에 저장되어 있는 5가지 방향 모두 수행
    for(int i=0; i<5; i++){
        //cout << i << "th direction : " << dir[i] << '\n';
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

    vector< vector<int> > A(n, vector<int>(n,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A[i][j];
        }
    }

    // 비트마스크를 활용해 모든 경우의 수를 만든다.
    for(int i=0; i< (1<<10); i++){
        // 2진수를 4진수 형태로 바꾸어 방향을 나타내도록 한다.
        vector<int> dir = getDir(i);
        // simulate
        ans = max(ans, check(dir, A));
    }

    // vector<int> dir = getDir(3);
    // ans = max(ans, check(dir,A));
    cout << ans;


    return 0;
}