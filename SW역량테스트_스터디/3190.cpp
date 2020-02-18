#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
    BOJ 3190 뱀 (Simulation)
    1. 뱀이 위치한 좌표들을 deque<pair<int,int>> 형태로 저장한다.
    2. 꼬리 자를 때 deque.pop_front();
    3. 길이 추가할 때 deque.push_back();
    4. 방향을 바꿀지 말지는 해당 초의 시행이 끝난 이후에 판단.

*/

// 0은 빈공간, 1은 사과, 2는 뱀
int A[101][101];

// 진행방향 왼쪽 0, 위, 1, 오른쪽 2, 아래 3
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    int k;

    cin >> k;

    for(int i=0; i<k; i++){
        int row, col;
        cin >> row >> col;

        // 사과위치 체크
        A[row-1][col-1] = 1;
    }

    int l;

    cin >> l;

    // 방향 변환 정보 저장
    vector<pair<int, char>> change(l);

    for(int i=0; i<l; i++){
        cin >> change[i].first;
        cin >> change[i].second;
    }

    int curx = 0;
    int cury = 0;
    A[0][0] = 2;
    int curDir = 2;
    int changeIndex = 0;
    int cnt = 0;

    deque<pair<int,int>> snake; // 뱀이 위치한 좌표를 deque에 저장한다.
    snake.push_back(make_pair(0,0));

    while(true){

        cnt++;

        // 다음 위치 저장
        int nx = curx + dx[curDir];
        int ny = cury + dy[curDir];

        // 다음 위치가 범위를 벗어나면 break;
        if(nx >= n || ny >= n || nx < 0 || ny < 0){
            break;
        }   
        
        // 다음 위치가 비어있을 경우, 꼬리가 위치한 칸을 비워준다.
        if(A[nx][ny] == 0){
            A[snake.front().first][snake.front().second] = 0; // 뱀의 꼬리좌표 삭제
            snake.pop_front(); // 뱀의 꼬리좌표 삭제
            snake.push_back(make_pair(nx,ny)); // 새로 들어온 head 저장
            A[nx][ny] = 2;
            curx = nx;
            cury = ny;
        }else if(A[nx][ny] == 1){ // 사과일경우, 꼬리는 움직이지 않는다.
            A[nx][ny] = 2;
            snake.push_back(make_pair(nx,ny)); // 새로 들어온 head 저장
            curx = nx;
            cury = ny;
        }else if(A[nx][ny] == 2){ // 꼬리에 부딪힐 경우
            break;
        }

        // 현재 초가 끝난 뒤에 방향을 바꾸는지 체크
        if(changeIndex < l && change[changeIndex].first == cnt){
            if(change[changeIndex].second == 'L'){
                curDir-=1;
                if(curDir==-1) curDir = 3;
            }else if(change[changeIndex].second == 'D'){
                curDir+=1;
                if(curDir==4) curDir = 0;
            }
            changeIndex++;
        }
    }

    cout << cnt << '\n';    


    return 0;
}