#include <iostream>
#include <string>
#include <math.h>
using namespace std;

/*
    BOJ 1063.킹
    1. 움직임에 따른 좌표값의 변화를 먼저 초기화한다.
    2. king, stone 위치를 좌표값 형태로 변환
    3. 이동
*/

int chess[8][8];
int dx[] = {0,-1,-1,-1,0,1,1,1}; // 이동방향 ㅡ \ | / ㅡ 방향으로
int dy[] = {-1,-1,0,1,1,1,0,-1}; // 

pair<int,int> strToPair(string str);
void move(pair<int,int> &king, pair<int,int> &stone, int dir);
string pairToStr(pair<int,int> p);

int main(){

    pair<int,int> king;
    pair<int,int> stone;

    string kstr;
    string ststr;

    cin >> kstr >> ststr;

    king  = strToPair(kstr);
    stone = strToPair(ststr);

    int t;
    cin >> t;

    while(t--){
        string dir;
        cin >> dir;

        // 왼쪽부터 시계방향으로 차례로
        if(dir == "L"){
            move(king, stone, 0);
        }else if(dir == "LT"){
            move(king, stone, 1);
        }else if(dir == "T"){
            move(king, stone, 2);
        }else if(dir == "RT"){
            move(king, stone, 3);
        }else if(dir == "R"){
            move(king, stone, 4);
        }else if(dir == "RB"){
            move(king, stone, 5);
        }else if(dir == "B"){
            move(king, stone, 6);
        }else if(dir == "LB"){
            move(king, stone, 7);
        }
    }

    kstr = pairToStr(king);
    ststr = pairToStr(stone);
    
    cout << kstr << '\n';
    cout << ststr << '\n';

    return 0;
}

pair<int,int> strToPair(string str){
    pair<int,int> ret;
    int x, y;
    x = abs((str[1] - '0') - 8);
    y = str[0] - 'A';
    ret = make_pair(x,y);
    return ret;
}

void move(pair<int,int> &king, pair<int,int> &stone, int dir){
    // 먼저, king 이동
    int kx, ky, nkx, nky;
    kx = king.first;
    ky = king.second;
    nkx = kx + dx[dir];
    nky = ky + dy[dir];
    if(nkx >= 0 && nky >= 0 && nkx < 8 && nky < 8){ // 체스판 범위내라면
        king = make_pair(nkx, nky);    
    }else{
        return;
    }

    // 이동하려는 자리에 돌이있다면
    if(nkx == stone.first && nky == stone.second){
        int sx, sy, nsx, nsy;
        sx = stone.first;
        sy = stone.second;
        nsx = sx + dx[dir];
        nsy = sy + dy[dir];
        if(nsx >= 0 && nsy >= 0 && nsx < 8 && nsy < 8){ // 체스판 범위내라면
            stone = make_pair(nsx, nsy);
        }else{
            king  = make_pair(kx, ky);
        }
    }
    return;
}

string pairToStr(pair<int,int> p){
    string tmp = "";
    // 열부터
    tmp += (p.second + 'A');
    // 행
    tmp += (8 - p.first) + '0';

    return tmp;
}