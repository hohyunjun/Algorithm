#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    체스판 다시 칠하기
    1. 8*8 크기로 자르기 : Brute Force
    2. 다시 칠해야 하는 정사각형 개수 구하기 : 미리 만들어놓은 8*8 체스판과 비교
*/
vector<string> chess_1(8); // 왼쪽 위 코너가 흰색
vector<string> chess_2(8); // 왼쪽 위 코너가 검은색
vector<string> input(50);

// chess_1과 비교해서 칠해야 하는 개수 반환
int check_1(int a, int b){
    int diff = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(chess_1[i][j] != input[a+i][b+j]) diff++;
        }
    }
    return diff;
}

// chess_2와 비교해서 칠해야 하는 개수 반환
int check_2(int a, int b){
    int diff = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(chess_2[i][j] != input[a+i][b+j]) diff++;
        }
    }
    return diff;
}

int main(){

    // 기본 체스판 초기화
    string w_start = "WBWBWBWB";
    string b_start = "BWBWBWBW";
    for(int i=0; i<8; i++){
        if(i%2){
            chess_1[i] = b_start;
        }else{
            chess_1[i] = w_start;
        }
    }

    for(int i=0; i<8; i++){
        if(i%2){
            chess_2[i] = w_start;
        }else{
            chess_2[i] = b_start;
        }
    }

    // input 배열을 받는다
    int n, m; // n 이 세로, m 이 가로

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> input[i];
    }

    int ans = 0x7FFFFFFF;

    for(int i=0; i<=n-8; i++){
        for(int j=0; j<=m-8; j++){
            ans = min(ans, check_1(i,j));
            ans = min(ans, check_2(i,j));
        }
    }

    cout << ans << '\n';

    return 0;
}